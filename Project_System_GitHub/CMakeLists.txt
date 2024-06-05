cmake_minimum_required(VERSION 3.19)
project(Project_Systems LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
	src/main.cpp
	src/Car.cpp
	src/component/Accelerometer.cpp
	src/component/Button.cpp
	src/component/Buzzer.cpp
	src/component/Infrared.cpp
	src/component/Motor.cpp
	src/component/SServo.cpp
	src/component/UltraSound.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include/)

target_link_arduino_libraries(${PROJECT_NAME} PRIVATE core Wire Servo)
target_enable_arduino_upload(${PROJECT_NAME})
