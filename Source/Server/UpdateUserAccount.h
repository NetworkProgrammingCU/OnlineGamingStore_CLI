// Update User Account Information
// ================================
// ================================
// This file holds functions that allows the user to update their
//  personal account information.  Thus, their settings are changed
//  in real time during their active session with the service.




// Inclusion Guard
// -----------------
#ifndef _UPDATEUSRACCINFOFUNCS_H_
#define _UPDATEUSRACCINFOFUNCS_H_
// -----------------




// Function Prototypes for Update Account Information
// -----------------------------------
void UpdateUserInfoMenu(CustomerData**);                    // Provides the menu
int UpdateUserInfoMenuGetInput();
void UpdateUserInfoMenuUpdateChoice(CustomerData**, int);
void UpdateUserInfoShowMenu(CustomerData*);
void UpdateUserInfoMenuUpdateChoice_MSG(char*, char**);
// -----------------------------------




// Concluding Inclusion Guard
#endif
