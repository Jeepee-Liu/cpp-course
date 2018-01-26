#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm> // std::for_each(...)
#include <utility> // std::move(...)
#include <cmath>

class MyVector {

	/**************** FRIENDS ****************/
	
	friend MyVector& operator* ( const double dbl, const MyVector& myVec );
	friend std::ostream& operator<< ( std::ostream& os, const MyVector& myVec );
	friend inline MyVector cross( const MyVector& myVec1, const MyVector& myVec2 );
	// friend inline MyVector cross( const MyVector& myVec1, const MyVector& myVec2 );
	friend inline double angle( const MyVector& myVec1, const MyVector& myVec2 );

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
	inline MyVector& initialize( double* const dblPtr );
	inline MyVector& randomInitialize();

	/**************** CALCULATIONS ****************/

	inline MyVector& normalize();
	inline double module() const;

	inline MyVector& setMagnitute( const double mag );
	inline MyVector cross( const MyVector& myVec ) const;
	inline double angle( const MyVector& myVec ) const;

	/**************** OPERATORS ****************/

	/**
	 * selecting operator []
	 */
	inline double& operator[] ( const int i );
	inline const double& operator[] ( const int i ) const ;

	/**
	 * assignment operator =
	 */
	inline void operator= ( double* const dblPtr );
	inline void operator= ( const MyVector& myVec );
	
	/**
	 * operator + - * / ( with scalar )
	 */
	inline MyVector operator+ ( const double scalar ) const;
	inline MyVector operator- ( const double scalar ) const;
	inline MyVector operator* ( const double scalar ) const;
	inline MyVector operator/ ( const double scalar ) const;

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
	inline MyVector& pretty(); // as MATLAB

private:
	std::vector<double> _data;
	static int _dim;
	static bool _dimIsSet;
	static const double pi;
	inline double norm( int k ) const;
	static const char* sep;
	static const int precision;
	static const int width;
};

/**
 * left scalar product
 */
MyVector& operator* ( const double dbl, const MyVector& myVec );

/**
 * outstream operator <<
 */
std::ostream& operator<< ( std::ostream& os, const MyVector& myVec );

/**
 * cross product of two vectors
 * return a new vector.
 */
inline MyVector cross( const MyVector& myVec1, const MyVector& myVec2 );
// inline MyVector cross( const MyVector& myVec1, const MyVector& myVec2 );

/**
 * calculate the angle between two vectors.
 */
inline double angle( const MyVector& myVec1, const MyVector& myVec2 );

#include "MyVector.cpp"
#endif