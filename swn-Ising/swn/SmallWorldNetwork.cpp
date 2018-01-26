#ifdef SMALL_WORLD_NETWORK

SmallWorldNetwork::SmallWorldNetwork( int argc, char* argv[] ) :
_workingDir("/Users/jeepee/Documents/Cpp_trade/cpp-course/swn-Ising"),
_setting( argc, argv ), _rd(), _gen(_rd()), _unitDis(0.0, 1.0),
_outputDone(false), _generationDone(false) {}

SmallWorldNetwork& SmallWorldNetwork::generate() {
	if( _generationDone ) { return *this; }
	// generate a library of unconnected sites
	// and shuffle all the sites in the elements
	// NOTE:
	// std::vector<T> is a random accessible capacitor
	// that is suitable for std::shuffle()
	std::vector<SiteNumT> v;
	for ( SiteNumT i=0; i<_setting.siteN; ++i ) {
		v.push_back(i);
	}
	std::shuffle( v.begin(), v.end(), _gen);
	_unconnectedSites.assign(v.begin(), v.end());

	for( SiteNumT i=0; i<_setting.siteN; ++i ) {
		_tryConnect( i );
	}
	
	if( _setting.mode == SettingT::verbose ) {
		std::cout << "Graph generated!" << std::endl;
	}
	_generationDone = true;
	return *this;
}

inline void SmallWorldNetwork::_tryConnect( SiteNumT index ) {
	auto thisSite = std::find(
		_unconnectedSites.begin(),
		_unconnectedSites.end(), index);
	if( thisSite != _unconnectedSites.end()
		&& _isToConnect() ) {
			_connect( thisSite );
	}
	// record all the neighbouring edges
	/////// Only one extra link is allowed
	/*
		for( SiteNumT i = 0; i<_setting.siteN-1; ++i ) {
			_connection[i] = i+1;
			_connection[i+1] = i;
		}
		_connection[0] = _setting.siteN-1;
		_connection[_setting.siteN-1] = 0;
	*/
}

inline bool SmallWorldNetwork::_isToConnect() {
	return ( _unitDis(_gen) < _setting.p );
}

inline void SmallWorldNetwork::_connect( UnconnSiteIter thisSite ) {
	// "Draw a card" from the top of the library.
	// This simulates the process of random pairing.
	auto top = _unconnectedSites.begin();
	auto thatSite = _findLegalConnection( thisSite, top );
	// Record the bidirectional connection in the map
	_connection[*thisSite] = *thatSite;
	_connection[*thatSite] = *thisSite;
	// erase both ends from the unconnected sites
	_unconnectedSites.erase( thisSite );
	_unconnectedSites.erase( thatSite );
}

SmallWorldNetwork& SmallWorldNetwork::outputMMAStyleConn() {
	std::ofstream fout( _setting.graphFileDir );
	std::map<SiteNumT, SiteNumT> connection (_connection);
	// list[[1]] : site number
	fout << _setting.siteN <<"\n{";
	// list[[2]] : site connections 
	for( SiteNumT i=0; i < _setting.siteN-1; ++i ) {
		fout << i << "<->" << i+1 << ",";
	}
	for( auto i = connection.begin();
		i != connection.end(); ++i ) {
		fout << i->first << "<->" << i->second
		<< ",";
		connection.erase(i->second);
	}
	fout << _setting.siteN-1 << "<->0}"<< std::endl;
	// list[[3]] : working directory
	fout << "\"" <<_workingDir << "\"" << std::endl;
	_outputDone = true;
	if( _setting.mode == SettingT::verbose ) {
		std::cout << "Graph connection saved in: "
		<< _setting.graphFileDir << std::endl;
	}
	return *this;
}

SmallWorldNetwork& SmallWorldNetwork::plotNetwork() {
	if( !_outputDone ) { return *this; }
	auto command = _workingDir + "/MMA_src/runMMA";
	std::system( command.c_str() );
	if( _setting.mode == SettingT::verbose ) {
		std::cout << "Graph plotted with Mathematica 10.0!"
		<< std::endl;
	}
	return *this;
}

inline SmallWorldNetwork::UnconnSiteIter SmallWorldNetwork::_findLegalConnection(
	UnconnSiteIter thisSite,
	UnconnSiteIter iter ) {
	if(( *iter == *thisSite ) 
		|| ( *iter == *thisSite - 1 ||  *iter == *thisSite + 1 )
		|| ( *iter == 0 && *thisSite == _setting.siteN )
		|| ( *iter == _setting.siteN && *thisSite == 0 )) {
		// The first card you draw is :
		//     1. overlapped with the one you want to pair;
		// or neighboring to the one you want to pair :
		//     2. in a general position;
		//     3. in the head/tail position;
		// Just draw the next card!
		return _findLegalConnection( thisSite, ++iter );
	}
	else {
		// No neighboring, no overlapping!
		// Exactly this card.
		return iter;
	}
}

#endif