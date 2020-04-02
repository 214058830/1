#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SERVER_PORT 9999

int main(int argc, char** argv){
	if(argc != 2){
		printf("please enter pragram and ip\n");
		return 1;
	}

	char buf[1024];
	memset(buf, '\0', sizeof(buf));
	struct sockaddr_in server_sock;
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&server_sock, sizeof(server_sock));
	server_sock.sin_family = AF_INET;
	server_sock.sin_addr.s_addr = inet_addr(argv[1]);
	server_sock.sin_port = htons(SERVER_PORT);

	int ret = connect(sock, (struct sockaddr*)&server_sock, sizeof(server_sock));
	if(ret < 0){
		printf("connect failed..., errno is:%d, errstring is:%s\n", errno, strerror(errno));
		return 2;
	}
	printf("connect is success\n");
	while(1){
		printf("client:#");
		fgets(buf, sizeof(buf), stdin);
		//fgets 最多读取sizeof(buf)-1个字节 最后一个存放'\0' 如果不能读取到一行则在最后增加NULL 再加 '\0'
		printf("读取到%d个字节\n", strlen(buf));
		buf[strlen(buf)-1] = '\0';
		write(sock, buf, sizeof(buf));
		if(strncasecmp(buf, "quit", 4) == 0){
			printf("quit\n");
			break;
		}
		printf("please wait...\n");
		read(sock, buf, sizeof(buf));
		printf("server:$ %s\n", buf);
	}
	close(sock);
	return 0;
}
