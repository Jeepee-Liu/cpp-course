#ifndef RANDOM_WALK_H
#define RANDOM_WALK_H

#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>

class RandomWalk {
public:
	RandomWalk(int stepN, double stepLength, std::string fileName, int avgN, double pWalk);
	void run(char mode);
	void end();
private:
	int stepN;
	int avgN;
	double stepLength;
	double xPos, yPos;
	std::ofstream fo;
	static const double sqrt2;
	double pWalk;
	void move(char mode);
	double getDistance();
	void appendMove(int j, double* xs, double* ys, double* ds);
	double* calculateData(double* xs, double* ys, double* ds);
	double average(double* vs);
	double stdDiv(double* vs);
	void writeData(int index, double *avgData);
};
# include "randomWalk.cpp"
#endif