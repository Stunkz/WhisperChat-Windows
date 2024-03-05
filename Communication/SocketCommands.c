//  SocketCommands.c
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#include "SocketCommands.h"

void initWinsock() {
    WSADATA wsaData;
    int const success = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if ( success != 0 ) {
        char * errstr = getErrorMessage(success);
        error("Couldn't initialize Winsock, error: %d - %s", success, errstr);
        free(errstr);
        raise(SIGABRT);
    }
    okay("Initialized Winsock successfully !");
}

void createSocket(SOCKET * pSocket) {
    SOCKET socketTemp = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if ( socketTemp == INVALID_SOCKET ) {
        error("Haven't been able to create the socket, error: %d", WSAGetLastError());
        raise(SIGABRT);
    }

    *pSocket = socketTemp;
    okay("Created the socket successfully !");
}

void connectSocket(SOCKET socketConnect, PSockAddressIn pServerAddress) {
    info("Trying to connect to the server...");

    if ( connect(socketConnect, (PSockAddress)pServerAddress, sizeof(*pServerAddress)) == SOCKET_ERROR ) {
        error("Couldn't connect to the server, error: %d", WSAGetLastError());
        raise(SIGABRT);
    }
    okay("Yay ! Got a connection to the server !");
}







void closeSocket(PSocket pSocket) {
    if ( pSocket->ip != NULL ) {
        free(pSocket->ip);
    }
    if ( pSocket->identify != NULL ) {
        pSocket->identify = NULL;
    }

    pSocket->socket = close(pSocket->socket);
    pSocket->port = 0;
    memset(&(pSocket->address), 0, sizeof(pSocket->address));
    if ( pSocket->socket == -1 ) {
        char * errstr = getErrorMessage(errno);
        warn("Couldn't close the socket, error: %d - %s", errno, errstr);
        free(errstr);
    } else {
        okay("Closed the socket successfully !");
    }
}



char * getIpAddress(SockAddressIn sockAddress) {
    char * ipBuffer = malloc(sizeof(char)*INET_ADDRSTRLEN);

    // Convert the binary IP address to a string
    if (inet_ntop(AF_INET, &(sockAddress.sin_addr), ipBuffer, INET_ADDRSTRLEN) == NULL) {
        fprintf(stderr, "Error converting IP address to string\n");
        return NULL;
    }

    // Return the IP address string
    return ipBuffer;
}

const int getPort(SockAddressIn sockAddress) {
    return ntohs(sockAddress.sin_port);
}

void setIpV4Address(PSockAddressIn pSockAddress, char * buffer) {
    int const success = inet_pton(AF_INET, buffer, &(pSockAddress->sin_addr));
    if ( success == -1 || !success ) {
        char * errstr = getErrorMessage(errno);
        warn("Couldn't set the IP address, error: %d - %s", errno, errstr);
        free(errstr);
    }
}

void setIpV6Address(PSockAddressIn pSockAddress, char * buffer) {
    int const success = inet_pton(AF_INET6, buffer, &(pSockAddress->sin_addr));
    if ( success == -1 || !success ) {
        char * errstr = getErrorMessage(errno);
        warn("Couldn't set the IP address, error: %d - %s", errno, errstr);
        free(errstr);
    }
}

void shutdownSocket(CSocket socket, int const how) {

    int const success = shutdown(socket.socket, how);

    if ( success == -1 ) {
        char * errstr = getErrorMessage(errno);
        warn("Couldn't shutdown the socket %d %s:%d, error: %d - %s", socket.socket, socket.ip, socket.port, errno, errstr);
        free(errstr);
    } else {
        okay("Shutdown the socket %d %s:%d successfully !", socket.socket, socket.ip, socket.port);
    }
}
