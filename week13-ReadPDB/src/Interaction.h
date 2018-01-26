#ifndef INTERACTION_H
#define INTERACTION_H

#include "Residue.h"
#include <string>
#include <iostream>
#include <iomanip>

class Interaction : public Format {

public:
	
	Interaction ();
	Interaction (const Residue& res1,
		const Residue& res2);
	Interaction (const Interaction& interaction);

	std::ostream& print (std::ostream& os) const;
	
	Interaction& operator= (Interaction&& rhs);

protected:

	std::string type = "NUL";
	ResNumT i = 0;
	ResNumT j = 0;
	double magnitude = 0.0;
	double distance = 0.0;

};

std::ostream& operator<< (std::ostream& os,
	const Interaction& interaction); 

#endif