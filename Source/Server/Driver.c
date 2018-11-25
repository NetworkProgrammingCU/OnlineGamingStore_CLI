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
// ===============================




// Function Prototypes
// ===============================
void UpdateUserInfoMenu(CustomerData**);
int UpdateUserInfoMenuGetInput();
void UpdateUserInfoMenuUpdateChoice(CustomerData**, int);
void UpdateUserInfoShowMenu(CustomerData*);
// ~~~~~~~~~~~~~~~~~~~~
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




// Update User Information Menu
// -----------------------------------
// Documentation:
//  This will provide the user with the ability
//  to choose what they want to update regarding
//  their personal information that is stored on
//  their account.
// -----------------------------------
// Parameters:
//  userCard [CustomerData]
//      session user's information that will be
//      update during this process.
// -----------------------------------
void UpdateUserInfoMenu(CustomerData **userCard)
{
    // Declarations and Initializations
    // ----------------------------------
    bool isContinue = true;     // User request to leave this menu
    int userRequest;            // User's request
    // ----------------------------------
    
    // Run the User Update Menu Loop
    do
    {
    DrawUserLoggedIn((*userCard)->userID);  // Show who is currently logged into the session
    printf("\n\n");                         // Provide extra padding for readability              
    UpdateUserInfoShowMenu(*userCard);      // Display the Menu
    
    userRequest =                           // Get the user's request and cache the value
        UpdateUserInfoMenuGetInput();       //  to process it.
    
    printf("User Request == %d\n", userRequest);
    // Inspect the user's input
    if (userRequest < 10)       // Execute the user's request
        printf("Request\n");
        //UpdateUserInfoMenuUpdateChoice(userCard, userRequest);
    else if (userRequest == 10) // Return to main menu
        printf("Exit\n");
        //isContinue = false;
    else
        printf("<!> BAD REQUEST <!>\n");
        printf("-------------------------------\n");
        printf("Please select an option from the menu provided\n");
    } while(isContinue);
} // UpdateUserInfoMenu()




// Update User Information - Get Input
// -----------------------------------
// Documentation:
//  This function will retrieve the input from the
//  user and then report back what the user has
//  requested regarding from the User Information
//  Update Menu.
// -----------------------------------
// Output:
//  Returns the user's request
//      0 = Selected was First Name
//      1 = Selected was Last Name
//      2 = Selected was Account Password
//      3 = Selected was E-Mail Address
//      4 = Selected was Phone Number
//      5 = Selected was Address [City]
//      6 = Selected was Address [State]
//      7 = Selected was Address [Country]
//      8 = Selected was Address [Street]
//      9 = Selected was Address [Zip]
//     10 = Return to main menu
//    255 = Bad Request
// -----------------------------------
int UpdateUserInfoMenuGetInput()
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
    
    // I am dreading the fact that I can't use a switch() to pull this off...
    //  I am sorry for those that are reading this; there has to be a better
    //  way to handle this, but due to time-constraint - I can't do reasonable
    //  research to figure this out.  Instead, I know If(cond.) will work
    //  just - - I'd rather use something nicer... [NG]
    if (!strncmp(userInput, "1\n", 2)) // already regretting my life's decisions.... [NG]
        return 0;   // First Name
    else if (!strncmp(userInput, "2\n", 2)) // ugh...
        return 1;   // Last Name
    else if (!strncmp(userInput, "3\n", 2)) // I
        return 2;   // Account Password
    else if (!strncmp(userInput, "4\n", 2)) // Hate
        return 3;   // E-Mail Address
    else if (!strncmp(userInput, "5\n", 2)) // This
        return 4;   // Phone Number
    else if (!strncmp(userInput, "6\n", 2)) // Seriously
        return 5;   // Address - City
    else if (!strncmp(userInput, "7\n", 2)) // I am
        return 6;   // Address - State
    else if (!strncmp(userInput, "8\n", 2)) // sorry
        return 7;   // Address - Country
    else if (!strncmp(userInput, "9\n", 2)) // that you
        return 8;   // Address - Street
    else if (!strncmp(userInput, "10\n", 3))// are reading this...
        return 9;   // Address - Zip
        
    // -------------------
    // CHECK FOR RETURN TO MAIN MENU REQUEST
    // -------------------
    else if (!CheckForUserQuit(userInput, _MAX_CHAR_INPUT_))
        return 10;  // Return to Main Menu
    else if ((!strncmp(userInput, "x\n", 2)) ||
            (strncmp(userInput, "X\n", 2)))
        return 10;  // Return to Main Menu
    
    // -------------------
    // UNKNOWN REQUEST
    // -------------------
    else 
        return 255; // Unknown Request
} // UpdateUserInfoMenuGetInput()




// Update User Information - Update Request
// -----------------------------------
// Documentation:
//  This function will allow the user to actually
//  update their information based on their request.
// -----------------------------------
void UpdateUserInfoMenuUpdateChoice(CustomerData **userCard, int request)
{
    return;
} // UpdateUserInfoMenuUpdateChoice()




// Update User Information - Show Menu
// -----------------------------------
// Documentation:
//  This function will provide the user with the
//  Update User Information Menu and any instructions
//  necessary when dealing with the this menu.
// -----------------------------------
// Parameters:
//  userCard [CustomerData]
//      Only used to display the user's current information.
// -----------------------------------
void UpdateUserInfoShowMenu(CustomerData *userCard)
{    
    printf("Update User Information Menu\n");
    printf("------------------------------------------------\n\n");
    // User's First Name
    printf("[1] - First Name\n");
    printf("       Current Value: [%s]\n", userCard->firstName);
    // User's Last Name
    printf("[2] - Last Name\n");
    printf("       Current Value: [%s]\n", userCard->lastName);
    // User's Account Password
    printf("[3] - Account Password\n");
    printf("       Current Value: [%s]\n", userCard->userKey);
    // User's E-Mail Address
    printf("[4] - E-Mail Address\n");
    printf("       Current Value: [%s]\n", userCard->email);
    // User's Phone Number
    printf("[5] - Phone Number\n");
    printf("       Current Value: [%s]\n", userCard->phoneNumber);
    // User's Address [City]
    printf("[6] - Address [City]\n");
    printf("       Current Value: [%s]\n", userCard->addressCity);
    // User's Address [State]
    printf("[7] - Address [State]\n");
    printf("       Current Value: [%s]\n", userCard->addressState);
    // User's Address [Country]
    printf("[8] - Address [Country]\n");
    printf("       Current Value: [%s]\n", userCard->addressCountry);
    // User's Address [Street]
    printf("[9] - Address [Street]\n");
    printf("       Current Value: [%s]\n", userCard->addressStreet);
    // User's Address [Zip]
    printf("[10] - Address [Zip Code]\n");
    printf("       Current Value: [%s]\n", userCard->addressPostalCode);
    // Leave the menu
    printf("[X] - Return to Main Menu\n");
} // UpdateUserInfoShowMenu()




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
