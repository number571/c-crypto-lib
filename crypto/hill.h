#pragma once

extern void set_char_hill (const unsigned char ch);
extern char set_alpha_hill (const unsigned char * const alpha);
extern char hill (
	unsigned char * to,
	const signed char mode,
	unsigned char * key,
	unsigned char * from
);
