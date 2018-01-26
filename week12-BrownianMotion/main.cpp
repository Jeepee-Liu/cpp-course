#include <iostream>
#include <BrownianMotion.h>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <string>

BrownianMotion::SettingT parseArgs (int argc, char* const argv[]);
void usage (char* const argv0);

int main(int argc, char* const argv[]) {
	BrownianMotion bm (parseArgs (argc, argv));
	bm.run();
	return 0;
}

BrownianMotion::SettingT parseArgs (int argc,
	char* const argv[]) {
	int opt = 0;
	BrownianMotion::SettingT setting;
	const char* optString = "n:d:t:m:g:f:p:h?";
	std::string argStr;
	while ((opt = getopt (argc, argv, optString))
		!= -1) {
		switch (opt) {
			case 'n':
				setting.stepN = std::atoi(optarg);
				break;
			case 'd':
				setting.dt = std::atof(optarg);
				break;
			case 't':
				setting.kT= std::atof(optarg);
				break;
			case 'm':
				setting.m = std::atof(optarg);
				break;
			case 'g':
				setting.gamma = std::atof(optarg);
				break;
			case 'f':
				setting.dir = optarg;
				break;
			case 'p':
				argStr = optarg;
				if ( argStr.find("true") == std::string::npos
					|| argStr.find("True") == std::string::npos ) {
					setting.toPlot = true;
				}
				break;
			case 'h':
			case '?':
			default:
				usage (argv[0]);
				break;
		}
	}
	return setting;
}

void usage (char* const argv0) {
	std::cerr
	<< "usage: " << argv0 << " [ opt | para ] ...\n"
	<< "options:" << std::endl
	<< std::setw(17) << "-n  "
	<< "number of steps of the simulation\n"
	<< std::setw(17) << "-d  "
	<< "time interval of two steps\n"
	<< std::setw(17) << "-t  "
	<< "temperature (k*T) of the system\n"
	<< std::setw(17) << "-m  "
	<< "mass of the particle\n"
	<< std::setw(17) << "-g  "
	<< "viscosity of the particle\n"
	<< std::setw(17) << "-f  "
	<< "directory to save the log\n"
	<< std::setw(17) << "-p  "
	<< " set \"true\" to plot with python\n"
	<< std::setw(17) << "-h -?  "
	<< "show this help page\n"
	<< std::endl;
	exit(1);
}