#pragma once

extern void set_char_bacon  (const char ch1, const char ch2);
extern char set_alpha_bacon (const char * const alpha);
extern void to_string_bacon (char * to, const char * from);
extern void to_bytes_bacon  (char * to, const char * from);
extern void print_bacon     (const char * from);
extern void println_bacon   (const char * from);

extern char bacon (
	char * const to, 
	const char mode, 
	const char * const from
);