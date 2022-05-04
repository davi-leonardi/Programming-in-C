#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SZ 20
#define MAX_LINE 50
#define MAX_ENTRIES 100

struct Synonym
{
    char name[MAX_SZ + 1];
    int relatedFactor; // 1=highly | 2=moderately | 3=loosely
};

struct WordInfo
{
    char word[MAX_SZ + 1];
    struct Synonym synonyms[MAX_ENTRIES];
    int synonymCount;
};

void clearInputBuffer(void)
{
    while (getchar() != '\n')
        ; // empty on purpose
}

int add(const char word[], const char synonym[], const int relatedFactor, struct WordInfo thesaurus[], int arrSize)
{
    int addedWord = 0, found = 0, i;

    // lookup for existing word
    for (i = 0; i < arrSize && !found; i++)
    {
        // found match
        if (!strcmp(word, thesaurus[i].word))
        {
            printf("word: %s; index: %d", thesaurus[i].word, i);
            strcpy(thesaurus[i].synonyms[thesaurus[i].synonymCount].name, synonym);
            //thesaurus[i].synonyms[thesaurus[i].synonymCount].name[relatedFactor] = relatedFactor;
            thesaurus[i]->synonyms[thesaurus[i].synonymCount].name = relatedFactor;
            thesaurus[i].synonymCount++;
            printf("%s", thesaurus[i].synonyms[thesaurus[i].synonymCount].name);
            found = 1; // toggle exit from loop
        }
        // not found and Empty slot: add to thesaurus.word array | set thesaurus.synonymCount to 1 | set result to 1
        else if (thesaurus[i].word[0] == '\0')
        {
            addedWord = 1; // toggle return value to 1 (added)
            found = 1; // toggle exit from loop
            strcpy(thesaurus[i].word, word);                       
            //strcpy(thesaurus[i].synonyms->name, synonym);
            thesaurus[i].synonyms->relatedFactor = relatedFactor;
            thesaurus[i].synonymCount++;
            printf("name: %s\n related: %d\n", thesaurus[i].synonyms->name, thesaurus[i].synonyms->relatedFactor);
        }
    }

    return addedWord;
}

int main(void)
{
    struct WordInfo thesaurus[MAX_ENTRIES] = { { {0} } };
    int i, j, quitting, numEntries = 0, valid;

    char word[MAX_SZ + 1], synonym[MAX_SZ + 1];
    int relatedFactor;

    // -----------------------------
    // Instructions
    printf("Enter a word, synonym, and related factor (example: Structure|House|1)\n");
    printf("Enter 'Q' by itself to exit (example: Q)\n\n");

    do
    {
        // -----------------------------
        // Prompt:
        printf("Add to thesaurus [word|synonym|factor]: ");
        valid = scanf("%20[^|\n]|%20[^|]|%d", word, synonym, &relatedFactor);
        clearInputBuffer();

        quitting = (valid == 1 && strcmp("Q", word) == 0);
        if (quitting)
        {
            // -----------------------------
            // Display the thesaurus
            printf("\n");
            printf("Thesaurus Data:\n");
            for (i = 0; i < numEntries; i++)
            {
                printf("%2d) %s\n", i + 1, thesaurus[i].word);
                for (j = 0; j < thesaurus[i].synonymCount; j++)
                {
                    printf("\t%2d. %s (Factor:%d)\n", j + 1, thesaurus[i].synonyms[j].name, thesaurus[i].synonyms[j].relatedFactor);
                }
            }
            printf("\n");
        }
        else if (valid == 3)
        {
            printf("entrou");
            // -----------------------------
            // If new word was added, returns 1, otherwise 0
            numEntries += add(word, synonym, relatedFactor, thesaurus, MAX_ENTRIES);
        }
        else
        {
            // -----------------------------
            // Show error message
            printf("\n");
            printf("!!! Invalid input !!!\n");
            printf("Enter a word, synonym, and related factor (example: Structure|House|1)\n");
            printf("Enter 'Q' by itself to exit (example: |)\n\n");
        }

    } while (!quitting);

    // -----------------------------
    // Show goodbye
    printf("Application exiting... Goodbye!\n");

    return 0;
}