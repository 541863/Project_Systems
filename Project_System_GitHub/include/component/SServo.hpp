#ifndef COMPONENT_SSERVO_HPP
#define COMPONENT_SSERVO_HPP

#include <Servo.h>

class SServo
{
	public:
		SServo(const int pin);
		void init();
		void angle(int angle);
	
	private:
		const int pin_;
		Servo servo_;
};

#endif // COMPONENT_SSERVO_HPP
