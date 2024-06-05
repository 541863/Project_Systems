#ifndef COMPONENT_ACCELEROMETER_HPP
#define COMPONENT_ACCELEROMETER_HPP

#include <MPU9250_asukiaaa.h>

class Accelerometer
{
	public:
		Accelerometer(const int SCL, const int SDA);

		float pitch();
	
	private:
		MPU9250_asukiaaa sensor_;
};

#endif // COMPONENT_ACCELEROMETER_HPP
