//  MessageHandler.h
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#ifndef WHISPERCHAT_MESSAGEHANDLER_H
#define WHISPERCHAT_MESSAGEHANDLER_H

#ifndef MAX_MESSAGE_LENGTH
#define MAX_MESSAGE_LENGTH 64
#endif

#include "../Ressources/Macro.h"
#include "../Communication/Encryption.h"
#include <stdio.h>
#include <signal.h>

/**
 * This function is used to handle the message received from the server.
 * It returns a printable string with identify and the message. (e.g. <Stunkz> Hello World!)
 *
 * @param encryptedMessage : The encrypted message.
 * @return Pointer to the message.
 */
 char * messageHandler(unsigned char * encryptedMessage);

#endif //WHISPERCHAT_MESSAGEHANDLER_H
