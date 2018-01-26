#ifndef RESIDUE_H
#define RESIDUE_H

#include "format.h"
#include <cstdlib>
#include <utility>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <iostream>

class Atom : public Format {
public:
	Atom( std::vector<std::string> contentVec );
	AtomNumT atomIdx;
	double atomPos[3] = {0.0, 0.0, 0.0};
	double atomMass = 0.0;
};

class Residue : public Format {

public:

	void append( std::vector<std::string> contentVec );
	std::ostream& print (std::ostream& os) const;

	ResNumT resIdx = 0;
	std::string resName = "undef";
	double resPos[3] = {0.0, 0.0, 0.0};
	double resMass = 0.0;
	std::vector<Atom> atoms;

};

std::ostream& operator<< (std::ostream& os, const Residue& res);

inline double dist (const Atom& atom1,
	const Atom& atom2) {
	return std::sqrt(
		  (atom1.atomPos[0] - atom2.atomPos[0])
		* (atom1.atomPos[0] - atom2.atomPos[0])
		+ (atom1.atomPos[1] - atom2.atomPos[1])
		* (atom1.atomPos[1] - atom2.atomPos[1])
		+ (atom1.atomPos[2] - atom2.atomPos[2])
		* (atom1.atomPos[2] - atom2.atomPos[2])
		);
} // DONE

inline double dist (const Residue& res1,
	const Residue& res2) {
	return std::sqrt(
		  (res1.resPos[0] - res2.resPos[0])
		* (res1.resPos[0] - res2.resPos[0])
		+ (res1.resPos[1] - res2.resPos[1])
		* (res1.resPos[1] - res2.resPos[1])
		+ (res1.resPos[2] - res2.resPos[2])
		* (res1.resPos[2] - res2.resPos[2])
		);
}


#endif