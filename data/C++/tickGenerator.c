/*
 ** talker.c -- a datagram "client" demo
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include <thread>
#include <iostream>
#include "randomPrice.h"

#define SERVERPORT "4950"    // the port users will be connecting to


int main(int argc, char *argv[])
{
    int sockfd;
    struct addrinfo hints, *servinfo;
    int rv;
    size_t numbytes;
    char* address = "192.168.1.109";
    printf("Pushing ticks to %s:%s\n", address, SERVERPORT);
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = 0;
    
    if ((rv = getaddrinfo(address, SERVERPORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }
    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    
    char myPrice[7];
    float f;
    while(1) {
        f = randPrice();
        ftoa(f, myPrice, 2); // Convert price to string
        myPrice[5] = '\n'; myPrice[6] = '\0';
    
        std::cout << "Price unicasted: " << myPrice;
        if ((numbytes = sendto(sockfd, myPrice, strlen(myPrice), 0, servinfo->ai_addr, servinfo->ai_addrlen)) == -1) {
            perror("talker: sendto");
            exit(1);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
    freeaddrinfo(servinfo);
    close(sockfd);
    
    return 0;
}