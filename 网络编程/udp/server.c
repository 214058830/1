#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 9999

int main(int argc, char** argv){
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0){
		perror("socket");
		return 2;
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sock, (struct sockaddr*)&server, sizeof(server)) < 0){
		perror("bind");
		return 3;
	}

	char buf[1024];
	struct sockaddr_in client;
	printf("bind and sock is success\n");
	while(1){
		socklen_t len = sizeof(client);
		ssize_t s = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&client, &len);
		printf("读取到了%d个数据\n", s);
		if(s > 0){
			buf[s] = '\0';
			printf("[%s:%d]:%s\n",inet_ntoa(client.sin_addr), ntohs(client.sin_port), buf);
			sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&client, sizeof(client));
		}
	}
	close(sock);
	return 0;
}
