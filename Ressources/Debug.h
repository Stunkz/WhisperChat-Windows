//  Debug.h
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#ifndef WHISPERCHAT_DEBUG_H
#define WHISPERCHAT_DEBUG_H

#include "Macro.h"
#include <stdio.h>
#include <errno.h>
#include <error.h>
#include <string.h>
#include <stdlib.h>

/**
 * Get the error message from the error code. Need to be freed after use.
 * @param errorCode : The error code.
 * @return Pointer to the error message.
 */
char * getErrorMessage( int const errorCode );

#endif //WHISPERCHAT_DEBUG_H
