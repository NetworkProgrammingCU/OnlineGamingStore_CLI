// Client Prospective
//  Part of TCPCLI01.c



// Included Libraries
// ============================
#include "myunp.h"      // Our custom UNP Header file
// ============================



// String Client
// -----------------------------------
// Arguments:
//  fp [FILE]
//      File to print to the server [UNUSED]
//  sockfd [int]
//      Socket File descriptor
// -----------------------------------
void str_cli(FILE *fp, int sockfd)
{
    // Declarations and Initializations
    // ----------------------------------
    char sendBuffer[MAXLINE];       // Sending message buffer
    char receiveBuffer[MAXLINE];    // Receiving message buffer
    // ----------------------------------

    // Immediately clear out the entire buffer; avoid garbage
    ClearBuffer(sendBuffer, MAXLINE);
    ClearBuffer(receiveBuffer, MAXLINE);
    // ----
    
    DisplayPrompt();        // Display the prompt
    
    // Read and Write to and from the server
    while (fgets(sendBuffer, MAXLINE, fp) != NULL)
    {
        // Check if the user wanted to quit
        if (!CheckForUserQuit(sendBuffer, strlen(sendBuffer)))
        {
            printf("Closing program. . .\n");
            exit(0);
        } // User Requested: Termination

        // Push the string to the server
        write(sockfd, sendBuffer, strlen(sendBuffer));
        
        // Provide an line for clarity sakes
        printf("\n");
        
        // Server fault
        if (read(sockfd, receiveBuffer, MAXLINE) == 0)
        {
            printf("<!> SERVER DISCONNECTED <!>\n");
            printf("The server is no longer available.\n");
            exit(1);    // System call to stop the program
        } // if Server Fault
        
        // Add a tag to the user
        MessageTag("Server\0");
        
        // Output the message to the screen
        fputs(receiveBuffer, stdout);
        
        // Clear the buffers
        ClearBuffer(sendBuffer, strlen(sendBuffer));
        ClearBuffer(receiveBuffer, strlen(receiveBuffer));
        
        // Display the prompt
        DisplayPrompt();
    } // While()
} // str_cli()