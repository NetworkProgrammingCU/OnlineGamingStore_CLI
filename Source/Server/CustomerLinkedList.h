// Guards
#ifndef _CUSTOMERLINKEDLISTFUNCS_H_
#define _CUSTOMERLINKEDLISTFUNCS_H_


// Function Prototypes
// ===============================
void GenerateUserList(struct // Generate predefined users.
    CustomerData**);
static void CreateNewCustomer(CustomerData**,  // Create a new Customer entry
                                const char*, const char*,
                                const char*, const char*,
                                const char*, const char*,
                                const char*, const char*,
                                const char*, const char*,
                                const char*, int);
static void AppendNewCustomer(CustomerData**,  // Add the new customer to the primary Linked-List.
                                CustomerData *);
// ===============================



// Concluding Guard
#endif