#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../substitute.h"
#include "../substitute_obj.h"

#include "../../append/macro.h"

static void _free_memsize_substitute (void) {
	free(substitute_obj.message);
}

static void _set_memsize_substitute (const size_t size) {
	substitute_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_substitute (const char * const from) {
	strcpy(substitute_obj.message, from);
}

static char _encrypt_substitute (void) {
	return substitute(substitute_obj.message, ENCRYPT_MODE, substitute_obj.message);
}

static char _decrypt_substitute (void) {
	return substitute(substitute_obj.message, DECRYPT_MODE, substitute_obj.message);
}

static void _print_substitute (void) {
	printf("%s", substitute_obj.message);
}

static void _println_substitute (void) {
	printf("%s\n", substitute_obj.message);
}

SUBSTITUTE substitute_obj = {
	.free_memsize = _free_memsize_substitute,
	.set_memsize  = _set_memsize_substitute,
	.set_message  = _set_message_substitute,
	.set_alpha 	  = set_alpha_substitute,
	.print 	   	  = _print_substitute,
	.println   	  = _println_substitute,
	.encrypt   	  = _encrypt_substitute,
	.decrypt   	  = _decrypt_substitute,
};
