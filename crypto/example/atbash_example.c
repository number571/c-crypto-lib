//// gcc atbash_example.c ../cipher/atbash.c

#include <stdio.h>

#include "../atbash.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_alpha_atbash("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

	atbash(message, message);
	printf("%s\n", message);

	atbash(message, message);
	printf("%s\n", message);

	return 0;
}

//// gcc atbash_example.c ../cipher/atbash.c ../obj/cipher/atbash_obj.c

// #include "../obj/atbash_obj.h"

// int main(void) {
// 	atbash_obj.set_memsize(100);
// 	atbash_obj.set_message("HELLO, WORLD");

// 	// atbash_obj.set_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

// 	atbash_obj.encrypt();
// 	atbash_obj.println();

// 	atbash_obj.decrypt();
// 	atbash_obj.println();

// 	atbash_obj.free_memsize();

// 	return 0;
// }
