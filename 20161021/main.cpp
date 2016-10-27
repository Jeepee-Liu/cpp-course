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
	std::cout << "Number of character \"a\" in myStr2: "
	<< myStr2.count('a') << std::endl;

	MyString myStr3("hello");
	MyString myStr4;
	myStr4 = ( '\n' + myStr3 + '\n' );
	std::cout << myStr4;
	
	return 0;
}
