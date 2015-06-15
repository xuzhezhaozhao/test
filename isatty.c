#include <stdio.h>
#include <unistd.h>

int fileno (FILE *__stream);
int main(int argc, char *argv[])
{
	if (isatty(fileno(stdout))) {
		printf("isatty\n");
	}
	return 0;
}
