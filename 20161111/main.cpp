#include <iostream>
#include <IsingSquare.hpp>

int main (int argc, char* const argv[]) {
	IsingSquare simu(argc, argv);
	simu.simulate();
	return 0;
}