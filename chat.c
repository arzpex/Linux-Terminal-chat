#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<ncurses.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>  
#include <unistd.h>     
#include <string.h>
#include<errno.h>

#define PORT 9999 
#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
	
int main() {
	int sockfd;
	struct sockaddr_in serveraddress;

	sockfd=socket(AF_INET,SOCK_STREAM, 0);

	if(sockfd<0){
		perror("socket creation error");
		exit(EXIT_FAILURE);
	}

        serveraddress.sin_family=AF_INET;
	serveraddress.sin_port=htons(PORT);
        
        if (inet_pton(AF_INET, SERVER_IP, &serveraddress.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }


	int result = connect(sockfd, (struct sockaddr *)&serveraddress, sizeof(serveraddress));

if (result < 0) {
    perror("Connection failed");
    close(sockfd);
    exit(EXIT_FAILURE);
}
printf("connection established\n");	
return 0;
}
