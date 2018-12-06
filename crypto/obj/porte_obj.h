#pragma once

#include <stddef.h>
#include "../append/types.h"

typedef struct {
	short * message;
	bool encrypted;
	void (* const free_memsize) (void);
	void (* const set_memsize ) (const size_t size);
	void (* const set_message ) (char * const from);
	char (* const set_alpha   ) (char * const alpha);
	void (* const set_char    ) (const char ch);
	char (* const to_string   ) (short * const to);
	char (* const to_bytes    ) (short * const to);
	void (* const print       ) (void);
	void (* const println     ) (void);
	char (* const encrypt     ) (void);
	char (* const decrypt     ) (void);
} PORTE;

extern PORTE porte_obj;
