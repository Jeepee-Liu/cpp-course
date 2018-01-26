#ifdef DSORT_H

/************** PUBLIC ****************/

DSort::DSort (const std::string& fileName) :
_wordMap() {
	_fObj.open(fileName.c_str());
};

DSort& DSort::classify () {
	int lineN = 0;
	char* buffer = new char[_bufSize];
	while ( _fObj >> buffer ) {
		++_wordMap[ _parseLine (buffer) ];
		lineN++;
		if (lineN%10000 == 0) {
			std::cout << "[ line ] " << lineN << "\t / 1000000" << std::endl;
		}
	}
	delete[] buffer;
	return *this;
}

void DSort::show () {
	for (const auto& w : _wordMap) {
		std::cout << _str(w.first)
		<< "\t: " << w.second << std::endl;
	}
	std::cout << "*** Number of types in the file is: "
	<< _wordMap.size() << std::endl;
}

/************** PRIVATE ****************/

inline DSort::UnorderedWordT DSort::_parseLine (char* buffer) {
	UnorderedWordT uWord;
	for ( char* charPtr = buffer;
		*charPtr != '\0';
		++charPtr) {
		// duc
		uWord.insert(*charPtr);
	}
	return uWord;
}

inline std::string DSort::_str (UnorderedWordT uWord) {
	std::string str;
	for (const auto& i : uWord) {
		str += i;
	}
	return str;
}

//////////////////////////
//////////////////////////
//////////////////////////
///


DEncode::DEncode (const std::string& fileName) :
_word("0000000000"), _dict() {
	_fObj.open(fileName.c_str());
}

DEncode& DEncode::classify () {
	int lineN = 0;
	while ( _fObj >> _buffer ) {
		++_dict[ _parseLine (_buffer) ];
		if (++lineN%10000 == 0) {
			std::cout << "[ line ] " << lineN << "\t / 1000000" << std::endl;
		}
	}
	return *this;
}

void DEncode::show () {
	for (const auto& word : _dict) {
		std::cout << _str(word.first) << "\t: " << word.second << std::endl;
	}
	std::cout << "*** Number of types in the file is: "
	<< _dict.size() << std::endl;
}

inline DEncode::WordT DEncode::_parseLine (const char* buffer) {
	_word.reset ();
	static int pos = 0;
	for(const char* charPtr = buffer;
		*charPtr != '\0'; ++charPtr) {
		pos = (int) (*charPtr) - (int) 'A';
		_word.set(pos, true);
	}
	return _word;
}

inline std::string DEncode::_str (WordT word) {
	std::string str;
	for (int i=0; i<10; ++i) {
		if (word[i]) {
			str += (char)(i+(int)'A');
		}
	}
	return str;
}

#endif