// Game Linked List Functionality
// ================================
// ================================
// This file holds functions related into supporting the Game Data
//  Linked-List object.  With the functions provided in this file,
//  the functions will allow scanning through, generating, and
//  manipulate the list and nodes as necessary.




// Included Libraries
// ===============================
#include <stdio.h>          // Required for input and output
#include <stddef.h>         // NULLPTR; used for pointers
#include <stdlib.h>         // Pointer Memory Allocation
#include <stdbool.h>        // Because I was spoiled with C++ and C#, just give me the Bool data types!
#include <string.h>         // strcmp() for User Account Authentication Challenge
#include <ctype.h>          // for toupper(); Full Game Info - Game Title
#include "GlobalDefs.h"     // Program Macro-Definitions
#include "CustomerData.h"   // Customer Data Object
#include "GameData.h"       // Game Data Object
#include "ProgInformation.h"// Instructions and Informational Output
#include "CommonFunctions.h"// Shared functions; to help minimize development cost between sub-projects.
#include "GameLinkedList.h" // Prototype functions for this implementation source
// ===============================




// Macro-Definitions
// ===============================
#define naturalStart 1      // Because humans start at '1' naturally,
                            //  when we start an iterator
                            //  (commonly 'i' in a loop), start at
                            //  that position instead '0'.
                            //  This exists for my sanity ;) [NG]
// ===============================




// Display Game List
// -----------------------------------
// Documentation:
//  This function will display all of the
//  products available within the store.
// -----------------------------------
// Parameters:
//  gList [GameData]
//      Holds the products within the store
// -----------------------------------
void DisplayGameList(GameData* gList)
{
    // Because the user will select a game from the list,
    //  we will a for() to also update our 'i'.  This 'i'
    //  is necessary so the user can 'select' a game from
    //  the list provided from here.
    for (int i = naturalStart; gList != NULL; ++i)
    {
        // Display the Game Title
        printf("[%d] - %s\n", i, gList->title);
        
        // Display the Publisher
        printf("       %s\n", gList->publisher);
        
        // Provide an extra space to assure
        //  that the products are 'connected'
        //  visually to the user.
        printf("\n");
        
        // Go to the next product
        gList = gList->next;
    } // while
} // DisplayGameList()




// Store Driver
// -----------------------------------
// Documentation:
//  This function manages how the store will operate
//  and work within the program.  Essentially, this
//  is our store driver - drive the user to the operate
//  protocols as specified in this function.
// -----------------------------------
// Parameters:
//  gList [GameData]
//      Holds the products within the store
//  userCard [CustomerData]
//      Holds the user that is currently logged into
//      the session.
// -----------------------------------
void StoreDriver(GameData *gList, CustomerData *userCard)
{
    // Declarations and Initializations
    // ----------------------------------
    int numProducts = 0;        // How many products exists within the store
    int userRequest;            // User's request within the store page.
    bool isContinue = true;     // User request to leave the store (return to main menu)
    // ----------------------------------

    // Run the store loop
    do
    {
        // Clear some space for the main menu screen
        ClearScreen();
        
        // Display the program's header
        DrawHeader();
        
        // Display the user that is presently logged into the system
        DrawUserLoggedIn(userCard->userID);
        
        // Push a few line-feeds to separate the contents
        printf("\n\n");
        
        // Provide a header for the product list
        printf("Store Page\n");
        
        // Provide a header border
        StoreBorder();
        
        // Provide an extra line-feed
        printf("\n");
        
        // Display the products
        DisplayGameList(gList);
        
        // Retrieve how many are available.
        numProducts = CountProducts(gList);

        // Provide a footer border
        StoreBorder();
        
        // Ask the user what they want todo and capture the response
        userRequest = StoreMenu(numProducts);
        
        
        switch (userRequest)
        {
            case 0:     // User requested to return to the main menu
                isContinue = false;
                break;
            case -1:    // Invalid request or bad input
                printf("<!> BAD REQUEST <!>\n");
                printf("-------------------------------\n");
                printf("Please select an option from the menu provided\n");
                break;
            default:    // Selected something from the store
                SelectedProduct(gList, userCard, userRequest);
                break;
        } // switch()
    } while (isContinue);
} // StoreDriver()




// Selected Product
// -----------------------------------
// Documentation:
//  This function will provide a small protocol
//  procedure for how the information should be
//  presented and to provide the user with the
//  choice to 'purchase' the game and\or return
//  back to the main menu.
// -----------------------------------
// Parameters:
//  gList [GameData]
//      Holds the products within the store
//  userCard [CustomerData]
//      Holds the current user within this session
//  numRequested [int]
//      Holds the number (product ID; counter)
//      that the user requested to view.
// -----------------------------------
void SelectedProduct(GameData *gList, CustomerData *userCard, int numRequested)
{
    // Declarations and Initializations
    // ----------------------------------
    bool isContinue = true;         // Required for the loop; is the
                                    //  user finished viewing the product?
    int userRequest;                // User's request
    // ----------------------------------
    
    // Loop; assure proper feedback from the user
    //  hence why we need this loop.
    do
    {
        // Clear some space for the main menu screen
        ClearScreen();
        
        // Display the program's header
        DrawHeader();
        
        // Display the user that is presently logged into the system
        DrawUserLoggedIn(userCard->userID);
        
        // Push a few line-feeds to separate the contents
        printf("\n\n");
        
        // Provide a header for the product list
        printf("Game Details\n");
        
        // Provide a header border
        StoreBorder();
        
        // Provide an extra line-feed
        printf("\n");
        
        // Display the product to the user
        SelectedProduct_Display(gList, numRequested);
        
        // Provide a header border
        StoreBorder();
        
        // Retrieve user request
        userRequest = SelectedProduct_FeedBack();
        
        // Evaluate the user's request
        switch(userRequest)
        {
            case 0:     // Game back to the store page
                isContinue = false;
                break;
            case 1:     // Purchase the product
                SelectedProduct_Purchased(userCard);
                isContinue = false;
                break;
            default:    // Incorrect request
                printf("<!> BAD REQUEST <!>\n");
                printf("-------------------------------\n");
                printf("Please select an option from the menu provided\n");
                break;
        } // switch()
    } while (isContinue);
} // SelectedProduct()




// Selected Product - Purchased
void SelectedProduct_Purchased(CustomerData *userCard)
{
    printf("Game purchased!\n");
    printf("====================\n");
    printf("Game will be shipped to the following address:\n");
    printf("%s, %s, %s, %s, %s\n", userCard->addressStreet, userCard->addressCity, userCard->addressState, userCard->addressPostalCode, userCard->addressCountry);
} // SelectedProduct_Purchased()




// Selected Product - Feedback
// -----------------------------------
// Documentation:
//  This function will ask the user two questions:
//  - Purchase the game
//  - Return to Store Page
//  Nothing is really done within this function
//  other than retrieving feedback from the user
//  and checking the response.
// -----------------------------------
// Output:
//  0 = Go back to Store Page
//  1 = Purchase Item
//  2 = Incorrect or unknown response
// -----------------------------------
int SelectedProduct_FeedBack()
{
    // Declarations and Initializations
    // ----------------------------------
    char userInput[_MAX_CHAR_INPUT_];    // This will hold the user input.
    // ----------------------------------
    
    // Show the user what options are available
    printf("What would you like to do?\n");
    printf("\n");
    printf("Options:\n");
    printf("------------------\n");
    printf("[Buy] - Purchase the game\n");
    printf("[X] - Return to the Store\n");    
    
    // Display the prompt
    DisplayPrompt();
    
    // Get the user input
    fgets(userInput, _MAX_CHAR_INPUT_, stdin);
    
    // Lower case the user's input
    LowerCaseUserInput(userInput);
    
    // Try to determine the user's request
    // User requested to buy the game
    if (!strncmp(userInput, "buy", 3))
        return 1;
        
    // User request to go back to previous menu?
    else if (!CheckForUserQuit(userInput, _MAX_CHAR_INPUT_))
        return 0;  // Return to Store Page
    else if ((!strncmp(userInput, "x\n", 2)) ||
            (!strncmp(userInput, "X\n", 2)))
        return 0;  // Return to Store Page
    
    // Incorrect request?
    else
        return 2;
} // SelectedProduct_FeedBack()




// Selected Product - Display Game
// -----------------------------------
// Documentation:
//  This function will provide the game
//  information to the user.
// -----------------------------------
// Parameters:
//  gList [GameData]
//      Holds the products within the store
//  numRequested [int]
//      Holds the number (product ID; counter)
//      that the user requested to view.
// -----------------------------------
void SelectedProduct_Display(GameData *gList, int numRequested)
{
    // Scan the Linked-List until we find the exact product we are looking for
    //  Remember, we can not DYNAMICALLY go specifically to that node, we must
    //  scan until we hit that exact node.
    for(int i = 1; i < numRequested; ++i)
        gList = gList->next;
    
    
    // Provide the Game Information
    // -----------------------------
    
    // TITLE
    printf("%s\n", gList->title);
    printf("\n");
    
    // DESCRIPTION
    printf("Description:\n");
    printf("%s\n", gList->description);
    printf("\n");
    
    // PUBLISHER
    printf("Publisher:\n");
    printf("%s\n", gList->publisher);
    printf("\n");
    
    // DEVELOPERS
    printf("Developers:\n");
    printf("%s\n", gList->developers);
    printf("\n");
    
    // GENRE
    printf("Genre:\n");
    printf("%s\n", gList->genre);
    printf("\n");
    
    // NOTES
    printf("Notes:\n");
    printf("%s\n", gList->notes);
    printf("\n");
} // SelectedProduct_Display()




// Store Menu
// -----------------------------------
// Documentation:
//  This allows the user to issue a request
//  as to what they want to do within the store.
//  They may select a product or return back
//  to the main menu.
// -----------------------------------
// Parameters:
//  numProducts [int]
//      How many products are avialable in the store
// -----------------------------------
// Output:
//   -1 = Invalid selection
//    0 = Return to Main Menu
//  0 < = Product within 
// -----------------------------------
int StoreMenu(int numProducts)
{
    // Declarations and Initializations
    // ----------------------------------
    char userInput[_MAX_CHAR_INPUT_];   // This will hold the user input.
    int numInput;                       // Holds numeric value of what
                                        //  the user typed.
    // ----------------------------------
    
    // Show 'Other Options' and instructions
    printf("Select the game by using the number keys\n");
    printf("\n");
    printf("Other Options:\n");
    printf("------------------\n");
    printf("[X] - Exit\n");
    
    
    // Display the prompt
    DisplayPrompt();
    
    // Get the user input
    fgets(userInput, _MAX_CHAR_INPUT_, stdin);
    
    // Lower case the user's input
    LowerCaseUserInput(userInput);
    
    // Fetch the numeric value; Convert from string to int (safely)
    numInput = strtol(userInput, NULL, 10);
    
    // Inspect the user's input and determine their request.
    if((numInput <= numProducts) &&         // 1 <= numInput <= numProducts
       (numInput >= naturalStart) &&
       (naturalStart <= numProducts))       // 1 <= numProducts; assure we have atleast
                                            //   one product available
        return numInput;
        
    // -------------------
    // CHECK FOR RETURN TO MAIN MENU REQUEST
    // -------------------
    else if (!CheckForUserQuit(userInput, _MAX_CHAR_INPUT_))
        return 0;  // Return to Main Menu
    else if ((!strncmp(userInput, "x\n", 2)) ||
            (!strncmp(userInput, "X\n", 2)))
        return 0;  // Return to Main Menu
        
    // -------------------
    // UNKNOWN REQUEST
    // -------------------
    else 
        return -1; // Unknown Request
} // StoreMenu()




// Count Products
// -----------------------------------
// Documentation:
//  This function will provide a number of
//  how many products exists within the store,
//  this will also be used to determine what
//  game the user selected - as the counter
//  will act as an ID to the products that is
//  displayed in the store.
// -----------------------------------
// Parameters:
//  gList [GameData]
//      Holds the products within the store
// -----------------------------------
// Output:
//  Number of Products [int]
//      How many products are available within the store
//      Also acts as an ID for each product listed
// -----------------------------------
int CountProducts(GameData* gList)
{
    // Declarations and Initializations
    // ----------------------------------
    int numProducts = 0;    // Counter for products
    // ----------------------------------

    // Merely scan the list and stop once we
    //  hit the end of the list.
    while(gList != NULL)
    {
        // Increment the counter
        ++numProducts;
        
        // Go to the next product
        gList = gList->next;
    } // while()
    
    // Return the number of available products
    return numProducts;
} // CountProducts()




// Store Border
// -----------------------------------
// Documentation:
//  This function will merely provides a border.
//  Ideally to help separate the content and to showcase focus
// -----------------------------------
void StoreBorder()
{
    printf("------------------------------------\n");
} // StoreBorder




// Append New Game
// -----------------------------------
// Documentation:
//  This function will take the primary list and append the new list.
// -----------------------------------
// Parameters:
//  gList [GameData]
//      The primary Linked-List; this will be modified
//  newGList [GameData]
//      The temporary list, which will be added to the primary list.
// -----------------------------------
static void AppendNewGame(GameData **gList, GameData *newGList)
{
    // Empty list; merely append it
    if (gList == NULL)
        *gList = newGList;
    else
    {
        // Add the new game to the front of the list, all others is pushed back.
        newGList->next = *gList;
        *gList = newGList;
    } // else
} // AppendNewGame()




// Create New Game Entry
// -----------------------------------
// Documentation:
//  This function will create a new node into the link-list
// -----------------------------------
// Parameters:
//  gList [GameData]
//      The game list Linked-List obj. that will be modified.
//  title [char *]
//      Title of the game.
//  description [char *]
//      Description of the game.
//  publisher [char *]
//      Game publisher
//  developers [char *]
//      Developers for the game
//  genre [char *]
//      The game's genre.
//  notes [char *]
//      Notes regarding the game.
// -----------------------------------
static void CreateNewGame(GameData** gList,
                            const char *title,
                            const char *description,
                            const char *publisher,
                            const char *developers,
                            const char *genre,
                            const char *notes)
{
    // Create a new Node to store the new information
    GameData* tempGList = (struct GameData*)malloc(sizeof(GameData));
    
    // Generate the required fields.
    tempGList->title = (char *)title;
    tempGList->description = (char *)description;
    tempGList->publisher = (char *)publisher;
    tempGList->developers = (char *)developers;
    tempGList->genre = (char *)genre;
    tempGList->notes = (char *)notes;
    
    // Update the next pointer
    tempGList->next = NULL;
    
    // Add the entry into the linked-list.
    AppendNewGame(gList, tempGList);
} // GenerateNewGame()




// Generate Game List
// -----------------------------------
// Documentation
//  This function will merely provide a list of
//  games that is available within the store.
// -----------------------------------
// Parameters
//  *glist [GameData]
//      The 'head' or 'starting' position of the LinkedList of Game Data.
//      This list -WILL-BE-MODIFIED!
// -----------------------------------
void GenerateGameList(struct GameData** gList)
{
    for (int i = 0; i < 3; ++i)
        switch (i)
        {
        case 0:
            CreateNewGame(gList,                        // Game Linked-List
                            "Ultimate Doom",            // Title
                            "UAC Unleashed the hell!",  // Description
                            "id Software",              // Publisher
                            "id Software",              // Developers
                            "First-Person Shooter",     // Genre
                            "Hell has been released");  // Notes
            break;
        case 1:
            CreateNewGame(gList,                        // Game Linked-List
                            "Doom 2",                   // Title
                            "Hell on Earth",            // Description
                            "id Software",              // Publisher
                            "id Software",              // Developers
                            "First-Person Shooter",     // Genre
                            "RIP Daisy");               // Notes
            break;
        case 2:
            CreateNewGame(gList,                        // Game Linked-List
                            "Final Doom",               // Title
                            "The Plutonia Experiement", // Description
                            "id Software",              // Publisher
                            "id Software",              // Developers
                            "First-Person Shooter",     // Genre
                            "It's never over!");        // Notes
            break;
        } // switch
} // GenerateGameList()
