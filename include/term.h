#ifndef __TERM_H__
#define __TERM_H__

#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>

static struct termios tin;

// Save the terminal session configuation
static void terminal_set(void) {
    tcgetattr(STDIN_FILENO, &tin);
     
    static struct termios tlocal;
    memcpy(&tlocal, &tin, sizeof(tin));
    cfmakeraw(&tlocal);
    tcsetattr(STDIN_FILENO,TCSANOW,&tlocal);
}

// Restore the previously saved terminal session configuration
static void terminal_reset(void) {
    tcsetattr(STDIN_FILENO,TCSANOW,&tin);
}

#endif /* __TERM_H__ */

