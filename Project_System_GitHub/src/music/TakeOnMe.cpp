#include "music/TakeOnMe.hpp"

#include "Notes.hpp"

// Take on me
// Robson Couto, 2019
// Code from https://github.com/robsoncouto/arduino-songs/blob/master/takeonme/takeonme.ino
// Score available at https://musescore.com/user/27103612/scores/4834399
TakeOnMe::TakeOnMe() :
	tempo_{140}
{}

void TakeOnMe::next_note(int *note, int *duration, int *tempo, bool restart) const
{
	static chord_t music[] =
	{
		{NOTE_FS5, 8}, {NOTE_FS5, 8}, {NOTE_D5, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_E5, 8},
		{REST, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_E5, 8}, {NOTE_GS5, 8}, {NOTE_GS5, 8}, {NOTE_A5, 8}, {NOTE_B5, 8},
		{NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_D5, 8}, {REST, 8}, {NOTE_FS5, 8},
		{REST, 8}, {NOTE_FS5, 8}, {REST, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8}, {NOTE_E5, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8}
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
