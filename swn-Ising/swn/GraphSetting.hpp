#ifndef GRAPH_SETTING
#define GRAPH_SETTING

#include <unistd.h> // for getopt()
#include <cstdlib> // for atoi(), atof()...
#include <string>
#include <iostream>

class SettingT {
public:

	typedef uint32_t SiteNumT;
	typedef uint32_t StepNumT;

	/***** member functions *****/
	SettingT( int argc, char* argv[] );
	void usage( const char* argv0 );

	/***** data *****/
	// network properties
	SiteNumT siteN = 10000;
	float p = 0.5;
	// simulation properties
	double kT = 1.0;
	float initialSpin = 0.5;
	StepNumT stepN = 10000;
	StepNumT avgN = 500;
	// I/O properties
	std::string simuFileDir = "./tmp.log";
	std::string graphFileDir = "./connections.mma.list";
	// other properties
	enum ModeT {
		verbose = 0,
		silent = 1
	} mode;
};


SettingT::SettingT(int argc, char* argv[]) {
	char ch = '\0';
	while(( ch = getopt( argc, argv, "s:p:t:i:n:a:f:g:v:h" ) ) != -1 ){
		// go through all the valid parameters
		switch (ch) {
			case 's':
				siteN = std::atoi(optarg);
				break;
			case 'p':
				p = std::atof(optarg);
				break;
			case 't':
				kT = std::atof(optarg);
				break;
			case 'i':
				initialSpin = std::atof(optarg);
				break;
			case 'a':
				stepN = std::atoi(optarg);
				break;
			case 'k':
				avgN = std::atoi(optarg);
				break;
			case 'f':
				simuFileDir = optarg;
				break;
			case 'g':
				graphFileDir = optarg;
				break;
			case 'v':
				mode = verbose;
				break;
			case 'h':
				usage(argv[0]);
			case '?':
				usage(argv[0]);
		}
	}
}


void SettingT::usage( const char* argv0 ) {
	// usage is written to stream "std::cerr"
	std::cerr << "Usage: " << argv0 << " [options] ... " << std::endl
	<< "\tThis program is to simulate an Ising model in a small world network.\n\n"
	<< "inputs:\n"
	<< "######## Network Properties:\n"
	<< "\t[ -s 10000   ]\tNumber of steps to walk.\n"
	<< "\t[ -p 0.5     ]\tContraction of the link in this network.\n"
	<< "######## Simulation Properties:\n"
	<< "\t[ -t 1.0     ]\tSet the k*T of the system.\n"
	<< "\t[ -i 0.5     ]\tSet the initial spin up expectation of the system.\n"
	<< "\t[ -n 10000   ]\tSet the step number of simulation.\n"
	<< "\t[ -a 500     ]\tSet average Number of each set of points.\n"
	<< "######## Output Properties:\n"
	<< "\t[ -f tmp.log ]\tDirectory to save the status log.\n"
	<< "\t[ -f tmp.log ]\tDirectory to save the graph message.\n"
	<< "######## Others:\n"
	<< "\t[ -h         ]\tShow help page of This program.\n\n"
	<< "outputs:\n"
	<< "Formatted as below:\n"
	/**** TO BE COMPLETED ****/
	<< std::endl;
	exit(1);
} // Done


#endif