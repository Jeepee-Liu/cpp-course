#include "SmallWorldNetworkIsing.hpp"

int main( int argc, char* argv[] ) {
	SmallWorldNetworkIsing network( argc, argv );
	network.generate().outputMMAStyleConn().plotNetwork();
	network.simulate();
	return 0;
}