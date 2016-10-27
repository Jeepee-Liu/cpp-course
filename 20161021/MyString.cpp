#ifdef MY_STRING_H

/////////////////////////////////////////////////////
/////////////////// class methods ///////////////////
/////////////////////////////////////////////////////


/***************** public methods *****************/

//////////////////// constructors ////////////////////

MyString::MyString() {
	headP = new char[1];
	if( headP == nullptr ) {
		allocError();
	}
	else {
		headP[0] = eos;
	}
} // Done

MyString::MyString( const char ch ) {
	headP = new char[2];
	if( headP == nullptr ) {
		allocError();
	}
	else {
		headP[0] = ch;
		headP[1] = eos;
	}
} // Done

MyString::MyString( MyStrSizeT len, const char ch ) {
	headP = new char[ len + 1 ];
	if( headP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			headP[i] = ch;
		}
		headP[len] = eos;
	}
} // Done

MyString::MyString( const char* chars ){
	// get the length of target string;
	MyStrSizeT len = getStrLength(chars);
	headP = new char[ len + 1 ];
	if( headP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			headP[i] = chars[i];
		}
		headP[len] = eos;
	}
} // Done

MyString::MyString( const MyString& myStr ) {
	MyStrSizeT len = myStr.size();
	char* tempCharP = myStr.getString();
	headP = new char[ len + 1 ];
	if( headP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			headP[i] = tempCharP[i];
		}
		headP[len] = eos;
	}
	delete[] tempCharP;
} // Done

//////////////////// destructor ////////////////////

MyString::~MyString() {
	delete[] headP;
} // Done

//////////////////// size getter ////////////////////

inline MyString::MyStrSizeT MyString::size() const {
	MyStrSizeT len = getStrLength(headP);
	return len;
} // Done

///////////////// empty checker /////////////////

inline bool MyString::empty() const {
	return ( size() == 0 );
}

//////////////////// print ////////////////////

inline std::ostream& MyString::print(std::ostream& os) {
	os << headP;
	return os;
}

inline const std::ostream& MyString::print(std::ostream& os) const {
	os << headP;
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
	char* newheadP = new char[ len + 1 ];
	if( newheadP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			newheadP[i] = headP[i];
		}
		newheadP[len] = eos;
	}
	return newheadP;
} // Done

//////////////////// operator = ////////////////////

void MyString::operator=( const char ch ) {
	delete[] headP;
	headP = new char[2];
	if( headP == nullptr ) {
		allocError();
	}
	else {
		headP[0] = ch;
		headP[1] = eos;
	}
} // Done

void MyString::operator=( const char* chars ) {
	delete[] headP;
	MyStrSizeT len = getStrLength(chars);
	headP = new char[ len + 1 ];
	if( headP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			headP[i] = chars[i];
		}
		headP[len] = eos;
	}
} // Done

void MyString::operator=( const MyString& myStr ) {
	delete[] headP;
	MyStrSizeT len = myStr.size();
	char* tempCharP = myStr.getString();
	headP = new char[ len + 1 ];
	if( headP == nullptr ) {
		allocError();
	}
	else {
		for( MyStrSizeT i=0; i<len; ++i ) {
			headP[i] = tempCharP[i];
		}
		headP[len] = eos;
	}
	delete[] tempCharP;
} // Done

//////////////////// operator + ////////////////////

MyString MyString::operator+( const char ch ) {
	const char str[2] = { ch, eos };
	char* tempCharP = concatenate( headP, str );
	MyString myNewStr(tempCharP);
	delete[] tempCharP;
	return myNewStr;
} // Done

MyString MyString::operator+( const char* str ) {
	char* tempCharP = concatenate( headP, str );
	MyString myNewStr(tempCharP);
	delete[] tempCharP;
	return myNewStr;
}

MyString MyString::operator+( const MyString& myStr ) {
	char* str = myStr.getString();
	char* tempCharP = concatenate( headP, str );
	MyString myNewStr(tempCharP);
	delete[] tempCharP;
	delete[] str;
	return myNewStr;
}

//////////////////// operator += ////////////////////

void MyString::operator+=( const char ch ) {
	const char str2[2] = { ch, eos };
	char* tempStr = concatenate( headP, str2 );
	delete[] headP;
	headP = tempStr;
}

void MyString::operator+=( const char* str ) {
	char* tempStr = concatenate( headP, str );
	delete[] headP;
	headP = tempStr;
}

void MyString::operator+=( const MyString& myStr ) {
	char* str2 = myStr.getString();
	char* tempStr = concatenate( headP, str2 );
	delete[] headP;
	delete[] str2;
	headP = tempStr;
}

//////////////////// operator [] ////////////////////

inline char MyString::operator[] ( MyStrSizeT index ) const {
	char ch = *( headP + index );
	return ch;
}

//////////////////// counter ////////////////////

inline MyString::MyStrSizeT MyString::count( const char ch ) const {
	MyStrSizeT cnt = 0;
	char* curP = headP;
	while( *curP != eos ) {
		if( ch == *curP ) cnt++;
		curP++;
	}
	return cnt;
}

//////////////////// finder ////////////////////

inline long int MyString::find( const char ch ) const {
	char* curP = headP;
	long int position = 0;
	while( *curP != eos ) {
		if( ch == *curP ) return position;
		position++;
		curP++;
	}
	return -1;
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

/////////////////////////////////////////////////////
////////////////// other functions //////////////////
/////////////////////////////////////////////////////

///////////////// ostream operator /////////////////

std::ostream &operator<<( std::ostream &os, MyString &myStr ){
	char* tempCharP = myStr.getString();
	os << tempCharP;
	delete[] tempCharP;
	return os;
} // Done

//////////////////// operator + ///////////////////

MyString operator+( const char* str, const MyString& myStr ) {
	MyString tempMyStr(str);
	MyString myNewStr = ( tempMyStr + myStr );
	return myNewStr;
}

MyString operator+( const char ch, const MyString& myStr ) {
	MyString tempMyStr(ch);
	MyString myNewStr = ( tempMyStr + myStr );
	return myNewStr;
}

#endif