// ============================================
// Programmers:     Nicholas Gautier
//                  Justin Griffith
//                  Marilyn Li
// Class:           CS3013; Network Programming
// Assignment #:    3
// Due Date:        12.December.2018
// Instructor:      Dr. Zhao
// Description:     TO-BE-DETERMINED
// Credits:
//  Base Source Code provided by W. Richard Stevens in
//      Unix Network Programming, The Sockets Networking API
//      Volume 1, 3rd edition.  All credit goes to him for the framework
// Return Codes:
//  0 = Successful Operation
// ============================================



// Included Libraries
// ===============================
#include <stdio.h>                  // Input\Output Stream
#include <stdbool.h>                // Because I was spoiled with C++ and C#, just give me the Bool data types!
#include <ctype.h>                  // tolower() functions for user input
#include <stddef.h>                 // NULLPTR; used for pointers
#include <stdlib.h>                 // Pointer Memory Allocation
//#include "myunp.h"              // Our custom UNP Header file
//#include "CommonFunctions.c"    // This contains our common functions
                                //  will be available through out the
                                //  entire program.
// ===============================



// Global Definitions
// ===============================
#define _NAME_ "Totally Not Steam!"         // Name of this program
#define _VERSION_ "1.0"                     // Version of this program
#define _VERSION_NAME_ "Squeeze"            // Version Code-Name
// ===============================



// Function Prototypes
// ===============================
void DrawInstructionsMainMenu();
void DrawMenuMain();
void DrawStorePage();
void CloseProgram();
void DrawHeader();
void DrawAbout();
void DrawUserLoggedIn();
// ===============================



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
    //int sockfd;                     // Socket File Descriptor
    //struct sockaddr_in servaddr;    // Server Info Struct.
    // ----------------------------------
    
    // Display the program's header
    DrawHeader();
    
    // Display the program's about section
    DrawAbout();
    
    // Push a few line-feeds to separate the contents
    printf("\n\n");
    
    // Display the user that is presently logged into the system
    DrawUserLoggedIn();
    
    // Push a few line-feeds to separate the contents
    printf("\n\n\n");
    
    // Draw the Main Menu
    DrawInstructionsMainMenu();
    DrawMenuMain();
    
    
    return 0;
} // main()




// Draw Instructions
// -----------------------------------
// Documentation
//  This function will provide the instructions to the client,
//  in regards into how to use the main menu screen.
// -----------------------------------
void DrawInstructionsMainMenu()
{
    printf("Select the following options from the screen:\n");
} // DrawInstructions()




// Draw Main Menu
void DrawMenuMain()
{
    printf("Main Menu\n");
    printf("------------------------------------------------\n\n");
    // View Store Catalogue
    printf("[1] - View Game Store\n");
    printf("       View what games are available within our store!\n");
    // Update Personal Information
    printf("[2] - Update Personal Information\n");
    printf("       View and change your personal account settings, such as email, address, etc.\n");
    // Leave terminate session
    printf("[X] - Leave Store\n");
    printf("       Exit from the store\n");
} // DrawMenuMain()



void DrawStorePage()
{
    
}



// Closing Program
// -----------------------------------
// Documentation
//  This function will perform any protocols necessary before the program's instance is destroyed or terminated.
// -----------------------------------
void CloseProgram()
{
    printf("Closing program. . .\n\n\n");
} // CloseProgram()



// Draw Header
// -----------------------------------
// Documentation
//  This function is designed to provide a header to the top-most space on the terminal buffer.
// -----------------------------------
void DrawHeader()
{
    printf("%s - Version: %s\n", _NAME_, _VERSION_);
    printf("%s\n", _VERSION_NAME_);
    printf("-----------------------------------------------\n\n");
} // DrawHeader()



// Draw About
// -----------------------------------
// Documentation
//  This function provides the 'About' section of the program
// -----------------------------------
void DrawAbout()
{
    printf("Welcome to the %s Store!\n", _NAME_);
    printf("--------------------------------------------\n");
    printf("Browse through our collection of games and purchase as many games as you want.  When you purchase a game, the game will be sent to your house by the slowest means possible.  Do note that the game you purchase is mere copies of the game, thus it is a non-genuine copy of the game.  Because of that, we charge extra for the activation or authentication keys.  In addition, there is no refunds if any game CD's and\\or floppies are damaged during shipping.\n");
    printf("--------\n");
    printf("See what others are saying about us!\n");
    printf("Reviewer from NY Times: Stay clear from this store!  I ordered a game from there and the experience was totally crappy!  The game took three months to arrive in the mail and the company is merely two __BLOCKS__ away from my house!  The CD I ordered was badly scratch - but magically my computer could still read it just fine.  But what caught me off guard, I need an Activation Key in order to play my game!  I called the company furiously over the phone, but the representatives promptly laughed at me while saying \"SUCKER\"!  Seriously, STAY_AWAY_FROM_THIS_STORE!\n");
} // DrawAbout()



// Draw User Logged-In Status
// -----------------------------------
// Documentation
//  This function will simply provide who is presently logged into the store.
// -----------------------------------
void DrawUserLoggedIn()
{
    printf("You are logged in as: {{PLACEHOLDER}}\n");
} // DrawUserLoggedIn()
