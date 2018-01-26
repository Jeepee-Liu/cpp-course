#include <randomWalk.h>
#include <iostream>
#include <vector>

class RandomWalkDist : public RandomWalk {

public:
	
	RandomWalkDist() : RandomWalk() {
		std::cout << "RandomWalkDist initialized" << std::endl;
		setting.mode = SettingT::oneStep;
	}

	// OVERLOAD, Not an override!
	void run (double boundaryDist) {
		// Declarations and initializations
		int stepCount = 0;
		std::vector<double> distVec;
		std::vector<int> stepCntVec;
		distVec.push_back(0.0);
		MyVector zeroVec;
		zeroVec[0] = 0;
		zeroVec[1] = 0;

		fout << std::setprecision(8);
		std::cout << std::setw(8)
		<< "Step" << std::setw(16)
		<< "Distance" << std::endl;
		// test 500 loops
		for (int i=0; i < 1000; ++i) {
			stepCount = 0;
			distVec.clear();
			vec = zeroVec;
			while (distVec.back() < boundaryDist) {
				distVec.push_back (moveStep());
				stepCount ++;
				// print to file
				/*
				fout << std::setw(8)
				<< stepCount << std::setw(16)
				<< distVec.back() << std::endl;
				*/
			}
			std::cout << "[ trial #" << std::setw(4)
			<< std::left << i << " ]" 
			<< " Step Num: " << std::setw(8)
			<< stepCount << std::endl;
			stepCntVec.push_back(stepCount);
		}

		// calculate average 
		int sum = 0;
		double avgStepNum;
		for (auto& eachCnt : stepCntVec) {
			sum += eachCnt;
		}
		avgStepNum = (double) sum / (double) stepCntVec.size();


		// Output
		std::cout
		<< "Simulation completed!" << std::endl
		<< "Average number of steps to reach "
		<< boundaryDist << " is: " << avgStepNum << std::endl;
	}

};

int main () {
	// std::cout << "RWDist start" << std::endl;
	RandomWalkDist rwdist;
	std::cout << "START 1" << std::endl;
	rwdist.run(10.0);
	return 0;
}
