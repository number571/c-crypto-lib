#pragma once

#include <stddef.h>
#include "../append/types.h"

typedef struct {
	char * message;
	bool encrypted;
	void (* const free_memsize) (void);
	void (* const set_memsize ) (const size_t size);
	void (* const set_message ) (const char * const from);
	char (* const set_alpha   ) (const char * const alpha);
	char (* const to_string   ) (char * const to);
	char (* const to_bytes    ) (char * const to);
	void (* const print       ) (void);
	void (* const println     ) (void);
	char (* const encrypt     ) (void);
	char (* const decrypt     ) (void);
} POLYBIUS;

extern POLYBIUS polybius_obj;
