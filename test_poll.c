#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#include <sys/epoll.h>

int main(int argc, char *argv[])
{
	int fd = open("test.txt", O_CREAT, S_IRWXU);
	if (fd == -1) {
		perror("open");
		exit(-1);
	}
	struct pollfd pfd;
	pfd.fd = fd;
	pfd.events = POLLIN;

	int epfd = epoll_create(2);
	if (epfd == -1) {
		perror("epoo_create");
		exit(-1);
	}

	struct epoll_event event;
	event.events = EPOLLIN | EPOLLOUT;
	epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);

	return 0;
}
