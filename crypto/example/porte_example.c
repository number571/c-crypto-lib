//// gcc porte_example.c ../cipher/porte.c

#include <stdio.h>

#include "../append/macro.h"
#include "../porte.h"

int main(void) {
	short message[100];
	copy(message, char, "HELLO, WORLD", END_OF_STRING);

	// set_char_porte('?');
	// set_alpha_porte("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

	porte(message, ENCRYPT_MODE, message);
	println_nums(short, message);

	// to_string_porte(message, message);
	// println_chars(short, message);

	// // char buffer[100];
	// // copy(buffer, short, message, END_OF_STRING);

	// // printf("%s\n", buffer);

	// to_bytes_porte(message, message);

	porte(message, DECRYPT_MODE, message);
	println_chars(short, message);

	return 0;
}

//// gcc porte_example.c ../cipher/porte.c ../obj/cipher/porte_obj.c

// // #include <stdio.h>
// // #include "../append/macro.h"
// #include "../obj/porte_obj.h"

// int main(void) {
// 	porte_obj.set_memsize(100);
// 	porte_obj.set_message("HELLO, WORLD");

// 	// porte_obj.set_char('?');
// 	// porte_obj.set_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ ,");

// 	porte_obj.encrypt();
// 	porte_obj.println();

// 	// porte_obj.to_string(porte_obj.message);
// 	// println_chars(short, porte_obj.message);

// 	// // char buffer[100];
// 	// // copy(buffer, short, porte_obj.message, END_OF_STRING);

// 	// // printf("%s\n", buffer);

// 	// porte_obj.to_bytes(porte_obj.message);

// 	porte_obj.decrypt();
// 	porte_obj.println();

// 	porte_obj.free_memsize();

// 	return 0;
// }
