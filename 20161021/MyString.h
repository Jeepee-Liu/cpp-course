#ifndef MY_STRING_H
#define MY_STRING_H

/**
 * for std::cout in MyString::show()
 * and std::ostream
 */
#include <iostream>


class MyString {
/**
 * Using safer method getString() to avoid
 * direct access to ptivate member.
 */
// friend std::ostream& operator<<( ostream& os, MyString& myStr );

public:

	/**
	 * MyStrSizeT is the type of length of the string
	 */
	typedef uint32_t MyStrSizeT;

	/**
	 * 5 overloaded constructors
	 */
	MyString();
	MyString( const char ch );
	MyString( MyStrSizeT len, const char ch );
	MyString( const char* chars );
	MyString( const MyString& myStr );

	/**
	 * destructor
	 */
	~MyString();

	/**
	 * size reader
	 */
	inline MyStrSizeT size() const;

	/**
	 * empty checker
	 */
	inline bool empty() const;

	/**
	 * print current string to an ostream "os"
	 */
	inline std::ostream& print(std::ostream& os);
	inline const std::ostream& print(std::ostream& os) const;
	
	/**
	 * show current string at std::cout
	 */
	inline MyString& show();
	inline const MyString& show() const;

	char* getString() const;

//////////////////// operators ////////////////////

	/**
	 * assignment operator =
	 */
	void operator=( const char ch );
	void operator=( const char* str );
	void operator=( const MyString& myStr );

	/**
	 * concatenation operator +
	 */
	MyString operator+( const char ch );
	MyString operator+( const char* str );
	MyString operator+( const MyString& myStr );

	/**
	 * elongation operator +=
	 */
	void operator+=( const char ch );
	void operator+=( const char* str );
	void operator+=( const MyString& myStr );
	
	/**
	 * slice operator []
	 */
	inline char operator[] ( MyStrSizeT index ) const;

	/**
	 * char counter
	 * [ argument ] char ch
	 * [  return  ] the number of ch in this object
	 */
	inline MyStrSizeT count( const char ch) const;

	/**
	 * find a char in my string
	 * return the position of the string
	 */
	inline long int find( const char ch ) const;
	
private:

	const char eos = '\0';
	char* headP;
	inline void allocError() const;
	inline MyStrSizeT getStrLength(const char* chars) const;
	inline char* concatenate( const char* str1, const char* str2 ) const ;

};

MyString operator+( const char* str, const MyString& myStr );
MyString operator+( const char ch, const MyString& myStr );

std::ostream& operator<<( std::ostream& os, MyString& myStr );

#include "MyString.cpp"

#endif