#include <ncurses.h>				// Switching out displaying out to NCurses

#include "PID.h"					// Our PID Class header file

int main() {

	PID pid(100, .5, .1, .1);

	pid.run();

	return 0;

}





