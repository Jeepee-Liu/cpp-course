#ifndef _TEST_PRINT_H
#define _TEST_PRINT_H

#include <string>
#include <ctime>
#include <iostream>

// New feature: TIMER

class TestPrint{
public:
	TestPrint();
	// Print a line of symbol
	void anyLine(int len, char anyChar);
	void starLine(int len);
	void barLine(int len);
	void slashLine(int len);
	void sharpLine(int len);

	// Print prompt words with
	// beautifully decorated BLOCKS
	void promptBlock(const char* promptStr);
	void promptBlock(void);

	// Print a spare line
	void newLine(void);

	// timer
	void printTimeElapsed(void);

private:
	double timeElapsed(void);
	std::clock_t startClock;
};

#include "testPrint.cpp"
#endif