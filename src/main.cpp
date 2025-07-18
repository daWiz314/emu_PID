#include <iostream>

#include "PID.h"					// Our PID Class header file

using namespace std;				// I am lazy and don't want to type out STD
									// I also don't have to worry about other namespaces in this program

int main() {
	cout << "Hello World" << endl;

	PID pid(100, 1, 0.1, 0.5);
	pid.run();

	return 0;

}





