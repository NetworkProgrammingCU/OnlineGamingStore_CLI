// Game Linked List Functionality
// ================================
// ================================
// This file holds functions related into supporting the Game Data
//  Linked-List object.  With the functions provided in this file,
//  the functions will allow scanning through, generating, and
//  manipulate the list and nodes as necessary.




// Inclusion Guard
// -----------------
#ifndef _GAMELINKEDLISTFUNCS_H_
#define _GAMELINKEDLISTFUNCS_H_
// -----------------




// Function Prototypes for Game Data
// -----------------------------------
void GenerateGameList(struct GameData**);       // Generate predefined games.
static void CreateNewGame(GameData**,           // Create a new Game entry
                    const char*, const char*,
                    const char*, const char*,
                    const char*, const char*);
static void AppendNewGame(GameData**,           // Add the new game to
                            GameData*);         //  the primary Linked-List.
// -----------------------------------




// Concluding Inclusion Guard
#endif
