//==============================================
// Name:           Davi Leonardi Mathey 
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR
// Date:           
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
#include <ctype.h>

// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
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
    int flag = 0;
    do
    {
        if (flag)
        {
            printf("\n(Press Enter to Continue)");
            clearKeyboard();
            flag = 0;
            printf("\n");
        }
        choice = menu();
        switch (choice)
        {
        case 1:
            printf("\n<<< Feature 1 is unavailable >>>\n");
            flag = 1;
            break;
        case 2:
            printf("\n<<< Feature 2 is unavailable >>>\n");
            flag = 1;
            break;
        case 3:
            printf("\n<<< Feature 3 is unavailable >>>\n");
            flag = 1;
            break;
        case 4:
            printf("\n<<< Feature 4 is unavailable >>>\n");
            flag = 1;
            break;
        case 5:
            printf("\n<<< Feature 5 is unavailable >>>\n");
            flag = 1;
            break;
        case 6:
            printf("\n<<< Feature 6 is unavailable >>>\n");
            flag = 1;
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
    char exceeded = '\0';
    int i;

    while (needInput == 1)
    {
        needInput = 0;
        scanf("%10[^\n]%c", phoneNum, &exceeded);

        for (i = 0; i <= 9; i++)
        {
            notDigit = isdigit(phoneNum[i]);
            if (notDigit == 0)
            {               
                needInput = 1;
            }

        }

        if (strlen(phoneNum) != 10 || needInput == 1 || exceeded != '\0')
        {               
            printf("Enter a 10-digit phone number: ");
            needInput = 1;
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
    
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{

}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{

}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{

}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{

}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{

}