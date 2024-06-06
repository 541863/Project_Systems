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

float Accelerometer::pitch(float out_low, float out_high)
{
	sensor_.accelUpdate();

	auto fmap = [](float value, float from_low, float from_high, float to_low, float to_high) -> float
	{return ((int) (((value - from_low) * (to_high - to_low) / (from_high - from_low) + to_low) * 100) / 100.0);};

	const float y_axis = sensor_.accelY() + 1;
	const float y_map_down = fmap(y_axis, 0.0, 2.0, out_low, out_high);
	const float y_map_up = fmap(y_map_down, out_low, out_high, 0.0, 2.0);
	return y_map_up;
}
