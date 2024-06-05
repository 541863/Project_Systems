#ifndef BADTOTHEBONE_MUSIC_HPP
#define BADTOTHEBONE_MUSIC_HPP

// TODO use macros
#include "Notes.hpp"

// Bad to the Bone

const chord_t bad_to_the_bone_chords[] = {{NOTE_G3, 8}, {NOTE_G3, 8}, {NOTE_C4, 8}, {NOTE_G3, 8}, {NOTE_GS3, -32}, {NOTE_AS3, 8}, {NOTE_G3, -16}, {REST, 4}};
const int bad_to_the_bone_len = sizeof(bad_to_the_bone_chords) / sizeof(bad_to_the_bone_chords[0]);

const melody_t bad_to_the_bone = {bad_to_the_bone_chords, bad_to_the_bone_len};
const int bad_to_the_bone_tempo = 149;

#endif // BADTOTHEBONE_MUSIC_HPP
