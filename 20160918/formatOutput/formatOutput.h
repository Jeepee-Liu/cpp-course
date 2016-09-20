#ifndef _FORMAT_OUTPUT_H
#define _FORMAT_OUTPUT_H

#include <string>

static enum DataType = {
		strings = 0,
		doubles = 1,
		ints = 2,
	};

class FormatOutput{
public:
	FormatOutput();
	bool setFileDir(std::string dir);

private:
	std::string fileDir;
	DataType dataType;
	int dataSize[2];
	std::vector<std::string>  
};

#include "formatOutput.cpp"

#endif