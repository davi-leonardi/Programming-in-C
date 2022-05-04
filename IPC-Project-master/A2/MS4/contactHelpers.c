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
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
#include <ctype.h>

#define MAXCONTACTS 5

// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
    printf("\n(Press Enter to Continue)");
    clearKeyboard();
    printf("\n");
}

// getInt function definition goes here:
int getInt(void)
{
    char NL = 'x';
    int value = 0;
    while (NL != '\n')
    {
        scanf("%d%c", &value, &NL);
        if (NL != '\n')      //if (NL != '\n' || value == 0)
        {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
    int getIntRangeNum = getInt();
    while (getIntRangeNum < min || getIntRangeNum > max)
    {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        getIntRangeNum = getInt();
    }
    return getIntRangeNum;
}

// yes function definition goes here:
int yes(void)
{
    char yesNo = '\0';
    char checker = '\0';
    scanf("%c%c", &yesNo, &checker);
    while ((yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n') || checker != '\n')
    {
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        clearKeyboard();
        scanf("%c%c", &yesNo, &checker);
    }

    if (yesNo == 'Y' || yesNo == 'y')
    {
        return 1;
    }

    return 0;
}

// menu function definition goes here:
int menu(void)
{
    int choice;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");
    choice = getIntInRange(0, 6);
    return choice;
}
// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
    int yesNo = 0;
    int choice = 7;
    int contactsSize = 3; 
    int j;
    /*char cellNum[11] = { '\0' };*/

    struct Contact contacts[MAXCONTACTS] =
    {
        { { "Rick", {'\0'}, "Grimes" },
            { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
            { "4161112222", "4162223333", "4163334444" } },
        {
            { "Maggie", "R.", "Greene" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9051112222", "9052223333", "9053334444" } }, 
        {
            { "Morgan", "A.", "Jones" },
            { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
            { "7051112222", "7052223333", "7053334444" } },
        {
            { "Sasha", {'\0'}, "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555" } }, 
    };

    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            printf("\n");
            displayContacts(contacts, contactsSize);    //&contacts
            pause();
            break;
        case 2:
            printf("\n");
            addContact(contacts, contactsSize);         //&contacts

            if (strcmp(contacts[contactsSize].numbers.cell, "\0") && contactsSize < 4)
            {
                contactsSize += 1;
            }

            pause();
            break;
        case 3:
            printf("\n");
            updateContact(contacts, contactsSize);      //&contacts
            pause();
            break;
        case 4:       
            printf("\n");
            deleteContact(contacts, contactsSize);      //&contacts

            for (j = 0; j < MAXCONTACTS; j++)
            {
                if (contacts[j].numbers.cell[0] == 'x') 
                {
                    *contacts[j].numbers.cell = '\0';
                    contactsSize -= 1;
                    break;
                }
            }                                            
            pause();
            break;
        case 5:            
            printf("\n");
            searchContacts(contacts, contactsSize);
            break;

        case 6:
            printf("\n<<< Feature to sort is unavailable >>>\n");
            pause();
            break;
        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            yesNo = yes();
            if (yesNo)
            {
                printf("\nContact Management System: terminated\n");
                break;
            }
            printf("\n");
            break;
        }
    } while (yesNo == 0);
}


// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;
    int notDigit = 0;
    char NL = '\n';
    int i;

    while (needInput == 1)
    {
        needInput = 0;
        scanf("%10[^\n]%c", phoneNum, &NL);

        for (i = 0; i <= 9; i++)
        {
            notDigit = isdigit(phoneNum[i]);
            if (notDigit == 0)
            {
                needInput = 1;
                break;
            }

        }

        if (strlen(phoneNum) != 10 || needInput == 1 || NL != '\n')
        {
            if (NL != '\n')
            {
                clearKeyboard();
            }
            printf("Enter a 10-digit phone number: ");
            needInput = 1;
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i;
    int index = -1;

    for (i = 0; i < size; i++)
    {
        if (!strcmp(cellNum, contacts[i].numbers.cell))
        {
            index = i;
            break;
        }

    }
    
    return index;

}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d", count + 1);
    printf("\n");
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
    if (contact->numbers.cell[0] != '\0')
    {
        if (strcmp(contact->name.middleInitial, "\0"))
        {
            printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
        }
        else
        {
            printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
        }

        printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
        printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

        if (contact->address.apartmentNumber > 0)
        {
            printf("Apt# %d, ", contact->address.apartmentNumber);
        }

        printf("%s, %s\n", contact->address.city, contact->address.postalCode);
    }
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
    int i;

    displayContactHeader();
    for (i = 0; i < MAXCONTACTS; i++)
    {
        displayContact(&contacts[i]);
    }
    displayContactFooter(size);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
    char cellNum[11] = { '\0' };
    int result;

    printf("Enter the cell number for the contact: ");      
    getTenDigitPhone(cellNum);     //&cellNum

    result = findContactIndex(contacts, MAXCONTACTS, cellNum);    //contacts, size, cellNum
        
        if (result != -1)
        {
            printf("\n");
            displayContact(&contacts[result]);
        }
        else
        {
            printf("*** Contact NOT FOUND ***\n");
        }

        pause();    

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
    int freeSlot = 0;

    freeSlot = findContactIndex(contacts, MAXCONTACTS, "\0");  

    if (freeSlot == -1)
    {
        printf("*** ERROR: The contact list is full! ***\n");
    }
    else
    {
        getContact(&contacts[freeSlot]); 
        printf("--- New contact added! ---\n");
    }
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
    char cellNum[11] = { '\0' };
    int result = -1;
    int yesNo = -1;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum);     //&cellNum
    result = findContactIndex(contacts, MAXCONTACTS, cellNum); //contacts, size, cellNum

    if (result != -1)
    {
        printf("\nContact found:");
        printf("\n");
        displayContact(&contacts[result]);
        printf("\nDo you want to update the name? (y or n): ");
        yesNo = yes();
        if (yesNo)
        {
            getName(&contacts[result].name);
        }

        printf("Do you want to update the address? (y or n): ");
        yesNo = yes();
        if (yesNo)
        {
            getAddress(&contacts[result].address);
        }

        printf("Do you want to update the numbers? (y or n): ");
        yesNo = yes();
        if (yesNo)
        {
            getNumbers(&contacts[result].numbers);
        }

        printf("--- Contact Updated! ---\n");
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
    char cellNum[11] = { '\0' };
    int result = -1;
    int yesNo = -1;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum);     //&cellNum
    result = findContactIndex(contacts, MAXCONTACTS, cellNum);     //contacts, size, cellNum
    
    if (result != -1)
    {
        printf("\nContact found:");
        printf("\n");
        displayContact(&contacts[result]);
        printf("\nCONFIRM: Delete this contact? (y or n): ");
        
        yesNo = yes();
        if (yesNo)
        {
            contacts[result].numbers.cell[0] = 'x';
            printf("--- Contact deleted! ---\n");
        }
    }
    else
    {
        printf("*** Contact NOT FOUND***\n");
    }
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{

}