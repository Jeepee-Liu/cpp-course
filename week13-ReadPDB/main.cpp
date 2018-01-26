#include "main.hpp"

int main (int argc, char* const argv[]) {
	
	PdbIO::IOSettingT setting;
	parseArgs (argc, argv, setting);
	PdbIO myPdbParser(setting);
	myPdbParser.run();

	return 0;
}