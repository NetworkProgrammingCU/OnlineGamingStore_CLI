// Common Functions
//  To avoid redundancy within the program




// Lowercase User Input
// ------------------------
// Documentation
//  This function takes the input provided by the user and
//  lowers all cases within the string.
// ------------------------
// Parameters
//  string [char*]
//      string to lower all alphabets letters
// ------------------------
// Includes
//  Used for 'tolower()'
#include <ctype.h>
// ------------------------
void LowerCaseUserInput(char string[])
{
    for(int i = 0; string[i] != '\0'; i++)
        string[i] = tolower(string[i]);
} // LowerCaseUserInput




// Check for User Quit
// ------------------------
// Documentation
//  This function will inspect the user's input and check to see
//  if the user has requested a termination.
// ------------------------
// Parameters
//  string [char*]
//      char[] to inspect; this is the user's request to examine.
//  stringSize [int]
//      the size of the char array size.
// ------------------------
// Dependency List
//  LowerCaseUserInput()
// ------------------------
// Includes
//  Used for 'strcmp()'
#include <string.h>
// ------------------------
int CheckForUserQuit(char string[], int stringSize)
{
    // Declarations and Initializations
    // ----------------------------------
    char workingString[stringSize]; // Holds 'string' var
                                    //  Because we are going to alter 'string' var,
                                    //  we do NOT want to alter the final result.
                                    //  We cache the value and allow that to be changed.
    // ----------------------------------
    
    // Copy the string value to our cache var.
    strcpy(workingString, string);
    
    // Lower all alphabet letters in the array
    LowerCaseUserInput(workingString);

    // Check for termination requests
    if (strcmp("exit\n", workingString) == 0)
        return 0; // Match!
    else if (strcmp("quit\n", workingString) == 0)
        return 0; // Match!
    else
        return 1; // Not a match!
} // CheckForUserQuit()




// Display Prompt (Pythonish)
// ------------------------
// Documentation
//  This function will display the prompt message; this is
//      to indicate that we are ready for user input.
// ------------------------
// Includes
//  Used for 'strcmp()'
#include <stdio.h>
// ------------------------
void DisplayPrompt()
{
    printf(">>>>> ");
} // DisplayPrompt()




// Clear Buffer
// ------------------------
// Documentation
//  This function will clear the char[] buffer.  This is useful to clear
//      out any pre-existing char's left over from the previous messages.
// ------------------------
// Parameters
//  stringBuffer [char*]
//      string char array to clear.
//  bufferSize [int]
//      Buffer size of the char array.
// ------------------------
void ClearBuffer(char stringBuffer[], int bufferSize)
{
    memset(stringBuffer, '\0', bufferSize);
} // ClearBuffer()
