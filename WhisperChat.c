//  WhisperChat.c
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#include "WhisperChat.h"
#include "Key.h"



int main( void ) {

    printf("WhisperChat\n");

    return 0;
}

void stopProgram() {
    space();
    warn("--------------[ Program terminated ]-------------- [!]");
    space();



    info("Freeing memory... (づ￣ ³￣)づ");
    if ( publicKey != NULL ) {
        EVP_PKEY_free(publicKey);
    }
    if ( privateKey != NULL ) {
        EVP_PKEY_free(privateKey);
    }
    if ( PReceiveThread != NULL ) {
        pthread_cancel(*PReceiveThread);
        free(PReceiveThread);
    }
    if ( PSendThread != NULL ) {
        pthread_cancel(*PSendThread);
        free(PSendThread);
    }

    WSACleanup();

    info("B-but why ar-are you leaving m-me ? (╥_╥)");
    exit(0);
}