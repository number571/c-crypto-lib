//// gcc vigenere_example.c ../cipher/vigenere.c

#include <stdio.h>

#include "../append/macro.h"
#include "../vigenere.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_alpha_vigenere("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

	vigenere(message, ENCRYPT_MODE, "QWERTY", message);
	printf("%s\n", message);

	vigenere(message, DECRYPT_MODE, "QWERTY", message);
	printf("%s\n", message);

	return 0;
}

//// gcc vigenere_example.c ../cipher/vigenere.c ../obj/cipher/vigenere_obj.c

// #include "../obj/vigenere_obj.h"

// int main(void) {
// 	vigenere_obj.set_memsize(100);
// 	vigenere_obj.set_message("HELLO, WORLD");

// 	// vigenere_obj.set_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

// 	vigenere_obj.encrypt("QWERTY");
// 	vigenere_obj.println();

// 	vigenere_obj.decrypt("QWERTY");
// 	vigenere_obj.println();

// 	vigenere_obj.free_memsize();

// 	return 0;
// }
