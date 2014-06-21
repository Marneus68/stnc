#ifndef __TNC_H__
#define __TNC_H__

typedef enum tnc_error {
    TNCE_HOST_ERROR = -2,
    TNCE_ERROR = -1,
    TNCE_SUCCESS = 0
} tnc_error;

tnc_error tnc (char * host, char * port, char * user, unsigned int login);

#endif /* __TNC_H__ */
