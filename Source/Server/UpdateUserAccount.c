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
#include <stdbool.h>            // Because I was spoiled with C++ and C#, just give me the Bool data types!
#include <string.h>             // strcmp() for User Account Authentication Challenge
#include "GlobalDefs.h"         // Program Macro-Definitions
#include "CustomerData.h"       // Customer Data Object
#include "CustomerLinkedList.h" // Provides the prototypes
#include "CommonFunctions.h"    // Prompt
#include "myunp.h"				// For MAXLINE
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
            CreateNewCustomer(cList,                    // Customer Linked-List
                            "Theodore",                 // First Name
                            "Roosevelt",                // Last Name
                            "The Big Stick Teddy",      // User ID
                            "1h3_13ddY",                // User Password
                            "TheBigStick@yahoo.com",    // E-Mail
                            "000-000.0000",             // Phone Number
                            "Oyster Bay",               // Address (City)
                            "New York",                 // Address (State)
                            "United States",            // Address (Country)
                            "20 Sagamore Hill Rd",      // Address (Street)
                            "11771",                    // Address (Zip Code)
                            1);							// Administrator?  
            break;
        case 1:
            CreateNewCustomer(cList,                    // Customer Linked-List
                            "Al",                       // First Name
                            "Bundy",                    // Last Name
                            "AlDaddyBundy",             // User ID
                            "shootme",                  // User Password
                            "AlBimby@GarysShoes.com",   // E-Mail
                            "000-000.0000",             // Phone Number
                            "Chicago",                  // Address (City)
                            "Illinois",                 // Address (State)
                            "United States",            // Address (Country)
                            "9764 Jeopardy Lane",       // Address (Street)
                            "60015",                    // Address (Zip Code)
                            0);							// Administrator?
            break;
        case 2:
            CreateNewCustomer(cList,                    // Customer Linked-List
                            "Hana",                     // First Name
                            "Eris",                     // Last Name
                            "Hana",                     // User ID
                            "1234",                     // User Password
                            "HanaErie@gmail.com",       // E-Mail
                            "000-000.0000",             // Phone Number
                            "El Paso",                  // Address (City)
                            "Texas",                    // Address (State)
                            "United States",            // Address (Country)
                            "4389 Brosius Cir.",        // Address (Street)
                            "79904",                    // Address (Zip Code)
                            0);							// Administrator?
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
//  userCard [CustomerData]
//      The userCard contains information about the current
//      user that is currently active within the session.
// -----------------------------------
void ManuallyCreateNewUser(struct CustomerData** cList, struct CustomerData** userCard, int sockfd)
{
	char sendbuffer[MAXLINE];
	ClearBuffer(sendbuffer, MAXLINE);
	
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
    int cmpResponse;         // Used to assure that the user's response is meaningful
    // ----------------------------------
    
    // Tell the user that we're gathering information from them
    sprintf(sendbuffer, "In order to register an account in this store, we're going to need a bit of information from you.\nPlease provide the following information:\n\n");
	write(sockfd, sendbuffer, MAXLINE);
    ClearBuffer(sendbuffer, MAXLINE);
    
    // Capture input from the user
    // -------------------------------
    // User Login ID
    do
    {
        sprintf(sendbuffer, "Provide User Login Screen Name:\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(userID, charSize);
        read(sockfd, userID, charSize);
        
        // Is the response valid and meaningful?
        cmpResponse = strncmp(userID, "\n", 1);
		
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    
    // User Login Password
    do
    {
        sprintf(sendbuffer, "Provide User Login Password:\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(userKey, charSize);
        read(sockfd, userKey, charSize);
        
        // Is the response valid and meaningful?
        cmpResponse = strncmp(userKey, "\n", 1);
		
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
    } while(!cmpResponse);
    
    
    
    // User E-Mail Account
    do
    {
        sprintf(sendbuffer, "Provide an E-Mail Account:\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(email, charSize);
        read(sockfd, email, charSize);
        
        // Is the response valid and meaningful?
        cmpResponse = strncmp(email, "\n", 1);
		
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    
    // User First Name
    do
    {
        sprintf(sendbuffer, "Provide your First Name:\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(firstName, charSize);
        read(sockfd, firstName, charSize);
    
        // Is the response valid and meaningful?
        cmpResponse = strncmp(firstName, "\n", 1);
		
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    
    // User Last Name
    do
    {
        sprintf(sendbuffer, "Provide your Last Name:\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(lastName, charSize);
        read(sockfd, lastName, charSize);
    
        // Is the response valid and meaningful?
        cmpResponse = strncmp(lastName, "\n", 1);
		
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    
    // User Phone Number
    do
    {
        sprintf(sendbuffer, "Provide your Phone Number:\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(phoneNumber, charSize);
        read(sockfd, phoneNumber, charSize);
    
        // Is the response valid and meaningful?
        cmpResponse = strncmp(phoneNumber, "\n", 1);
		
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    
    // User Address [city]
    do
    {
        sprintf(sendbuffer, "Provide your Address (City):\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(addressCity, charSize);
        read(sockfd, addressCity, charSize);
    
        // Is the response valid and meaningful?
        cmpResponse = strncmp(addressCity, "\n", 1);
        
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    
    // User Address [state]
    do
    {
        sprintf(sendbuffer, "Provide your Address (State):\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(addressState, charSize);
        read(sockfd, addressState, charSize);
    
        // Is the response valid and meaningful?
        cmpResponse = strncmp(addressState, "\n", 1);
        
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    
    // User Address [country]
    do
    {
        sprintf(sendbuffer, "Provide your Address (Country):\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(addressCountry, charSize);
        read(sockfd, addressCountry, charSize);
    
        // Is the response valid and meaningful?
        cmpResponse = strncmp(addressCountry, "\n", 1);
        
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    
    // User Address [street]
    do
    {
        sprintf(sendbuffer, "Provide your Address (Street):\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(addressStreet, charSize);
        read(sockfd, addressStreet, charSize);
    
        // Is the response valid and meaningful?
        cmpResponse = strncmp(addressStreet, "\n", 1);
        
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    
    // User Address [zip]
    do
    {
        sprintf(sendbuffer, "Provide your Address (ZIP-Code):\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
		ClearBuffer(addressPostalCode, charSize);
        read(sockfd, addressPostalCode, charSize);
    
        // Is the response valid and meaningful?
        cmpResponse = strncmp(addressPostalCode, "\n", 1);
        
        if (!cmpResponse)
        {
			sprintf(sendbuffer, "!ERR!: Please provide a valid value!\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
        sprintf(sendbuffer, "\n");   // Provide an extra line-feed.
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while(!cmpResponse);
    
    
    // Tell the user that we creating the account for them.
    sprintf(sendbuffer, "Please wait, creating your account. . .\n");
	write(sockfd, sendbuffer, MAXLINE);
	ClearBuffer(sendbuffer, MAXLINE);
    
    // Filter the values before appending them into the system
    CreateNewUser_ValueFiltering(&firstName,
                                &lastName,
                                &userID,
                                &userKey,
                                &email,
                                &phoneNumber,
                                &addressCity,
                                &addressState,
                                &addressCountry,
                                &addressStreet,
                                &addressPostalCode);
    
    // With the data provided from the user, throw the information to the
    //  customer Linked-List for further use.
    CreateNewCustomer(cList,            // Customer Linked-List
                    firstName,          // First Name
                    lastName,           // Last Name
                    userID,             // User ID
                    userKey,            // User Password
                    email,              // E-Mail
                    phoneNumber,        // Phone Number
                    addressCity,        // Address (City)
                    addressState,       // Address (State)
                    addressCountry,     // Address (Country)
                    addressStreet,      // Address (Street)
                    addressPostalCode,  // Address (Zip Code)
                    adminRights);       // Administrator?
                    
    // Generate the UserCard here as well
    (*userCard)->firstName = firstName;
    (*userCard)->lastName = lastName;
    (*userCard)->userID = userID;
    (*userCard)->userKey = userKey;
    (*userCard)->email = email;
    (*userCard)->phoneNumber = phoneNumber;
    (*userCard)->addressCity = addressCity;
    (*userCard)->addressState = addressState;
    (*userCard)->addressCountry = addressCountry;
    (*userCard)->addressStreet = addressStreet;
    (*userCard)->addressPostalCode = addressPostalCode;
    (*userCard)->admin = 0;
    
    // Tell the user that their account has been successfully created
    sprintf(sendbuffer, "Your account has been created!\n");
	write(sockfd, sendbuffer, MAXLINE);
	ClearBuffer(sendbuffer, MAXLINE);
} // ManuallyCreateNewUser()




// Value Filtering for the Create New User
// -----------------------------------
// Documentation:
//  This function will clean up the values provided in the
//  parameters; clean up resulting on removing the '\n'
//  character that will be recorded in the variable --
//  when the 'enter key' value is kept, we need it expunged.
// -----------------------------------
// -----------------------------------
// Parameters
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
// -----------------------------------
void CreateNewUser_ValueFiltering(char **firstName,
                                    char **lastName,
                                    char **userID,
                                    char **userKey,
                                    char **email,
                                    char **phoneNumber,
                                    char **addressCity,
                                    char **addressState,
                                    char **addressCountry,
                                    char **addressStreet,
                                    char **addressPostalCode)
{
    // First Name
    FilterUserInputArray(*firstName, _MAX_CHAR_INPUT_);
    
    // Last Name
    FilterUserInputArray(*lastName, _MAX_CHAR_INPUT_);
    
    // User ID
    FilterUserInputArray(*userID, _MAX_CHAR_INPUT_);
    
    // User Key
    FilterUserInputArray(*userKey, _MAX_CHAR_INPUT_);
    
    // E-Mail
    FilterUserInputArray(*email, _MAX_CHAR_INPUT_);
    
    // Phone Number
    FilterUserInputArray(*phoneNumber, _MAX_CHAR_INPUT_);
    
    // Address City
    FilterUserInputArray(*addressCity, _MAX_CHAR_INPUT_);
    
    // Address State
    FilterUserInputArray(*addressState, _MAX_CHAR_INPUT_);
    
    // Address Country
    FilterUserInputArray(*addressCountry, _MAX_CHAR_INPUT_);
    
    // Address Street
    FilterUserInputArray(*addressStreet, _MAX_CHAR_INPUT_);
    
    // Address ZIP Code
    FilterUserInputArray(*addressPostalCode, _MAX_CHAR_INPUT_);
} // CreateNewUser_ValueFiltering()




// Find User _AND_ Return User Information
// -----------------------------------
// Documentation:
//  This function will scan the Primary Linked-List for the user's account.
//  If an account exists, then we will provide the user's card and provide
//  a successful status.  But, if the account does not exist or the credentials
//  are incorrect, the user's card is NULL with a failure status.
// -----------------------------------
// Parameters:
//  cList [CustomerData]
//      The Primary Linked-List to reference from.
//  userCard [CustomerData]
//      The User's Account Information; if exists in Database, return the
//      user's information for general program use.
//  userID [char*]
//      User's Screen Name (or  Login ID) to access the store via user account.
//  UserKey [char*]
//      User's Password to access their account.
// -----------------------------------
// Output:
//  True ( 0 < x)
//      Credentials matched against the Database.
//      Found user's account
//      User's Card has been initialized
//  False ( 0 )
//      Credentials didn't match against the Database.
//      OR Failure to find the user's account.
//      User's Card remains NULL.
// -----------------------------------
bool FindUser_ReturnUserInfo(CustomerData *cList,
                            CustomerData **userCard,
                            char *userID,
                            char *userKey, int sockfd)
{ 
	char sendbuffer[MAXLINE];			//buffer used to send critical error message
	ClearBuffer(sendbuffer, MAXLINE);
	
    // Traverse through the Linked-List until we find the user's ID or reach NULL.
    while (cList != NULL && (0 != strcmp(cList->userID, userID)))
        cList = cList->next;

    // Once we leave the loop, determine what happened.
    //  Because we left the loop, we don't know if we found the user's account
    //  or if we reached NULL within the Linked-List.
    if (cList == NULL)
    {   // Reached end of the Linked List, user's account was not found.
        userCard = NULL;    // If in-case it was not done so previously, NULL the card now.
        return false;       // Return a failure signal.
    } // if :: NULL
    else if (0 == strcmp(cList->userID, userID))
    {   // Found the User's ID!
        // Check if the user's password challenge matches
        if (0 == strcmp(cList->userKey, userKey))
        {
            *userCard = cList;
            return true;
        } // if :: Successful!
        
        // Else, the password was incorrect.
        userCard = NULL;        // If in-case it was not done so previously, NULL the card now.
        return false;           // Return a failure signal.
    } // if :: Found User Account!
    else
    {
        // Something went horribly wrong; if we reach here - throw a hard-crash.
        sprintf(sendbuffer, "    <!> CRITICAL FAILURE <!>\n");
        strcat(sendbuffer, "------------------------------------\n");
        strcat(sendbuffer, "Unable to successfully obtain account details.  Some reasons for this nasty message:\n");
        strcat(sendbuffer, " *Linked-List was corrupted\n");
        strcat(sendbuffer, " *Improper Conditional Checks\n");
        strcat(sendbuffer, " *Or worse, a very unknown error\n");
        strcat(sendbuffer, "Please send your complaints to the slave monkey coders.  We don't pay them anything, so please be some-what nice to them!\n");
		
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
        
        // Send a hard-crash-out.
        exit(2);
    } // Something went horribly wrong....
} // FindUser_ReturnUserInfo()




// Ask User for Login Details
// -----------------------------------
// Documentation:
//  This function will ask the user for their login
//  details.  The information that they provide
//  be checked against the database in the later
//  process.
// -----------------------------------
// Parameters:
//  userID [char]
//      User's screen name, User ID, or account ID.
//  userKey [char]
//      User's password for that account.
// -----------------------------------
void AskUserLogin(char **userID, char **userKey, int sockfd)
{
    // Declarations and Initializations
    // ----------------------------------
    const int inputSize = 128;  // Maximum buffer\char length
    char rawUserID[inputSize];  // Unfiltered User Input - User ID
    char rawUserKey[inputSize]; // Unfiltered User Input - User Key
	
	char sendbuffer[MAXLINE];
	ClearBuffer(sendbuffer, MAXLINE);
    // ----------------------------------
    
    
    // Ask the user for their User ID
    sprintf(sendbuffer, "Please provide your User Name:\n");     // Tell the user what we are wanting
	write(sockfd, sendbuffer, MAXLINE);
	
	
	DisplayPrompt(sockfd);							// Display the Prompt msg.
    ClearBuffer(sendbuffer, MAXLINE);
	
	ClearBuffer(rawUserID, inputSize);
    read(sockfd, rawUserID, inputSize);             // Capture the user's input
	
	
    
    // Filter the user's input
    FilterUserInputArray(rawUserID, inputSize);     // Filter the user's input; because
                                                    //  it contains the '\n' and will cause
                                                    //  the strcmp() to fail.
    strcpy(*userID, rawUserID);                     // Copy the result that in which will be
                                                    //  returned.
                                                    
    // By chance, did the user request to leave this program?
    if (!CheckForUserQuit(*userID, inputSize))
        exit(1);    // Leave the program by user request
    
    
    // Ask the user for their password
    sprintf(sendbuffer, "Please provide the password for this account:\n");// Tell the user what we are wanting
	write(sockfd, sendbuffer, MAXLINE);
	ClearBuffer(sendbuffer, MAXLINE);
	
    DisplayPrompt(sockfd);                                // Display the Prompt msg.
	
	ClearBuffer(rawUserKey, inputSize);
    read(sockfd, rawUserKey, inputSize);            // Capture the user's input.
    
    // Filter the user's input again
    FilterUserInputArray(rawUserKey, inputSize);    // Filter the user's input; because
                                                    //  it contains the '\n' and will cause
                                                    // the strcmp() to fail.
    strcpy(*userKey, rawUserKey);                   // Copy the result that in which will be
                                                    //  returned.
} // AskUserLogin()




// User Login (Procedural)
// -----------------------------------
// Documentation:
//  This function is a procedural function, which will assure
//  that the login-system is executed as it should.  Because
//  this entire system is slightly complex, we want to assure
//  that everything works as intended.
// -----------------------------------
// Parameters:
//  cList [CustomerData]
//      Customer Primary Linked-List; the list that will
//      scanned to find the user's account.
//  userCard [CustomerData]
//      Contains the user's account information, provided
//      that the user's account exists and that credentials
//      matched against the database.
// -----------------------------------
void UserLogin(CustomerData* cList, CustomerData **userCard, int sockfd)
{
    // Declarations and Initializations
    // ----------------------------------
    char *userID = malloc(128*sizeof(char));    // User's account ID
    char *userKey = malloc(128*sizeof(char));   // User's password for the account
    const int maxRetries = 4;                   // How many times can the user retry to login after so many failed attempts.
    int retryCounter = 0;                       // How many attempts has the user made thus far?
	
	char sendbuffer[MAXLINE];
	ClearBuffer(sendbuffer, MAXLINE);
    // ----------------------------------
    
    do
    {
        // Ask the user for their account details
        AskUserLogin(&userID, &userKey, sockfd);
        
        // Check their account details against the database
        if (FindUser_ReturnUserInfo(cList, userCard, userID, userKey, sockfd))
            // Credentials matched!
            return;     // Leave the function; success!
        
        // Credentials did not match
        retryCounter++;     // Update the country
		
        sprintf(sendbuffer, "Incorrect username or password\n\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
    } while (retryCounter <= maxRetries);
    
    // If we are still executing, then the user exceeded the amount of retries.
    // Terminate the session.
	
    sprintf(sendbuffer, "Maximum retries has been exceeded!  Connection to the store has been terminated!\n\n\n");
	write(sockfd, sendbuffer, MAXLINE);
	ClearBuffer(sendbuffer, MAXLINE);
	
    exit(3);
} // UserLogin()

    // Run the User Update Menu Loop
    do
    {
		ClearBuffer(sendbuffer, MAXLINE);
		DrawUserLoggedIn((*userCard)->userID, sockfd);  // Show who is currently logged into the session
		strcpy(sendbuffer, "\n\n");   	// Provide extra padding for readability
		write(sockfd, sendbuffer, MAXLINE);
		UpdateUserInfoShowMenu(*userCard, sockfd);      // Display the Menu
    
		userRequest =                           // Get the user's request and cache the value
			UpdateUserInfoMenuGetInput(sockfd);       //  to process it.
    
		// Inspect the user's input
		if (userRequest < 10)       // Execute the user's request
			UpdateUserInfoMenuUpdateChoice(userCard, userRequest, sockfd);
		else if (userRequest == 10) // Return to main menu
			isContinue = false;
		else
		{
			ClearBuffer(sendbuffer, MAXLINE);
			strcpy(sendbuffer, "<!> BAD REQUEST <!>\n");
			strcat(sendbuffer, "-------------------------------\n");
			strcat(sendbuffer, "Please select an option from the menu provided\n");
			write(sockfd, sendbuffer, MAXLINE);
		}
	} while(isContinue);
} // UpdateUserInfoMenu()




// Update User Information - Get Input
// -----------------------------------
// Documentation:
//  This function will retrieve the input from the
//  user and then report back what the user has
//  requested regarding from the User Information
//  Update Menu.
// -----------------------------------
// Output:
//  Returns the user's request
//      0 = Selected was First Name
//      1 = Selected was Last Name
//      2 = Selected was Account Password
//      3 = Selected was E-Mail Address
//      4 = Selected was Phone Number
//      5 = Selected was Address [City]
//      6 = Selected was Address [State]
//      7 = Selected was Address [Country]
//      8 = Selected was Address [Street]
//      9 = Selected was Address [Zip]
//     10 = Return to main menu
//    255 = Bad Request
// -----------------------------------
int UpdateUserInfoMenuGetInput(int sockfd)
{
    // Declarations and Initializations
    // ----------------------------------
    char userInput[MAXLINE];    // This will hold the user input.
	ClearBuffer(userInput, MAXLINE);
    // ----------------------------------
    
    // Display the prompt
    DisplayPrompt(sockfd);
    
    // Get the user input
    read(sockfd, userInput, MAXLINE);
    
    // Lower case the user's input
    LowerCaseUserInput(userInput);
    
    // I am dreading the fact that I can't use a switch() to pull this off...
    //  I am sorry for those that are reading this; there has to be a better
    //  way to handle this, but due to time-constraint - I can't do reasonable
    //  research to figure this out.  Instead, I know If(cond.) will work
    //  just - - I'd rather use something nicer... [NG]
    if (!strncmp(userInput, "1\n", 2)) // already regretting my life's decisions.... [NG]
        return 0;   // First Name
    else if (!strncmp(userInput, "2\n", 2)) // ugh...
        return 1;   // Last Name
    else if (!strncmp(userInput, "3\n", 2)) // I
        return 2;   // Account Password
    else if (!strncmp(userInput, "4\n", 2)) // Hate
        return 3;   // E-Mail Address
    else if (!strncmp(userInput, "5\n", 2)) // This
        return 4;   // Phone Number
    else if (!strncmp(userInput, "6\n", 2)) // Seriously
        return 5;   // Address - City
    else if (!strncmp(userInput, "7\n", 2)) // I am
        return 6;   // Address - State
    else if (!strncmp(userInput, "8\n", 2)) // sorry
        return 7;   // Address - Country
    else if (!strncmp(userInput, "9\n", 2)) // that you
        return 8;   // Address - Street
    else if (!strncmp(userInput, "10\n", 3))// are reading this...
        return 9;   // Address - Zip
        
    // -------------------
    // CHECK FOR RETURN TO MAIN MENU REQUEST
    // -------------------
    else if (!CheckForUserQuit(userInput, MAXLINE))
        return 10;  // Return to Main Menu
    else if ((!strncmp(userInput, "x\n", 2)) ||
            (!strncmp(userInput, "X\n", 2)))
        return 10;  // Return to Main Menu
    
    // -------------------
    // UNKNOWN REQUEST
    // -------------------
    else 
        return 255; // Unknown Request
} // UpdateUserInfoMenuGetInput()




// Update User Information - Update Request
// -----------------------------------
// Documentation:
//  This function will allow the user to actually
//  update their information based on their request.
// -----------------------------------
// Parameters:
//  userCard [CustomerData]
//      The user's personal information that will be modified.
//  request [int]
//      What is to be modified on the user's User Card.
// -----------------------------------
void UpdateUserInfoMenuUpdateChoice(CustomerData **userCard, int request, int sockfd)
{
    // Declarations and Initializations
    // ----------------------------------
    char *userInput = (char*)malloc(sizeof(char)*_MAX_CHAR_INPUT_);
	char sendbuffer[MAXLINE];
	ClearBuffer(sendbuffer, MAXLINE);
    // ----------------------------------
    
    
    // Execute the user's request
    switch(request)
    {
        case 0: // First Name
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->firstName, &userInput, sockfd);
            (*userCard)->firstName = userInput;
            break;
        case 1: // Last Name
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->lastName, &userInput, sockfd);
            (*userCard)->lastName = userInput;
            break;
        case 2: // Account Password
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->userKey, &userInput, sockfd);
            (*userCard)->userKey = userInput;
            break;
        case 3: // E-Mail Address
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->email, &userInput, sockfd);
            (*userCard)->email = userInput;
            break;
        case 4: // Phone Number
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->phoneNumber, &userInput, sockfd);
            (*userCard)->phoneNumber = userInput;
            break;
        case 5: // Address [City]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressCity, &userInput, sockfd);
            (*userCard)->addressCity = userInput;
            break;
        case 6: // Address [State]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressState, &userInput, sockfd);
            (*userCard)->addressState = userInput;
            break;
        case 7: // Address [Country]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressCountry, &userInput, sockfd);
            (*userCard)->addressCountry = userInput;
            break;
        case 8: // Address [Street]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressStreet, &userInput, sockfd);
            (*userCard)->addressStreet = userInput;
            break;
        case 9: // Address [Zip]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressPostalCode, &userInput, sockfd);
            (*userCard)->addressPostalCode = userInput;
            break;
        default:// Bad key; don't fatally error out - no reason too.
			ClearBuffer(sendbuffer, MAXLINE);
            strcpy(sendbuffer, "<!> ERROR <!>\n");
            strcat(sendbuffer, "--------------------------------\n");
            strcat(sendbuffer, "Unknown User Card Request!\nRequest was canceled!\n");
			write(sockfd, sendbuffer, MAXLINE);
            break;
    } // switch()
} // UpdateUserInfoMenuUpdateChoice()




// Update User Information Menu Update Choice - Message [Because long function names are cool!]
// -----------------------------------
// Documentation:
//  This function, merely reducing repetitiveness, allows
//  the user to provide an update on their personal information.
//  After which, the user's input will be cleaned-up and sent
//  back for further instructions.
// -----------------------------------
// Parameters:
//  msg [char]
//      The present value that currently exists.
//  response [char]
//      The new value that will replace the older-value
//      [relating to the 'msg' variable above]
// -----------------------------------
void UpdateUserInfoMenuUpdateChoice_MSG(char* msg, char **response, int sockfd)
{
    // Declarations and Initializations
    // ----------------------------------
    bool isContinue = true;     // Handle's the loop; if input is valid
	char sendbuffer[MAXLINE];
    // ----------------------------------
    
    // Capture a valid response from the user
    do
    {
		ClearBuffer(sendbuffer, MAXLINE);
        // Display the current value
        strcpy(sendbuffer, "Currently: ");
		strcat(sendbuffer, msg);
		strcat(sendbuffer, "\n");
        
        // Tell the user to provide a new value
        strcat(sendbuffer, "Provide a new value\n");
		write(sockfd, sendbuffer, MAXLINE);
		ClearBuffer(sendbuffer, MAXLINE);
		
        DisplayPrompt(sockfd);
        
        // Fetch the new value
		ClearBuffer(*response, MAXLINE);
        read(sockfd, *response, MAXLINE);
        
        // Clean it up; otherwise the '\n' char
        //  will still remain in the new value.
        FilterUserInputArray(*response, MAXLINE);
        
        if (!strncmp(*response, "\0", 1))
		{
			ClearBuffer(sendbuffer, MAXLINE);
            strcpy(sendbuffer, "!ERR!: Please provide a valid value!\n\n");   // Bootless Star's old error messages :) [NG]
			write(sockfd, sendbuffer, MAXLINE);
			ClearBuffer(sendbuffer, MAXLINE);
		}
		
		else
		{
            isContinue = false;
		}
    } while(isContinue);
} // UpdateUserInfoMenuUpdateChoice_MSG()




// Update User Information - Show Menu
// -----------------------------------
// Documentation:
//  This function will provide the user with the
//  Update User Information Menu and any instructions
//  necessary when dealing with the this menu.
// -----------------------------------
// Parameters:
//  userCard [CustomerData]
//      Only used to display the user's current information.
// -----------------------------------
void UpdateUserInfoShowMenu(CustomerData *userCard, int sockfd)
{    
	char sendbuffer[MAXLINE];
	ClearBuffer(sendbuffer, MAXLINE);
	
    strcpy(sendbuffer, "Update User Information Menu\n");
    strcat(sendbuffer, "------------------------------------------------\n\n");
    // User's First Name
    strcat(sendbuffer, "[1] - First Name\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->firstName);
	strcat(sendbuffer, "\n");
    // User's Last Name
    strcat(sendbuffer, "[2] - Last Name\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->lastName);
	strcat(sendbuffer, "\n");
    // User's Account Password
    strcat(sendbuffer, "[3] - Account Password\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->userKey);
	strcat(sendbuffer, "\n");
    // User's E-Mail Address
    strcat(sendbuffer, "[4] - E-Mail Address\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->email);
	strcat(sendbuffer, "\n");
    // User's Phone Number
    strcat(sendbuffer, "[5] - Phone Number\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->phoneNumber);
	strcat(sendbuffer, "\n");
    // User's Address [City]
    strcat(sendbuffer, "[6] - Address [City]\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->addressCity);
	strcat(sendbuffer, "\n");
    // User's Address [State]
    strcat(sendbuffer, "[7] - Address [State]\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->addressState);
	strcat(sendbuffer, "\n");
    // User's Address [Country]
    strcat(sendbuffer, "[8] - Address [Country]\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->addressCountry);
	strcat(sendbuffer, "\n");
    // User's Address [Street]
    strcat(sendbuffer, "[9] - Address [Street]\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->addressStreet);
	strcat(sendbuffer, "\n");
    // User's Address [Zip]
    strcat(sendbuffer, "[10] - Address [Zip Code]\n");
    strcat(sendbuffer, "       Current Value: ");
	strcat(sendbuffer, userCard->addressPostalCode);
	strcat(sendbuffer, "\n");
    // Leave the menu
    strcat(sendbuffer, "[X] - Return to Main Menu\n");
	
	write(sockfd, sendbuffer, MAXLINE);
	ClearBuffer(sendbuffer, MAXLINE);
} // UpdateUserInfoShowMenu()

    {
    DrawUserLoggedIn((*userCard)->userID);  // Show who is currently logged into the session
    printf("\n\n");                         // Provide extra padding for readability
    UpdateUserInfoShowMenu(*userCard);      // Display the Menu
    
    userRequest =                           // Get the user's request and cache the value
        UpdateUserInfoMenuGetInput();       //  to process it.
    
    // Inspect the user's input
    if (userRequest < 10)       // Execute the user's request
        UpdateUserInfoMenuUpdateChoice(userCard, userRequest);
    else if (userRequest == 10) // Return to main menu
        isContinue = false;
    else
        printf("<!> BAD REQUEST <!>\n");
        printf("-------------------------------\n");
        printf("Please select an option from the menu provided\n");
    } while(isContinue);
} // UpdateUserInfoMenu()




// Update User Information - Get Input
// -----------------------------------
// Documentation:
//  This function will retrieve the input from the
//  user and then report back what the user has
//  requested regarding from the User Information
//  Update Menu.
// -----------------------------------
// Output:
//  Returns the user's request
//      0 = Selected was First Name
//      1 = Selected was Last Name
//      2 = Selected was Account Password
//      3 = Selected was E-Mail Address
//      4 = Selected was Phone Number
//      5 = Selected was Address [City]
//      6 = Selected was Address [State]
//      7 = Selected was Address [Country]
//      8 = Selected was Address [Street]
//      9 = Selected was Address [Zip]
//     10 = Return to main menu
//    255 = Bad Request
// -----------------------------------
int UpdateUserInfoMenuGetInput()
{
    // Declarations and Initializations
    // ----------------------------------
    char userInput[_MAX_CHAR_INPUT_];    // This will hold the user input.
    // ----------------------------------
    
    // Display the prompt
    DisplayPrompt();
    
    // Get the user input
    fgets(userInput, _MAX_CHAR_INPUT_, stdin);
    
    // Lower case the user's input
    LowerCaseUserInput(userInput);
    
    // I am dreading the fact that I can't use a switch() to pull this off...
    //  I am sorry for those that are reading this; there has to be a better
    //  way to handle this, but due to time-constraint - I can't do reasonable
    //  research to figure this out.  Instead, I know If(cond.) will work
    //  just - - I'd rather use something nicer... [NG]
    if (!strncmp(userInput, "1\n", 2)) // already regretting my life's decisions.... [NG]
        return 0;   // First Name
    else if (!strncmp(userInput, "2\n", 2)) // ugh...
        return 1;   // Last Name
    else if (!strncmp(userInput, "3\n", 2)) // I
        return 2;   // Account Password
    else if (!strncmp(userInput, "4\n", 2)) // Hate
        return 3;   // E-Mail Address
    else if (!strncmp(userInput, "5\n", 2)) // This
        return 4;   // Phone Number
    else if (!strncmp(userInput, "6\n", 2)) // Seriously
        return 5;   // Address - City
    else if (!strncmp(userInput, "7\n", 2)) // I am
        return 6;   // Address - State
    else if (!strncmp(userInput, "8\n", 2)) // sorry
        return 7;   // Address - Country
    else if (!strncmp(userInput, "9\n", 2)) // that you
        return 8;   // Address - Street
    else if (!strncmp(userInput, "10\n", 3))// are reading this...
        return 9;   // Address - Zip
        
    // -------------------
    // CHECK FOR RETURN TO MAIN MENU REQUEST
    // -------------------
    else if (!CheckForUserQuit(userInput, _MAX_CHAR_INPUT_))
        return 10;  // Return to Main Menu
    else if ((!strncmp(userInput, "x\n", 2)) ||
            (!strncmp(userInput, "X\n", 2)))
        return 10;  // Return to Main Menu
    
    // -------------------
    // UNKNOWN REQUEST
    // -------------------
    else 
        return 255; // Unknown Request
} // UpdateUserInfoMenuGetInput()




// Update User Information - Update Request
// -----------------------------------
// Documentation:
//  This function will allow the user to actually
//  update their information based on their request.
// -----------------------------------
// Parameters:
//  userCard [CustomerData]
//      The user's personal information that will be modified.
//  request [int]
//      What is to be modified on the user's User Card.
// -----------------------------------
void UpdateUserInfoMenuUpdateChoice(CustomerData **userCard, int request)
{
    // Declarations and Initializations
    // ----------------------------------
    char *userInput = (char*)malloc(sizeof(char)*_MAX_CHAR_INPUT_);
    // ----------------------------------
    
    
    // Execute the user's request
    switch(request)
    {
        case 0: // First Name
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->firstName, &userInput);
            (*userCard)->firstName = userInput;
            break;
        case 1: // Last Name
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->lastName, &userInput);
            (*userCard)->lastName = userInput;
            break;
        case 2: // Account Password
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->userKey, &userInput);
            (*userCard)->userKey = userInput;
            break;
        case 3: // E-Mail Address
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->email, &userInput);
            (*userCard)->email = userInput;
            break;
        case 4: // Phone Number
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->phoneNumber, &userInput);
            (*userCard)->phoneNumber = userInput;
            break;
        case 5: // Address [City]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressCity, &userInput);
            (*userCard)->addressCity = userInput;
            break;
        case 6: // Address [State]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressState, &userInput);
            (*userCard)->addressState = userInput;
            break;
        case 7: // Address [Country]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressCountry, &userInput);
            (*userCard)->addressCountry = userInput;
            break;
        case 8: // Address [Street]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressStreet, &userInput);
            (*userCard)->addressStreet = userInput;
            break;
        case 9: // Address [Zip]
            UpdateUserInfoMenuUpdateChoice_MSG((*userCard)->addressPostalCode, &userInput);
            (*userCard)->addressPostalCode = userInput;
            break;
        default:// Bad key; don't fatally error out - no reason too.
            printf("<!> ERROR <!>\n");
            printf("--------------------------------\n");
            printf("Unknown User Card Request!\nRequest was canceled!\n");
            break;
    } // switch()
} // UpdateUserInfoMenuUpdateChoice()




// Update User Information Menu Update Choice - Message [Because long function names are cool!]
// -----------------------------------
// Documentation:
//  This function, merely reducing repetitiveness, allows
//  the user to provide an update on their personal information.
//  After which, the user's input will be cleaned-up and sent
//  back for further instructions.
// -----------------------------------
// Parameters:
//  msg [char]
//      The present value that currently exists.
//  response [char]
//      The new value that will replace the older-value
//      [relating to the 'msg' variable above]
// -----------------------------------
void UpdateUserInfoMenuUpdateChoice_MSG(char* msg, char **response)
{
    // Declarations and Initializations
    // ----------------------------------
    bool isContinue = true;     // Handle's the loop; if input is valid
    // ----------------------------------
    
    // Capture a valid response from the user
    do
    {
        // Display the current value
        printf("Currently: %s\n", msg);
        
        // Tell the user to provide a new value
        printf("Provide a new value\n");
        DisplayPrompt();
        
        // Fetch the new value
        fgets(*response, _MAX_CHAR_INPUT_, stdin);
        
        // Clean it up; otherwise the '\n' char
        //  will still remain in the new value.
        FilterUserInputArray(*response, _MAX_CHAR_INPUT_);
        
        if (!strncmp(*response, "\0", 1))
            printf("!ERR!: Please provide a valid value!\n\n");   // Bootless Star's old error messages :) [NG]
        else
            isContinue = false;
    } while(isContinue);
} // UpdateUserInfoMenuUpdateChoice_MSG()




// Update User Information - Show Menu
// -----------------------------------
// Documentation:
//  This function will provide the user with the
//  Update User Information Menu and any instructions
//  necessary when dealing with the this menu.
// -----------------------------------
// Parameters:
//  userCard [CustomerData]
//      Only used to display the user's current information.
// -----------------------------------
void UpdateUserInfoShowMenu(CustomerData *userCard)
{    
    printf("Update User Information Menu\n");
    printf("------------------------------------------------\n\n");
    // User's First Name
    printf("[1] - First Name\n");
    printf("       Current Value: [%s]\n", userCard->firstName);
    // User's Last Name
    printf("[2] - Last Name\n");
    printf("       Current Value: [%s]\n", userCard->lastName);
    // User's Account Password
    printf("[3] - Account Password\n");
    printf("       Current Value: [%s]\n", userCard->userKey);
    // User's E-Mail Address
    printf("[4] - E-Mail Address\n");
    printf("       Current Value: [%s]\n", userCard->email);
    // User's Phone Number
    printf("[5] - Phone Number\n");
    printf("       Current Value: [%s]\n", userCard->phoneNumber);
    // User's Address [City]
    printf("[6] - Address [City]\n");
    printf("       Current Value: [%s]\n", userCard->addressCity);
    // User's Address [State]
    printf("[7] - Address [State]\n");
    printf("       Current Value: [%s]\n", userCard->addressState);
    // User's Address [Country]
    printf("[8] - Address [Country]\n");
    printf("       Current Value: [%s]\n", userCard->addressCountry);
    // User's Address [Street]
    printf("[9] - Address [Street]\n");
    printf("       Current Value: [%s]\n", userCard->addressStreet);
    // User's Address [Zip]
    printf("[10] - Address [Zip Code]\n");
    printf("       Current Value: [%s]\n", userCard->addressPostalCode);
    // Leave the menu
    printf("[X] - Return to Main Menu\n");
} // UpdateUserInfoShowMenu()
