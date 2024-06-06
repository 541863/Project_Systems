#ifndef PPID_HPP
#define PPID_HPP

#include <PID_v1.h>

class PPID
{
	public:
		PPID(const double kp, const double ki, const double kd);
		void set(const double far);
		double compute(const double error);
	
	private:
		double setpoint_;
		double input_;
		double output_;

		PID pid_;
};

#endif // PPID_HPP
