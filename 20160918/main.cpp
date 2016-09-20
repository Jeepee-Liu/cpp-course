#include <iostream>
#include <vector>
#include <cstdlib> // std::rand()
#include <ctime> // std::time() for seeding
#include "testPrint.h" // Run the code with testprint Debug
#include <cmath>
#include <unistd.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[], char *env[]) {
	TestPrint tp; // Run with EZ-debug
	
	int buffer;
	vector<int> intVec;
	int count = 0;

	cout << "Please input some integers and end with CTRL+D:"
	<< endl;

	while(std::cin >> buffer) {
		intVec.push_back(buffer);
	}

	for(auto elem: intVec) {
		++count;
	}

	cout << count << " element(s) are input in total."
		<< endl;

	tp.promptBlock("Finished!");
	return 0;
}