//// gcc a1z26_example.c ../cipher/a1z26.c

#include <stdio.h>

#include "../a1z26.h"
#include "../append/macro.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	a1z26(message, ENCRYPT_MODE, message);
	println_nums(char, message);

	// to_string_a1z26(message, message);
	// printf("%s\n", message);

	// to_bytes_a1z26(message, message);

	a1z26(message, DECRYPT_MODE, message);
	printf("%s\n", message);

	return 0;
}

//// gcc a1z26_example.c ../cipher/a1z26.c ../obj/cipher/a1z26_obj.c

// // #include <stdio.h>
// #include "../obj/a1z26_obj.h"

// int main(void) {
// 	a1z26_obj.set_memsize(100);
// 	a1z26_obj.set_message("HELLO, WORLD");

// 	a1z26_obj.encrypt();
// 	a1z26_obj.println();

// 	// a1z26_obj.to_string(a1z26_obj.message);
// 	// printf("%s\n", a1z26_obj.message);

// 	// a1z26_obj.to_bytes(a1z26_obj.message);

// 	a1z26_obj.decrypt();
// 	a1z26_obj.println();

// 	a1z26_obj.free_memsize();

// 	return 0;
// }
