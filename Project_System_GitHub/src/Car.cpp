#include "Car.hpp"

#include <Arduino.h>
#include <math.h>

#include "music/BadToTheBone.hpp"
#include "music/TakeOnMe.hpp"

Car::Car(Accelerometer accelerometer, Button button, Buzzer buzzer, Infrared infrared, Motor motor, SServo servo, UltraSound ultrasound) :
	accelerometer_{accelerometer},
	button_{button},
	buzzer_{buzzer},
	infrared_{infrared},
	motor_{motor},
	servo_{servo},
	ultrasound_{ultrasound},

	pid_{1.0, 0.05, 0.25}
{
	servo_.init();
}

bool Car::is_button_pressed() const
{
	return button_.pressed();
}

bool Car::play_starting_music(const music_e state) const
{
	static BadToTheBone music{0};
	static bool is_next_note = false;

	static int note = 0;
	static int duration = 0;
	static int tempo = 0;

	if (state == START_PLAYING)
	{
		buzzer_.play(0, 0, 0, true);
		is_next_note = music.next_note(&note, &duration, &tempo, true);
	}
	else if ((state == CONTINUE_PLAYING && !is_next_note) || state == STOP_PLAYING)
	{
		if (state == STOP_PLAYING)
		{
			buzzer_.play(0, 0, 0, true);
			is_next_note = false;
		}
		return false;
	}

	bool done_playing_note = buzzer_.play(note, duration, tempo, false);
	if (done_playing_note)
		is_next_note = music.next_note(&note, &duration, &tempo, false);

	return !is_next_note;
}

void Car::play_stopping_music(const music_e state) const
{
	static TakeOnMe music{(int) (50)};
	static bool is_next_note = false;

	static int note = 0;
	static int duration = 0;
	static int tempo = 0;

	if (state == START_PLAYING)
	{
		buzzer_.play(0, 0, 0, true);
		is_next_note = true;
		music.next_note(&note, &duration, &tempo, true);
	}
	else if ((state == CONTINUE_PLAYING && !is_next_note) || state == STOP_PLAYING)
	{
		if (state == STOP_PLAYING)
		{
			buzzer_.play(0, 0, 0, true);
			is_next_note = false;
		}
		return;
	}

	bool done_playing_note = buzzer_.play(note, duration, tempo, false);
	if (done_playing_note)
		music.next_note(&note, &duration, &tempo, false);
}

int Car::is_only_middle_on() const
{
	return infrared_.direction() == 0b00100;
}

bool Car::is_all_on() const
{
	return infrared_.direction() == 0b11111;
}

bool Car::is_any_on() const
{
	return infrared_.direction() != 0;
}

void Car::change_angle(const int slight, const int far)
{
	const int direction = infrared_.direction();
	const int slight_angle = !!(direction & 0b01000) * slight + !!(direction & 0b00010) * -slight;
	const int far_angle = !!(direction & 0b10000) * far + !!(direction & 0b00001) * -far;

	const int raw_angle = (far_angle + slight_angle) / ((slight_angle != 0 && far_angle != 0) ? 2 : 1);
	const int angle = pid_.compute(raw_angle); // TODO Fix PID giving negative value as setting point.

	servo_.angle(angle);
}

void Car::move(const int speed, const float out_low, const float out_high)
{
	// TODO
	/*const int pitch_speed = pow(speed, accelerometer_.pitch(out_low, out_high));
	if (pitch_speed > 100)
		return;*/
	motor_.move(/*pitch_*/speed);
}

void Car::stop() const
{
	motor_.move(0);
}

void Car::look_straight()
{
	servo_.angle(0);
}

bool Car::detects_obstacle(const int closest, const int furthest) const
{
	const float distance = ultrasound_.distance();
	const float is_found = distance != NAN;
	return is_found && distance >= closest && distance <= furthest;
}

bool Car::evade_obstacle(const int angle, const int time)
{
	static bool is_evading = false;
	static unsigned long prev_mil = 0;

	if (!is_evading)
	{
		is_evading = true;
		prev_mil = millis();
		servo_.angle(-angle);
	}

	unsigned long curr_mil = millis();

	if (is_evading && curr_mil - prev_mil > (unsigned long) time)
	{
		servo_.angle(angle);
		is_evading = false;
	}
	
	return is_evading;
}
