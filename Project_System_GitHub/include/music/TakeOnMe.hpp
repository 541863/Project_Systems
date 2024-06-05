#ifndef TAKEONME_MUSIC_HPP
#define TAKEONME_MUSIC_HPP

// TODO use macros
#include "Notes.hpp"

// Take on me
// Robson Couto, 2019
// Code from https://github.com/robsoncouto/arduino-songs/blob/master/takeonme/takeonme.ino
// Score available at https://musescore.com/user/27103612/scores/4834399

const chord_t take_on_me_chords[] = {
	{NOTE_FS5, 8}, {NOTE_FS5, 8},{NOTE_D5, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_E5, 8}, 
	{REST, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_E5, 8}, {NOTE_GS5, 8}, {NOTE_GS5, 8}, {NOTE_A5, 8}, {NOTE_B5, 8},
	{NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_D5, 8}, {REST, 8}, {NOTE_FS5, 8}, 
	{REST, 8}, {NOTE_FS5, 8}, {REST, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8}, {NOTE_E5, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8},
	{NOTE_FS5, 8}, {NOTE_FS5, 8},{NOTE_D5, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_E5, 8}, 
	{REST, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_E5, 8}, {NOTE_GS5, 8}, {NOTE_GS5, 8}, {NOTE_A5, 8}, {NOTE_B5, 8},
	{NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_D5, 8}, {REST, 8}, {NOTE_FS5, 8}, 
	{REST, 8}, {NOTE_FS5, 8}, {REST, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8}, {NOTE_E5, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8},
	{NOTE_FS5, 8}, {NOTE_FS5, 8},{NOTE_D5, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_B4, 8}, {REST, 8}, {NOTE_E5, 8}, 
	{REST, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_E5, 8}, {NOTE_GS5, 8}, {NOTE_GS5, 8}, {NOTE_A5, 8}, {NOTE_B5, 8},
	{NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_A5, 8}, {NOTE_E5, 8}, {REST, 8}, {NOTE_D5, 8}, {REST, 8}, {NOTE_FS5, 8}, 
	{REST, 8}, {NOTE_FS5, 8}, {REST, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8}, {NOTE_E5, 8}, {NOTE_FS5, 8}, {NOTE_E5, 8}
};
const int take_on_me_chords_len = sizeof(take_on_me_chords) / sizeof(take_on_me_chords[0]);

const melody_t take_on_me = {take_on_me_chords, take_on_me_chords_len};
const int take_on_me_tempo = 140;

#endif // TAKEONME_MUSIC_HPP
