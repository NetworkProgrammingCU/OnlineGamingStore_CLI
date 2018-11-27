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
void StoreDriver(GameData*, CustomerData*);     // The Store Driver; manages
                                                //  how the store operates.
void DisplayGameList(GameData*);                // Displays the products on
                                                //  the terminal.
void StoreBorder();                             // Displays the border
int CountProducts(GameData*);                   // Returns how many products exists
                                                //  within the store
int StoreMenu(int);                             // Allows user to provide a request,
                                                //  select game or return to main menu.
void SelectedProduct(GameData*, CustomerData*,  // This function provides a protocol of
                     int);                      //  displaying the product and giving
                                                //  user the ability to purchase it or
                                                //  return back to the store page.
void SelectedProduct_Display(GameData*, int);   // Display the full game information
int SelectedProduct_FeedBack();                 // Fetch user response about the product.
// -----------------------------------




// Concluding Inclusion Guard
#endif
