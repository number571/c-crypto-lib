//// gcc rot13_example.c ../cipher/rot13.c

#include <stdio.h>

#include "../rot13.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	rot13(message, message);
	printf("%s\n", message);

	rot13(message, message);
	printf("%s\n", message);

	return 0;
}

//// gcc rot13_example.c ../cipher/rot13.c ../obj/cipher/rot13_obj.c

// #include "../obj/rot13_obj.h"

// int main(void) {
// 	rot13_obj.set_memsize(100);
// 	rot13_obj.set_message("HELLO, WORLD");

// 	rot13_obj.encrypt();
// 	rot13_obj.println();

// 	rot13_obj.decrypt();
// 	rot13_obj.println();

// 	rot13_obj.free_memsize();

// 	return 0;
// }
