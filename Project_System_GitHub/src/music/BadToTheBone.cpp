#include "music/BadToTheBone.hpp"

#include <EEPROM.h>
#include "Notes.hpp"

BadToTheBone::BadToTheBone(const int address) :
	address_{address},
	tempo_{149}
{

#ifdef EEPROM_INIT
	int len = 0;

	CREATE(bad_to_the_bone, 1, address_, len,
		{NOTE_G3, 8}, {NOTE_G3, 8}, {NOTE_C4, 8}, {NOTE_G3, 8}, {NOTE_GS3, -32}, {NOTE_AS3, 8}, {NOTE_G3, -16}, {REST, 4}
	)
#endif

}

bool BadToTheBone::next_note(int *note, int *duration, int *tempo, bool restart) const
{
	static chord_t music;
	static int len = 0;
	static int index = 0;

	if (restart)
	{
		EEPROM.get(address_, len);
		index = 0;
	}

	if (len == index)
		return false;

	EEPROM.get(address_ + sizeof(int) + (index * sizeof(chord_t)), music);
	*note = music.note;
	*duration = music.duration;
	*tempo = tempo_;
	index++;

	return true;
}
