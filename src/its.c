#include <ctype.h>
#include <string.h>

#include "its.h"

static void
strrev(char* string, size_t len)
{
	unsigned int i;
	char tmp;

	for (i = 0; i < len/2; i++) {
		tmp = string[i];
		string[i] = string[len-i-1];
		string[len-i-1] = tmp;
	}
}

struct __its_base {
	const char* digits;
	size_t base;
};

static intmax_t
sign_extend(void* data, size_t bitsize, size_t bytesize)
{
	intmax_t result;
	int sign;

	result = 0;
	memcpy(&result, data, bytesize);

	if (sizeof(intmax_t)*8 == bitsize)
		return result;

	result &= ((intmax_t)1 << bitsize) - (intmax_t)1;
	sign = !!(result & ((intmax_t)1 << bitsize));
	if (sign)
		result |= ((intmax_t)-1 << bitsize);
	else
		result &= (((intmax_t)1 << bitsize) - (intmax_t)1);

	return result;
}

static uintmax_t
zero_extend(void* data, size_t bitsize, size_t bytesize)
{
	uintmax_t result;

	result = 0;
	memcpy(&result, data, bytesize);

	if (sizeof(uintmax_t)*8 == bitsize)
		return result;

	result &= (((uintmax_t)1 << bitsize) - (uintmax_t)1);

	return result;
}

char*
its(void* data, size_t bitsize, uint8_t signedness, uint32_t encoding)
{
	static struct __its_base bases[] = {
		{ "0123456789abcdef", 16 },
		{ "0123456789", 10 },
		{ "01234567", 8 },
		{ "01", 2 }
	};

	struct __its_base* b;
	char result[100];
	unsigned int result_idx;
	uintmax_t i;
	uintmax_t integer;
	intmax_t tmp;
	int negative;
	size_t bytesize;

	b = &bases[encoding & 0xf];
	result_idx = 0;
	memset(result, '\0', 100);
	negative = 0;

	if (bitsize % 8 == 0)
		bytesize = bitsize/8;
	else
		bytesize = ((bitsize-(bitsize%8))/8)+1;

	if (signedness == ITS_SIGNED) {
		tmp = sign_extend(data, bitsize, bytesize);
		negative = (tmp < 0);
		integer = (uintmax_t)tmp;
	} else
		integer = zero_extend(data, bitsize, bytesize);

	if (integer == 0)
		result[result_idx++] = '0';

	for (i = integer; i != 0; i /= (b->base))
		result[result_idx++] = b->digits[i % b->base];

	if (b->base == 16 && encoding & ITS_UPPER_CASE)
		for (i = 0; i < result_idx; i++)
			if (isalpha(result[i]))
				result[i] = (char)toupper(result[i]);

	if (encoding & ITS_PREFIX) {
		if (b->base == 2) {
			result[result_idx++] = 'b';
			result[result_idx++] = '0';
		}

		if (b->base == 8)
			result[result_idx++] = '0';

		if (b->base == 16) {
			result[result_idx++] = 'x';
			result[result_idx++] = '0';
		}
	}

	if (negative)
		result[result_idx++] = '-';
	
	strrev(result, result_idx);
	return strdup(result);
}

