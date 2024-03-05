//  Debug.c
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#include "Debug.h"

char * getErrorMessage( int const errorCode ) {
    char * buffer = calloc(257, sizeof(char));
    strerror_s(buffer, 256, errorCode);
    buffer[256] = '\0';
    return buffer;
}