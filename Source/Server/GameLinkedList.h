// Guards
#ifndef _GAMELINKEDLISTFUNCS_H_
#define _GAMELINKEDLISTFUNCS_H_


// Function Prototypes
// ===============================
void GenerateGameList(struct             // Generate predefined games.
    GameData**);
static void CreateNewGame(GameData**,           // Create a new Game entry
                    const char*, const char*,
                    const char*, const char*,
                    const char*, const char*);
static void AppendNewGame(GameData**,           // Add the new game to the primary Linked-List.
                    GameData*);
// ===============================


// Concluding Guard
#endif
