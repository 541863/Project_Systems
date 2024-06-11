#ifndef GREENHILLZONE_MUSIC_HPP
#define GREENHILLZONE_MUSIC_HPP

class GreenHillZone
{
	public:
		GreenHillZone();
		void next_note(int *note, int *duration, int *tempo, bool restart) const;

	private:
		const int tempo_;
};

#endif // GREENHILLZONE_MUSIC_HPP
