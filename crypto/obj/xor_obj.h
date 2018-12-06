#pragma once

#include <stddef.h>

typedef struct {
	char * message;
	void (* const free_memsize) (void);
	void (* const set_memsize ) (const size_t size);
	void (* const set_message ) (const char * const from);
	void (* const print       ) (void);
	void (* const println     ) (void);
	char (* const encrypt     ) (const char key);
	char (* const decrypt     ) (const char key);
} XOR;

extern XOR xor_obj;
