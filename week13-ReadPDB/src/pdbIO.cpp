#include "pdbIO.h"
#ifdef PDBIO_H

/***** PUBLIC *****/

PdbIO::PdbIO ( IOSettingT settingIn ) :
	setting( settingIn ),
	fin( setting.inputDir ),
	fout( setting.outputDir ),
	system() {}
	

PdbIO::PdbIO () :
	PdbIO( IOSettingT() ) {}

void PdbIO::run() {
	calcData();
	printData();
} // DONE

/***** PROTECTED *****/

void PdbIO::calcData() {
	std::string strBuf;
	
	// read in all atoms
	while( fin ) {
		std::getline( fin, strBuf );
		parseLine(strBuf);
	}
	
	// get all interactions
	for (auto& res1 : system.residues) {
		for (auto& res2 : system.residues) {
			// if i > j
			if (res1.first > res2.first) {
				system.interactions[{res1.first, res2.first}]
				 = Interaction (res1.second, res2.second);
			}
		}
	}
	
} // DONE

void PdbIO::printData() {
	
	// Print residues' data
	for( auto& residue : system.residues ) {
		fout << residue.second;
		if( setting.verbose != 0 ) {
			std::cout << residue.second;
		}
	}

	// Print interactions' data
	for( auto& interaction : system.interactions ) {
		fout << interaction.second;
		if( setting.verbose != 0 ) {
			std::cout << interaction.second;
		}
	}
} // DONE

inline void
PdbIO::parseLine( std::string strBuf ) {
	std::vector<std::string> content = split(strBuf);
	if( content[0] == "ATOM" ) {
		// std::cout << "Parsing line:\n" << strBuf << std::endl;
		ResNumT resIdx = std::atoi(content[input.resIdxCol].c_str());
		system.residues[resIdx].append(content);
	}
} // DONE

inline std::vector<std::string>
PdbIO::split( std::string strBuf ) {
	std::vector<std::string> v;
	std::string tmpStr;
	for( std::string::size_type i=0; i < strBuf.size(); ++i ) {
		if( strBuf[i] != ' ' ) {
			tmpStr += strBuf[i];
		}
		else {
			v.push_back( tmpStr );
			tmpStr.clear();
			while ( strBuf[i+1] == ' ' ) {
				++i;
			}
		}

	}
	v.push_back( tmpStr );
	return v;
} // DONE & TESTED

#endif