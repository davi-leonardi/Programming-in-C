//==============================================
// Name:           Davi Leonardi Mathey
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR	
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications

#include <stdio.h>

int main(void)
{
	double amount, GST;
	int loonies, quarters, dimes, nickels, pennies;
	int balance1, balance2, balance3, balance4, balance5;

	printf("Please enter the amount to be paid: $");    //8.68
	scanf("%lf", &amount);

	GST = (amount * .13) + .005;

	printf("GST: 1.13\n");
	
	amount += GST;

	printf("Balance owing: $%.2lf\n", amount);

	loonies = amount;  //9.81
	balance1 = (amount - loonies) * 100;  //81
	
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, (double)balance1 / 100);
	
	quarters = balance1 / 25; //25 = 0.25 * 100;
	balance2 = balance1 % 25; //25 = 0.25 * 100;

	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (double)balance2/100);

	dimes = balance2 / 10; //10 = 0.10 * 100;                
	balance3 = balance2 % 10;  //10 = 0.10 * 100;                 

	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (double)balance3/100);

	nickels = balance3 / 5; //5 = 0.05 * 100
	balance4 = balance3 % 5; //5 = 0.05 * 100

	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, (double)balance4 / 100);

	pennies = balance4 / 1; //1 = 0.01 * 100
	balance5 = balance4 % 1; //1 = 0.01 * 100

	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (double)balance5 / 100);

	return 0;
}