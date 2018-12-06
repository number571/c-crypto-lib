#pragma once

#include <stddef.h>

typedef struct {
	char * message;
	void (* const free_memsize) (void);
	void (* const set_memsize ) (const size_t size);
	void (* const set_message ) (const char * const from);
	void (* const print       ) (void);
	void (* const println     ) (void);
	char (* const encrypt     ) (void);
	char (* const decrypt     ) (void);
} ROT13;

extern ROT13 rot13_obj;
