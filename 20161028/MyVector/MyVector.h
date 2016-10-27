#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm> // std::for_each()

class MyVector {

	/**************** FRIENDS ****************/
	
	/**
	 * left scalar product
	 */
	friend MyVector operator* ( const double, const MyVector& );
	
	/**
	 * outstream operator <<
	 */
	friend std::ostream& operator<< ( std::ostream&, const MyVector& );

public:
	
	/**************** BASIC INIT. ****************/

	/**
	 * constructor
	 */
	MyVector();

	/**
	 * dimension setter & getter
	 */
	inline static void setDim( int d );
	inline static int getDim();
	inline MyVector& initialize( double* dblPtr );
	inline MyVector& randomInitialize();

	/**************** CALCULATE ****************/

	inline MyVector& normalize();
	inline double module() const;

	/**************** OPERATORS ****************/

	/**
	 * selecting operator []
	 */
	inline double& operator[] ( const int i );
	inline const double& operator[] ( const int i ) const ;

	/**
	 * assignment operator =
	 */
	inline void operator= ( double* dblPtr );
	inline void operator= ( const MyVector& myVec );
	
	/**
	 * operator + - * / ( with scalar )
	 */
	inline MyVector operator+ ( double scalar ) const;
	inline MyVector operator- ( double scalar ) const;
	inline MyVector operator* ( double scalar ) const;
	inline MyVector operator/ ( double scalar ) const;

	/**
	 * operator + - * ( with vector )
	 */
	inline MyVector operator+ ( const MyVector& myVec ) const;
	inline MyVector operator- ( const MyVector& myVec ) const;
	inline double operator* ( const MyVector& myVec ) const;

	/**
	 * operator += -= *= /= ( with scalar )
	 */
	inline MyVector& operator+= ( double scalar );
	inline MyVector& operator-= ( double scalar );
	inline MyVector& operator*= ( double scalar );
	inline MyVector& operator/= ( double scalar );

	/**
	 * operator += -= ( with vector )
	 */
	inline MyVector& operator+= ( MyVector& myVec );
	inline MyVector& operator-= ( MyVector& myVec );
	
	/**************** DISPLAYING ****************/

	inline MyVector& disp( std::ostream& os );
	inline MyVector& show();

private:
	std::vector<double> _data;
	static int _dim;
	static bool _dimIsSet;
	inline double norm( int k ) const;
	static const char* sep;
	static const int precision;
	static const int width;

};

MyVector operator* ( const double d, const MyVector& myVec );
std::ostream& operator<< ( std::ostream& os, const MyVector& myVec );

#include "MyVector.cpp"
#endif