#include "PPID.hpp"

PPID::PPID(const double kp, const double ki, const double kd) :
	setpoint_{0},
	input_{0},
	output_{0},
	pid_{&input_, &output_, &setpoint_, kp, ki, kd, DIRECT}
{
	pid_.SetMode(AUTOMATIC);
}

void PPID::set(const double far)
{
	pid_.SetOutputLimits(-far, far);
}

double PPID::compute(const double error)
{
	input_ = error;
	pid_.Compute();
	return output_;
}
