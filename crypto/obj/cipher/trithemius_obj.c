#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../trithemius.h"
#include "../trithemius_obj.h"

#include "../../append/macro.h"

static void _free_memsize_trithemius (void) {
	free(trithemius_obj.message);
}

static void _set_memsize_trithemius (const size_t size) {
	trithemius_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_trithemius (const char * const from) {
	strcpy(trithemius_obj.message, from);
}

static void _print_trithemius (void) {
	printf("%s", trithemius_obj.message);
}

static void _println_trithemius (void) {
	printf("%s\n", trithemius_obj.message);
}

static char _encrypt_trithemius (char (* const key) (const char x)) {
	return trithemius(trithemius_obj.message, ENCRYPT_MODE, key, trithemius_obj.message);
}

static char _decrypt_trithemius (char (* const key) (const char x)) {
	return trithemius(trithemius_obj.message, DECRYPT_MODE, key, trithemius_obj.message);
}

TRITHEMIUS trithemius_obj = {
	.free_memsize = _free_memsize_trithemius,
	.set_memsize  = _set_memsize_trithemius,
	.set_message  = _set_message_trithemius,
	.set_alpha 	  = set_alpha_trithemius,
	.print	      = _print_trithemius,
	.println      = _println_trithemius,
	.encrypt      = _encrypt_trithemius,
	.decrypt      = _decrypt_trithemius,
};
