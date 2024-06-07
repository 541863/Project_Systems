#include "music/BadToTheBone.hpp"

#include "Notes.hpp"

BadToTheBone::BadToTheBone() :
	tempo_{149}
{}

bool BadToTheBone::next_note(int *note, int *duration, int *tempo, bool restart) const
{
	static chord_t music[] = {{NOTE_G3, 8}, {NOTE_G3, 8}, {NOTE_C4, 8}, {NOTE_G3, 8}, {NOTE_GS3, -32}, {NOTE_AS3, 8}, {NOTE_G3, -16}, {REST, 4}};
	static int len = sizeof(music) / sizeof(music[0]);
	static int index = 0;

	if (restart)
		index = 0;

	if (len == index)
		return false;

	*note = music[index].note;
	*duration = music[index].duration;
	*tempo = tempo_;
	index++;

	return true;
}
