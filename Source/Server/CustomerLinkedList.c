// Customer Linked List Functionality
// ================================
// ================================
// This file holds functions related into supporting the Customer
//  Data Linked-List object.  With the functions provided in this
//  file, the functions will allow scanning through, generating,
//  and manipulate the list and nodes as necessary.




// Included Libraries
// ===============================
#include <stdio.h>              // Required for input and output
#include <stddef.h>             // NULLPTR; used for pointers
#include <stdlib.h>             // Pointer Memory Allocation
#include "CustomerData.h"       // Game Data Object
#include "CommonFunctions.h"    // Prompt
// ===============================




// Append New Customer
// -----------------------------------
// Documentation:
//  This function will take the primary list and append the new list.
// -----------------------------------
// Parameters:
//  cList [CustomerData]
//      The primary Linked-List; this will be modified
//  newCList [CustomerData]
//      The temporary list, which will be added to the primary list.
// -----------------------------------
static void AppendNewCustomer(CustomerData **cList, CustomerData *newCList)
{
    // Empty list; merely append it
    if (cList == NULL)
        *cList = newCList;
    else
    {
        // Add the new customer to the front of the list, all others is pushed back.
        newCList->next = *cList;
        *cList = newCList;
    } // else
} // AppendNewCustomer()




// Create a New Customer Node
// -----------------------------------
// Documentation
//  This function will create a new node into the link-list
// -----------------------------------
// Parameters (god help me)
//  cList [CustomerData]
//      The customer list Linked-List obj. that will be modified
//  firstName [char*]
//      The customer's first name
//  lastName [char*]
//      The customer's last name
//  userID [char*]
//      The customer's User ID to log into the store
//  userKey [char*]
//      The customer's Password to log into the store
//  email [char*]
//      The customer's email address
//  phoneNumber [char*]
//      The customer's phone number
//  addressCity [char*]
//      The customer's Address information: City
//  addressState [char*]
//      The customer's Address information: State
//  addressCountry [char*]
//      The customer's Address information: Country
//  addressStreet [char*]
//      The customer's Address information: Street
//  addressPostalCode [char*]
//      The customer's Address information: Zip Code (without +4)
//  adminRights
//      when '1' or 'true', the user is considered an Administrator
// -----------------------------------
static void CreateNewCustomer(CustomerData **cList,
                        const char *firstName,
                        const char *lastName,
                        const char *userID,
                        const char *userKey,
                        const char *email,
                        const char *phoneNumber,
                        const char *addressCity,
                        const char *addressState,
                        const char *addressCountry,
                        const char *addressStreet,
                        const char *addressPostalCode,
                        int adminRights)
{
    // Create a new Node to store the new information
    CustomerData* tempCList = (struct CustomerData*)malloc(sizeof(CustomerData));

    // Generate the required fields
    tempCList->firstName = (char *)firstName;
    tempCList->lastName = (char *)lastName;
    tempCList->userID = (char *)userID;
    tempCList->userKey = (char *)userKey;
    tempCList->email = (char *)email;
    tempCList->phoneNumber = (char *)phoneNumber;
    tempCList->addressCity = (char *)addressCity;
    tempCList->addressState = (char *)addressState;
    tempCList->addressCountry = (char *)addressCountry;
    tempCList->addressStreet = (char *)addressStreet;
    tempCList->addressPostalCode = (char *)addressPostalCode;
    tempCList->admin = adminRights;

    // Update the next pointer
    tempCList->next = NULL;

    // Add the entry into the linked-list.
    AppendNewCustomer(cList, tempCList);
} // CreateNewCustomer()




// Generate Customer List
// -----------------------------------
// Documentation
//  This function will simply generate a small list of users that have an account within the store.
// -----------------------------------
// Parameters
//  *cList [CustomerData]
//      The 'head' or 'starting' position of the LinkedList of Customer Data.
//      This list -WILL-BE-MODIFIED!
// -----------------------------------
void GenerateUserList(struct CustomerData** cList)
{
    for (int i = 0; i < 3; i++)
        switch (i)
        {
        case 0:
            CreateNewCustomer(cList,
                            "Theodore",
                            "Roosevelt",
                            "The Big Stick Teddy",
                            "1h3_13ddY",
                            "TheBigStick@yahoo.com",
                            "000-000.0000",
                            "Oyster Bay",
                            "New York",
                            "United States",
                            "20 Sagamore Hill Rd",
                            "11771",
                            1);
            break;
        case 1:
            CreateNewCustomer(cList,
                            "Al",
                            "Bundy",
                            "AlDaddyBundy",
                            "shootme",
                            "AlBimby@GarysShoes.com",
                            "000-000.0000",
                            "Chicago",
                            "Illinois",
                            "United States",
                            "9764 Jeopardy Lane",
                            "60015",
                            0);
            break;
        case 2:
            CreateNewCustomer(cList,
                            "Hana",
                            "Eris",
                            "Hana",
                            "1234",
                            "HanaErie@gmail.com",
                            "000-000.0000",
                            "El Paso",
                            "Texas",
                            "United States",
                            "4389 Brosius Cir.",
                            "79904",
                            0);
            break;
        } // switch
} // GenerateUserList()




// Manually Create a New User Account
// -----------------------------------
// Documentation:
//  This function will guide the user into creating a new
//  account into the store.  This function will provide
//  step-by-step procedure into creating an account.
// -----------------------------------
// Parameters:
//  cList [CustomerData]
//      The primary Linked-List that will be modified to
//      retain the new user account.
// -----------------------------------
void ManuallyCreateNewUser(struct CustomerData** cList)
{
    // Declarations and Initializations
    // ----------------------------------
    const int charSize = 128;   // Character pointer array size.
    int adminRights = 0;        // By default, the new user can not be an administrator.
    char *firstName         = malloc(charSize*sizeof(char));   // First Name
    char *lastName          = malloc(charSize*sizeof(char));   // Last Name
    char *userID            = malloc(charSize*sizeof(char));   // User Login
    char *userKey           = malloc(charSize*sizeof(char));   // User Password
    char *email             = malloc(charSize*sizeof(char));   // E-Mail Address
    char *phoneNumber       = malloc(charSize*sizeof(char));   // Phone Number
    char *addressCity       = malloc(charSize*sizeof(char));   // Address (city)
    char *addressState      = malloc(charSize*sizeof(char));   // Address (state)
    char *addressCountry    = malloc(charSize*sizeof(char));   // Address (country)
    char *addressStreet     = malloc(charSize*sizeof(char));   // Address (street)
    char *addressPostalCode = malloc(charSize*sizeof(char));   // Address (Zip Code)
    // ----------------------------------
    
    // Tell the user that we're gathering information from them
    printf("In order to register an account in this store, we're going to need a bit of information from you.\n");
    printf("Please provide the following information:\n\n");
    
    
    // Capture input from the user
    // -------------------------------
    // User Login ID
    printf("Provide User Login Screen Name:\n");
    DisplayPrompt();
    fgets(userID, charSize, stdin);
    
    // User Login Password
    printf("Provide User Login Password:\n");
    DisplayPrompt();
    fgets(userKey, charSize, stdin);
    
    // User E-Mail Account
    printf("Provide an E-Mail Account:\n");
    DisplayPrompt();
    fgets(email, charSize, stdin);
    
    // User First Name
    printf("Provide your First Name:\n");
    DisplayPrompt();
    fgets(firstName, charSize, stdin);
    
    // User Last Name
    printf("Provide your Last Name:\n");
    DisplayPrompt();
    fgets(lastName, charSize, stdin);
    
    // User Phone Number
    printf("Provide your Phone Number:\n");
    DisplayPrompt();
    fgets(phoneNumber, charSize, stdin);
    
    // User Address [city]
    printf("Provide your Address (City):\n");
    DisplayPrompt();
    fgets(addressCity, charSize, stdin);
    
    // User Address [state]
    printf("Provide your Address (State):\n");
    DisplayPrompt();
    fgets(addressState, charSize, stdin);
    
    // User Address [country]
    printf("Provide your Address (Country):\n");
    DisplayPrompt();
    fgets(addressCountry, charSize, stdin);
    
    // User Address [street]
    printf("Provide your Address (Street):\n");
    DisplayPrompt();
    fgets(addressStreet, charSize, stdin);
    
    // User Address [zip]
    printf("Provide your Address (ZIP-Code):\n");
    DisplayPrompt();
    fgets(addressPostalCode, charSize, stdin);
    
    
    // Tell the user that we creating the account for them.
    printf("Please wait, creating your account. . .\n");
    
    
    // With the data provided from the user, throw the information to the
    //  customer Linked-List for further use.
    CreateNewCustomer(cList,
                    firstName,
                    lastName,
                    userID,
                    userKey,
                    email,
                    phoneNumber,
                    addressCity,
                    addressState,
                    addressCountry,
                    addressStreet,
                    addressPostalCode,
                    adminRights);
                    
    // Tell the user that their account has been successfully created
    printf("Your account has been created!\n");
} // ManuallyCreateNewUser()
