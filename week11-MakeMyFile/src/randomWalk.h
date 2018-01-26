#ifndef RANDOM_WALK_H
#define RANDOM_WALK_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <MyVector.h>

class RandomWalk {

public:

	struct SettingT {
		int stepN = 500;
		int avgN = 500;
		double stepLength = 0.01;
		std::string fileDir = "./data.log";
		enum ModeT {
			infRun,
			oneStep
		} mode;
	};

	RandomWalk();
	RandomWalk(SettingT settingIn);
	~RandomWalk();
	double run();

protected:

	SettingT setting;
	MyVector vec;		// position of particle
	MyVector stepVec;   // step to move
	double* dists;		// list of distances from O
	std::ofstream fout;
	inline double move();
	inline double moveStep();
	
};

# include <randomWalk.cpp>
#endif