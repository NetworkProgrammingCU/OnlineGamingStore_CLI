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
#include "MainMenu.h"           // Main Menu
#include "UpdateUserAccount.h"  // Update User Account Information (user card)
// ===============================




// Function Prototypes
// ===============================
void DrawStorePage();               // Display the store page to the user.
void CloseProgram();                // Perform the termination protocol (if any).
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
    bool isContinue = true;                             // User request to terminate the program
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
            ManuallyCreateNewUser(&customerList, &sessionUser);
            break;
        case 2:
            printf("User requested to leave\n");
            exit(1);
            break;
        default:
            exit(255);
            break;
    } // switch()
    
    do
    {
        // Clear some space for the main menu screen
        ClearScreen();
        
        // Display the program's header
        DrawHeader();
        
        // Display the program's about section
        DrawAbout();
        
        // Push a few line-feeds to separate the contents
        printf("\n\n");
        
        // Display the user that is presently logged into the system
        DrawUserLoggedIn(sessionUser->userID);
        
        // Push a few line-feeds to separate the contents
        printf("\n\n\n");
        
        // Provide the Main Menu and determine the user's request
        switch (MainMenu())
        {
            case 0: // Store Page
                printf("Store Page requested\n");
                break;
            case 1: // Update User Information
                UpdateUserInfoMenu(&sessionUser);
                break;
            case 2: // Leave the Store
                isContinue = false;     // Negate this flag; leave the loop
                break;
            default: // Incorrect input or request
                printf("<!> BAD REQUEST <!>\n");
                printf("-------------------------------\n");
                printf("Please select an option from the menu provided\n");
                break;
        } // switch()
    } while(isContinue);
    
    // Prepare to close the program
    CloseProgram();
    
    // Terminate the program
    return 0;
} // main()




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
