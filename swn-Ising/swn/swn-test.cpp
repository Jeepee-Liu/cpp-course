#include "SmallWorldNetwork.hpp"

int main( int argc, char* argv[] ) {
	SmallWorldNetwork network( argc, argv );
	network.generate().outputMMAStyleConn().plotNetwork();
	return 0;
}