#ifndef SMALL_WORLD_NETWORK
#define SMALL_WORLD_NETWORK

#include <random>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "GraphSetting.hpp"

class SmallWorldNetwork {

public:

	typedef uint32_t SiteNumT;
	typedef std::list<SiteNumT>::iterator UnconnSiteIter;

	SmallWorldNetwork( int argc, char* argv[] );
	virtual SmallWorldNetwork& generate();
	virtual SmallWorldNetwork& outputMMAStyleConn();
	SmallWorldNetwork& plotNetwork();
	virtual ~SmallWorldNetwork() = default;
	
private:

	// These are functions related to
	// the construction of the graph
	std::list<SiteNumT> _unconnectedSites;
	inline void _tryConnect( SiteNumT index );
	inline bool _isToConnect();
	inline void _connect( UnconnSiteIter thisSite ) ;
	inline UnconnSiteIter _findLegalConnection(
		UnconnSiteIter thisSite,
		UnconnSiteIter iter );

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

};

#include "SmallWorldNetwork.cpp"

#endif
