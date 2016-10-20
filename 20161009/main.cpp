#include "main.h"

/***********************************************
 * Demostrate a 2D Monte Carlo walk simulation.
 * Functions are encapsulated in class MCWalk.
 * Automatically parse arguments from terminal input.
 * Author: Zhiping Liu
 * Last update: Oct. 16, 2016
 ***********************************************/

int main(int argc, char* argv[]) {
	MCWalk walk;
	parseArgs(argc, argv, walk);
	walk.loop();
	walk.end();
	return 0;
}