#include "component/Accelerometer.hpp"

#include <Arduino.h>
#include <Wire.h>
#include <MPU9250_asukiaaa.h>

Accelerometer::Accelerometer(const int SCL, const int SDA)
{
	(void) SCL;
	(void) SDA;

	Wire.begin();
	sensor_.setWire(&Wire);
	sensor_.beginAccel();
}

float Accelerometer::pitch()
{
	sensor_.accelUpdate();
	float max_axis = sensor_.accelX() * -1 + 1;
	return max_axis;
}
