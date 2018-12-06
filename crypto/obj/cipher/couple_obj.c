#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../couple.h"
#include "../couple_obj.h"

static void _free_memsize_couple (void) {
	free(couple_obj.message);
}

static void _set_memsize_couple (const size_t size) {
	couple_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_couple (const char * const from) {
	strcpy(couple_obj.message, from);
}

static void _print_couple (void) {
	printf("%s", couple_obj.message);
}

static void _println_couple (void) {
	printf("%s\n", couple_obj.message);
}

static char _encrypt_couple (void) {
	return couple(couple_obj.message, couple_obj.message);
}

COUPLE couple_obj = {
	.free_memsize = _free_memsize_couple,
	.set_memsize  = _set_memsize_couple,
	.set_message  = _set_message_couple,
	.set_alpha    = set_alpha_couple,
	.print        = _print_couple,
	.println      = _println_couple,
	.encrypt      = _encrypt_couple,
	.decrypt      = _encrypt_couple,
};
