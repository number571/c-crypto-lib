//// gcc couple_example.c ../cipher/couple.c

#include <stdio.h>

#include "../couple.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_alpha_couple("ABCDEFGHIJKLM", "NOPQRSTUVWXYZ");

	couple(message, message);
	printf("%s\n", message);

	couple(message, message);
	printf("%s\n", message);

	return 0;
}

//// gcc couple_example.c ../cipher/couple.c ../obj/cipher/couple_obj.c

// #include "../obj/couple_obj.h"

// int main(void) {
// 	couple_obj.set_memsize(100);
// 	couple_obj.set_message("HELLO, WORLD");

// 	// couple_obj.set_alpha("ABCDEFGHIJKLM", "NOPQRSTUVWXYZ");

// 	couple_obj.encrypt();
// 	couple_obj.println();

// 	couple_obj.decrypt();
// 	couple_obj.println();

// 	couple_obj.free_memsize();

// 	return 0;
// }
