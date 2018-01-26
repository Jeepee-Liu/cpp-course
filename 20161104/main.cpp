#include "dSort.h"
#include <string>

const std::string fileIn("./seq.txt");

int main() {
	// method 1 (slow, ~4.4sec)
	// DSort dictionary(fileIn);
	// dictionary.classify().show();
	// method 2 (fast, ~0.7sec)
	DEncode encodedDict(fileIn);
	encodedDict.classify().show();
	return 0;
}
