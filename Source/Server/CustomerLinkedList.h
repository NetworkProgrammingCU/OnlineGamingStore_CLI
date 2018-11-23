// Customer Linked List Functionality
// ================================
// ================================
// This file holds functions related into supporting the Customer
//  Data Linked-List object.  With the functions provided in this
//  file, the functions will allow scanning through, generating,
//  and manipulate the list and nodes as necessary.




// Inclusion Guard
// -----------------
#ifndef _CUSTOMERLINKEDLISTFUNCS_H_
#define _CUSTOMERLINKEDLISTFUNCS_H_
// -----------------




// Function Prototypes for Customer Data
// -----------------------------------
void GenerateUserList(struct CustomerData**);       // Generate predefined users.
static void CreateNewCustomer(CustomerData**,       // Create a new Customer entry
                            const char*, const char*,
                            const char*, const char*,
                            const char*, const char*,
                            const char*, const char*,
                            const char*, const char*,
                            const char*, int);
static void AppendNewCustomer(CustomerData**,       // Add the new customer to
                                CustomerData *);    //   the primary Linked-List.
void ManuallyCreateNewUser(struct CustomerData**);  // Manually create a new user
                                                    //  account for our store.
bool FindUser_ReturnUserInfo(CustomerData*,         // Provides the ability to scan
                            CustomerData**,         //  for a user and checks if the
                            char*, char*);          //  credentials match.
void UserLogin(CustomerData*,                       // This will provide the procedures
                    CustomerData**);                //  for the login system.
void AskUserLogin(char**, char**);                  // Ask the user for login information
                                                    //  Required for the login system.
// -----------------------------------




// Concluding Inclusion Guard
#endif
