//  ServerCommunication.h
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#ifndef WHISPERCHAT_SERVERCOMMUNICATION_H
#define WHISPERCHAT_SERVERCOMMUNICATION_H

#ifndef MAX_MESSAGE_LENGTH
#define MAX_MESSAGE_LENGTH 64
#endif

#include "../Ressources/Debug.h"
#include "SocketCommands.h"
#include "Encryption.h"
#include "ReceiveData/ReceiveData.h"
#include "SendData.h"
#include <stdio.h>
#include <signal.h>
#include <windows.h>
#include <pthread.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"

extern pthread_t * PReceiveThread;
extern pthread_t * PSendThread;

#endif //WHISPERCHAT_SERVERCOMMUNICATION_H
