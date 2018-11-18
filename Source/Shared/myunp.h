// This is our customized UNP Header file.
//  This header was created before the Fall
//  Vacation.  This was necessary as the
//  original header file requires the relative
//  paths to be resolved.

// Guards
#ifndef _MYUNP_H
#define _MYUMP_H


// Included Libraries
// ============================
#include <stdlib.h>         // fork
#include <stdio.h>          // fgets, fputs, input\output stream
#include <errno.h>          // Error Number
#include <sys/socket.h>     // Socket function
#include <string.h>         // bzero function comes from this
#include <netinet/in.h>     // ADDR_ANY
#include <ctype.h>          // pid_t
#include <unistd.h>         // read(), write()
#include <arpa/inet.h>      // inet_addr()
// ============================


// Definitions
// ============================
#define LISTENQ 4096        // Used for the backlog
#define MAXLINE 4096        // Maximum characters during communication
#define SERV_PORT 6324      // LIVING ON THE EDGE!  - must be unique
#define SA struct sockaddr  // SA definition
// ============================

// Concluding Guard
#endif
