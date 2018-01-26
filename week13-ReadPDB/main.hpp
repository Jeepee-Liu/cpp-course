#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <unistd.h>

#include "src/pdbIO.h"
#include "src/Residue.h"
#include "src/Interaction.h"

void usage (char* const argv0) {
	std::cerr
	<< "Usage: " << argv0 << "[ options | param ] ...\n"
	<< std::left << std::setw(16)
	<< "[ -i data/1COA.pdb"
	<< " ] read pdb file of atoms in protein.\n"
	<< std::left << std::setw(16)
	<< "[ -o data/1COA.pdb "
	<< " ] wirte pdb file of residues and interactions.\n"
	<< std::left << std::setw(16)
	<< "[ -v / -V "
	<< " ] non-verbose / verbose mode.\n"
	<< std::left << std::setw(16)
	<< "[ -h / -? "
	<< " ] show this help page.\n"
	<< std::endl;
	exit(1);
}

void parseArgs (int argc,
	char* const argv[],
	PdbIO::IOSettingT& setting) {
	setting.verbose = 1;
	const char* optstr = "i:o:vVh?";
	char opt;
	do {
		opt = getopt (argc, argv, optstr);
		switch (opt) {
			case 'i':
				setting.inputDir = optarg;
				break;
			case 'o':
				setting.outputDir = optarg;
				break;
			case 'v':
				setting.verbose = 0;
				break;
			case 'V':
				setting.verbose = 1;
				break;
			case 'h':
			case '?':
				usage (argv[0]);
				break;
			default:
				break;
		}
	} while (opt != -1);	
}

#endif