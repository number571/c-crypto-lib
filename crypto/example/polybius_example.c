//// gcc polybius_example.c ../cipher/polybius.c

#include <stdio.h>

#include "../append/macro.h"
#include "../polybius.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_alpha_polybius("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

	polybius(message, ENCRYPT_MODE, message);
	println_nums(char, message);

	// to_string_polybius(message, message);
	// printf("%s\n", message);

	// to_bytes_polybius(message, message);

	polybius(message, DECRYPT_MODE, message);
	printf("%s\n", message);

	return 0;
}

//// gcc polybius_example.c ../cipher/polybius.c ../obj/cipher/polybius_obj.c

// // #include <stdio.h>
// #include "../obj/polybius_obj.h"

// int main(void) {
// 	polybius_obj.set_memsize(100);
// 	polybius_obj.set_message("HELLO, WORLD");

// 	// polybius_obj.set_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

// 	polybius_obj.encrypt();
// 	polybius_obj.println();

// 	// polybius_obj.to_string(polybius_obj.message);
// 	// printf("%s\n", polybius_obj.message);

// 	// polybius_obj.to_bytes(polybius_obj.message);

// 	polybius_obj.decrypt();
// 	polybius_obj.println();

// 	polybius_obj.free_memsize();

// 	return 0;
// }
