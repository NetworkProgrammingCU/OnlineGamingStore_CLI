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
//      Lewisk3 (from the ZDoom Community) [NG]
//          Greatly helped me unfuck the Pointeramania issues
//          Seriously, it was bad - like really bad.
//  Base Source Code provided by W. Richard Stevens in
//      Unix Network Programming, The Sockets Networking API
//      Volume 1, 3rd edition.  All credit goes to him for the framework
// Return Codes:
//  0 = Successful Operation
//  1 = User Requested to leave at Login (normal exit)
//  2 = User Account Validation Failure (Login failure)
//  3 = User Exceeded Login Retries (Bad credentials used)
//  255 = Vague error; usually something really bad.
// ============================================




// Included Libraries
// ===============================
#include <stdio.h>              // Input\Output Stream
#include <stdbool.h>            // Because I was spoiled with C++ and C#, just give me the Bool data types!
#include <ctype.h>              // tolower() functions for user input
#include <stddef.h>             // NULLPTR; used for pointers
#include <stdlib.h>             // Pointer Memory Allocation
#include <time.h>               // time() function for randomized seeds
#include "GlobalDefs.h"         // Program Macro-Definitions
#include "myunp.h"              // Our custom UNP Header file
#include "CommonFunctions.h"    // Shared functions; to help minimize development cost between sub-projects.
#include "CustomerData.h"       // Customer Data Object
#include "GameData.h"           // Game Data Object
#include "ProgInformation.h"    // Instructions and Informational Output
#include "GameLinkedList.h"     // Linked-List Support for Games
#include "CustomerLinkedList.h" // Linked-List Support for Customers
#include "Welcome.h"            // Welcome Menu
// ===============================




// Function Prototypes
// ===============================
void DrawMenuMain();                // Display the main menu to the user.
void DrawStorePage();               // Display the store page to the user.
void CloseProgram();                // Perform the termination protocol (if any).
void DrawUserLoggedIn();            // Display who is viewing the store.
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
    struct CustomerData*
        customerList = malloc(sizeof(CustomerData));    // Customer Data Linked-List
    struct GameData*
        gameList = malloc(sizeof(GameData));            // Game Data Linked-List
    struct CustomerData*
        sessionUser = malloc(sizeof(CustomerData));     // The user for this session
    // ----------------------------------
    
    // Immediate Execution
    // ===================================
    // Randomize the seed
    srand((unsigned)time(NULL));      // This will come in handy when we do the randomization of information.
    
    // All Linked-List heads point to NULL
    customerList = NULL;    // Customer List
    gameList = NULL;        // Game List
    
    // Prepare the linked-lists
    GenerateUserList(&customerList);    // Create the Customer List
    GenerateGameList(&gameList);        // Create the Game List (our catalog)
    // ===================================

    
    // Determine the user's request
    switch (WelcomeProtocol())
    {
        case 0:
            printf("User requested to login\n");
            UserLogin(customerList, &sessionUser);
            break;
        case 1:
            printf("User requested to register\n");
            ManuallyCreateNewUser(&customerList);
            break;
        case 2:
            printf("User requested to leave\n");
            exit(1);
            break;
        default:
            printf("Unknown request\n");
            exit(255);
            break;
    } // switch()
    
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
        
    // Get some data
    // DEBUG STUFF
    printf("First name: %s\n", customerList->firstName);
    printf("User ID: %s\n", customerList->userID);
    printf("Phone Number: %s\n", customerList->phoneNumber);
    printf("ZIP Code: %s\n", customerList->addressPostalCode);
    // END OF DEBUG STUFF
    
    return 0;
} // main()




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




// Draw User Logged-In Status
// -----------------------------------
// Documentation
//  This function will simply provide who is presently logged into the store.
// -----------------------------------
void DrawUserLoggedIn()
{
    printf("You are logged in as: {{PLACEHOLDER}}\n");
} // DrawUserLoggedIn()
