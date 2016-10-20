#ifdef MY_STRING_H

/***************** public methods *****************/

//////////////////// constructors ////////////////////

MyString::MyString() {
	curP = new char[1];
	if( curP == nullptr ) {
		allocError();
	}
	else {
		curP[0] = eos;
	}
} // Done

MyString::MyString( const char ch ) {
	curP = new char[2];
	if( curP == nullptr ) {
		allocError();
	}
	else {
		curP[0] = ch;
		curP[1] = eos;
	}
} // Done

MyString::MyString( MyStrSizeT len, const char ch ) {
	curP = new char[ len + 1 ];
	if( curP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			curP[i] = ch;
		}
		curP[len] = eos;
	}
} // Done

MyString::MyString( const char* chars ){
	// get the length of target string;
	MyStrSizeT len = getStrLength(chars);
	curP = new char[ len + 1 ];
	if( curP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			curP[i] = chars[i];
		}
		curP[len] = eos;
	}
} // Done

MyString::MyString( const MyString& myStr ) {
	MyStrSizeT len = myStr.size();
	char* tempCharP = myStr.getString();
	curP = new char[ len + 1 ];
	if( curP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			curP[i] = tempCharP[i];
		}
		curP[len] = eos;
	}
	delete[] tempCharP;
} // Done

//////////////////// destructor ////////////////////

MyString::~MyString() {
	delete[] curP;
} // Done

//////////////////// size getter ////////////////////

inline MyString::MyStrSizeT MyString::size() const {
	MyStrSizeT len = getStrLength(curP);
	return len;
} // Done

///////////////// empty checker /////////////////

inline bool MyString::empty() const {
	return ( size() == 0 );
}

//////////////////// print ////////////////////

inline std::ostream& MyString::print(std::ostream& os) {
	os << curP;
	return os;
}

inline const std::ostream& MyString::print(std::ostream& os) const {
	os << curP;
	return os;
}

//////////////////// show ////////////////////

inline MyString& MyString::show() {
	print(std::cout);
	std::cout << std::endl;
	return *this;
} // Done & tested

inline const MyString& MyString::show() const {
	print(std::cout);
	std::cout << std::endl;
	return *this;
}

/////////// char* form hard copy getter ///////////

char* MyString::getString() const {
	MyStrSizeT len = size();
	char* newCurP = new char[ len + 1 ];
	if( newCurP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			newCurP[i] = curP[i];
		}
		newCurP[len] = eos;
	}
	return newCurP;
} // Done

//////////////////// operator = ////////////////////

void MyString::operator=( const char ch ) {
	delete[] curP;
	curP = new char[2];
	if( curP == nullptr ) {
		allocError();
	}
	else {
		curP[0] = ch;
		curP[1] = eos;
	}
} // Done

void MyString::operator=( const char* chars ) {
	delete[] curP;
	MyStrSizeT len = getStrLength(chars);
	curP = new char[ len + 1 ];
	if( curP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			curP[i] = chars[i];
		}
		curP[len] = eos;
	}
} // Done

void MyString::operator=( const MyString& myStr ) {
	delete[] curP;
	MyStrSizeT len = myStr.size();
	char* tempCharP = myStr.getString();
	curP = new char[ len + 1 ];
	if( curP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			curP[i] = tempCharP[i];
		}
		curP[len] = eos;
	}
	delete[] tempCharP;
} // Done

//////////////////// operator + ////////////////////

MyString MyString::operator+( const char ch ) {
	const char str[2] = { ch, eos };
	char* tempCharP = concatenate( curP, str );
	MyString myNewStr(tempCharP);
	delete[] tempCharP;
	return myNewStr;
} // Done

MyString MyString::operator+( const char* str ) {
	char* tempCharP = concatenate( curP, str );
	MyString myNewStr(tempCharP);
	delete[] tempCharP;
	return myNewStr;
}

MyString MyString::operator+( const MyString& myStr ) {
	char* str = myStr.getString();
	char* tempCharP = concatenate( curP, str );
	MyString myNewStr(tempCharP);
	delete[] tempCharP;
	delete[] str;
	return myNewStr;
}

//////////////////// operator += ////////////////////

void MyString::operator+=( const char ch ) {
	const char str2[2] = { ch, eos };
	char* tempStr = concatenate( curP, str2 );
	delete[] curP;
	curP = tempStr;
}

void MyString::operator+=( const char* str ) {
	char* tempStr = concatenate( curP, str );
	delete[] curP;
	curP = tempStr;
}
void MyString::operator+=( const MyString& myStr ) {
	char* str2 = myStr.getString();
	char* tempStr = concatenate( curP, str2 );
	delete[] curP;
	delete[] str2;
	curP = tempStr;
}

//////////////////// operator [] ////////////////////

inline char MyString::operator[] ( MyStrSizeT index ) const {
	char ch = *(curP + index);
	return ch;
}

/***************** private methods *****************/

inline void MyString::allocError() const {
	std::cerr << "Failed to allocate new space!" << std::endl;
	exit(1);
} // Done

inline MyString::MyStrSizeT MyString::getStrLength(const char* chars) const {
	MyStrSizeT len = 0;
	const char* tempP;
	for( tempP = chars; *tempP != eos; ++tempP ) {
		len++;
	}
	return len;
} // Done

inline char* MyString::concatenate( const char* str1, const char* str2 ) const {
	MyStrSizeT len1 = getStrLength(str1);
	MyStrSizeT len2 = getStrLength(str2);
	// Size of new myString
	MyStrSizeT len = len1 + len2;
	char* charP = new char[len+1];
	for( MyStrSizeT i=0; i < len1; ++i ) {
		charP[i] = str1[i];
	}
	for( MyStrSizeT i=len1; i < len; ++i ) {
		charP[i] = str2[i-len1];
	}
	charP[ len ]   = eos;
	return charP;
} // Done

std::ostream &operator<<( std::ostream &os, MyString &myStr ){
	char* tempCharP = myStr.getString();
	os << tempCharP;
	delete[] tempCharP;
	return os;
} // Done


#endif