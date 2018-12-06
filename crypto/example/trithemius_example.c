//// gcc trithemius_example.c ../cipher/trithemius.c

#include <stdio.h>

#include "../append/macro.h"
#include "../trithemius.h"

char func_key(const char x) {
	return x * 2 + 1;
}

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_alpha_trithemius("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

	trithemius(message, ENCRYPT_MODE, func_key, message);
	printf("%s\n", message);

	trithemius(message, DECRYPT_MODE, func_key, message);
	printf("%s\n", message);

	return 0;
}

//// gcc trithemius_example.c ../cipher/trithemius.c ../obj/cipher/trithemius_obj.c

// #include "../obj/trithemius_obj.h"

// char func_key(const char x) {
// 	return x * 2 + 1;
// }

// int main(void) {
// 	trithemius_obj.set_memsize(100);
// 	trithemius_obj.set_message("HELLO, WORLD");

// 	// trithemius_obj.set_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

// 	trithemius_obj.encrypt(func_key);
// 	trithemius_obj.println();

// 	trithemius_obj.decrypt(func_key);
// 	trithemius_obj.println();

// 	trithemius_obj.free_memsize();

// 	return 0;
// }
