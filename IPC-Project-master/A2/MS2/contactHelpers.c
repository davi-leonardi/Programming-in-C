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

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
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
