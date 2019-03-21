#include <stdio.h>  //printf
#include <string.h> //memset
#include <stdlib.h> //for exit(0);
#include <sys/socket.h>
#include <errno.h> //For errno - the error number
#include <netdb.h> //hostent
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int sockfd, clen, clientfd;
    struct sockaddr_in saddr, caddr;
    unsigned short port = 8784;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error creating socket\n");
        return -1;
    }
    memset(&saddr, 0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(port);
if
(bind(sockfd , (struct sockaddr *) &saddr,sizeof(saddr)) < 0) {
        printf("Error binding\n");
        return -1;
}
if
(listen(sockfd, 5) < 0) {
        printf("Error listening\n");
        return -1;
}

clen=sizeof(caddr);
if
((clientfd=accept(sockfd, (struct sockaddr *) &caddr, &clen)) < 0) {
        printf("Error accepting connection\n");
        return -1;
}

printf("A lady wants to connect with me ");
    return 0;
}
