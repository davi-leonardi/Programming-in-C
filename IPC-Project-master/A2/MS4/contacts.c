//==============================================
// Name:           Davi Leonardi Mathey	
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
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

    if (yesNo)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);   //%6[^\n]%*c
        clearKeyboard();
    }
    else
    {
        *name->middleInitial = 0;
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    char yesNo;
    char NL = 'x';

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
        address->apartmentNumber = getInt();
        //scanf("%d%*c", address->apartmentNumber);

        while (address->apartmentNumber < 1)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
            //scanf("%d%*c", &address->apartmentNumber);
        }

    }
    else
    {
        address->apartmentNumber = 0;
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]%c", address->postalCode, &NL);   
    
    if (NL != '\n')
    {
        clearKeyboard();
    }
   
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    char yesNo;

    printf("Please enter the contact's cell phone number: ");
    //scanf("%10[^\n]%*c", numbers->cell);
    getTenDigitPhone(numbers->cell);  //&numbers[0]

    printf("Do you want to enter a home phone number? (y or n): ");
    yesNo = yes();

    //if (yesNo == 'y' && yesNo == 'Y') // <-- No! can't be both 'y' AND 'Y' (should be OR ||)
    if (yesNo)
    {
        printf("Please enter the contact's home phone number: ");
        //scanf("%10[^\n]%*c", numbers->home);
        getTenDigitPhone(numbers->home);   //&numbers[1]
    }
    else
    {
        *numbers->home = 0;
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yesNo = yes();

    if (yesNo)
    {
        printf("Please enter the contact's business phone number: ");
        //scanf("%10[^\n]%*c", numbers->business);
        getTenDigitPhone(numbers->business);  //&numbers[2]
    }
    else
    {
        *numbers->business = 0;
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}