#ifndef SETTING
#define SETTING

#include <unistd.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

struct RangeT {
	int x = 100;
	int y = 100;
};

struct SettingT {
	SettingT (int argc, char* const argv[]);
	RangeT range;
	// 
	double kT = 0.5;
	int stepN = 100;
	int avgN = 100;
	double precision = 1.0e-5;

	enum InitModeT {
		random = 0,
		allUp = 1
	} initMode;
	// file dir
	std::string outputDir = "./data.log";
	void usage (char* const argv[]);
};

#include <setting.cpp>

#endif