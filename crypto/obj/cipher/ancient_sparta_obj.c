#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../ancient_sparta.h"
#include "../ancient_sparta_obj.h"

#include "../../append/macro.h"

static void _free_memsize_ancient_sparta (void) {
	free(ancient_sparta_obj.message);
}

static void _set_memsize_ancient_sparta (const size_t size) {
	ancient_sparta_obj.message = (char *)malloc(size * sizeof(char));
}

static void _set_message_ancient_sparta (const char * const from) {
	strcpy(ancient_sparta_obj.message, from);
}

static void _print_ancient_sparta (void) {
	printf("%s", ancient_sparta_obj.message);
}

static void _println_ancient_sparta (void) {
	printf("%s\n", ancient_sparta_obj.message);
}

static char _encrypt_ancient_sparta (const char key) {
	return ancient_sparta(ancient_sparta_obj.message, ENCRYPT_MODE, key, ancient_sparta_obj.message);
}

static char _decrypt_ancient_sparta (const char key) {
	return ancient_sparta(ancient_sparta_obj.message, DECRYPT_MODE, key, ancient_sparta_obj.message);
}

ANCIENT_SPARTA ancient_sparta_obj = {
	.free_memsize = _free_memsize_ancient_sparta,
	.set_memsize  = _set_memsize_ancient_sparta,
	.set_message  = _set_message_ancient_sparta,
	.set_char 	  = set_char_ancient_sparta,
	.print 	   	  = _print_ancient_sparta,
	.println   	  = _println_ancient_sparta,
	.encrypt  	  = _encrypt_ancient_sparta,
	.decrypt  	  = _decrypt_ancient_sparta,
};
