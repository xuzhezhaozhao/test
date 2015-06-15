#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sfd == -1) {
		perror("socket");
		exit(-1);
	}

	struct sockaddr_storage addr;
	socklen_t addrlen = sizeof(addr);

	/* TODO addr 中填什么? */
	if (connect(sfd, (struct sockaddr *)&addr, addrlen) == -1) {
		perror("connect");
		exit(-1);
	}

	if (getpeername(sfd, (struct sockaddr *)&addr, &addrlen) == -1) {
		perror("getpeername");
		exit(-1);
	}
	return 0;
}


