//  MessageHandler.h
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#ifndef WHISPERCHAT_MESSAGEHANDLER_H
#define WHISPERCHAT_MESSAGEHANDLER_H

#ifndef MAX_MESSAGE_LENGTH
#define MAX_MESSAGE_LENGTH 64
#endif

#include "../../../Ressources/Debug.h"
#include <stdio.h>
#include <signal.h>

 char * messageHandler(unsigned char * encryptedMessage);

#endif //WHISPERCHAT_MESSAGEHANDLER_H
