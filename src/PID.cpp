#include "PID.h"



float PID::calc_prop_term() {
	// Proportional Term Formula
	// Kp * e(t)
	// Error calculation
	// e_t = SP - PV_t
	if (this->time == 0) {
		this->old_error = 0;
	} else {
		this->old_error = this->cur_error;
	}	
	this->cur_error = this->SP - this->PV;

	return (float) this->Kp * this->cur_error;
}

float PID::calc_inte_term() {
	// Integral Term Formula
	// Ki * (integral symbol)e(t)*dt
	// Integral Error Formula
	// Previous steps error integral + (cur_error * (math delta) t)
	
	// Integral of error:
	this->inte_error += this->cur_error * this->time_between;

	// Actual integral term
	return (float) this->Ki * this->inte_error;

}


float PID::calc_deri_term() {
	// Derivative Term Formula
	// Kd * (de(t)/dt)
	
	//Derivative of error Formula
	// de(t)/dt = (cur_error - old_error) / (math delta) t
	
	return (float) this->Kd * ((this->cur_error - this->old_error) / this->time_between);
}


float PID::control_output() {
	// Formula
	// Proportional term + integral term + derivative term
	
	return this->calc_prop_term() + this->calc_inte_term() + this->calc_deri_term();
}

void PID::run() {
	// This will run the PID until it reaches the goal
	
	this->time = 0;
	
	while(true) {
		
		std::cout << "Times Run: " << this->time << std::endl;
		std::cout << "PV: " << this->PV << std::endl;
		std::cout << "SP: " << this->SP << std::endl;
		if (this->PV >= this->SP) {
			break;
		}
		float temp = this->control_output();
		std::cout << "Returned calc: " << temp << std::endl;
		this->PV += (temp/10);
		
		this->time++;
	}
}














