#include "music/GreenHillZone.hpp"

#include "Notes.hpp"

// Green Hill Zone - Sonic the Hedgehog
// Robson Couto, 2019
// Code from https://github.com/robsoncouto/arduino-songs/blob/master/greenhill/greenhill.ino
// Score available at https://musescore.com/user/248346/scores/461661
GreenHillZone::GreenHillZone() :
	tempo_{240}
{}

void GreenHillZone::next_note(int *note, int *duration, int *tempo, bool restart) const
{
	static chord_t music[] =
	{
		{REST,2}, {NOTE_D5,8}, {NOTE_B4,4}, {NOTE_D5,8}, 
		{NOTE_CS5,4}, {NOTE_D5,8}, {NOTE_CS5,4}, {NOTE_A4,2}, 
		{REST,8}, {NOTE_A4,8}, {NOTE_FS5,8}, {NOTE_E5,4}, {NOTE_D5,8},
		{NOTE_CS5,4}, {NOTE_D5,8}, {NOTE_CS5,4}, {NOTE_A4,2}, 
		{REST,4}, {NOTE_D5,8}, {NOTE_B4,4}, {NOTE_D5,8},
		{NOTE_CS5,4}, {NOTE_D5,8}, {NOTE_CS5,4}, {NOTE_A4,2}, 

		{REST,8}, {NOTE_B4,8}, {NOTE_B4,8}, {NOTE_G4,4}, {NOTE_B4,8}, 
		{NOTE_A4,4}, {NOTE_B4,8}, {NOTE_A4,4}, {NOTE_D4,2},
		{REST,4}, {NOTE_D5,8}, {NOTE_B4,4}, {NOTE_D5,8},
		{NOTE_CS5,4}, {NOTE_D5,8}, {NOTE_CS5,4}, {NOTE_A4,2}, 
		{REST,8}, {NOTE_A4,8}, {NOTE_FS5,8}, {NOTE_E5,4}, {NOTE_D5,8},
		{NOTE_CS5,4}, {NOTE_D5,8}, {NOTE_CS5,4}, {NOTE_A4,2}, 

		{REST,4}, {NOTE_D5,8}, {NOTE_B4,4}, {NOTE_D5,8}, 
		{NOTE_CS5,4}, {NOTE_D5,8}, {NOTE_CS5,4}, {NOTE_A4,2}, 
		{REST,8}, {NOTE_B4,8}, {NOTE_B4,8}, {NOTE_G4,4}, {NOTE_B4,8},
		{NOTE_A4,4}, {NOTE_B4,8}, {NOTE_A4,4}, {NOTE_D4,8}, {NOTE_D4,8}, {NOTE_FS4,8},
		{NOTE_E4,-1},
		{REST,8}, {NOTE_D4,8}, {NOTE_E4,8}, {NOTE_FS4,-1},

		{REST,8}, {NOTE_D4,8}, {NOTE_D4,8}, {NOTE_FS4,8}, {NOTE_F4,-1}, 
		{REST,8}, {NOTE_D4,8}, {NOTE_F4,8}, {NOTE_E4,-1}
	};
	static int len = sizeof(music) / sizeof(music[0]);
	static int index = 0;

	if (restart || len == index)
		index = 0;

	*note = music[index].note;
	*duration = music[index].duration;
	*tempo = tempo_;
	index++;
}
