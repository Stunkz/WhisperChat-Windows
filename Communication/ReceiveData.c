//  ReceiveData.c
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#include "ReceiveData.h"

void * receiveData(void * arg) {
    while (1) {
        char buffer[260];
        ssize_t const bytesReceived= read(serverSocket.socket, buffer, sizeof(char)*260);

        if ( bytesReceived == -1 ) {
            char * errstr = getErrorMessage(errno);
            warn("Couldn't read data from server, error: %d - %s", errno, errstr);
            free(errstr);
        }
        else if ( bytesReceived == 0 ) {
            warn("Server closed the connection");
            raise(SIGABRT);
            break;
        } else {
            buffer[bytesReceived] = '\0';

            dataHandler(buffer);


            if (numMessages < MAX_MESSAGES) {
                strncpy(messages[numMessages], message, MAX_MESSAGE_LENGTH);
                numMessages++;
            } else {
                // Scroll the messages up by one when reaching the maximum
                for (int i = 0; i < MAX_MESSAGES - 1; i++) {
                    strncpy(messages[i], messages[i + 1], MAX_MESSAGE_LENGTH);
                }
                strncpy(messages[MAX_MESSAGES - 1], message, MAX_MESSAGE_LENGTH);
            }
            free(messageDecrypted);
        }
    }
}
