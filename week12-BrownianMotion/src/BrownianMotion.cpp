#ifdef BROWNIANMOTION_H

/******** PUBLIC ********/
BrownianMotion::BrownianMotion (SettingT settingIn) :
	setting(settingIn),
	rd (),			// Initialize Random Device 
	gen (rd()),		// Initialize MT19937 random generator
	ndist (0,1),	// Normal distribution
	state (),		// Default Initializing. (ZERO)
	fout (setting.dir),
					// Directory to save the log
	_c1 (0.0),		// Initialize in the function body.
	_c2 (0.0)		// Initialize in the function body.
{
	_c1 = 1.0 - setting.gamma * setting.dt / \
		setting.m / \
		(1.0 + 0.5 * setting.gamma * setting.dt);
	std::cout << "c1 = " << _c1 << std::endl;
	_c2 = std::sqrt(2.0 / setting.m * \
		setting.gamma * setting.kT * \
		setting.dt) / \
		(1.0 + 0.5 * setting.gamma * setting.dt);
	// setting.disp();
	std::cout << "c2 = " << _c2 << std::endl;
}

BrownianMotion::BrownianMotion () :
BrownianMotion (SettingT()) {}

void BrownianMotion::run () {
	std::cout
	<< "Calculating Brownian motion by random Markov chain..."
	<< std::endl;
	printHead (fout);
	printHead (std::cout);
	for (StepNumT i=0; i < setting.stepN; ++i) {
		move();
		fout << *this;
		std::cout << *this;
	}
	if (setting.toPlot) plot();
}

/******** PROTECTED ********/

inline void BrownianMotion::move () {
	// update state space vector
	state.r[0] = state.r[0] + \
		_c1 * state.v[0] * setting.dt + \
		_c2 * ndist(gen) * setting.dt;
	state.r[1] = state.r[1] + \
		_c1 * state.v[1] * setting.dt + \
		_c2 * ndist(gen) * setting.dt;
	state.v[0] = \
		_c1 * state.v[0] + \
		_c2 * ndist(gen);
	state.v[1] = \
		_c1 * state.v[1] + \
		_c2 * ndist(gen);
	state.t += setting.dt;
}

inline void BrownianMotion::printHead (std::ostream& os) {
	os << std::setw(16) << "time"
	<< std::setw(16) << "x"
	<< std::setw(16) << "y"
	<< std::setw(16) << "v_x"
	<< std::setw(16) << "v_y"
	<< std::endl;
}

void BrownianMotion::plot() {
	std::string cmd("./plotData.py ");
	cmd += setting.dir;
	std::system(cmd.c_str());
}

/******** FRIENDS *********/

std::ostream& operator<< (std::ostream& os, BrownianMotion& bm) {
	os << std::setprecision(7)
	<< std::setw(16) << bm.state.t
	<< std::setw(16) << bm.state.r[0]
	<< std::setw(16) << bm.state.r[1]
	<< std::setw(16) << bm.state.v[0]
	<< std::setw(16) << bm.state.v[1]
	<< std::endl;
	return os;
}

#endif