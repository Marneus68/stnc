#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

// Buffer length for the exchanged messages
#define BUFLEN 20

// Command code for the dialog with the server
#define DO 0xfd
#define WONT 0xfc
#define WILL 0xfb
#define DONT 0xfe
#define CMD 0xff

#define CMD_ECHO 1
#define CMD_WINDOW_SIZE 31

#endif /* __CONSTANTS_H__ */
