#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	extern char **environ;
	for (int i = 0; argv[i]; i++) {
		printf("%s\n", argv[i]);
		printf("%p\n", argv[i]);
	}

	for (int i = 0; environ[i] != NULL; i++) {
		printf("%s\n", environ[i]);
		printf("%p\n", environ[i]);
	}
	return 0;
}
