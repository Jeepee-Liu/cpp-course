#include "Residue.h"
#ifdef RESIDUE_H

void Residue::append( std::vector<std::string> lineV ) {
	resIdx = std::atoi(lineV[input.resIdxCol].c_str());
	// std::cout << "Appending residue No." << resIdx << std::endl;
	Atom thisAtom(lineV);
	resMass += thisAtom.atomMass;
	if( lineV[input.atomTypeCol] == "CA" ) {
		resPos[0] = thisAtom.atomPos[0];
		resPos[1] = thisAtom.atomPos[1];
		resPos[2] = thisAtom.atomPos[2];
	}
	resName = lineV[input.resNameCol];
	atoms.push_back( std::move( thisAtom ) );
} // DONE

std::ostream& Residue::print (std::ostream& os) const {
	os << "ATOM " << resName
	<< std::setw(8)
	<< resMass
	<< std::setw(8)
	<< resPos[0]
	<< std::setw(8)
	<< resPos[1]
	<< std::setw(8)
	<< resPos[2]
	<< std::endl;
	return os;
}


Atom::Atom( std::vector<std::string> lineV ) :
atomIdx (std::atoi( lineV[input.atomNoCol].c_str())),
atomPos {
	std::atof (lineV[input.atomXPosCol].c_str()),
	std::atof (lineV[input.atomYPosCol].c_str()),
	std::atof (lineV[input.atomZPosCol].c_str())
	} {
	char atomName = lineV[input.atomNameCol].c_str()[0];
	switch (atomName) {
		case 'H':
			atomMass = 1.0;
			break;
		case 'C':
			atomMass = 12.0;
			break;
		case 'N':
			atomMass = 14.0;
			break;
		case 'O':
			atomMass = 16.0;
			break;
		case 'S':
			atomMass = 32.0;
			break;
		default:
			std::cerr << "Cannot identify the element." << std::endl;
	}
} // DONE

std::ostream& operator<< (std::ostream& os,
	const Residue& res) {
	return res.print (os);
}

#endif