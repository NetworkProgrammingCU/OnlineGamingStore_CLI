// Included Libraries
// ===============================
#include "GameData.h"           // Game Data Object
// ===============================




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
void GenerateGameList(struct GameData** gList)
{
    for (int i = 0; i < 1; ++i)
    switch(i)
    {
        case 0:
            CreateNewGame(gList,
                            "The Ultimate Doom",
                            "Hell has unleashed",
                            "id Software",
                            "id Software",
                            "FPS",
                            "Nothing");
            break;
    } // switch
} // GenerateGameList()




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
    GameData* tempGList = (struct GameData*)malloc(sizeof(CustomerData));
    
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
