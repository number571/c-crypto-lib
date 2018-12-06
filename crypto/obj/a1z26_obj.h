#pragma once

#include <stddef.h>
#include "../append/types.h"

typedef struct {
	char * message;
	bool encrypted;
	void (* const free_memsize) (void);
	void (* const set_memsize) (const size_t size);
	void (* const set_message) (const char * const from);
	char (* const to_string) (char * const to);
	char (* const to_bytes ) (char * const to);
	void (* const print    ) (void);
	void (* const println  ) (void);
	char (* const encrypt  ) (void);
	char (* const decrypt  ) (void);
} A1Z26;

extern A1Z26 a1z26_obj;
