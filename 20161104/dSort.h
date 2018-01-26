#ifndef DSORT_H
#define DSORT_H

#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
#include <fstream>

#include <bitset>

class DSort {

public:

	typedef std::set<char> UnorderedWordT;
	typedef std::map<UnorderedWordT, int> WordMapT;

	DSort (const std::string& fileName);
	DSort& classify ();
	void show ();

private:
	
	WordMapT _wordMap;
	std::ifstream _fObj;
	const int _bufSize = 6;

	inline UnorderedWordT _parseLine (char* buffer);
	inline std::string _str (UnorderedWordT uWord);

};

///////////////////////////////////////////////////

class DEncode{

public:

	typedef std::bitset<10> WordT;
	typedef std::unordered_map<WordT, int> DictT;

	DEncode (const std::string& fileName);
	DEncode& classify();
	void show();

private:

	std::ifstream _fObj;
	WordT _word;
	DictT _dict;
	char _buffer[6];

	inline WordT _parseLine (const char* buffer);
	inline std::string _str (WordT word);

};

#include "dSort.cpp"

#endif