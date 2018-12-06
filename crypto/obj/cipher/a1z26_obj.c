#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../a1z26.h"
#include "../a1z26_obj.h"

#include "../../append/macro.h"
#include "../../append/types.h"

static void _free_memsize_a1z26 (void) {
	free(a1z26_obj.message);
}

static void _set_memsize_a1z26 (const size_t size) {
	a1z26_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_a1z26 (const char * const from) {
	strcpy(a1z26_obj.message, from);
}

static char _to_string_a1z26 (char * const to) {
	if (!a1z26_obj.encrypted)
		return -1;

	to_string_a1z26(to, a1z26_obj.message);
	return 0;
}

static char _to_bytes_a1z26 (char * const to) {
	if (!a1z26_obj.encrypted)
		return -1;

	to_bytes_a1z26(to, a1z26_obj.message);
	return 0;
}

static void _print_a1z26 (void) {
	if (a1z26_obj.encrypted)
		print_nums(char, a1z26_obj.message);
	else
		printf("%s", a1z26_obj.message);
}

static void _println_a1z26 (void) {
	if (a1z26_obj.encrypted)
		println_nums(char, a1z26_obj.message);
	else
		printf("%s\n", a1z26_obj.message);
}

static char _encrypt_a1z26 (void) {
	if (a1z26_obj.encrypted)
		return -1;

	a1z26_obj.encrypted = true;
	return a1z26(a1z26_obj.message, ENCRYPT_MODE, a1z26_obj.message);
}

static char _decrypt_a1z26 (void) {
	if (!a1z26_obj.encrypted)
		return -1;

	a1z26_obj.encrypted = false;
	return a1z26(a1z26_obj.message, DECRYPT_MODE, a1z26_obj.message);
}

A1Z26 a1z26_obj = {
	.encrypted 	  = false,
	.free_memsize = _free_memsize_a1z26,
	.set_message  = _set_message_a1z26,
	.set_memsize  = _set_memsize_a1z26,
	.to_string 	  = _to_string_a1z26,
	.to_bytes  	  = _to_bytes_a1z26,
	.print 	   	  = _print_a1z26,
	.println   	  = _println_a1z26,
	.encrypt   	  = _encrypt_a1z26,
	.decrypt   	  = _decrypt_a1z26,
};
