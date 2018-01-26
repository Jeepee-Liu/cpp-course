#include <SmallWorldNetwork.hpp>

int main( int argc, const char* argv[] ) {
	SmallWorldNetwork network( argc, argv );
	network.generate().simulate();
	return 0;
}