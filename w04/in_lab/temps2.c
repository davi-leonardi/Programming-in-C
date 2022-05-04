//==============================================
// Name:           Davi Leonardi Mathey	
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define SZ 10

int main(void)
{
	int days = 0, i;
	int high[SZ] = {0}, low[SZ] = {0};

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);

	while (days < 3 || days > SZ)
	{
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
	}
	
	printf("\n");

	for (i = 0; i < days; i++)
	{ 
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i < days; i++) 
	{
		printf("%d    %d    %d\n", (i + 1), high[i], low[i]);
	}
	
	return 0;
}