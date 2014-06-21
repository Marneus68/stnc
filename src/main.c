#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

#include "usage.h"
#include "tnc.h"

int main(int argc, const char *argv[])
{
    int c,
        opt_index;

    char *  host = "";
    char *  port = "";
    char *  user = "";
    unsigned int login = 0;

    if (argc == 1) {
        printf ("Not enough arguments provided.\n\n");
        usage();
    }

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
                break;
            case 'h':
                printf ("Host %s\n", optarg);
                break;
        }
    }

    if (strcmp(host, "")) {
        printf ("No host provided.\n\n");
        usage();
        return EXIT_SUCCESS;
    }

    switch (tnc(host, port, user, login)) {
        case (TNCE_ERROR):
            return EXIT_FAILURE;
        case (TNCE_SUCCESS):
            return EXIT_SUCCESS;
    }
}
