#include "music/TakeOnMe.hpp"

#include <EEPROM.h>
#include "Notes.hpp"

// Take on me
// Robson Couto, 2019
// Code from https://github.com/robsoncouto/arduino-songs/blob/master/takeonme/takeonme.ino
// Score available at https://musescore.com/user/27103612/scores/4834399
TakeOnMe::TakeOnMe(const int address) :
	address_{address},
	tempo_{140}
{

#ifdef EEPROM_INIT
	int len = 0;

	CREATE(take_on_me, 1, address_, len,
		{NOTE_FS5, 8}, {NOTE_FS5, 8}, {NOTE_D5, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_E5, 8},
		{REST, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_E5, 8}, {NOTE_GS5, 8}, {NOTE_GS5, 8}, {NOTE_A5, 8}, {NOTE_B5, 8},
		{NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_D5, 8}, {REST, 8}, {NOTE_FS5, 8},
		{REST, 8}, {NOTE_FS5, 8}, {REST, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8}, {NOTE_E5, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8}
	)
#endif

}

void TakeOnMe::next_note(int *note, int *duration, int *tempo, bool restart) const
{
	static chord_t music;
	static int len = 0;
	static int index = 0;

	if (restart || len == index)
	{
		EEPROM.get(address_, len);
		index = 0;
	}

	EEPROM.get(address_ + sizeof(int) + (index * sizeof(chord_t)), music);
	*note = music.note;
	*duration = music.duration;
	*tempo = tempo_;
	index++;
}
