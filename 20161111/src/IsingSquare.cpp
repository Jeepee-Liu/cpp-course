#ifdef ISING_SQUARE

IsingSquare::IsingSquare (int argc, char* const argv[]) :
_setting (argc, argv), _precision(_setting.precision),
_rd (), _gen (_rd()),
_boolRand (0, 1), _unitRand (0, 1),
fout (_setting.outputDir.c_str()), _width(16),
_flipQueue() {
	/* Generate spin array */
	_spin = new bool* [_setting.range.x];
	for (int i = 0; i < _setting.range.x; ++i ) {
		_spin[i] = new bool[_setting.range.y];
		for (int j = 0; j < _setting.range.y; ++j ) {
			_spin[i][j] = _generateOneSpin();
		}
	}
	
	/* generate flip probability map */
	// energy input is always negative
	// for this test.
	_flipProb[-1] = std::exp(-2.0/_setting.kT);
	_flipProb[-2] = std::exp(-4.0/_setting.kT);
	_flipProb[-3] = std::exp(-6.0/_setting.kT);
	_flipProb[-4] = std::exp(-8.0/_setting.kT);

	/* generate the to-be-shuffled list of xs & ys */
	for (int i=0; i < _setting.range.x; ++i) {
		for (int j=0; j < _setting.range.y; ++j) {
			xs.push_back (i);
			ys.push_back (j);
		}
	}
	
} // DONE

IsingSquare::~IsingSquare () {
	for (int i = 0; i < _setting.range.x; ++i ) {
		delete []_spin[i];
	}
	delete []_spin;
} // DONE

void IsingSquare::simulate () {
	// TODO finish this func
	double* ms = new double[_setting.avgN];
	bool stop = false;
	if (!fout) {
		std::cerr << "Cannot open file!" << std::endl;
		return;
	}
	fout << std::setw(_width) << "loop#"
	<< std::setw(_width) << "m_mean"
	<< std::setw(_width) << "m_std" << std::endl
	<< std::setprecision(8);
	
	for (int bigStep = 0;
		bigStep < _setting.stepN;
		++bigStep) {
		for (int smallStep = 0;
			smallStep < _setting.avgN;
			smallStep++) {
			_tryToFlipAll();
			ms[smallStep] = _calcMagnetization();
		}
		stop = _statisticsPrintln(bigStep, ms, fout);
		if (stop) {
			std::cout << "precision reached. STOP simulation!" << std::endl;
			break;
		}
	}
	delete[] ms; 
}

inline bool IsingSquare::_generateOneSpin () {
	switch (_setting.initMode) {
		case SettingT::allUp:
			return (_boolRand(_gen) == 0) ? false : true;
		case SettingT::random:
			return true;
		default:
			return (_boolRand(_gen) == 0) ? false : true;
	}
}

inline void IsingSquare::_tryToFlipAll () {
	_generateFlipQueue();
	
	for (auto pos = _flipQueue.begin();
		pos != _flipQueue.end(); ++pos) {
		_tryToFlipThis (pos);
	}
}

inline void IsingSquare::_generateFlipQueue () {
	std::shuffle (xs.begin(), xs.end(), _gen);
	std::shuffle (ys.begin(), ys.end(), _gen);
	_flipQueue.clear();
	auto i = xs.begin();
	auto j = ys.begin();
	for (; i != xs.end(); ++i, ++j) {
		std::pair<int, int> pair(*i, *j);
		_flipQueue.push_back (std::move(pair));
	}
}

inline void IsingSquare::_tryToFlipThis (FlipQueueT::iterator& pos) {
	int x = pos->first;
	int y = pos->second;
	int xMax = _setting.range.x;
	int yMax = _setting.range.y;

	// Periodic boundary condition
	int l = (x == 0) ? xMax-1 : x-1;
	int r = (x == xMax-1) ? 0 : x+1;
	int u = (y == yMax-1) ? 0 : y+1;
	int d = (y == 0) ? yMax-1 : y-1;

	// BRA "l\tr\td\tu\n" << l << "\t" << r << "\t" << d << "\t" << u KET

	// Calculate energy
	int energy = _twoSpinEnergy (x, y, l, y)
		+ _twoSpinEnergy (x, y, r, y)
		+ _twoSpinEnergy (x, y, x, u)
		+ _twoSpinEnergy (x, y, x, d);
	// Calculate flip probability
	// using short circuit logical OR operator: ||
	// A non-negative energy value will never be
	// the key of the map
	// 
	if (energy >= 0
		|| (_unitRand (_gen) < _flipProb[energy])) {
		// BRA "IN if{}" KET
		_spin[x][y] = !_spin[x][y];
	}
}


inline int IsingSquare::_twoSpinEnergy (const int& x1,
	const int& y1, const int& x2, const int& y2) const {
	return (_spin[x1][y1] != _spin[x2][y2]) ? 1 : -1;
}

inline double IsingSquare::_calcMagnetization () const {
	int sum = 0;
	for (int i=0; i < _setting.range.x; ++i) {
		for (int j=0; j < _setting.range.y; ++j) {
			sum += _spin[i][j] ? 1 : -1;
		}
	}
	return std::abs((double)sum/(double)(_setting.range.x * _setting.range.y));
}

inline bool IsingSquare::_statisticsPrintln (int bigStep,
	double* ms,
	std::ostream& fout) {
	double mean = 0;
	double diffSqSum = 0;
	double stdDiv = 0;
	for (int i=0; i < _setting.avgN; ++i) {
		mean += ms[i];
	}
	mean /= _setting.avgN;
	for (int i=0; i < _setting.avgN; ++i) {
		diffSqSum += ms[i]*ms[i]
			- 2*mean*ms[i] + mean*mean;
	}

	stdDiv = std::sqrt (diffSqSum / _setting.avgN);
	fout << std::setw(_width) << bigStep
	<< std::setw(_width) << mean 
	<< std::setw(_width) << stdDiv << std::endl;
	std::cout << std::setw(_width) << bigStep
	<< std::fixed <<std::setw(_width) << mean 
	<< std::setw(_width) << stdDiv << std::endl;
	avgMagnDeq.push_back(mean);
	return  _diff() < _precision;
}

/*
inline double IsingSquare::_diff(double* ms) const {
	double max = ms[0];
	double min = ms[0];
	for (int i=0; i < _setting.avgN; ++i) {
		max = (ms[i] > max) ? ms[i] : max;
		min = (ms[i] < max) ? ms[i] : min;
	}
	return max - min;
}
*/

inline double IsingSquare::_diff() {
	/**
	 * returns the relative difference of the vector
	 */
	
	int len = avgMagnDeq.size();
	if (len <= 5) {
		return 2.0; // larger than precision
	}
	else {
		if (len > 20) {
			avgMagnDeq.pop_front();
		}
		double max = avgMagnDeq.front();
		double min = avgMagnDeq.front();
		for (auto& i : avgMagnDeq) {
			max = (i > max) ? i : max;
			min = (i < max) ? i : min;
		}
		return (max - min)/(double)len;
	}
}

#endif