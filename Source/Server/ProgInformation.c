// Program Information and Instructions
// ================================
// ================================
// This file holds some of the program information and instructions
//  that could be useful for the user within the program.  Allowing
//  the user read some of the program's contents and help documentation
//  if any are to be provided.




// Included Libraries
// ===============================
#include <stdio.h>              // Input\Output Stream
#include "GlobalDefs.h"         // Program Macro-Definitions
// ===============================




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
