#ifndef SMALL_WORLD_NETWORK_ISING
#define SMALL_WORLD_NETWORK_ISING

#include "SmallWorldNetwork.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <cmath>


class SmallWorldNetworkIsing : public SmallWorldNetwork {

public:
	// type definitions
	typedef uint32_t StepNumT;
	typedef std::map< SiteNumT, std::vector<SiteNumT> > ConnectionT;

/* Base class methods
	typedef uint32_t SiteNumT;
	typedef std::list<SiteNumT>::iterator UnconnSiteIter;
	
	SmallWorldNetwork( int argc, char* argv[] );
	virtual SmallWorldNetwork& generate();
	virtual SmallWorldNetwork& outputMMAStyleConn();
	SmallWorldNetwork& plotNetwork();
	virtual ~SmallWorldNetwork() = default;
 */

	SmallWorldNetworkIsing( int argc, char* argv[] );
	~SmallWorldNetworkIsing();
	SmallWorldNetworkIsing& generate();
	SmallWorldNetworkIsing& simulate();
	SmallWorldNetworkIsing& outputMMAStyleConn();
	void usage();

/* Base class methods

protected:
	// working directory
	const std::string _workingDir;
	// settings about the graph
	SettingT _setting;
	// random devices
	std::random_device _rd;
	std::mt19937 _gen;
	std::uniform_real_distribution<> _unitDis;
	// state recorder
	bool _outputDone;
	bool _generationDone;
	// KEY AVRIABLE
	// storing the structure of the graph
	std::map<SiteNumT, SiteNumT> _connection;

 */

private:

	ConnectionT _fullConnection;
	//std::uniform_int_distribution<> _toLink;
	bool* _spin;
	std::uniform_real_distribution<> _chooseSpin;
	std::uniform_real_distribution<> _simuFlip;
	void _generateSpin();
	void _generateFullConnection();
	void _stepSimu();
	// calcluate physic quantities
	inline double _calcMagnetization();
	inline double _calcAverage( double* m, SiteNumT n );
	inline double _calcStdDev( double* m, SiteNumT n );
	inline void _tryflip( SiteNumT i, int delta_energy );
	inline double _flipProb( double delta_energy );
	
};

#include "SmallWorldNetworkIsing.cpp"

#endif