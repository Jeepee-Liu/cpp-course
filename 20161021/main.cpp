#include "MyString.h"
#include <iostream>

int main() {
	MyString myStr("Hello, world!");

	myStr.show();
	myStr += " Love & peace in this world!";
	myStr.show();
	std::cout << myStr[7] << myStr[8] << myStr[9] << std::endl;

	MyString myStr2(50,'a');
	myStr2.show();



	return 0;
}
