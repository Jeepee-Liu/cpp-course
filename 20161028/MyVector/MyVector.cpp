#ifdef MY_VECTOR_H

///////////////////////////////////////////////////
/////////////////// OUT OF CLASS DEF.
///////////////////////////////////////////////////

/**************** FRIENDS ****************/

MyVector operator* ( const double dbl, const MyVector& myVec ) {
	MyVector myNewVec;
	const int length = MyVector::getDim();
	double* dblPtr = new double[length];
	for( int i=0; i<length; ++i ) {
		dblPtr[i] = myVec._data[i] * dbl;
	}
	myNewVec.initialize( dblPtr );
	delete[] dblPtr;
	return myNewVec;
} // Done

std::ostream& operator<< ( std::ostream& os, const MyVector& myVec ) {
	std::vector<double> dataVec = myVec._data;
	os << std::setprecision( MyVector::precision );
	
	std::for_each( dataVec.begin(), dataVec.end(),
		[ &os ]( double dbl ) { os << std::setw(MyVector::width) << dbl; } );
	/*
	for( auto i = myVec._data.begin();
		i != myVec._data.end();
		++i ) {
		os << std::setw(10) << *i ;
	}
	*/
	return os;
} // Done

///////////////////////////////////////////////////
/////////////////// public:
//////////////////////////////////////////////////////

/**************** BASIC INIT. ****************/

/**
 * constructor
 */
MyVector::MyVector() : _data( _dim, 0.0 ) {
	_dimIsSet = true;
} // Done

/**
 * dimension setter & getter
 */
inline void MyVector::setDim( int d ) {
	if( !_dimIsSet ) {
		_dim = d;
		_dimIsSet = true;
	}
	else {
		std::cerr << "\n" << "[ ERROR ] Failed to set the dimension of MyVector!\n"
		<< "\tDimension of MyVector has been set.\n" << std::endl;
	}
} // Done

inline int MyVector::getDim() {
	return _dim;
} // Done

inline MyVector& MyVector::initialize( double* dblPtr ) {
	for( int i=0; i<_dim; ++i ) {
		_data[i] = dblPtr[i];
	}
	return *this;
} // Done

inline MyVector& MyVector::randomInitialize() {
	std::uniform_real_distribution<> distribution(0, 1);
	std::random_device rd;
	std::mt19937 gen(rd());
	for( int i=0; i<_dim; ++i ) {
		_data[i] = distribution(gen);
	}
	return *this;
} // Done

/**************** CALCULATE ****************/

inline MyVector& MyVector::normalize() {
	double m = module();
	for (int i = 0; i < _dim; ++i) {
	 	_data[i] /= m;
	 }
	return *this;
} // Done

inline double MyVector::module() const {
	return norm(2);
} // Done

/**************** OPERATORS ****************/

/**
 * selecting operator []
 */
inline double& MyVector::operator[] ( const int i ) {
	return _data[i];
} // Done

inline const double& MyVector::operator[] ( const int i ) const {
	return _data[i];
} // Done

/**
 * assignment operator =
 */
inline void MyVector::operator= ( double* dblPtr ) {
	initialize( dblPtr );
} // Done

inline void MyVector::operator= ( const MyVector& myVec ) {
	for( int i = 0; i < _dim; ++i ) {
		_data[i] = myVec[i];
	}
} // Done

/**
 * operator + - * / ( with scalar )
 */
inline MyVector MyVector::operator+ ( double scalar ) const {
	MyVector myNewVec;
	myNewVec = *this;
	for (int i = 0; i < _dim; ++i) {
		myNewVec[i] += scalar;
	}
	return myNewVec;
} // Done

inline MyVector MyVector::operator- ( double scalar ) const {
	MyVector myNewVec;
	myNewVec = *this;
	for (int i = 0; i < _dim; ++i) {
		myNewVec[i] -= scalar;
	}
	return myNewVec;
} // Done

inline MyVector MyVector::operator* ( double scalar ) const {
	MyVector myNewVec;
	myNewVec = *this;
	for (int i = 0; i < _dim; ++i) {
		myNewVec[i] *= scalar;
	}
	return myNewVec;
} // Done

inline MyVector MyVector::operator/ ( double scalar ) const {
	MyVector myNewVec;
	myNewVec = *this;
	for (int i = 0; i < _dim; ++i) {
		myNewVec[i] /= scalar;
	}
	return myNewVec;
} // Done

/**
 * operator + - * ( with vector )
 */
inline MyVector MyVector::operator+ ( const MyVector& myVec ) const {
	MyVector myNewVec;
	myNewVec = *this;
	for (int i = 0; i < _dim; ++i) {
		myNewVec[i] += myVec[i];
	}
	return myNewVec;
} // Done

inline MyVector MyVector::operator- ( const MyVector& myVec ) const {
	MyVector myNewVec;
	myNewVec = *this;
	for (int i = 0; i < _dim; ++i) {
		myNewVec[i] -= myVec[i];
	}
	return myNewVec;
} // Done

inline double MyVector::operator* ( const MyVector& myVec ) const {
	double sum = 0.0;
	for (int i = 0; i < _dim; ++i) {
		sum += _data[i] * myVec[i];
	}
	return sum;
} // Done

/**
 * operator += -= *= /= ( with scalar )
 */
inline MyVector& MyVector::operator+= ( double scalar ) {
	for (int i = 0; i < _dim; ++i) {
		_data[i] += scalar;
	}
	return *this;
} // Done

inline MyVector& MyVector::operator-= ( double scalar ) {
	for (int i = 0; i < _dim; ++i) {
		_data[i] -= scalar;
	}
	return *this;
} // Done

inline MyVector& MyVector::operator*= ( double scalar ) {
	for (int i = 0; i < _dim; ++i) {
		_data[i] *= scalar;
	}
	return *this;
} // Done

inline MyVector& MyVector::operator/= ( double scalar ) {
	for (int i = 0; i < _dim; ++i) {
		_data[i] /= scalar;
	}
	return *this;
} // Done

/**
 * operator += -= ( with vector )
 */
inline MyVector& MyVector::operator+= ( MyVector& myVec ) {
	for (int i = 0; i < _dim; ++i) {
		_data[i] += myVec[i];
	}
	return *this;
} // Done

inline MyVector& MyVector::operator-= ( MyVector& myVec ) {
	for (int i = 0; i < _dim; ++i) {
		_data[i] -= myVec[i];
	}
	return *this;
} // Done

/**************** DISPLAYING ****************/

inline MyVector& MyVector::disp( std::ostream& os ) {
	os << *this << std::endl;
	return *this;
} // Done

inline MyVector& MyVector::show() {
	disp(std::cout);
	return *this;
}

///////////////////////////////////////////////////
//////////////////// private:
////////////////////////////////////////////////////

int MyVector::_dim = 3;
bool MyVector::_dimIsSet = false;
const char* MyVector::sep = "\t";
const int MyVector::precision = 5;
const int MyVector::width = 8;

inline double MyVector::norm( int k ) const {
	double sum = 0.0;
	for( int i=0; i < _dim; ++i ) {
		sum += std::pow( _data[i], k );
	}
	return std::pow( sum, 1/(double)k );
} // Done

#endif