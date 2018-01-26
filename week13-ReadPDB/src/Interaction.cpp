#include "Interaction.h"
#ifdef INTERACTION_H

Interaction::Interaction () {}

Interaction::Interaction (const Residue& res1,
	const Residue& res2) :
type ("NDF"), i (res1.resIdx), j (res2.resIdx),
magnitude (0.0), distance(4.0) {
	if (i - j == 1) { // Harmonic interaction
		type = "HAR";
		magnitude = 100.0;
		distance = dist (res1, res2);
	}
	else { // supposingly (i - j > 1)
		int pairCount = 0;
		for (auto& a1 : res1.atoms) {
			for (auto& a2 : res2.atoms ) {
				if (dist (a1, a2) < 5.0) {
					pairCount++;
				}
			}
		}
		if (pairCount > 0) { // L-J interaction
			type = "LJ";
			magnitude = (double) pairCount;
			distance = dist (res1, res2);
		}
		else { // Repellent interaction
			type = "REP";
			magnitude = 1.0;
			distance = 4.0;
		}
	}
} // DONE

Interaction::Interaction (const Interaction& interaction) {
	type = interaction.type;
	i = interaction.i;
	j = interaction.j;
	magnitude = interaction.magnitude;
	distance = interaction.distance;
}

std::ostream& Interaction::print (std::ostream& os) const {
	os << std::left
	<< std::setw(4) << type
	<< std::setw(4) << i
	<< std::setw(4) << j
	<< std::setw(8)
	<< magnitude
	<< std::setw(8) << std::setprecision(3)
	<< distance << std::endl;
	return os;
} // DONE

Interaction& Interaction::operator= (Interaction&& interaction) {
	type = interaction.type;
	i = interaction.i;
	j = interaction.j;
	magnitude = interaction.magnitude;
	distance = interaction.distance;
	return *this;
}

std::ostream& operator<< (std::ostream& os,
	const Interaction& interaction) {
	return interaction.print(os);
} // DONE

#endif