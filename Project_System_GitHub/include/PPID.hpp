#ifndef PPID_HPP
#define PPID_HPP

#include <PID_v1.h>

class PPID
{
	public:
		PPID(const double kp, const double ki, const double kd);
		double compute(const double input);
	
	private:
		double setpoint_;
		double input_;
		double output_;

		PID pid_;
};

#endif // PPID_HPP
