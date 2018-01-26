#ifdef SETTING

SettingT::SettingT (int argc, char* const argv[]) {
	// To be done
	char indicator;
	while ( (indicator = getopt (argc, argv, "x:y:t:n:a:p:m:f:h:?") ) != -1  ) {
		switch (indicator) {
		case 'x':
			range.x = std::atoi (optarg);
			break;
		case 'y':
			range.y = std::atoi (optarg);
			break;
		case 't':
			kT = std::atof (optarg);
			break;
		case 'n':
			stepN = std::atoi (optarg);
			break;
		case 'a':
			avgN = std::atoi (optarg);
			break;
		case 'p':
			precision = std::atof (optarg);
			break;
		case 'm':
			initMode = (std::atoi (optarg) == 0) ? random : allUp;
			break;
		case 'f':
			outputDir = optarg;
			break;
		case 'h':
			usage (argv);
			break;
		case '?':
			usage (argv);
			break;
		default:
			usage (argv);
		}
	}
}

void SettingT::usage (char* const argv[]) {
	const int width = 15;
	std::cerr << "Usage: " << argv[0] << " [options] [parameters]" << std::endl
	<< "options:\n"
	<< std::left << std::setw(width) << "-x 100"
	<< " : range of the lattice in x direction." << std::endl
	<< std::left << std::setw(width) << "-y 100"
	<< " : range of the lattice in y direction." << std::endl
	<< std::left << std::setw(width) << "-t 0.5"
	<< " : parameter k*T of the simulation." << std::endl
	<< std::left << std::setw(width) << "-n 1000"
	<< " : number of big steps of the simulation." << std::endl
	<< std::left << std::setw(width) << "-a 100" 
	<< " : number of small steps of the simulation." << std::endl
	<< std::left << std::setw(width) << "-p 1.0e-5" 
	<< " : relative precision to reach." << std::endl
	<< std::left << std::setw(width) << "-m 0" 
	<< " : choose mode to initialize the lattice:" << std::endl
	<< std::left << std::setw(width) << " "
	<< "       mode 0: randomly set up/down of each spin\n"
	<< std::left << std::setw(width) << " "
	<< "       mode 1: set all spins up\n"
	<< std::left << std::setw(width) << "-f ./data.log" 
	<< " : set the file to save output data." << std::endl
	<< std::left << std::setw(width) << "-h / ?" << " : " 
	<< "show this usage prompt." << std::endl
	<< "\noutput:\n"
	<< std::right
	<< std::setw(16) << "step #"
	<< std::setw(16) << "mean mag." 
	<< std::setw(16) << "stderr mag." << std::endl
	<< std::setw(16) << 1
	<< std::fixed <<std::setw(16) << 0.99521 
	<< std::setw(16) << 0.0002196 << std::endl
	<< std::setw(16) << 2
	<< std::fixed << std::setw(16) << 0.99998 
	<< std::setw(16) << 0.0000013 << std::endl
	<< std::setw(16) << "......" << std::endl;
	exit(0);
	// 
}

#endif