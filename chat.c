#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<ncurses.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h> 
#include<arpa/inet.h>  
#include<unistd.h>     
#include<string.h>
#include<errno.h>

#define PORT 9999 
#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
	
void* l1(){

	return NULL;
}
int main() {
	initscr();
	cbreak();
	int sockfd;
	struct sockaddr_in serveraddress;

	sockfd=socket(AF_INET,SOCK_STREAM, 0);

	if(sockfd<0){
		printw("socket creation error");
		refresh();
		getch();
		endwin();
		exit(EXIT_FAILURE);
	}

        serveraddress.sin_family=AF_INET;
	serveraddress.sin_port=htons(PORT);
        
        if (inet_pton(AF_INET, SERVER_IP, &serveraddress.sin_addr) <= 0) {
        printw("Invalid address/ Address not supported");
	refresh();
	getch();
        endwin();
        close(sockfd);
        exit(EXIT_FAILURE);
    }


	int result = connect(sockfd, (struct sockaddr *)&serveraddress, sizeof(serveraddress));

if (result < 0) {
    printw("Connection failed");
    refresh();
    getch();
    endwin();
    close(sockfd);
    exit(EXIT_FAILURE);
}
printw("connection established\n");	
getch();
endwin();
return 0;
}
