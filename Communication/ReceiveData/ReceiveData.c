//  ReceiveData.c
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#include "ReceiveData.h"

void * receiveData(void * arg) {
    // Stack of messages that the program have to treat.
    MessageStack = calloc(1, sizeof(char));

    SOCKET serverSocket = *(SOCKET *) arg;

    while (1) {
        char dataReceived[261] = { 0 };
        int bytesReceived = recv(serverSocket, dataReceived, 260, 0);

        if ( bytesReceived < 0 ) {
            error("recv() failed with error code : %d", WSAGetLastError());
            break;
        } else if ( bytesReceived == 0 ) {
            warn("Connection closed");
            raise(SIGABRT);
        } else {
            dataHandler(dataReceived);
        }
    }
}

void dataHandler(unsigned char * messageEncrypted) {

    char * dataType = calloc(5, sizeof(char));
    unsigned char * messageDecrypted = (unsigned char *) calloc(246, sizeof(char));

    for ( int i = 0; i < 4; i++) {
        dataType[i] = messageEncrypted[i];
    }

    if (strcmp(dataType, "MESG") == 0) {

        messageHandler();
    } else {
        warn("Unknown data type");
    }
}
