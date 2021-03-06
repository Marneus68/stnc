#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

#include "usage.h"
#include "tnc.h"

int main(int argc, const char *argv[])
{
    int c, l = 0,
        opt_index;

    char host[256];
    char port[256];
    char user[256];
    unsigned int login = 0;

    if (argc == 1) {
        printf ("Not enough arguments provided.\n\n");
        usage();
    }

    host[0] = '\0';

    static struct option opts[] = {
        {"host",    required_argument,  0, 'h'},
        {"port",    required_argument,  0, 'p'},
        {"user",    required_argument,  0, 'u'},
        {"login",   no_argument,        0, 'l'},
        {0,         0,                  0, 0 }
    };

    while ((c = getopt_long(argc, 
            (char * const*)argv, "h:p:u:l", opts, &opt_index)) != -1) {
        switch (c) {
            case 0:
                break;
            case 'u':
                printf ("Attempting connection for user : `%s'\n", optarg);
                break;
            case 'l':
                printf ("Automatic login is ON.\n");
                break;
            case 'p':
                printf ("Port %s\n", optarg);
                // TODO: Verify that optarg is a valid port (is a number)
                snprintf(port,256,"%s",optarg);
                break;
            case 'h':
                printf ("Host %s\n", optarg);
                snprintf(host,256,"%s",optarg);
                break;
        }
    }

    if (host[0] == '\0') {
        printf ("No host provided.\n\n");
        usage();
        return EXIT_SUCCESS;
    }

    if (tnc(host, port, user, login) == TNCE_SUCCESS) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}
