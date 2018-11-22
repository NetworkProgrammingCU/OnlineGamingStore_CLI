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
// ============================================




// Included Libraries
// ===============================
#include <stdio.h>              // Input\Output Stream
#include <stdbool.h>            // Because I was spoiled with C++ and C#, just give me the Bool data types!
#include <ctype.h>              // tolower() functions for user input
#include <stddef.h>             // NULLPTR; used for pointers
#include <stdlib.h>             // Pointer Memory Allocation
#include <time.h>               // time() function for randomized seeds
#include "myunp.h"              // Our custom UNP Header file
#include "CommonFunctions.h"    // Shared functions; to help minimize development cost between sub-projects.
#include "CustomerData.h"       // Customer Data Object
#include "GameData.h"           // Game Data Object
// ===============================




// Global Definitions
// ===============================
#define _NAME_ "The Exotic Hairy Pickle"    // Name of this program
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
static void GenerateUserList(struct // Generate predefined users.
    CustomerData**);
void GenerateGameList(struct        // Generate predefined games.
    GameData*);
int RandomNum(int randMin,          // Provides a random number within the given constraints.
    int randMax);
void Randomizer(char *charString,   // Generates a specific random number set for the supported types.
    int randomType);
static void CreateNewCustomer(CustomerData**,  // Create a new Customer entry
                                const char*, const char*,
                                const char*, const char*,
                                const char*, const char*,
                                const char*, const char*,
                                const char*, const char*,
                                const char*, int);
static void AppendNewCustomer(CustomerData**,  // Add the new customer to the primary Linked-List.
                    CustomerData *);
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
    // ----------------------------------
    
    // Head points to NULL
    customerList = NULL;
    
    // Randomize the seed
    srand((unsigned)time(NULL));      // This will come in handy when we do the randomization of information.
    
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
    
    // Create the customer list
    GenerateUserList(&customerList);
    
    // Get some data
    // DEBUG STUFF
    printf("First name: %s\n", customerList->firstName);
    printf("User ID: %s\n", customerList->userID);
    printf("Phone Number: %s\n", customerList->phoneNumber);
    printf("ZIP Code: %s\n", customerList->addressPostalCode);
    // END OF DEBUG STUFF
    
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
static void GenerateUserList(struct CustomerData** cList)
{
    for (int i = 0; i < 1; i++)
        switch (i)
        {
        case 0:
            CreateNewCustomer(cList,
                            "Theodore",
                            "Roosevelt",
                            "The Big Stick Teddy",
                            "1h3_13ddY",
                            "TheBigStick@yahoo.com",
                            "000-000.0000",
                            "Oyster Bay",
                            "New York",
                            "United States",
                            "20 Sagamore Hill Rd",
                            "11771",
                            1);
            break;
        } // switch
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




// Randomizer
// -----------------------------------
// Documentation
//  This function all auto-populate numeric based values into a String.
// -----------------------------------
// Parameters
//  *charString [Char[]]
//      The character (string) that will be modified.
//  randomType [int]
//      The randomization type to be executed.
//          0 = Phone Number
//          1 = Zip Code
// -----------------------------------
void Randomizer(char *charString, int randomType)
{
    // Initializations and Declarations
    // -----------------------------------
    int i;  // Used for iterating through the char array.
    // -----------------------------------
    switch (randomType)
    {
        case 0:
            // Phone Number
            for (i = 0; i < 10; i++)
                charString[i] = RandomNum(0, 10);   // Only generate a number between 0 - 9
            break;
        case 1:
            // Zip Code
            charString = RandomNum(10000, 99999);   // Only generate a random number within the given ranges to get our zip.
            break;
        default:
            // Unknown error occurred; we can not determine what Random Type we are supposed to use from here,
            //  thus, just supply '0' to assure everything continues to move smoothly.
            printf("Unknown Switch Condition was passed!\n Condition Passed was [ %d ]\n", randomType);
            charString[0] = "0\0";
            break;
    } // switch
} // Randomizer()




// Random Number
// -----------------------------------
// Documentation
//  This function will generate a random set of numbers based on the provided range.
// -----------------------------------
// Parameters
//  randMin [int]
//      The lowest boundary to produce from the randomizer (inclusive).
//  randMax [int]
//      The highest boundary to produce from the randomizer (exclusive).
// -----------------------------------
// Output
//  A random number provided by the specific ranges.
int RandomNum(int randMin, int randMax)
{
    return (rand() % randMax + randMin);
} // RandomNum()




// Create a New Customer Node
// -----------------------------------
// Documentation
//  This function will create a new node into the link-list
// -----------------------------------
// Parameters (god help me)
//  cList [CustomerData]
//      The customer list Linked-List obj. that will be modified
//  firstName [char*]
//      The customer's first name
//  lastName [char*]
//      The customer's last name
//  userID [char*]
//      The customer's User ID to log into the store
//  userKey [char*]
//      The customer's Password to log into the store
//  email [char*]
//      The customer's email address
//  phoneNumber [char*]
//      The customer's phone number
//  addressCity [char*]
//      The customer's Address information: City
//  addressState [char*]
//      The customer's Address information: State
//  addressCountry [char*]
//      The customer's Address information: Country
//  addressStreet [char*]
//      The customer's Address information: Street
//  addressPostalCode [char*]
//      The customer's Address information: Zip Code (without +4)
//  adminRights
//      when '1' or 'true', the user is considered an Administrator
// -----------------------------------
static void CreateNewCustomer(CustomerData **cList,
                        const char *firstName,
                        const char *lastName,
                        const char *userID,
                        const char *userKey,
                        const char *email,
                        const char *phoneNumber,
                        const char *addressCity,
                        const char *addressState,
                        const char *addressCountry,
                        const char *addressStreet,
                        const char *addressPostalCode,
                        int adminRights)
{
    // Create a new Node to store the new information
    CustomerData* tempCList = (struct CustomerData*)malloc(sizeof(CustomerData));

    // Generate the required fields
    tempCList->firstName = firstName;
    tempCList->lastName = lastName;
    tempCList->userID = userID;
    tempCList->userKey = userKey;
    tempCList->email = email;
    tempCList->phoneNumber = phoneNumber;
    tempCList->addressCity = addressCity;
    tempCList->addressState = addressState;
    tempCList->addressCountry = addressCountry;
    tempCList->addressStreet = addressStreet;
    tempCList->addressPostalCode = addressPostalCode;
    tempCList->admin = adminRights;

    // Update the next pointer
    tempCList->next = NULL;

    AppendNewCustomer(cList, tempCList);
} // CreateNewCustomer()




// Append New Customer
// -----------------------------------
// Documentation:
//  This function will take the primary list and append the new list.
// -----------------------------------
// Parameters:
//  cList [CustomerData]
//      The primary Linked-List; this will be modified
//  newCList [CustomerData]
//      The temporary list, which will be added to the primary list.
// -----------------------------------
static void AppendNewCustomer(CustomerData **cList, CustomerData *newCList)
{
    // Empty list; merely append it
    if (cList == NULL)
        *cList = newCList;
    else
    {
        // Add the new customer to the front of the list, all others is pushed back.
        newCList->next = *cList;
        *cList = newCList;
    } // else
} // AppendNewCustomer()
