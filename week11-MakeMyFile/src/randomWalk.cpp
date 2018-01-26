#ifdef RANDOM_WALK_H

/* public: */

RandomWalk::RandomWalk() : RandomWalk (SettingT()) {}

RandomWalk::RandomWalk(SettingT settingIn) : setting(settingIn),
vec(), stepVec(),
fout (setting.fileDir) {
	// TODO make the head of the file.
	// fout << "" << endl; 
	dists = new double[setting.avgN];
	std::cout << "RandomWalk initialized" << std::endl;
}

RandomWalk::~RandomWalk() {
	delete[] dists;
}

// main member function
double RandomWalk::run() {
	switch (setting.mode) {
		case SettingT::infRun :
			//std::cout << "infRun mode" << std::endl;
			fout << std::setprecision(8);
			// Move stepN steps
			double distance;
			std::cout << std::setw(8) << "Step #"
			<< std::setw(16) << "distance"
			<< std::endl;
			for (int i=0; i<setting.stepN; ++i ) {

				distance = move();
				fout << std::setw(8) << i
				<< std::setw(16) << distance
				<< std::endl;
				std::cout << std::setw(8) << i
				<< std::setw(16) << distance
				<< std::endl;
			}
			return distance;	// no need to break
		case SettingT::oneStep :
			std::cout << "oneStep mode" << std::endl;
			// move 1 step
			return move();		// no need to break
	}
	return 0.0;
}

/* protected: */

inline double RandomWalk::move() {
	/**
	 * Move avgN steps and calculate the averaged
	 * distance from original point as return value
	 */
	double avgDist = 0;
	// move and log
	for (int i=0; i < setting.avgN; ++i) {
		dists[i] = moveStep();
		avgDist += dists[i];
	}
	avgDist /= (double) setting.avgN;
	return avgDist;
}

inline double RandomWalk::moveStep () {
	vec += stepVec.randomInitialize().normalize();
	return vec.module();
}

#endif
