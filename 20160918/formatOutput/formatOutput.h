#ifndef _FORMAT_OUTPUT_H
#define _FORMAT_OUTPUT_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

template<typename dataType>
class FormatOutput{
// Output data in a 2D format
// with type "double"
public:	FormatOutput();
	void setFileDir(std::string dir);
	bool appendData(std::string name, std::vector<dataType> dataColumn);
	bool appendData(std::string name, dataType *dataColumn, int len);
	void clearData();
	bool writeData();
	void printData();

private:
	int **data; // for 2D data
	std::string fileDir;
	// A flag of file directory setter. 
	bool isFileDirSet;
	// dataSizeN :
	// First element is the length of each data column;
	// Second element is the number of data column.
	int dataSizeN[2];
	std::vector<std::string> namesVec;

};

#include "formatOutput.cpp"
#endif