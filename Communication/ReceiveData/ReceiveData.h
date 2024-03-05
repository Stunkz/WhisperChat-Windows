//  ReceiveData.h
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#ifndef WHISPERCHAT_RECEIVEDATA_H
#define WHISPERCHAT_RECEIVEDATA_H

#include "../../Ressources/Debug.h"
#include "../Encryption.h"
#include <stdio.h>
#include <winsock2.h>
#include <signal.h>

extern char * MessageStack;

void * receiveData(void * arg);

#endif //WHISPERCHAT_RECEIVEDATA_H
