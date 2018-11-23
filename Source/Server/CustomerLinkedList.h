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
// -----------------------------------




// Concluding Inclusion Guard
#endif
