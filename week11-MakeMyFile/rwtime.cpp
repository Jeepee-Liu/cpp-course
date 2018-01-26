#include <randomWalk.h>
#include <iostream>

class RandomWalkTime : public RandomWalk {

public:
	
	RandomWalkTime() : RandomWalk() {
		std::cout << "RandomWalkTime initialized" << std::endl;
		setting.mode = SettingT::oneStep;
	}

	// OVERLOAD, Not an override!
	void run (int time) {
		// Declarations and initializations
		std::vector<double> distVec;
		fout << std::setprecision(8);
		double distance;
/*		std::cout << std::setw(8)
		<< "Step" << std::setw(16)
		<< "Distance" << std::endl;*/

		// test 500 loops
		for (int i=0; i < 1000; ++i) {
			vec[0] = 0;
			vec[1] = 0;
			for (int t=0; t < time; ++t) {
				distance = moveStep();
				// print to file
				/*
				fout << std::setw(8)
				<< stepCount << std::setw(16)
				<< distVec.back() << std::endl;
				*/
			}
			distVec.push_back(distance);
			std::cout << "[ trial #" << std::setw(4)
			<< std::left << i << " ]" 
			<< " Distance from origin: " << std::setw(8)
			<< distance << std::endl;
		}

		// calculate average 
		double sum = 0;
		for (auto& dist : distVec) {
			sum += dist;
		}
		double avgDist = (double) sum / 1000.0;
		// Output
		std::cout
		<< "Simulation completed!" << std::endl
		<< "Average distance after "
		<< time << " steps is: " << avgDist << std::endl;

	}

};

int main () {
	// std::cout << "RWDist start" << std::endl;
	RandomWalkTime rwTime;
	std::cout << "START 1" << std::endl;
	rwTime.run(110);
	return 0;
}
