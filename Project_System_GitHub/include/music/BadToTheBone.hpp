#ifndef BADTOTHEBONE_MUSIC_HPP
#define BADTOTHEBONE_MUSIC_HPP

class BadToTheBone
{
	public:
		BadToTheBone();
		bool next_note(int *note, int *duration, int *tempo, bool restart) const;
	
	private:
		const int tempo_;
};

#endif // BADTOTHEBONE_MUSIC_HPP
