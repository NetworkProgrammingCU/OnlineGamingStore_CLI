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
#include <stdio.h>              // Input\Output Stream
#include <stdbool.h>            // Because I was spoiled with C++ and C#, just give me the Bool data types!
#include <ctype.h>              // tolower() functions for user input
#include <stddef.h>             // NULLPTR; used for pointers
#include <stdlib.h>             // Pointer Memory Allocation
#include "myunp.h"              // Our custom UNP Header file
#include "CommonFunctions.h"    // Shared functions; to help minimize development cost between sub-projects.
#include "CustomerData.h"       // Customer Data Object
#include "GameData.h"           // Game Data Object
// ===============================



// Global Definitions
// ===============================
#define _NAME_ "Totally Not Steam!"         // Name of this program
#define _VERSION_ "1.0"                     // Version of this program
#define _VERSION_NAME_ "Squeeze"            // Version Code-Name
// ===============================



// Function Prototypes
// ===============================
void DrawInstructionsMainMenu();    // Display the program instructions onto the terminal.
void DrawMenuMain();                // Display the main menu to the user.
void DrawStorePage();               // Display the store page to the user.
void CloseProgram();                // Perform the termination protocol (if any).
void DrawHeader();                  // Display the program header onto the terminal buffer.
void DrawAbout();                   // Display the purpose of the program to the user.
void DrawUserLoggedIn();            // Display who is viewing the store.
void GenerateUserList(struct        // Generate predefined users.
    CustomerData*);
void GenerateGameList(struct        // Generate predefined games.
    GameData*);
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
        customerList = NULL;        // Customer Data Linked-List
    struct GameData*
        gameList = NULL;            // Game Data Linked-List
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



// Generate Customer List
// -----------------------------------
// Documentation
//  This function will simply generate a small list of users that have an account within the store.
// -----------------------------------
// Parameters
//  *cList [CustomerData]
//      The 'head' or 'starting' position of the LinkedList of Customer Data.
//      This list -WILL-BE-MODIFIED!
// -----------------------------------
void GenerateUserList(struct CustomerData* cList)
{
    // For right now, we will only create one object instance
    cList->firstName = "Theodore";
    cList->lastName = "Roosevelt";
    cList->userID = "The Big Stick Teddy";
    cList->userKey = "1h3_13ddY";
    cList->email = "TheBigStick@yahoo.com";
    cList->phoneNumber = "000-000.0000";
    cList->addressCity = "Oyster Bay";
    cList->addressState = "New York";
    cList->addressCountry = "United States";
    cList->addressStreet = "20 Sagamore Hill Rd";
    cList->addressPostalCode = "11771";
    cList->admin = 1;
    cList->next = NULL;
} // GenerateUserList()



// Generate Game List
// -----------------------------------
// Documentation
//  This function will merely provide a list of games that is available within the store.
// -----------------------------------
// Parameters
//  *glist [GameData]
//      The 'head' or 'starting' position of the LinkedList of Game Data.
//      This list -WILL-BE-MODIFIED!
// -----------------------------------
void GenerateGameList(struct GameData* gList)
{
    // For right now, we will only create one object instance
    gList->title = "The Ultimate Doom";
    gList->description = "Hell has unleashed";
    gList->publisher = "id Software";
    gList->developers = "id Software";
    gList->genre = "FPS";
    gList->notes = "Nothing";
    gList->next = NULL;
} // GenerateGameList()
