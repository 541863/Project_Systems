#include "PPID.hpp"

PPID::PPID(const double kp, const double ki, const double kd) :
	setpoint_{0},
	input_{0},
	output_{0},
	pid_{&input_, &output_, &setpoint_, kp, ki, kd, DIRECT}
{
	pid_.SetMode(AUTOMATIC);
	pid_.SetOutputLimits(-30, 30);
}

double PPID::compute(const double input)
{
	input_ = input;
	pid_.Compute();
	return output_;
}
