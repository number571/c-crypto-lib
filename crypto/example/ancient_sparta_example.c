//// gcc ancient_sparta_example.c ../cipher/ancient_sparta.c

#include <stdio.h>

#include "../ancient_sparta.h"
#include "../append/macro.h"

int main(void) {
	char message[100] = "HELLO, WORLD";

	// set_char_ancient_sparta('?');

	ancient_sparta(message, ENCRYPT_MODE, 3, message);
	printf("%s\n", message);

	ancient_sparta(message, DECRYPT_MODE, 3, message);
	printf("%s\n", message);

	return 0;
}

//// gcc ancient_sparta_example.c ../cipher/ancient_sparta.c ../obj/cipher/ancient_sparta_obj.c

// #include "../obj/ancient_sparta_obj.h"

// int main(void) {
// 	ancient_sparta_obj.set_memsize(100);
// 	ancient_sparta_obj.set_message("HELLO, WORLD");

// 	// ancient_sparta_obj.set_char('?');

// 	ancient_sparta_obj.encrypt(3);
// 	ancient_sparta_obj.println();

// 	ancient_sparta_obj.decrypt(3);
// 	ancient_sparta_obj.println();

// 	ancient_sparta_obj.free_memsize();

// 	return 0;
// }
