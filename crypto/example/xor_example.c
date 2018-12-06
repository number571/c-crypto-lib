//// gcc xor_example.c ../cipher/xor.c

#include <stdio.h>

#include "../xor.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	xor(message, 3, message);
	printf("%s\n", message);

	xor(message, 3, message);
	printf("%s\n", message);

	return 0;
}

//// gcc xor_example.c ../cipher/xor.c ../obj/cipher/xor_obj.c

// #include "../obj/xor_obj.h"

// int main(void) {
// 	xor_obj.set_memsize(100);
// 	xor_obj.set_message("HELLO, WORLD");

// 	xor_obj.encrypt(3);
// 	xor_obj.println();

// 	xor_obj.decrypt(3);
// 	xor_obj.println();

// 	xor_obj.free_memsize();

// 	return 0;
// }
