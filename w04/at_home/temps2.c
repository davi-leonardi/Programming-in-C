//==============================================
// Name:           Davi Leonardi Mathey
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR
// Workshop:       4 (at-home)
//==============================================
//1. Start
//2. include library "stdio.h"
//3. define constant "sz" and set value to 10
//4. Start main function
//5. Declare and initialize the following variables in a safe state : days, highestDay, lowestDay, averageDay, highestTemp, lowestTemp, totalTemp, i.
//6. Declare arrays, set their index to "SZ" and put them in a safe state.
//7. Print to the user the title of the program
//8. request the number of days between 3 and 10
//9. Store the input in the variable "days"
//10. If the user inputs the wrong number, show error messageand keep requesting input until it is correct.
//11. Request the user to input the high and low temperature for "days" times
//12. Store the input in the arrays "high[i]" and "low[i]".
//13. Keep adding the inputs and store them in the var "totalTemp"
//14. After the loop finishes, store the highest temperature in the var "highestTemp" and the lowest temperature in the var "lowestTemp"
//15. print to the user all the temperature values that he inputed before like parallel arrays
//16.print to the user the highest and lowest temperature
//17. Request the user to input a number between 1 and 5
//18. if the input is - 1, go to step #24.
//19. if the input is not - 1 and not a number between 1 and 5, keep requesting him input until it is correct.
//20. store the number in the var "averageDay"
//21. calculate the average temperature up to the day inputed above
//22. print to the user the day that he inputed above and average temperature up to that day.
//23. go to step #17
//24. output to the user : "Goodbye!"
//25. return 0 to the system
//26. Stop
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Place your code below

#include <stdio.h>
#define SZ 10

int main(void)
{
	int days = 0, highestDay = 0, lowestDay = 0, averageDay = 0;
	int high[SZ] = { 0 }, low[SZ] = { 0 }, highestTemp = -100, lowestTemp = 100;
	int averageTemp[SZ] = { 0 }, totalTemp = 0;
	int i;

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

		if (highestTemp < high[i]) 
		{
			highestTemp = high[i];
			highestDay = (i + 1);
		}

		if (lowestTemp > low[i])
		{
			lowestTemp = low[i];
			lowestDay = (i + 1);
		}
		
		totalTemp += high[i] + low[i];
		averageTemp[i] = totalTemp;
			
	}
	
	printf("\nDay  Hi  Low\n");

	for (i = 0; i < days; i++)
	{
		printf("%d    %d    %d\n", (i + 1), high[i], low[i]);
	}

	printf("\nThe highest temperature was %d, on day %d", highestTemp, highestDay);
	printf("\nThe lowest temperature was %d, on day %d", lowestTemp, lowestDay);

	printf("\n");

	do
	{ 
		printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &averageDay);

		while (averageDay == 0 ||averageDay > 5)
		{
			printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");
			scanf("%d", &averageDay);
		}
		
		if (averageDay > 0)
		{
			averageDay--;
			printf("\nThe average temperature up to day %d is: %.2lf", (averageDay + 1), ((double)(averageTemp[averageDay]) / (((double)(averageDay) + 1.00) * 2.00)));
			averageDay++;
			printf("\n");
		}
	} while (averageDay >= 0);

	printf("\nGoodbye!");
	
	return 0;
}