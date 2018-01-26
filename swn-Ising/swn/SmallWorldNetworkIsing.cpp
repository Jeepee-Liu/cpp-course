#ifdef SMALL_WORLD_NETWORK_ISING

SmallWorldNetworkIsing::SmallWorldNetworkIsing(int argc, char* argv[]) :
SmallWorldNetwork( argc, argv ), _spin( new bool[_setting.siteN] ),
_chooseSpin( 0, 1 ), _simuFlip( 0, 1 ) {} // DONE

SmallWorldNetworkIsing::~SmallWorldNetworkIsing() {
	
	delete[] _spin;
} // DONE

SmallWorldNetworkIsing& SmallWorldNetworkIsing::generate() {
	// call the generate() of base class
	SmallWorldNetwork::generate();
	_generateSpin();
	return *this;
} // Done

SmallWorldNetworkIsing& SmallWorldNetworkIsing::simulate() {
	double* m = new double[_setting.avgN]; // magnetization
	std::ofstream fout( _setting.simuFileDir.c_str() );
	if( !fout ) return;
	fout << std::setprecision(10);
	_generateConnection();
	for( StepNumT bigStep=0; bigStep<_setting.stepN; ++bigStep) {
		for( StepNumT smallStep=0; smallStep<_setting.avgN; ++smallStep) {
			// UNDECLARED, UNDEFINED method!!!!
			_stepSimu(); // to be done

			m[smallStep] = _calcMagnetization();
		}
		// print into file
		fout << std::setw(16) << bigStep
		<< std::setw(16) << _calcAverage( m, _setting.avgN )
		<< std::setw(16) << _calcStdDev( m, _setting.avgN ) << std::endl;
	}
	delete[] m;
	return *this;
} // DONE

SmallWorldNetworkIsing& SmallWorldNetworkIsing::outputMMAStyleConn() {
	SmallWorldNetwork::outputMMAStyleConn();
	// appending the color indicating spin up/down
	std::ofstream fout( _setting.graphFileDir, std::ios::app );
	if( fout ) {
		fout << "{";
		for( SiteNumT i=0; i < _setting.siteN-1; ++i ) {
			fout << i << "->"
			<< ( _spin[i] ? "Red," : "Black," );
		}
		fout << _setting.siteN-1 << "->"
		<< ( _spin[_setting.siteN-1] ? "Red" : "Black" )
		<< "}" << std::endl;
	}
	return *this;
} // Done

void SmallWorldNetworkIsing::_generateSpin() {
	bool* spinP = _spin;
	for( SiteNumT i = 0; i < _setting.siteN; ++i, ++spinP) {
		*spinP = ( _chooseSpin(_gen) < _setting.initialSpin );
	}
} // Done


void SmallWorldNetworkIsing::_generateFullConnection() {
	std::vector<SiteNumT> neighbors;
	for( SiteNumT i = 0; i < _setting.siteN; ++i ) {
		neighbors.clear();
		neighbors.push_back(( i == 0 ) ? _setting.siteN : i-1);
		neighbors.push_back(( i == _setting.siteN ) ? 0 : i+1);
		auto remoteNeighbor = std::find(
			_connection.begin(), _connection.end(), i)
		if( remoteNeighbor != _connection.end() ) {
			neighbors.push_back( *remoteNeighbor );
		}
		_fullConnection[i] = std::move(neighbors);
	}
	return std::ref( connection );
} // Done

inline double SmallWorldNetworkIsing::_calcMagnetization() {
	// m = m(p, t) = [sum of spin] / [length of chain]
	// p : _setting.p
	// t : time
	int sum = 0;
	bool* spinP = _spin;
	for( SiteNumT i = 0; i < _setting.siteN; ++i ) {
		if( spinP[i] ) sum++;
	}
	return ( sum / _setting.siteN );
} // Done

inline double SmallWorldNetworkIsing::_calcAverage( double* m, SiteNumT n ) {
	double sum = 0.0;
	for( SiteNumT i = 0; i < _setting.siteN; ++i ) {
		sum += m[i];
	}
	return sum/n;
} // Done

inline double SmallWorldNetworkIsing::_calcStdDev( double* m, SiteNumT n ) {
	double sum = 0.0;
	double avg = _calcAverage( m, n );
	for( SiteNumT i = 0; i < _setting.siteN; ++i ) {
		sum += ( avg - m[i] ) * ( avg - m[i] );
	}
	return std::sqrt( sum / n );
} // Done

void SmallWorldNetworkIsing::_stepSimu() {
	std::vector<SiteNumT> neighbors;
	int energy = 0;
	for( SiteNumT i = 0; i < _setting.siteN; ++i ) {
		neighbors =  _fullConnection[i];
		energy = 0;
		for( const auto& neighbor : neighbors ) {
			energy += -( ( _spin[neighbor] == _spin[i] ) ? 1 : -1 ) ;
		}
		_tryflip( i, -2 * energy );
	}
} // DONE

inline void _tryflip( SiteNumT i, int delta_energy ) {
	if( delta_energy <= 0 ) {
		_flip( i );
	}
	else if( _simuFlip(_gen) < _flipProb( delta_energy ) ) {
		_flip( i );
	}
} // DONE

inline double _flipProb( double delta_energy ) {
	return std::exp( delta_energy / _setting.kT );
} // DONE

#endif