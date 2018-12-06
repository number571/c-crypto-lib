//// gcc caesar_example.c ../cipher/caesar.c

#include <stdio.h>

#include "../caesar.h"
#include "../append/macro.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_alpha_caesar("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

	caesar(message, ENCRYPT_MODE, 3, message);
	printf("%s\n", message);

	caesar(message, DECRYPT_MODE, 3, message);
	printf("%s\n", message);

	return 0;
}

//// gcc caesar_example.c ../cipher/caesar.c ../obj/cipher/caesar_obj.c

// #include "../obj/caesar_obj.h"

// int main(void) {
// 	caesar_obj.set_memsize(100);
// 	caesar_obj.set_message("HELLO, WORLD");

// 	// caesar_obj.set_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

// 	caesar_obj.encrypt(3);
// 	caesar_obj.println();

// 	caesar_obj.decrypt(3);
// 	caesar_obj.println();

// 	caesar_obj.free_memsize();

// 	return 0;
// }
