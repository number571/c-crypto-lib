//// gcc substitute_example.c ../cipher/substitute.c

#include <stdio.h>

#include "../append/macro.h"
#include "../substitute.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_alpha_substitute("ABCDEFGHIJKLM", "NOPQRSTUVWXYZ");

	substitute(message, ENCRYPT_MODE, message);
	printf("%s\n", message);

	substitute(message, DECRYPT_MODE, message);
	printf("%s\n", message);

	return 0;
}

//// gcc substitute_example.c ../cipher/substitute.c ../obj/cipher/substitute_obj.c

// #include "../obj/substitute_obj.h"

// int main(void) {
// 	substitute_obj.set_memsize(100);
// 	substitute_obj.set_message("HELLO, WORLD");

// 	// substitute_obj.set_alpha("ABCDEFGHIJKLM", "NOPQRSTUVWXYZ");

// 	substitute_obj.encrypt();
// 	substitute_obj.println();

// 	substitute_obj.decrypt();
// 	substitute_obj.println();

// 	substitute_obj.free_memsize();

// 	return 0;
// }
