#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../vigenere.h"
#include "../vigenere_obj.h"

#include "../../append/macro.h"

static void _free_memsize_vigenere (void) {
	free(vigenere_obj.message);
}

static void _set_memsize_vigenere (const size_t size) {
	vigenere_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_vigenere (const char * const from) {
	strcpy(vigenere_obj.message, from);
}

static void _print_vigenere (void) {
	printf("%s", vigenere_obj.message);
}

static void _println_vigenere (void) {
	printf("%s\n", vigenere_obj.message);
}

static char _encrypt_vigenere (const char * const key) {
	return vigenere(vigenere_obj.message, ENCRYPT_MODE, key, vigenere_obj.message);
}

static char _decrypt_vigenere (const char * const key) {
	return vigenere(vigenere_obj.message, DECRYPT_MODE, key, vigenere_obj.message);
}

VIGENERE vigenere_obj = {
	.free_memsize = _free_memsize_vigenere,
	.set_memsize  = _set_memsize_vigenere,
	.set_message  = _set_message_vigenere,
	.set_alpha 	  = set_alpha_vigenere,
	.print	      = _print_vigenere,
	.println      = _println_vigenere,
	.encrypt      = _encrypt_vigenere,
	.decrypt      = _decrypt_vigenere,
};
