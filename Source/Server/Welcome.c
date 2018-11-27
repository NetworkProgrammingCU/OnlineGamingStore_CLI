// Welcome Menu
// ================================
// ================================
// This file contains the Welcome Menu functions,
//  which will help guide the user into accessing
//  the store.  Because the user must be registered
//  in order to access the store, we will provide
//  the user with some assistance - by asking them
//  if they want to register, login, or exit.




// Included Libraries
// ===============================
#include <stdio.h>              // Input\Output Stream
#include "Welcome.h"            // Welcome Function Prototype
#include "GlobalDefs.h"         // Program Macro-Definitions
#include "CommonFunctions.h"    // Prompt and Filtering user Input
#include "ProgInformation.h"    // Used for the DrawHeader function
#include <string.h>             // strcmp() for User Account Authentication Challenge
// ===============================




// Welcome Protocol
// -----------------------------------
// Documentation:
//  This function will help to provide the necessary Welcome or Start
//  protocol - guiding the user through the protocol.
// -----------------------------------
// Output:
//  User Request
//      0 = Login Request
//      1 = Register Request
//      2 = Exit Request
// -----------------------------------
int WelcomeProtocol()
{
    // Declarations and Initializations
    // ----------------------------------
    int userRequest;        // Record the user's request
    // ----------------------------------
    
    // Protocol to get the user's input
    do
    {
        DrawHeader();           // Display the program's header
        
        WelcomeMessage();       // Display the welcome message
        WelcomeMenu();          // Display the Welcome Menu
        
        userRequest = WelcomeFetchInput();  // Record the user's request
        
        if (userRequest != 255) // If the user's request is valid, return it.
            return userRequest;
        
        
        ClearScreen();          // User's request was not valid; retry again.
    } while(1);
} // WelcomeProtocol()




// Welcome Message
// -----------------------------------
// Documentation:
//  This function will ask the user for input based on the
//  welcome menu.  This function will also depend on another
//  function to analyze the user input.
// -----------------------------------
// Output:
//  User Request
//      0 = Login Request
//      1 = Register Request
//      2 = Exit Request
//      255 = Fatal Error; unknown request
int WelcomeFetchInput()
{
    // Declarations and Initializations
    // ----------------------------------
    char userInput[_MAX_CHAR_INPUT_];   // This will be used to capture the user's input.
    // ----------------------------------
    
    DisplayPrompt();    // Show the prompt to the user.
    fgets(userInput, _MAX_CHAR_INPUT_, stdin);
    
    FilterUserInputArray(userInput, _MAX_CHAR_INPUT_);
    LowerCaseUserInput(userInput);
    
    // Analyze the user input and return the desired request
    if(strcmp(userInput, "log") == 0)
        // User Requested to Log Into the store
        return 0;
    else if (strcmp(userInput, "reg") == 0)
        // User Requested to Register to the store
        return 1;
    else if (CheckForUserQuit(userInput, _MAX_CHAR_INPUT_) == 0)
        // User Requested to leave from the store
        return 2;
    else
    {
        printf("<!> BAD REQUEST <!>\n");
        printf("-------------------------------\n");
        printf("Please select an option from the menu provided\n");
        printf(" User Requested [%s]\n", userInput);
        return 255;
    } // Fatal Error \ Unknown Request
} // WelcomeFetchInput()




// Welcome Message
// -----------------------------------
// Documentation:
//  This function will provide the welcome message
//  and the options available when first accessing
//  the store.
// -----------------------------------
void WelcomeMessage()
{
    // Welcome Page
    // -------------------------
    printf("Welcome to the %s Store!\n", _NAME_);
    printf("------------------------------------\n");
    printf("------------------------------------\n");
    printf("\n");
    printf("In order to access the store, you must have an account with this service.\n");
    printf("If you don't have an account, you can easily create a new account!\n");
    printf("Because of a tight budget and thinking of maximizing our profits, we require that you use your keyboard in order to navigate in this store.  If you would like a nice graphical interface, feel free to donate us unlimited supply of financial currency (NOT MONOPOLY MONEY!)\n");
    printf("\n");
    printf("\n");
} // WelcomeMessage()




// Welcome Menu
// -----------------------------------
// Documentation:
//  This function will display the welcome on the user's terminal.
// -----------------------------------
void WelcomeMenu()
{
    printf("Please use your keyboard to interact with the store.\n");
    printf("\n");
    printf("\n");
    printf("Other Options\n");
    printf("--------------\n");
    printf("[Log]  - Login\n");
    printf("[Reg]  - Register a new account\n");
    printf("[Exit] - Leave the store\n");
    printf("--------------\n");
    printf("\n");
} // WelcomeMenu()
