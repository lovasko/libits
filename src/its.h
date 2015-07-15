#ifndef ITS_H
#define ITS_H

#include <stdlib.h>
#include <stdint.h>

#define ITS_BASE_HEX    0
#define ITS_BASE_DEC    1
#define ITS_BASE_OCT    2
#define ITS_BASE_BIN    3
#define ITS_PREFIX     16
#define ITS_UPPER_CASE 32

#define ITS_SIGNED      0
#define ITS_UNSIGNED    1

#define ITS_SIZE_SHORT  (sizeof(short)*8)
#define ITS_SIZE_INT    (sizeof(int)*8)
#define ITS_SIZE_LONG   (sizeof(long)*8)
#define ITS_SIZE_INTMAX (sizeof(intmax_t)*8)

char*
its(void* data, size_t bitsize, uint8_t signedness, uint32_t encoding);

#endif

