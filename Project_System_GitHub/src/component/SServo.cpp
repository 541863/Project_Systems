#include "component/SServo.hpp"

#include <Arduino.h>
#include <PID_v1.h>

SServo::SServo(const int pin) :
	pin_{pin}
{}

void SServo::init()
{
	servo_.attach(pin_);
}

void SServo::angle(int angle)
{
	servo_.write(90 + angle);
}
