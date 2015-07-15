#include <stdio.h>
#include <stdlib.h>

#include "src/its.h"

int
main(void)
{
	int a;
	char* a_bin;
	char* a_bin_prefix;
	char* a_oct;
	char* a_oct_prefix;
	char* a_hex;
	char* a_hex_prefix;
	char* a_hex_upper;
	char* a_hex_upper_prefix;

	a = 123123;

	a_bin = its(&a,
		ITS_SIZE_INT,
		ITS_SIGNED,
		ITS_BASE_BIN);
	a_bin_prefix = its(&a,
		ITS_SIZE_INT,
		ITS_SIGNED,
		ITS_BASE_BIN | ITS_PREFIX);

	a_oct = its(&a,
		ITS_SIZE_INT,
		ITS_SIGNED,
		ITS_BASE_OCT);
	a_oct_prefix = its(&a,
		ITS_SIZE_INT,
		ITS_SIGNED,
		ITS_BASE_OCT | ITS_PREFIX);

	a_hex = its(&a,
		ITS_SIZE_INT,
		ITS_SIGNED,
		ITS_BASE_HEX);
	a_hex_prefix = its(&a,
		ITS_SIZE_INT,
		ITS_SIGNED,
		ITS_BASE_HEX | ITS_PREFIX);
	a_hex_upper = its(&a,
		ITS_SIZE_INT,
		ITS_SIGNED,
		ITS_BASE_HEX | ITS_UPPER_CASE);
	a_hex_upper_prefix = its(&a,
		ITS_SIZE_INT,
		ITS_SIGNED,
		ITS_BASE_HEX | ITS_UPPER_CASE | ITS_PREFIX);

	printf("bin:\n  %s\n  %s\n",
		a_bin,
		a_bin_prefix);

	printf("oct:\n  %s\n  %s\n",
		a_oct,
		a_oct_prefix);

	printf("hex:\n  %s\n  %s\n  %s\n  %s\n",
		a_hex,
		a_hex_prefix,
		a_hex_upper,
		a_hex_upper_prefix);
	
	free(a_bin);
	free(a_bin_prefix);
	free(a_oct);
	free(a_oct_prefix);
	free(a_hex);
	free(a_hex_prefix);
	free(a_hex_upper);
	free(a_hex_upper_prefix);

	return EXIT_SUCCESS;
}

