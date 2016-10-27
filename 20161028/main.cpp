#include "MyVector/MyVector.h"
#include <iostream>
#include <string>

#define LINE std::cout<<std::string(60,'-')<<std::endl;
#define NL std::cout<<std::endl;
#define TITLE_START NL LINE std::cout<<
#define TITLE_END <<std::endl; LINE NL

int main() {
	/**
	 * Test all the methods defined in
	 *     "./MyVector/MyVector.h"
	 * as below
	 */
	TITLE_START " ***** HELLO! Ready to test MyVector ***** " TITLE_END

	/********** testing dim. setter & getter **********/
	TITLE_START " ******* testing dim. setter & getter ******* " TITLE_END

	std::cout << "Setting dim of vector..." << std::endl;
	MyVector::setDim(3);
	std::cout << "Dimension of MyVector is "
	<< MyVector::getDim() << "." << std::endl;
	std::cout << "Try re-setting dim of vector..." << std::endl;
	MyVector::setDim(2);
	std::cout << "Dimension of MyVector is "
	<< MyVector::getDim() << "." << std::endl;

	/********** testing constructor **********/
	TITLE_START " ******* testing constructor  ******* " TITLE_END

	std::cout << "Constructing vectors..." << std::endl;
	MyVector v1, v2, v3;

	/********** test initializing methods **********/
	/**********       and disp / show     **********/
	TITLE_START " ******* testing initializing methods  ******* " TITLE_END

	std::cout << "Initializing vectors..." << std::endl;
	double dblPtr1[] = {2.0, 2.0, 2.0};
	double dblPtr2[] = {1.0, 2.0, 3.0};
	v1.initialize( dblPtr1 );
	v2.randomInitialize();
	v3.initialize( dblPtr2 );

	/**********   testing (<<) / disp / show     **********/

	TITLE_START " **********   testing (<<) / disp / show     ********** " TITLE_END

	std::cout << "Using operator (<<) :" << std::endl;
	std::cout << "vector 1 = ( " << v1 << " )" << std::endl;
	std::cout << "vector 2 = ( " << v2 << " )" << std::endl;
	std::cout << "vector 3 = ( " << v3 << " )" << std::endl;

	std::cout << "[ disp() ] vector 1 : " << std::endl;
	v1.disp(std::cout);
	std::cout << "[ show() ] vector 1 : " << std::endl;
	v1.show();

	/********** test single element operators **********/
	/**********         ( with scalar )       **********/

	TITLE_START " ***** testing single element operators (with scalar) ***** " TITLE_END

	std::cout << "vector 1 = " << std::endl;
	v1.show();
	
	std::cout << "vector 1 += 1 : ( " << ( v1 += 1 ) << " )" << std::endl;
	std::cout << "vector 1 -= 1 : ( " << ( v1 -= 1 ) << " )" << std::endl;
	std::cout << "vector 1 *= 4 : ( " << ( v1 *= 4 ) << " )" << std::endl;
	std::cout << "vector 1 /= 2 : ( " << ( v1 /= 2 ) << " )" << std::endl;

	/********** test single element operators **********/
	/**********         ( with vector )       **********/

	TITLE_START " ***** testing single element operators (with vector) ***** " TITLE_END

	std::cout << "vector 1 += vector 3 : ( " << ( v1 += v3 ) << " )" << std::endl;
	std::cout << "vector 1 -= vector 3 : ( " << ( v1 -= v3 ) << " )" << std::endl;

	/********** test double element operators **********/
	/**********         ( with scalar )       **********/

	TITLE_START " ***** testing double element operators (with scalar) ***** " TITLE_END

	std::cout << "vector 1 + 1 = ( " << ( v1 + 1 ) << " )" << std::endl; 
	std::cout << "vector 1 - 1 = ( " << ( v1 - 1 ) << " )" << std::endl; 
	std::cout << "vector 1 * 2 = ( " << ( v1 * 2 ) << " )" << std::endl;

	/********** test double element operators **********/
	/**********         ( with vector )       **********/

	TITLE_START " ***** testing double element operators (with vector) ***** " TITLE_END

	std::cout << "vector 1 + vector 3 = ( " << ( v1 + v3 ) << " )" << std::endl; 
	std::cout << "vector 1 - vector 3 = ( " << ( v1 - v3 ) << " )" << std::endl; 
	std::cout << "vector 1 * vector 3 = " << ( v1 * v3 )
		<< "\t( inner / dot product )" << std::endl;


	/********** test module and normalization **********/

	TITLE_START " ********* testing module and normalization ********* " TITLE_END

	std::cout << "vector 1: " << std::endl;
	v1.show();
	std::cout << "vector 1 module: " << v1.module() << std::endl;
	std::cout << "After normalization: " << std::endl;
	v1.normalize().show();
	std::cout << "vector 1 module: "
	<< v1.module() << std::endl;

	std::cout << "vector 2: " << std::endl;
	v2.show();
	std::cout << "After normalization: " << std::endl;
	v2.normalize().show(); 

	/**********     test assignement      **********/

	TITLE_START " ******** testing assignement operator ******** " TITLE_END

	v3 = v1+v2;
	std::cout << "vector 3 (vector 1 + vector 2) = ( "
	<< v3 << " )" << std::endl;

	return 0;
}