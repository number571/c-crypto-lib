#pragma once

#include <stdint.h>
#include "utils/types/integer.h"

/*
	A = ('A' .. 'O') * ('A' .. 'O') =
	    A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
	A 000 001 002 003 004 005 006 007 008 009 010 011 012 013 014 
	B 015 016 017 018 019 020 021 022 023 024 025 026 027 028 029 
	C 030 031 032 033 034 035 036 037 038 039 040 041 042 043 044 
	D 045 046 047 048 049 050 051 052 053 054 055 056 057 058 059 
	E 060 061 062 063 064 065 066 067 068 069 070 071 072 073 074 
	F 075 076 077 078 079 080 081 082 083 084 085 086 087 088 089 
	G 090 091 092 093 094 095 096 097 098 099 100 101 102 103 104 
	H 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 
	I 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 
	J 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 
	K 150 151 152 153 154 155 156 157 158 159 160 161 162 163 164 
	L 165 166 167 168 169 170 171 172 173 174 175 176 177 178 179 
	M 180 181 182 183 184 185 186 187 188 189 190 191 192 193 194 
	N 195 196 197 198 199 200 201 202 203 204 205 206 207 208 209 
	O 210 211 212 213 214 215 216 217 218 219 220 221 222 223 224
	M = "HELLO"
	E(M) = 
		I. 	IF ("HELLO" mod 2) = 1: APPEND 'O'
			(
				"HELLOO"
			)
		II. "HE" + "LL" + "OO"
		III.
			'H' + 'E' = 109
			'L' + 'L' = 176
			'O' + 'O' = 224
		C = 109 176 224
	D(C) =
			109 = 'H' + 'E'
			176 = 'L' + 'L'
			224 = 'O' + 'O'
		M = "HELLO"
*/

extern void set_char_porte  (const uint8_t ch);
extern char set_alpha_porte (uint8_t * const alpha);
extern void to_string_porte (__INTEGER__ * const to, const __INTEGER__ * from);
extern void to_bytes_porte  (__INTEGER__ * to, const __INTEGER__ * from);
extern char porte (
	__INTEGER__ * const to,
	const int8_t mode,
	__INTEGER__ * const from
);
