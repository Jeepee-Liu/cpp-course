#include <iostream>
#include <vector>
#include <cstdlib> // std::rand()
#include <ctime> // std::time() for seeding
#include "testPrint.h" // Run the code with testprint Debug
#include <cmath>
#include <unistd.h>

#include <fstream>

int main(int argc, char *argv[], char *env[]) {
	TestPrint tp; // Run with EZ-debug
	/* Below is the useful part */

/*	int loopN = 100;
	std::vector<int> intVec;
	std::vector<double> dblVec;
	// use current time as seed for random generator
	std::srand(std::time(0));
	for (int i = 0; i < loopN; ++i) {
		intVec.push_back(std::rand());
	}
	// sleep(5);
	for(auto j = intVec.begin();
		j != intVec.end();
		++j) {
		dblVec.push_back(std::sin(*j));
	}
	tp.printTimeElapsed();*/
	char buffer[256];
/*	std::cout << "Please input the word to record:" << std::endl;
	std::cin >> buffer;
	tp.newLine();*/

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

	return 0;
}