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
int MainMenu();                     // Manages with the Main Menu user Requests.
int MainMenuUserRequest();          // User provides their request within the main menu.
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
                printf("Update user information requested\n");
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




// Main Menu
// -----------------------------------
// Documentation:
//  This function will allow the user to provide
//  their request - which will allow them to navigate
//  within the program.
// -----------------------------------
// Output:
//  0 = Store Page
//  1 = Update User Information
//  2 = Exit
//  3 = Bad request
// -----------------------------------
int MainMenu()
{
    DrawInstructionsMainMenu();     // Draw Instructions
                                    //  regarding the main menu.
    DrawMenuMain();                 // Provide the Main Menu
    return MainMenuUserRequest();   // Fetch user input
} // MainMenu()




// Main Menu User Request
// -----------------------------------
// Documentation:
//  This will allow the user to provide input in regards to
//  the main menu, but the input will also be modified to work
//  within this program.
// -----------------------------------
// Output:
//  0 = Store Page
//  1 = Update User Information
//  2 = Exit
//  3 = Bad request
// -----------------------------------
int MainMenuUserRequest()
{
    // Declarations and Initializations
    // ----------------------------------
    char userInput[_MAX_CHAR_INPUT_];    // This will hold the user input.
    // ----------------------------------
    
    // Display the prompt
    DisplayPrompt();
    
    // Get the user input
    fgets(userInput, _MAX_CHAR_INPUT_, stdin);
    
    // Lower case the user's input
    LowerCaseUserInput(userInput);
    
    // Try to determine the user's request
    if (userInput[0] == '1')
        // Store Page
        return 0;
    else if (userInput[0] == '2')
        // Update User Information
        return 1;
    else if (userInput[0] == 'x')
        // Exit from the Store
        return 2;
    else
        // Unknown Request
        return 3;    
} // MainMenuUserRequest()




// Draw Main Menu
// -----------------------------------
// Documentation:
//  This will provide the main menu to the user.
// -----------------------------------
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
// Parameters:
//  screenName [char*]
//      The User ID that this session is attached to presently.
// -----------------------------------
void DrawUserLoggedIn(char *screenName)
{
    printf("You are logged in as: %s\n", screenName);
} // DrawUserLoggedIn()
