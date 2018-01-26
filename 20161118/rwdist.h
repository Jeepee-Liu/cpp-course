#ifndef RWDIST_H
#define RWDIST_H

#include <RandomWalk.h>

class RandomWalkDist : public RandomWalk {

public:
	// Not an override!
	void run (double distance) /* override */ {
		setting.mode = SettingT::oneStep;

	}

}

#endif