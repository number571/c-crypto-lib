#pragma once

#define TERMS \
	"M - open message\n"\
	"C - encrypted message\n"\
	"A - alphabet\n"\
	"K - key\n"\
	"E - function of encrypting\n"\
	"D - function of decrypting"

#define FUNCS \
	"*ciphername*() - main function\n"\
	"set_alpha_*ciphername*() - set alphabet/alphabets\n"\
	"set_char_*ciphername*() - set char/chars \n"\
	"print_*ciphername*() - print cipher text\n"\
	"println_*ciphername*() - print cipher text with new line\n"\
	"to_string_*ciphername*() - transfer from bytes to string\n"\
	"to_bytes_*ciphername*() - transfer from string to bytes"

#define APP_FUNCS \
	"get_coordinates - return structure Point\n"\
	"get_length - return length of array"

#define APP_TYPES \
	"bool - enum\n"\
	"Byte - union\n"\
	"schar_t - signed char\n"\
	"uchar_t - unsigned char\n"\
	"INTEGER_TYPE - macro\n"\
	"Point - structure"

#define APP_MACRO \
	"ENCRYPT_MODE\n"\
	"DECRYPT_MODE\n"\
	"END_OF_LINE\n"\
	"END_OF_STRING\n"\
	"END_OF_NUMBER\n"\
	"LEN_ALPHA\n"\
	"MAX_LENGTH\n"\
	"COPY\n"\
	"COPY_STR\n"\
	"COPY_NUM\n"\
	"SET_CHAR\n"\
	"SET_MESSAGE\n"\
	"SHIFTR\n"\
	"SHIFTL\n"\
	"PRINT_NUMS_WHILE\n"\
	"PRINTLN_NUMS_WHILE\n"\
	"PRINT_CHARS_WHILE\n"\
	"PRINTLN_CHARS_WHILE\n"\
	"PRINT_NUMS\n"\
	"PRINTLN_NUMS\n"\
	"PRINT_CHARS\n"\
	"PRINTLN_CHARS\n"\
	"PRINT_BYTE\n"\
	"PRINTLN_BYTE\n"\
	"PRINT_BYTES\n"\
	"PRINTLN_BYTES"
