//
//  main.c
//  TCP_SocketServer
//
//  Created by Ryan Price on 9/13/18.
//  Copyright © 2018 Ryan Price. All rights reserved.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define SIZE 1024
char buf[SIZE];
#define TIME_PORT 2013

int main(int argc, const char * argv[]) {
    char serverMessage[256] = "You got the server!";
    //creat the socket
    int netWorkSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9003);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //bind the socket
    int bindStatus = bind(netWorkSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if(bindStatus == -1){
        printf("Error\n\n");
    }
    else{
        printf("good bind\n");
    }

    listen(netWorkSocket, 5);
    //Accept
    int clientSocket = accept(netWorkSocket, NULL, NULL);
    send(clientSocket, serverMessage, sizeof(serverAddress), 0);
    shutdown(netWorkSocket, SHUT_RDWR);
    return 0;
}
