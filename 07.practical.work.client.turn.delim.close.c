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

    struct  sockaddr_in saddr;
    struct   hostent *h;
    int sockfd;
    char message[1000];
    char domain[256];
    unsigned short port = 8784;

    if (argc <2) {
        printf("Enter domain: ");
        scanf("%s", domain);
    }
    else if(argc > 2)
    {
        printf("Too much domain!");
        return -1;
    }
    

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error creating socket\n");
        close(sockfd);
        return-1;
    }
    if ((h = gethostbyname(domain)) == NULL)
    {
        printf("Unknown host\n");
        close(sockfd);
        return -1;

    }
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    memcpy((char *)&saddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);



    saddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
    {
        printf("Cannot connect\n");
        close(sockfd);
        return-1;
    }
    
    while(1){
        printf("Client: ");
        scanf("%s", message);
        write(sockfd, message, strlen(message)+1);

        read(sockfd, message, sizeof(message));
            printf("Server: %s\n", message);
        
    }
    
    return 0;
}



