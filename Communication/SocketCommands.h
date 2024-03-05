//  SocketCommands.h
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#ifndef WHISPERCHAT_SOCKETCOMMANDS_H
#define WHISPERCHAT_SOCKETCOMMANDS_H

#include "../Ressources/Debug.h"
#include <stdio.h>
#include <errno.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <signal.h>

typedef int FileDescriptor, * PFileDescriptor;
typedef struct sockaddr SockAddress, * PSockAddress;
typedef const SockAddress CSockAddress, * PCSockAddress;
typedef struct sockaddr_in SockAddressIn, * PSockAddressIn;
typedef const SockAddressIn CSockAddressIn, * PCSockAddressIn;

typedef struct {
    FileDescriptor socket;
    struct sockaddr_in address;
    char * ip;
    int port;
} Socket, * PSocket;


/**
 * @brief Initializes the Winsock library.
 *
 * This function initializes the Winsock library by calling WSAStartup.
 * If the initialization fails, it prints an error message,
 * and raises a SIGABRT signal to terminate the program.
 *
 * If the initialization is successful, it prints a success message.
 */
void initWinsock();


/**
 * @brief Creates a new socket and assigns it to the provided pointer.
 *
 * This function creates a new TCP socket using the AF_INET address family.
 * If the socket creation fails, it prints an error message and
 * raises a SIGABRT signal to terminate the program.
 *
 * If the socket is created successfully, it assigns the new socket to the provided pointer
 * and prints a success message.
 *
 * @param pSocket A pointer to a SOCKET where the new socket will be stored.
 */
void createSocket(SOCKET * pSocket);


/**
 * @brief Connects a socket to a server.
 *
 * This function attempts to connect a socket to a server. The server's address
 * and port number are specified in the PSockAddressIn structure.
 *
 * If the connection attempt fails, the function prints an error message and
 * raises a SIGABRT signal to terminate the program.
 *
 * If the connection is successful, the function prints a success message.
 *
 * @param socketConnect The socket to connect to the server.
 * @param pServerAddress A pointer to a PSockAddressIn structure that specifies
 *                       the server's address and port number.
 */
 void connectSocket(SOCKET socketConnect, PSockAddressIn pServerAddress);


#endif //WHISPERCHAT_SOCKETCOMMANDS_H
