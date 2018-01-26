#ifndef ISING_SQUARE
#define ISING_SQUARE

#include <setting.hpp>

#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <deque>
#include <utility>
#include <cmath>
#include <map>
#include <algorithm> // std::shuffle()

#define BRA std::cerr << "\n" << std::string(80,'#') << "\n"
#define KET << "\n" << std::string(80,'#') << "\n" << std::endl;


class IsingSquare {
	/**
	 * 2D Ising model on a square lattice
	 */
public:

	typedef std::deque< std::pair<int, int> > FlipQueueT;

	IsingSquare (int argc, char* const argv[]);
	~IsingSquare ();
	void simulate ();

private:

	/* private member variables */

	// Settings of the simulation
	SettingT _setting;
	double _precision;

	// random devices for MC simu
	std::random_device _rd;
	std::mt19937 _gen;
	std::uniform_int_distribution<> _boolRand;
	std::uniform_real_distribution<> _unitRand;

	// file to save
	std::ofstream fout;
	const int _width;

	// the queue of spins to flip.
	FlipQueueT _flipQueue;

	// a 2-d boolean array storing spins
	bool** _spin;

	// A map where you can get the chance
	// of flip without calculation
	std::map<int, double> _flipProb;

	// a double-end queue for shuffling
	std::deque<int> xs, ys;

	// a vactor storing averaged magnetization
	// used for judge precision
	std::deque<double> avgMagnDeq;

	/* private member functions */

	// initializing
	inline bool _generateOneSpin ();
	inline void _tryToFlipAll ();
	inline void _generateFlipQueue ();
	inline void _tryToFlipThis (FlipQueueT::iterator& pos);
	inline int _twoSpinEnergy (const int& x1,
		const int& y1, const int& x2, const int& y2) const;
	inline double _calcMagnetization () const;
	inline bool _statisticsPrintln (int bigStep, double* ms, std::ostream& fout);
	// inline double _diff(double* ms) const;
	inline double _diff();

};

#include "IsingSquare.cpp"

#undef BRA
#undef KET

#endif