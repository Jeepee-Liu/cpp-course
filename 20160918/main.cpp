#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // std::rand()
#include <ctime> // std::time() for seeding
#include <testPrint.h> // Run the code with testprint Debug
#include <formatOutput.h>

using namespace std;

int main(int argc, char *argv[]) {
	TestPrint tp; // Run with test print
	FormatOutput fo;
	if( !fo.setFileDir("test.txt") ) {
		std::cout << "Unable to open or create file!" << std::endl;
		return 1;
	}
	double buffer;
	vector<double> doubleVec;

	cout << "Please input some integers and end with CTRL+D:" << endl;
	while(std::cin >> buffer) {
		doubleVec.push_back(buffer);
	}
	cout << doubleVec.size() << " element(s) are input in total." << endl;
	fo.appendData("var_1", doubleVec);
	std::reverse(doubleVec.begin(), doubleVec.end());
	fo.appendData("var_rev_2", doubleVec);
	fo.printData();
	if( !fo.writeData() ) {
		cout << "cannot write data!" << endl;
		return 1;
	}



	tp.promptBlock("Finished!");
	return 0;
}