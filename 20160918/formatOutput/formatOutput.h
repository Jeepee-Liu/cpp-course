#ifndef _FORMAT_OUTPUT_H
#define _FORMAT_OUTPUT_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

class FormatOutput{
// Output data in a 2D format
// with type "double"
public:
	FormatOutput();
	bool setFileDir(std::string dir);
	bool appendData(std::string name, std::vector<double> dataColumn);
	bool appendData(std::string name, double* dataColumn, int len);
	int* getDataSize();
	void clearData();
	bool writeData();
	void printData();

private:
	double* data[20]; // for 2D data
	/* Rule of data arrangement:
	 * data[i] is the pointer to i-th column
	 * data[i][j] is the j-row element in the i-th column
	 * data column not exceed 20
	 * 
	 * A data sheet should like this: ( '\t' = ' '*8 )

		====================================
		Col 1		Col 2		Col 3
		------------------------------------
		1.000000	4.000000	7.000000
		2.000000	5.000000	8.000000
		3.000000	6.000000	9.000000
		====================================

	 */
	std::string fileDir;
	// A flag of file directory setter. 
	bool isFileDirSet;
	// dataSizeN :
	// First element is the length of each data column;
	// Second element is the number of data column.
	int dataSizeN[2];
	std::vector<std::string> namesVec;
	std::string dataStr;
	// private methods:
	void data2str(); // mode=0, 
	void data2str(int mode);
	std::string num2str(double num);
	void clearDataStr();
};

#include "formatOutput.cpp"
#endif