#pragma once

extern void set_char_porte (const char ch);
extern char set_alpha_porte (char * const alpha);
extern void to_string_porte (short * to, const short * from);
extern void to_bytes_porte (short * to, const short * from);
extern char porte (
	short * const to,
	const char mode,
	short * const from
);
