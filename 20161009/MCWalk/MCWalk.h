#ifndef MONTE_CARLO_WALK_H
#define MONTE_CARLO_WALK_H 

#include <cstdlib> // std::rand()
#include <ctime> // std::time(0) for seeding
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <unistd.h> // for optarg(）

class MCWalk {

friend void parseArgs(int argc, char* argv[], MCWalk& walk);

public:

	struct SettingT {
		/***
		 * The struct which defines the simulatin conditions.
		 * This struct is publicly accessible.
		 */
		/**
		 * Length of each step of partical movement
		 */
		double stepLength = 0.02;

		/**
		 * Number of steps in each simulation.
		 * Each "step" here is described by
		 * the mean value and standard deviation of avgN steps.
		 */
		int stepN = 10000;

		/**
		 * number of step for which steps are demostrated by their statistical properties
		 */
		int avgN = 500;

		/** In Monte Carlo Walk, the thermal energy of the partical is
		 * defined by the temperature T of the system.
		 * "k" here is the Boltzmann constant, with which temperature multiply
		 * gives the charasteristic energy E_c = k*T
		 *
		 * Here we use charasteristic energy to define the activity of the system.
		 */
		double kT = 0.2;
		/**
		 * The Outcome is saved in a text file of following directory:
		 */
		std::string fileDir = "tmp.log";

		/**
		 * "mode" determines the potential function for which you can select.
		 * Not a WELL-BUILT function
		 */
		int mode = 1;

		/** init mode 0: starting at the original point of the xy-plane
		 * init mode 1: starting at a random point in the potential
		 */
		int initMode = 0;

		/**
		 * The maximal radius where partical is allowed to move
		 */
		double bound = 2;

		/**
		 * functional pointer "potential"
		 */
		double (* potential)(double* position) = potential1;
	};

	/**
	 * constructor
	 * both default and specified
	 */ 
	MCWalk() = default;
	MCWalk(SettingT setting);

	/****
	 * start the simulation with this method
	 */ 
	void loop();

	/****
	 * distructor
	 * after simulation, end it by this method.
	 */ 
	~MCWalk();

	void showSetting() const;

private:
	/**
	 * settings are stored here
	 */
	SettingT setting;

	/**
	 * A new method for random gen
	 * @return [description]
	 */
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_real_distribution<> thetaDis;

	/**
	 * These constants are used to defined static methods
	 * of this class, so they have to be of qualifier "const".
	 */
	static const double pi;
	static const bool right;

	char buffer[100];
	double position[2];

	std::ofstream fo;

	inline static double getDistance(double* pos) {
		// return the distance to original point
		double d = std::sqrt(pos[0]*pos[0] + pos[1]*pos[1]);
		// std::cout << ">>> Break Point [getDistance() return]\n";
		return d;
	}

	static double potential1(double* position) {
		double r = getDistance(position);
		double potential = -0.5*std::cos(0.5*pi*r) - std::cos(1.5*pi*r);
		return potential;
	} // Done

	static double potential2(double* position) {
		// Unused
		double r = getDistance(position);
		return r*2;
	} // To be done

	void initPosition();

	inline void tryToMove();

	inline double getDirection();

	inline bool movable(double direction);
	
	inline void move(double direction);
	
	inline void record(int i, double* positions);
	// The 2 methods below is to get the statistic
	// parameters of the averaged avgN data.
	inline double mean(double* xs, int n) const;
	inline double standardDeviation(double* xs, int n) const;
};

#include <MCWalk.cpp>

#endif