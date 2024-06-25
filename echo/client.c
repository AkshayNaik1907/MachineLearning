#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#define BUFLEN 1024
int main(int argc , char **argv){
	int n;
	int sd,port;
	char buf[BUFLEN];
	struct sockaddr_in server;
	port=atoi(argv[1]);
	if((sd=socket(AF_INET,SOCK_STREAM,0))==-1){
		fprintf(stderr,"can't create a socket\n");
		exit(1);
	}
	server.sin_family=AF_INET;
	server.sin_port=port;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	if(connect(sd,(struct sockaddr *)&server, sizeof(server))==-1){
		fprintf(stderr,"can't connect\n");
	}
	printf("Enter the message to be echoed : ");
	scanf("%s",buf);
	write(sd,buf,BUFLEN);
	printf("Echoed Message : ");
	n=read(sd,buf,sizeof(buf));
	printf("%s\n",buf);
	close(sd);
	return(0);
}		
