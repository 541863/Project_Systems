#ifndef ATDOOMGATE_MUSIC_HPP
#define ATDOOMGATE_MUSIC_HPP

// TODO Split music sheet in two for better efficency.
// TODO Why are the macros failing?
// TODO Finish the rest.

#define NAME at_doom_gate

#include "Notes.hpp"

CREATE(1,
	{NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_E3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_D3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8},
	{NOTE_C3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_AS2, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_B2, 8}, {NOTE_C3, 8},
	{NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_E3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_D3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8},
	{NOTE_C3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_AS2, -2}
)

CREATE(2,
	{NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_E3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_D3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8},
	{NOTE_C3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_AS2, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_B2, 8}, {NOTE_C3, 8},
	{NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_E3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_D3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8},
	{NOTE_FS3, -16}, {NOTE_D3, -16}, {NOTE_B2, -16}, {NOTE_A3, -16}, {NOTE_FS3, -16}, {NOTE_B2, -16}, {NOTE_D3, -16}, {NOTE_FS3, -16}, {NOTE_A3, -16}, {NOTE_FS3, -16}, {NOTE_D3, -16}, {NOTE_B2, -16}
)

CREATE(3,
	{NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_E3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_D3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8},
	{NOTE_C3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_AS2, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_B2, 8}, {NOTE_C3, 8},
	{NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_E3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_D3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8},
	{NOTE_B3, -16}, {NOTE_G3, -16}, {NOTE_E3, -16}, {NOTE_G3, -16}, {NOTE_B3, -16}, {NOTE_E4, -16}, {NOTE_G3, -16}, {NOTE_B3, -16}, {NOTE_E4, -16}, {NOTE_B3, -16}, {NOTE_G4, -16}, {NOTE_B4, -16}
)

CREATE(4,
	{NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_A3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_G3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8},
	{NOTE_F3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_DS3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_E3, 8}, {NOTE_F3, 8},
	{NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_A3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_G3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8},
	{NOTE_F3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_DS3, -2}
)

CREATE(5,
	{NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_A3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_G3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8},
	{NOTE_F3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_DS3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_E3, 8}, {NOTE_F3, 8},
	{NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_A3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8}, {NOTE_G3, 8}, {NOTE_A2, 8}, {NOTE_A2, 8},
	{NOTE_A3, -16}, {NOTE_F3, -16}, {NOTE_D3, -16}, {NOTE_A3, -16}, {NOTE_F3, -16}, {NOTE_D3, -16}, {NOTE_C4, -16}, {NOTE_A3, -16}, {NOTE_F3, -16}, {NOTE_A3, -16}, {NOTE_F3, -16}, {NOTE_D3, -16},
)

CREATE(6,
	{NOTE_CS3, 8}, {NOTE_CS3, 8}, {NOTE_CS4, 8}, {NOTE_CS3, 8}, {NOTE_CS3, 8}, {NOTE_B3, 8}, {NOTE_CS3, 8}, {NOTE_CS3, 8},
	{NOTE_A3, 8}, {NOTE_CS3, 8}, {NOTE_CS3, 8}, {NOTE_G3, 8}, {NOTE_CS3, 8}, {NOTE_CS3, 8}, {NOTE_GS3, 8}, {NOTE_A3, 8},
	{NOTE_B2, 8}, {NOTE_B2, 8}, {NOTE_B3, 8}, {NOTE_B2, 8}, {NOTE_B2, 8}, {NOTE_A3, 8}, {NOTE_B2, 8}, {NOTE_B2, 8},
	{NOTE_G3, 8}, {NOTE_B2, 8}, {NOTE_B2, 8}, {NOTE_F3, -2},
)

CREATE(7,
	{NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_E3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_D3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8},
	{NOTE_C3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_AS2, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_B2, 8}, {NOTE_C3, 8},
	{NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_E3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8}, {NOTE_D3, 8}, {NOTE_E2, 8}, {NOTE_E2, 8},
	{NOTE_FS3, -16}, {NOTE_DS3, -16}, {NOTE_B2, -16}, {NOTE_FS3, -16}, {NOTE_DS3, -16}, {NOTE_B2, -16}, {NOTE_G3, -16}, {NOTE_D3, -16}, {NOTE_B2, -16}, {NOTE_DS4, -16}, {NOTE_DS3, -16}, {NOTE_B2, -16},
)

// At Doom's Gate (E1M1)
// Robson Couto, 2019
// Code from https://github.com/robsoncouto/arduino-songs/blob/master/doom/doom.ino
// Score available at https://musescore.com/pieridot/doom
const melody_t NAME[] =
{
	GET(1),
	GET(1),
	GET(1),
	GET(2),
	GET(1),
	GET(3),
	GET(4),
	GET(5),
	GET(1),
	GET(1),
	GET(6),
	GET(3),
	GET(1),
	GET(7)
};
const int /*VAR(len)*/at_doom_gate_len = sizeof(NAME) / sizeof(NAME[0]);
const int /*VAR(tempo)*/at_doom_gate_tempo = 225;

#endif // ATDOOMGATE_MUSIC_HPP
