//// gcc bacon_example.c ../cipher/bacon.c

#include <stdio.h>

#include "../bacon.h"
#include "../append/macro.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_char_bacon('0', '1');
	// set_alpha_bacon("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

	bacon(message, ENCRYPT_MODE, message);
	println_bacon(message);

	// to_string_bacon(message, message);
	// printf("%s\n", message);

	// to_bytes_bacon(message, message);

	bacon(message, DECRYPT_MODE, message);
	printf("%s\n", message);

	return 0;
}

//// gcc bacon_example.c ../cipher/bacon.c ../obj/cipher/bacon_obj.c

// // #include <stdio.h>
// #include "../obj/bacon_obj.h"

// int main(void) {
// 	bacon_obj.set_memsize(100);
// 	bacon_obj.set_message("HELLO, WORLD");

// 	// bacon_obj.set_char('0', '1');
// 	// bacon_obj.set_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

// 	bacon_obj.encrypt();
// 	bacon_obj.println();

// 	// bacon_obj.to_string(bacon_obj.message);
// 	// printf("%s\n", bacon_obj.message);

// 	// bacon_obj.to_bytes(bacon_obj.message);

// 	bacon_obj.decrypt();
// 	bacon_obj.println();

// 	bacon_obj.free_memsize();

// 	return 0;
// }
