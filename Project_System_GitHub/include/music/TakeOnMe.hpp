#ifndef TAKEONME_MUSIC_HPP
#define TAKEONME_MUSIC_HPP

class TakeOnMe
{
	public:
		TakeOnMe(const int address);
		void next_note(int *note, int *duration, int *tempo, bool restart) const;

	private:
		const int address_;
		const int tempo_;
};

#endif // TAKEONME_MUSIC_HPP
