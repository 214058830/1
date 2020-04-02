#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 9999
#define SERVER_IP "192.168.122.1"

int main(int argc, char** argv){

	if(argc != 2){
		printf("please enter pragram and ip\n");
		return 1;
	}
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0){
		perror("socket");
		return 2;
	}

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
	server.sin_addr.s_addr = inet_addr(argv[1]);

	char buf[1024];
	struct sockaddr_in client;
	while(1){
		socklen_t len = sizeof(client);
		printf("please enter#");
		fflush(stdout);
		ssize_t s = read(0, buf, sizeof(buf)-1);
		printf("读取到了：%d个数据\n", s);
		if(s > 0){
			buf[s-1] = 0;
			sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&server, sizeof(server));
			ssize_t _s = recvfrom(sock, buf, sizeof(buf)-1, 0, (struct sockaddr*)&client, &len);
			if(_s>0){
				buf[_s] = 0;
				printf("server echo# %s\n", buf);
			}
		}
	}
}
