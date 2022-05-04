//==============================================
// Name:           Davi Leonardi Mathey	
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4

int main(void)
{
	int highTemp, lowTemp, i, check, highestTemp = -41, lowestTemp = 40, highDay, lowDay;
	double averageTemp = 0.00, averageLowTemp = 0.00, averageHighTemp = 0.00;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++)
	{
		check = 1;
		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &highTemp);

		printf("\nEnter the low value for day %d: ", i + 1);
		scanf("%d", &lowTemp);
		printf("\n");
		while (highTemp < lowTemp || (highTemp > 40 || lowTemp < -41))
		{
			check = 0;
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
			i--;
			break;
		}

		if (check == 1)
		{
			averageTemp = (double)(averageTemp + highTemp + lowTemp);
			averageHighTemp += (double)highTemp;
			averageLowTemp += (double)lowTemp;
			
			if (highestTemp < highTemp)
			{
				highestTemp = highTemp;
				highDay = i;
			}

			if (lowestTemp > lowTemp)
			{
				lowestTemp = lowTemp;
				lowDay = i;
			}

		}
	}

	printf("The average (mean) LOW temperature was: %.2lf", averageLowTemp / (double)NUMS);
	printf("\nThe average (mean) HIGH temperature was: %.2lf", averageHighTemp / (double)NUMS);
	printf("\nThe average (mean) temperature was: %.2lf", averageTemp / (double)(NUMS * 2));
	printf("\nThe highest temperature was %d, on day %d", highestTemp, (highDay+1));
	printf("\nThe lowest temperature was %d, on day %d", lowestTemp, (lowDay+1));

	return 0;
}