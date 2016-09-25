#include <iostream>
#include <vector>
#include <cstdlib> // std::rand()
#include <ctime> // std::time() for seeding
#include "testPrint.h" // Run the code with testprint Debug
#include <cmath>
#include <unistd.h>
#include <fstream>
#include "formatOutput.h"

using namespace std;

int main(int argc, char *argv[], char *env[]) {
	TestPrint tp; // Run with EZ-debug
	FormatOutput fo;
	if( !fo.setFileDir("./test.txt") ) {
		std::cout << "" << std::endl;
		return 1;
	}

	double buffer;
	vector<double> doubleVec;

	cout << "Please input some integers and end with CTRL+D:"
	<< endl;
	while(std::cin >> buffer) {
		doubleVec.push_back(buffer);
	}
	cout << " number of " 
	<< doubleVec.size() << " element(s) are input in total." << endl;

	fo.appendData("变量1", doubleVec);
	fo.appendData("变量2", doubleVec);
	fo.appendData("变量3", doubleVec);
	fo.appendData("变量4", doubleVec);
	fo.printData();
	fo.writeData();

	tp.promptBlock("Finished!");
	return 0;
}