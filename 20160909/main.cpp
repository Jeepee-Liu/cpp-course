#include <iostream>
#include <vector>
#include <cstdlib>
// std::rand()
#include <ctime>
// std::time() for seeding
#include "testPrint.h"
// Run the code with testprint Debug
#include <unistd.h>

#include <fstream>

using namespace std;

int main(int argc, char *argv[], char *env[]) {
	TestPrint tp; // Run with EZ-debug
	
	std::string bufferStr;
	int n = 1024*1024*8;
	int m = atoi(argv[1]);
	double dbl = 1.0/(float)n;

	double sum = 0.0;
	for(int i = 1; i != n*m; ++i) {
		sum += dbl;
	}
	cout << sum << endl;
/*
	// Write file
	std::ofstream fout;
	fout.open("./fOutTest.txt", std::ios::app);
	if(!fout) return 1;
	fout << "Nothing cool." << std::endl;
	fout.close();

	// Read file
	std::ifstream fin;
	fin.open("./fOutTest.txt");
	if(!fout) return 1;

	int lineCounter = 0;
	while(!fin.eof()) {
		fin.getline(buffer, 100);
		std::cout << buffer << std::endl;
		++lineCounter;
	}
	fin.close();
	tp.newLine();
	std::cout << "Total line number:" << lineCounter
	<< std::endl;
*/
	return 0;
}