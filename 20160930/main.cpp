#include "main.h"

int main(int argc, char *argv[]) {
	const char mode = 'e';
	int stepN = 100000;
	double stepLength = 1.0;
	string fileName = "tmplog.txt";
	int avgN = 100;
	double pWalk = 0.8;
	parseArgs(argc, argv, &stepN, &stepLength, &fileName, &avgN, &pWalk);
	RandomWalk randWalk(stepN, stepLength, fileName, avgN, pWalk);
	randWalk.run(mode);
	randWalk.end();
	return 0;
}