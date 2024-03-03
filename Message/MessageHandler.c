//  MessageHandler.c
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#include "MessageHandler.h"

char * messageHandler(unsigned char * encryptedMessage) {

    unsigned char * messageDecrypted = (unsigned char *) calloc(246, sizeof(char));
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
    return buffer;
}