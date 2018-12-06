#pragma once

extern char set_alpha_trithemius (const char * const alpha);
extern char trithemius (
	char * const to, 
	const char mode, 
	char (* const key) (const char x), 
	char * const from
);
