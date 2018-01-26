#ifndef BROWNIANMOTION_H
#define BROWNIANMOTION_H

#include <random>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <random>
#include <array>
#include <cstdio>

class BrownianMotion {

/**
 * INTRODUCTION:
 * 
 * The essence of single particle Brownian motion
 * is a random Markov chain (RMC), where state
 * space vector:
 * 
 * 		          r(t) 
 * 		x(t) = [        ]
 *   	          v(t) 
 *   	          
 * is evolving according to the recursive rule
 * below:
 * 
 * 		x(t+dt) = F * x(t) + R
 * 		
 * where F is a 2-by-2 matrix and R is a 2-by-1 
 * matrix as below:
 * 
 * 		      1     _c1 * dt
 * 		F = [                ]
 * 		      0       _c1
 *
 *		      _c2 * dt * phi
 * 		R = [                ] 
 * 		        _c2 * phi
 * 		        
 * where _c1 and _c2 are coefficients to be
 * calculated in the constructor, and phi is an
 * independent & random & normal distribution.
 * By computing this RMC with its recursive
 * rule, with pre-evaluated variables _c1 and _c2,
 * it's fast to determine the state space vector after
 * any period of time.
 * 
 */

friend std::ostream& operator<< (std::ostream& os,
	BrownianMotion& bm);

public:

	// type defs
	typedef uint32_t StepNumT;
	typedef std::array<double, 2> VecT;
	typedef struct {
		// number of step to go
		StepNumT stepN = 5000;
		// time interval
		double dt = 1.0;
		// (k_B * T) of the system
		double kT = 1.0;
		// mass of the particle
		double m = 1.0;
		// viscosity of the particle
		double gamma = 1.0;
		// file to save the log
		std::string dir = "temp.log";
		// to plot (with python) or not
		bool toPlot = false;
		void disp() {
			std::cout
			<< "stepN = " << stepN << std::endl
			<< "dt = " << dt << std::endl
			<< "kT = " << kT << std::endl
			<< "m = " << m << std::endl
			<< "gamma = " << gamma << std::endl
			<< "dir = " << dir << std::endl
			<< "toPlot = " << toPlot << std::endl;
		}
	} SettingT;
	typedef struct {
		VecT r { {0.0, 0.0} };
		VecT v { {0.0, 0.0} };
		double t = 0.0;
	} StateT;

	BrownianMotion (SettingT settingIn);
	BrownianMotion ();

	void run ();

protected:
	
	// protected variables
	SettingT setting;
	std::random_device rd;
	std::mt19937 gen;
	std::normal_distribution<> ndist;
	StateT state;
	std::ofstream fout;

	// protected methods
	inline void move ();
	inline void printHead(std::ostream& os);
	void plot();

private:

	double _c1;
	double _c2;

};

std::ostream& operator<< (std::ostream& os,
	BrownianMotion& bm);

#include "BrownianMotion.cpp"

#endif