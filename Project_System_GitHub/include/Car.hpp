#ifndef CAR_HPP
#define CAR_HPP

#include "component/Accelerometer.hpp"
#include "component/Button.hpp"
#include "component/Buzzer.hpp"
#include "component/Infrared.hpp"
#include "component/Motor.hpp"
#include "component/SServo.hpp"
#include "component/UltraSound.hpp"

#include "Notes.hpp"

class Car
{
	public:
		Car(Accelerometer accelerometer, Button button, Buzzer buzzer, Infrared infrared, Motor motor, SServo servo, UltraSound ultrasoundo);
		bool is_button_pressed() const;
		bool play_starting_music(const music_e state) const;
		void play_stopping_music(const music_e state) const;
		bool is_only_middle_on() const;
		bool is_all_on() const;
		bool is_any_on() const;
		void change_angle(const int slight, const int far);
		void move(const int speed);
		void stop() const;
		void look_straight();
		bool detects_obstacle(const int closest, const int furthest) const;
		bool evade_obstacle(const int angle, const int time);

	private:
		Accelerometer accelerometer_;
		Button button_;
		Buzzer buzzer_;
		Infrared infrared_;
		Motor motor_;
		SServo servo_;
		UltraSound ultrasound_;
};

#endif // CAR_HPP
