#include "Car.hpp"

void setup()
{}

void loop()
{
	static Car car
	{
		Accelerometer(A5, A4),
		Button(8),
		Buzzer(7),
		Infrared(9, 10, 11, 12, 13),
		Motor(5, 4),
		SServo(6),
		UltraSound(3, 2)
	};
	static bool running = false;
	static bool music = false;
	static bool evade = false;

	if (car.is_button_pressed() || (car.is_button_pressed() && music))
	{
		car.play_stopping_music(STOP_PLAYING);

		if (music)
		{
			music = false;
			return;
		}
		
		running = !running;

		if (!running)
			return;

#ifndef STOP
		car.play_starting_music(START_PLAYING);
		while (!car.play_starting_music(CONTINUE_PLAYING));
		car.play_starting_music(STOP_PLAYING);
#endif
	}

	car.play_starting_music(CONTINUE_PLAYING);
	car.play_stopping_music(CONTINUE_PLAYING);

	if (!running)
	{
		car.stop();
		car.look_straight();
		return;
	}

	if (car.is_all_on())
	{
		car.stop();
		car.look_straight();
#ifndef STOP
		car.play_stopping_music(START_PLAYING);
#endif

		running = false;
		music = true;
		return;
	}

	car.move(30);

	if (car.detects_obstacle(45, 50) || evade)
	{
		evade = car.evade_obstacle(30, 800);
		return;
	}

	if (car.is_only_middle_on())
		car.look_straight();
	else if (car.is_any_on())
		car.change_angle(11, 30);
}
