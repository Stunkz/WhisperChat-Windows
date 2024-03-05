//  ServerCommunication.c
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#include "ServerCommunication.h"

void serverCommunication() {
    initWinsock();

    SOCKET serverSocket = INVALID_SOCKET;
    SockAddressIn serverAddress;

    createSocket(&connectSocket);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP);
    connectSocket(serverSocket, &serverAddress);

    PReceiveThread = (pthread_t * ) calloc(1, sizeof(pthread_t));
    pthread_create(PReceiveThread, NULL, receiveData, &serverSocket);
    PSendThread = (pthread_t * ) calloc(1, sizeof(pthread_t));;
    pthread_create(PSendThread, NULL, sendData, NULL);
}



void dataHandler(unsigned char * messageEncrypted) {

    char * dataType = calloc(5, sizeof(char));
    unsigned char * messageDecrypted = (unsigned char *) calloc(246, sizeof(char));

    for ( int i = 0; i < 4; i++) {
        dataType[i] = messageEncrypted[i];
    }

    if (strcmp(dataType, "MESG") == 0) {

        char * message = (char *) calloc(65, sizeof(char));
        char * identify = (char *) calloc(17, sizeof(char));
        char * buffer = (char *) calloc(81, sizeof(char));

        rsaDecrypt(encryptedMessage, messageDecrypted, 256);
        messageDecrypted[245] = '\0';

        for (int i = 0; i < 16; i++) {
            identify[i] = (char) messageDecrypted[i];
        }

        for (int i = 16; i < 80; i++) {
            message[i - 16] = (char) messageDecrypted[i];
        }

        sprintf(buffer, "<%s> %s", identify, message);

        free(identify);
        free(message);
        free(messageDecrypted);
    } else {
        warn("Can't handle the data, unknown data type");
    }

    free(dataType);
}