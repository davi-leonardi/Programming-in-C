//==============================================
// Name:           Davi Leonardi Mathey 
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR
// Date:           18/11/2020
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name* name)
{
    char yesNo;

    printf("Please enter the contact's first name: ");
    scanf("%12[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    yesNo = yes();
    //scanf("%s%*c", &yesNo); //<--- Incorrect, not a c string, must be a char

    if (yesNo)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
        clearKeyboard();
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    char yesNo;

    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();      

    while (address->streetNumber < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
    }

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);
    
    printf("Do you want to enter an apartment number? (y or n): ");
    yesNo = yes();

    if (yesNo)
    {
        printf("Please enter the contact's apartment number: ");
        scanf("%d%*c", &address->apartmentNumber);

        while (address->apartmentNumber < 1)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            scanf("%d%*c", &address->apartmentNumber);
        }
        
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%*c", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    char yesNo;

    printf("Please enter the contact's cell phone number: ");
    scanf("%10[^\n]%*c", numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    yesNo = yes();

    //if (yesNo == 'y' && yesNo == 'Y') // <-- No! can't be both 'y' AND 'Y' (should be OR ||)
    if (yesNo)
    {
        printf("Please enter the contact's home phone number: ");
        scanf("%10[^\n]%*c", numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yesNo = yes();

    if (yesNo)
    {
        printf("Please enter the contact's business phone number: ");
        scanf("%10[^\n]%*c", numbers->business);
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}