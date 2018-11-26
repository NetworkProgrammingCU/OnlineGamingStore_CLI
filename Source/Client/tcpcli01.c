// ============================================
// Programmer:      Nicholas Gautier
// Class:           CS3013; Network Programming
// Assignment #:    2
// Due Date:        29.October.2018
// Instructor:      Dr. Zhao
// Description:     This program allows communication between the client and server.
// Credits:
//  Base Source Code provided by W. Richard Stevens in
//      Unix Network Programming, The Sockets Networking API
//      Volume 1, 3rd edition.  All credit goes to him for the framework
// Return Codes:
//  0 = Successful Operation
//  1 = Connection to the server was disconnected abruptly
//  2 = Incorrect arguments when program was invoked
// ============================================



// Included Libraries
// ============================
#include "myunp.h"              // Our custom UNP Header file
#include "CommonFunctions.c"    // This contains our common functions
                                //  will be available through out the
                                //  entire program.
#include "str_cli.c"            // Client Communication
// ============================



// Main
// -----------------------------------
// Arguments:
//  argc [int]
//      How many arguments has been passed
//  argv [multi-string]
//      Arguments passed
// -----------------------------------
int main(int argc, char **argv)
{
    // Declarations and Initializations
    // ----------------------------------
    int sockfd;                     // Socket File Descriptor
    struct sockaddr_in servaddr;    // Server Info Struct.
    // ----------------------------------

    // Make sure that the program was invoked correctly.
    if (argc != 2)
    {
        printf("<!> Insufficient parameters <!>\n");
        printf("---------------------------------\n");
        printf("Please include the IP Address of the server that you want to connect.\n");
        printf("For example: client <server address>\n");
        printf("             client 127.0.0.1\n");
        exit(2);
    } // Incorrect arguments
    
    // Create the Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Reset all of the bits of servaddr to null
    bzero(&servaddr, sizeof(servaddr));

    // Internet Protocol [v4]
    servaddr.sin_family = AF_INET;

    // Port Number
    servaddr.sin_port = htons(SERV_PORT);

    // Converts the address to binary form
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    // Connect to the server
    connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

    // Execute the client's Read\Write echo
    str_cli(stdin, sockfd);

    // Terminate the program
    exit(0);
} // main()