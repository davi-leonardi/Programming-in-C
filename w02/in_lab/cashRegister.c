//==============================================
// Name:			Davi Leonardi Mathey
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>

int main(void) 
{
	double amount, balance1, balance2;
	int loonies;
	int quarters;

	printf("Please enter the amount to be paid: $");    //8.68
	scanf("%lf", &amount);

	loonies = amount;
	balance1 = (amount - loonies);
	quarters = balance1 / 0.25;
	balance2 = balance1 - (quarters * 0.25);

	
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, balance1);
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, balance2);
	
	return 0;
}
