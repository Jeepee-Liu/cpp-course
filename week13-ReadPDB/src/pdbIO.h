#ifndef PDBIO_H
#define PDBIO_H

#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <cstdlib>
#include "Interaction.h"
#include "Residue.h"

class PdbIO : public Format {

public:

	typedef std::map<ResNumT, Residue> ResT;
	typedef std::map<std::pair<ResNumT, ResNumT>,
		Interaction> InterT;
	typedef struct {
		ResT residues;
		InterT interactions;
	} SysT;
	typedef struct {
		std::string inputDir = "data/1COA.pdb";
		std::string outputDir = "data/residues.pdb";
		int verbose = 0;
	} IOSettingT;

	// Constructor
	PdbIO ( IOSettingT settingIn );
	PdbIO ();

	void run();

protected:

	IOSettingT setting;
	std::ifstream fin;
	std::ofstream fout;
	SysT system;		// containing residues data
						// and interaction data
	
	void calcData ();
	void printData ();
	inline void
		parseLine(std::string strBuf);
	inline std::vector<std::string>
		split( std::string strBuf );

};

#endif