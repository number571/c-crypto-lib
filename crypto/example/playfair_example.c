//// gcc playfair_example.c ../cipher/playfair.c

#include <stdio.h>

#include "../append/macro.h"
#include "../playfair.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_char_playfair('0');
	// set_alpha_playfair("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

	playfair(message, ENCRYPT_MODE, "KEY", message);
	printf("%s\n", message);

	playfair(message, DECRYPT_MODE, "KEY", message);
	printf("%s\n", message);

	return 0;
}

//// gcc playfair_example.c ../cipher/playfair.c ../obj/cipher/playfair_obj.c

// #include "../obj/playfair_obj.h"

// int main(void) {
// 	playfair_obj.set_memsize(100);
// 	playfair_obj.set_message("HELLO, WORLD");

// 	// playfair_obj.set_char('0');
// 	// playfair_obj.set_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

// 	playfair_obj.encrypt("KEY");
// 	playfair_obj.println();

// 	playfair_obj.decrypt("KEY");
// 	playfair_obj.println();

// 	playfair_obj.free_memsize();

// 	return 0;
// }
