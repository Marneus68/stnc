#ifndef __TNC_H__
#define __TNC_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <termios.h>
#include <fcntl.h>

#include "constants.h"

typedef enum tnc_error {
    TNCE_NO_SOCKET_ERROR = -5,
    TNCE_DISTANT_CLOSE = -4,
    TNCE_CONNECT_ERROR = -3,
    TNCE_HOST_ERROR = -2,
    TNCE_ERROR = -1,
    TNCE_SUCCESS = 0
} tnc_error;

tnc_error tnc (char * host, char * port, char * user, unsigned int login);

#endif /* __TNC_H__ */
