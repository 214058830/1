//多线程版本TCP服务端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define SERVER_PORT 9999

void ProcessRequest(int client_fd, struct sockaddr_in* client_addr) {
	char buf[1024] = {0};
	for (;;) {
		ssize_t read_size = read(client_fd, buf, sizeof(buf));
		if (read_size < 0) {
			perror("read");
			continue;
		}
		if (read_size == 0) {
			printf("client: %s say bye!\n", inet_ntoa(client_addr->sin_addr));
			close(client_fd);
			break;
		}
		buf[read_size] = '\0';
		printf("client: %s say: %s\n", inet_ntoa(client_addr->sin_addr), buf);
		write(client_fd, buf, strlen(buf));
	}
	return ;
}
typedef struct Arg {
	int fd;
	struct sockaddr_in addr;
} Arg;
void* CreateWorker(void* ptr) {
	Arg* arg = (Arg*)ptr;
	ProcessRequest(arg->fd, &arg->addr);
	free(arg);
	return NULL;
}
int main(){
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(SERVER_PORT);
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) {
		perror("socket");
		return 1;
	}
	int opt = 1;
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	int ret = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
	if (ret < 0) {
		perror("bind");
		return 1;
	}
	ret = listen(fd, 10);
	if (ret < 0) {
		perror("listen");
		return 1;
	}
	for (;;) {
		struct sockaddr_in client_addr;
		socklen_t len = sizeof(client_addr);
		int client_fd = accept(fd, (struct sockaddr*)&client_addr, &len);
		if (client_fd < 0) {
			perror("accept");
			continue;
		}
		pthread_t tid = 0;
		Arg* arg = (Arg*)malloc(sizeof(Arg));
		arg->fd = client_fd;
		arg->addr = client_addr;
		pthread_create(&tid, NULL, CreateWorker, (void*)arg);
		pthread_detach(tid);
	}
	return 0;
}
