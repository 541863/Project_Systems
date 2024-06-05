#include "Car.hpp"

#include <Arduino.h>
#include <PID_v1.h>
#include <math.h>

#include "music/AtDoomGate.hpp"
#include "music/TakeOnMe.hpp"
#include "music/BadToTheBone.hpp"

Car::Car(Accelerometer accelerometer, Button button, Buzzer buzzer, Infrared infrared, Motor motor, SServo servo, UltraSound ultrasound) :
	accelerometer_{accelerometer},
	button_{button},
	buzzer_{buzzer},
	infrared_{infrared},
	motor_{motor},
	servo_{servo},
	ultrasound_{ultrasound}
{
	servo_.init();
}

bool Car::is_button_pressed() const
{
	return button_.pressed();
}

bool Car::play_starting_music(const music_e state) const
{
	static int index = -1;

	if (state == START_PLAYING)
	{
		buzzer_.play(0, 0, 0, true);
		index = 0;
	}
	else if ((state == CONTINUE_PLAYING && index == -1) || state == STOP_PLAYING)
	{
		if (state == STOP_PLAYING)
		{
			index = -1;
			buzzer_.play(0, 0, 0, true);
		}
		return false;
	}

	const int note = bad_to_the_bone.chords[index].note;
	const int duration = bad_to_the_bone.chords[index].duration;
	const int tempo = bad_to_the_bone_tempo;
	bool finished_playing_note = buzzer_.play(note, duration, tempo, false);

	if (finished_playing_note) 
		index += 1;

	if (index == bad_to_the_bone.chord_len)
	{
		index = -1;
		return true;
	}

	return false;
}

void Car::play_driving_music(const music_e state) const
{
	static int index = -1;
	static int chord_index = 0;

	if (state == START_PLAYING)
	{
		buzzer_.play(0, 0, 0, true);
		index = 0;
		chord_index = 0;
	}
	else if ((state == CONTINUE_PLAYING && index == -1) || state == STOP_PLAYING)
	{
		if (state == STOP_PLAYING)
		{
			index = -1;
			buzzer_.play(0, 0, 0, true);
		}
		return;
	}

	const int note = at_doom_gate[index].chords[chord_index].note;
	const int duration = at_doom_gate[index].chords[chord_index].duration;
	const int tempo = at_doom_gate_tempo;
	bool finished_playing_note = buzzer_.play(note, duration, tempo, false);

	if (finished_playing_note) 
		chord_index += 1;

	if (chord_index == at_doom_gate[index].chord_len)
	{
		index += 1;
		chord_index = 0;
	}

	if (index == at_doom_gate_len)
		index = 0;
}

void Car::play_stopping_music(const music_e state) const
{
	static int index = -1;

	if (state == START_PLAYING)
	{
		buzzer_.play(0, 0, 0, true);
		index = 0;
	}
	else if ((state == CONTINUE_PLAYING && index == -1) || state == STOP_PLAYING)
	{
		if (state == STOP_PLAYING)
		{
			index = -1;
			buzzer_.play(0, 0, 0, true);
		}
		return;
	}

	const int note = take_on_me.chords[index].note;
	const int duration = take_on_me.chords[index].duration;
	const int tempo = take_on_me_tempo;
	bool finished_playing_note = buzzer_.play(note, duration, tempo, false);

	if (finished_playing_note) 
		index += 1;

	if (index == take_on_me.chord_len)
		index = 0;
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

void Car::change_angle(const int slight, const int far) const
{
	// TODO Use PID library for better steering.
	/*static double pid_setpoint;
	static double pid_input;
	static double pid_output;
	static PID pid(&pid_input, &pid_output, &pid_setpoint, 2, 5, 1, DIRECT);*/

	const int direction = infrared_.direction();
	const int slight_angle = !!(direction & 0b01000) * -slight + !!(direction & 0b00010) * slight;
	const int far_angle = !!(direction & 0b10000) * -far + !!(direction & 0b00001) * far;

	const int angle = (far_angle + slight_angle) / ((slight_angle != 0 && far_angle != 0) ? 2 : 1);
	servo_.angle(angle);
}

void Car::move(const int speed)
{
	const float pitch_speed = pow(speed, accelerometer_.pitch() + 1);
	if (pitch_speed > 100)
		return;
	motor_.move((const int) pitch_speed);
}

void Car::stop() const
{
	motor_.move(0);
}

void Car::look_straight() const
{
	servo_.angle(0);
}

bool Car::detects_obstacle(const int closest, const int furthest) const
{
	const float distance = ultrasound_.distance();
	const float is_found = distance != NAN;
	return is_found && distance >= closest && distance <= furthest;
}

bool Car::evade_obstacle(const int speed, const int angle, const int time) const
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
