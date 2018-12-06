#pragma once

extern char set_alpha_polybius (const char * const alpha);
extern void to_string_polybius (char * to, const char * from);
extern void to_bytes_polybius (char * to, const char * from);
extern char polybius (
	char * const to, 
	const char mode, 
	const char * const from
);
