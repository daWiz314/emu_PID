#ifndef PID_H
#define PID_H

#include <iostream>

class PID {
	private:
	float Kp, Ki, Kd;			// Our gain variables
	float cur_error, old_error; // Errors for math
	float inte_error;			// Integral Error
	const float SP;				// SP = Set Point (Goal)
	float PV = 0.0;				// PV = Process Variable (Current)
	int time;					// Times we have run
	const int time_between = 1;	// This is the time between steps, DEFAULT 1

	float calc_prop_term();		// Calculates the proportional term
	float calc_inte_term();		// Calculates the integral term
	float calc_deri_term();		// Calculates the derivative term

	float control_output();		// Calculates and returns the full control output

	public:
	PID(float _SP, float _Kp, float _Ki, float _Kd) : SP(_SP), Kp(_Kp), Ki(_Ki), Kd(_Kd) {};


	void run();					// Runs the program

};



#endif
