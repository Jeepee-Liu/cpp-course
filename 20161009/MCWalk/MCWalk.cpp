#ifdef MONTE_CARLO_WALK_H

const double MCWalk::pi = 3.14159265358979323;
const bool MCWalk::right = true;

MCWalk::MCWalk(MCWalk::SettingT setting) {
	std::srand(std::time(0));
	// New method
	switch (setting.mode) {
		// Determine the potential according to `mode`
		case 1:
			setting.potential = potential1;
			break;
		case 2:
			setting.potential = potential2;
			break;
		default:
			setting.potential = potential1;
			break;
	}
	this->setting = setting;
	initPosition();
	// std::cout << "kT = " << setting.kT << endl;
} // Done

void MCWalk::initPosition() {
	if (setting.initMode == 0) {
		position[0] = 0;
		position[1] = 0;
	}
	else {
		/* if (setting.initMode == 1) */
		float theta = 2*pi* std::rand()/(float)RAND_MAX;
		float rho = setting.bound * std::rand()/(float)RAND_MAX;
		position[0] = rho * std::cos(theta);
		position[1] = rho * std::sin(theta);
	}
}

void MCWalk::loop() {
	fo.open(setting.fileDir);
	sprintf( buffer, "%6s\t%12s\t%12s\n", "i", "x", "dx" );
	fo << buffer;
	// std::cout << "I'm looping!" << std::endl;
	double* distances = new double[setting.avgN];
	for( int i=0; i != setting.stepN; ++i ) {
		for( int j=0; j != setting.avgN; ++j ) {
			tryToMove();
			distances[j] = getDistance( position );
		}
		record(i, distances);
	}
	// remember to collect garbage!
	delete[] distances;
} // Done

void MCWalk::end() {
	fo.close();
	// std::cout << "I'm ending!" << std::endl;
} // Done

void MCWalk::tryToMove() {
	double direction = getDirection();
	if( movable(direction) )
		move(direction);
} // Done

double MCWalk::getDirection() {
	// return the angle to move
	// from 0 to 2*pi
	return 2 * pi * std::rand() / (double) RAND_MAX;
} // Done

bool MCWalk::movable(double direction){
	double nextPosition[2];
	nextPosition[0] = position[0] + setting.stepLength * std::cos(direction);
	nextPosition[1] = position[1] + setting.stepLength * std::sin(direction);
	double nextDistance = getDistance(nextPosition);
	double dE = setting.potential(nextPosition) - setting.potential(position);
	if( nextDistance < setting.bound ) {
		// Within boundary
		if( dE > 0 ) {
			double indicator = std::rand() / (double) RAND_MAX;
			if( indicator < std::exp( -dE / setting.kT ))
				return true;
			else
				return false;
		}
		else {
			return true;
		}
	}
	else {
		// Out of boundary
		return false; // For safety
	}
} // Done

void MCWalk::move(double direction) {
	position[0] += setting.stepLength * std::cos(direction);
	position[1] += setting.stepLength * std::sin(direction);
} // Done

void MCWalk::record(int i, double* distances) {
	double avg = mean(distances, setting.avgN);
	double std = standardDeviation(distances, setting.avgN);
	sprintf( buffer, "%6i\t%12.8f\t%12.8f\n", i+1, avg, std );
	fo << buffer;
}  // Done

double MCWalk::mean(double* xs, int n) const {
	double sum = 0.0;
	for(int i=0; i != n; ++i) {
		sum += xs[i];
	}
	return (sum/n);
} // Done

double MCWalk::standardDeviation(double* xs, int n) const {
	double meanVal = mean(xs,n);
	double sqSum = 0.0;
	for(int i=0; i != n; ++i) {
		sqSum += (xs[i] - meanVal)*(xs[i] - meanVal);
	}
	return std::sqrt(sqSum/n);
} // Done

void usage(char* argv0) {
	// usage is written to stream "std::cerr"
	std::cerr << "Usage: " << argv0 << std::endl
		<< "\tThis program is to simulate a 1-dimensional Monte-Carlo walking.\n"
		<< "inputs:\n"
		<< "\t[ -n 10000   ]\tNumber of steps to walk.\n"
		<< "\t[ -l 0.02    ]\tLength of each step.\n"
		<< "\t[ -f tmp.log ]\tDirectory to save the position log.\n"
		<< "\t[ -a 500     ]\tSet average Number of each set of points.\n"
		<< "\t[ -k 0.2     ]\tSet the k*T of the system.\n"
		<< "\t[ -i 0       ]\tSet the initial status of the pertical.\n"
		<< "\t[ -h         ]\tShow help page of This program.\n";
	exit(1);
} // Done

void parseArgs(int argc, char* argv[], MCWalk& walk) {
	char ch;
	while(( ch = getopt(argc,argv,"n:l:o:a:k:f:i:h") ) != -1 ){
		// go through all the valid parameters
		switch (ch) {
			case 'n':
				walk.setting.stepN = std::atoi(optarg);
				break;
			case 'l':
				walk.setting.stepLength = std::atof(optarg);
				break;
			case 'o':
				walk.setting.fileDir = optarg;
				break;
			case 'a':
				walk.setting.avgN = std::atoi(optarg);
				break;
			case 'k':
				walk.setting.kT = std::atof(optarg);
				break;
			case 'f':
				walk.setting.fileDir = optarg;
				break;
			case 'i':
				walk.setting.initMode = std::atoi(optarg);
				break;
			case 'h':
				usage(argv[0]);
			case '?':
				usage(argv[0]);
		}
	}
} // Done


#endif