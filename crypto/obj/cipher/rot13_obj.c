#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../rot13.h"
#include "../rot13_obj.h"

static void _free_memsize_rot13 (void) {
	free(rot13_obj.message);
}

static void _set_memsize_rot13 (const size_t size) {
	rot13_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_rot13 (const char * const from) {
	strcpy(rot13_obj.message, from);
}

static char _encrypt_rot13 (void) {
	return rot13(rot13_obj.message, rot13_obj.message);
}

static void _print_rot13 (void) {
	printf("%s", rot13_obj.message);
}

static void _println_rot13 (void) {
	printf("%s\n", rot13_obj.message);
}

ROT13 rot13_obj = {
	.free_memsize = _free_memsize_rot13,
	.set_memsize  = _set_memsize_rot13,
	.set_message  = _set_message_rot13,
	.print        = _print_rot13,
	.println      = _println_rot13,
	.encrypt      = _encrypt_rot13,
	.decrypt      = _encrypt_rot13,
};
