#pragma once

#include <stddef.h>

typedef struct {
	char * message;
	void (* const free_memsize) (void);
	char (* const set_alpha   ) (char * const alph1, char * const alph2);
	void (* const set_memsize ) (const size_t size);
	void (* const set_message ) (const char * const from);
	void (* const print       ) (void);
	void (* const println     ) (void);
	char (* const encrypt     ) (void);
	char (* const decrypt     ) (void);
} COUPLE;

extern COUPLE couple_obj;
