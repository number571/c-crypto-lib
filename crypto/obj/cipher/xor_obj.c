#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../xor.h"
#include "../xor_obj.h"

static void _free_memsize_xor (void) {
	free(xor_obj.message);
}

static void _set_memsize_xor (const size_t size) {
	xor_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_xor (const char * const from) {
	strcpy(xor_obj.message, from);
}

static void _print_xor (void) {
	printf("%s", xor_obj.message);
}

static void _println_xor (void) {
	printf("%s\n", xor_obj.message);
}

static char _encrypt_xor (const char key) {
	return xor(xor_obj.message, key, xor_obj.message);
}

XOR xor_obj = {
	.free_memsize = _free_memsize_xor,
	.set_memsize  = _set_memsize_xor,
	.set_message  = _set_message_xor,
	.print        = _print_xor,
	.println      = _println_xor,
	.encrypt      = _encrypt_xor,
	.decrypt      = _encrypt_xor,
};
