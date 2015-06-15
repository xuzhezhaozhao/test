#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef union {
	double u;
	void *s;
	long long i;
	long l;
} L_Umaxalign;

typedef union UTSting {
	L_Umaxalign dummy;
	char a[9];
} UTSting;

typedef struct TestPadding {
	UTSting us;
	char i;
} TestPadding;

#define LUA_INTEGER_FMT \
	"%"             \
	"ll"            \
	"d"

const char lua_ident[] =
    "$b"
    "a";

int luaO_int2fb(unsigned int x) {
	int e = 0; /* exponent */
	if (x < 8) return x;
	while (x >= 0x10) {
		x = (x + 1) >> 1;
		e++;
	}
	return ((e + 1) << 3) | (int)(x)-8;
}

struct sdshr {
	unsigned int len;
	char buf[];
};

int main(int argc, char *argv[]) {
	printf("%.17Lf\n", 1.0L / 3.0);

	return 0;
}
