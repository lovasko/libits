#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "src/its.h"

int
main(void)
{
	intmax_t a;
	intmax_t b;
	uintmax_t c;
	char* a_str;
	char* b_str;
	char* c_str;

	a = INTMAX_MAX - 5;
	b = -INTMAX_MAX + 7;
	c = UINTMAX_MAX - 100;

	a_str = its(&a, ITS_SIZE_INTMAX, ITS_SIGNED, ITS_BASE_BIN);	
	b_str = its(&b, ITS_SIZE_INTMAX, ITS_SIGNED, ITS_BASE_HEX | ITS_PREFIX);
	c_str = its(&c, ITS_SIZE_INTMAX, ITS_UNSIGNED, ITS_BASE_DEC);

	printf("%s\n%s\n%s\n", a_str, b_str, c_str);

	free(a_str);
	free(b_str);
	free(c_str);

	return EXIT_SUCCESS;
}

