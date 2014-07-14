#include "tnc.h"

#include <inttypes.h>

#include "term.h"

void negotiate(int sock, unsigned char *buf, int len) {
    int i;
     
    if (buf[1] == DO && buf[2] == CMD_WINDOW_SIZE) {
        // I want to start a negociation about the window size
        unsigned char tmp1[10] = {IAC, CWILL, 31};
        if (send(sock, tmp1, 3 , 0) < 0)
            exit(1);
         
        // I want a windows that is 80 columns wide and 24 lines long
        unsigned char tmp2[10] = {IAC, SB, 31, 0, 80, 0, 24, IAC, SE};
        if (send(sock, tmp2, 9, 0) < 0)
            exit(1);
        return;
    }
     
    for (i = 0; i < len; i++) {
        if (buf[i] == DO)
            buf[i] = WONT;
        else if (buf[i] == WILL)
            buf[i] = DO;
    }
 
    if (send(sock, buf, len , 0) < 0)
        exit(1);
}

tnc_error tnc (char * host, char * port, char * user, unsigned int login) {
    int sock, len, i;
    struct sockaddr_in server;
    unsigned char buf[BUFLEN + 1];

    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        return TNCE_NO_SOCKET_ERROR;
    }
    
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        return TNCE_CONNECT_ERROR;
    }
    puts("Connected...\n");
 
    terminal_set();
    atexit(terminal_reset);

    struct timeval ts;
    ts.tv_sec = 1;
    ts.tv_usec = 0;
 
    while (1) {
        // select setup
        fd_set fds;
        FD_ZERO(&fds);
        if (sock != 0)
            FD_SET(sock, &fds);
        FD_SET(0, &fds);
 
        // wait for data
        int nready = select(sock + 1, &fds, (fd_set *) 0, (fd_set *) 0, &ts);
        if (nready < 0) {
            return TNCE_ERROR;
        } else if (nready == 0) {
            ts.tv_sec = 1;
            ts.tv_usec = 0;
        } else if (sock != 0 && FD_ISSET(sock, &fds)) {
            // start by reading a single byte
            int rv;
            if ((rv = recv(sock , buf , 1 , 0)) < 0)
                return TNCE_ERROR;
            else if (rv == 0) {
                return TNCE_DISTANT_CLOSE;
            }
 
            if (buf[0] == CMD) {
                // read 2 more bytes
                len = recv(sock , buf + 1 , 2 , 0);
                if (len  < 0)
                    return TNCE_SUCCESS;
                else if (len == 0) {
                    return TNCE_DISTANT_CLOSE;
                }
                // We are connected. Let's negociate about the window size
                negotiate(sock, buf, 3);
            } else {
                len = 1;
                buf[len] = '\0';
                printf("%s", buf);
                fflush(0);
            }
        } else if (FD_ISSET(0, &fds)) {
            buf[0] = getc(stdin); //fgets(buf, 1, stdin);
            if (send(sock, buf, 1, 0) < 0)
                return TNCE_SUCCESS;
            if (buf[0] == '\n') 
                putchar('\r');
        }
    }
    close(sock);

    return TNCE_SUCCESS;
}
