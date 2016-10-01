#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cstdlib> // std::rand()
#include <ctime> // std::time(0) for seeding
#include <randomWalk.h>
#include <unistd.h>

using namespace std;

void usage(char* argv0) {
	cout << "Program usage: " << argv0 << endl;
	cout << "\tThis program is to simulate a 2-dimensional random walking." << endl;
	cout << "inputs:" << endl;
	cout << "\t[ -n 100000 ]\t\tNumber of steps to walk." << endl;
	cout << "\t[ -l 1.0 ]\t\tLength of each step." << endl;
	cout << "\t[ -f \"tmplog.txt\" ]\tDirectory to save the position log." << endl;
	cout << "\t[ -a 100 ]\t\tSet average Number of each set of points." << endl;
	cout << "\t[ -p 0.8 ]\t\tSet the probability of walking a full step; otherwise will walk half of a step." << endl;
	cout << "\t[ -h ]\t\t\tShow help page of This program." << endl;
	cout << "outputs:" << endl;
	cout << "\tOutput in a list form as below:\n";
	char title[200];
	char firstLine[200];
	std::sprintf( title, "%7s\t%12s\t%12s\t%12s\t%12s\t%12s\t%12s",
		"index", "x_pos", "x_err", "y_pos", "y_err", "dist", "dist_err");
	std::sprintf( firstLine, "%7i\t%12.8f\t%12.8f\t%12.8f\t%12.8f\t%12.8f\t%12.8f",
		0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	cout << '\t' << title << "\n\t" << firstLine << endl;
	cout << "\t......" << endl;
	exit(1);
} // Done

void parseArgs(int argc, char* argv[], int* stepN,
	double* stepLength, string* fileName, int* avgN, double* pWalk) {
	char ch;
	while(( ch = getopt(argc,argv,"n:l:o:a:h") ) != -1 ){
		switch (ch) {
		case 'n':
			*stepN = atoi(optarg);
			break;
		case 'l':
			*stepLength = atof(optarg);
			break;
		case 'o':
			*fileName = optarg;
			break;
		case 'a':
			*avgN = atoi(optarg);
			break;
		case 'p':
			*pWalk = atof(optarg);
		case 'h':
			usage(argv[0]);
		case '?':
			usage(argv[0]);
		}
	}
} // Done

#endif