#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../porte.h"
#include "../porte_obj.h"

#include "../../append/macro.h"
#include "../../append/types.h"

static void _free_memsize_porte (void) {
	free(porte_obj.message);
}

static void _set_memsize_porte (const size_t size) {
	porte_obj.message = (short *)malloc(size * sizeof(short));
}

static void _set_message_porte (char * const from) {
	copy(porte_obj.message, char, from, END_OF_STRING);
}

static char _to_string_porte (short * const to) {
	if (!porte_obj.encrypted)
		return -1;

	to_string_porte(to, porte_obj.message);
	return 0;
}

static char _to_bytes_porte (short * const to) {
	if (!porte_obj.encrypted)
		return -1;

	to_bytes_porte(to, porte_obj.message);
	return 0;
}

static void _print_porte (void) {
	if (porte_obj.encrypted)
		print_nums(short, porte_obj.message);
	else
		print_chars(short, porte_obj.message);
}

static void _println_porte (void) {
	if (porte_obj.encrypted)
		println_nums(short, porte_obj.message);
	else
		println_chars(short, porte_obj.message);
}

static char _encrypt_porte (void) {
	if (porte_obj.encrypted)
		return -1;

	porte_obj.encrypted = true;
	return porte(porte_obj.message, ENCRYPT_MODE, porte_obj.message);
}

static char _decrypt_porte (void) {
	if (!porte_obj.encrypted)
		return -1;

	porte_obj.encrypted = false;
	return porte(porte_obj.message, DECRYPT_MODE, porte_obj.message);
}

PORTE porte_obj = {
	.encrypted    = false,
	.free_memsize = _free_memsize_porte,
	.set_memsize  = _set_memsize_porte,
	.set_message  = _set_message_porte,
	.set_alpha    = set_alpha_porte,
	.set_char     = set_char_porte,
	.to_string    = _to_string_porte,
	.to_bytes     = _to_bytes_porte,
	.print        = _print_porte,
	.println      = _println_porte,
	.encrypt      = _encrypt_porte,
	.decrypt      = _decrypt_porte,
};
