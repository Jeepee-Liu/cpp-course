#include <iostream>
#include <cstdlib>
using namespace std;

int recursionGcd(int a, int b) {
	if(a == b) {
		return a;
	}
	else if(a < b){
		return recursionGcd(a,b-a);
	}
	else {
		return recursionGcd(b,a-b);
	}
}

int main(int argc, const char *argv[]) {
	int x1 = atoi(argv[1]);
	int x2 = atoi(argv[2]);
	int gcdRes = recursionGcd(x1, x2);
	cout << "The GCD of " << x1 << " and " << x2
	<< " is: " << gcdRes << endl;
}