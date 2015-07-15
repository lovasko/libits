# libits
C89/POSIX-compliant conversion library from integers to strings that supports
various signed and unsigned integer number bases and bit-widths.

## Example
```C
#include <stdlib.h>
#include <stdio.h>
#include <its.h>

int
main(void)
{
	int a;
	char* a_str;

	a = -123;
	a_str = its(&a, ITS_SIZE_INT, ITS_SIGNED, ITS_BASE_HEX | ITS_PREFIX);
	printf("%s\n", a_str);
	
	free(a_str);
	return EXIT_SUCCESS;
}
```

Compile & run:
```
$ clang example.c -lits
$ ./a.out
-0x7b
```

## Q&A
#### How is this better than `(asn)printf`?
 * Binary base
 * Signed hexadecimal and octal numbers up to `(U)INT_MAX`
 * Correct handling of arbitrary bit-sized integers

#### How is this worse than `(asn)printf`?
 * It is a (yet another) dependency
 * Not standard
 * More verbose usage

#### How do I get all the bonus features of `printf` (like fixed width printing or alignment).
For such features, the `printf` alternative is the solution. But instead of
`%lld` or any related format, use the `%s` format with value of a `its` call.

## Build
```
$ ninja
```

## Supported platforms & standards 
The library is working quite heavily with the two-complement format of signed
integers, which is one of the three signed number representations allowed by
the C89 standard and the only representation allowed in the POSIX family of
standards.

 * FreeBSD 10.0 with Clang 3.3

If a platform does not appear to be in the previous list, it does not mean that
`libits` will not work in such environment. It only means that nobody tested
it - you are encouraged to do so and report either success or failure.

## License
2-clause BSD license. For more information please consult the
[LICENSE](LICENSE.md) file. In the case that you need a different license, feel
free to contact me.

## Author
Daniel Lovasko lovasko@freebsd.org

