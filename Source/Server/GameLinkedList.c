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
#include "CustomerData.h"   // Customer Data Object
#include "GameData.h"       // Game Data Object
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
    printf("Store was activated!\n");
    DisplayGameList(gList);
} // StoreDriver()




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
