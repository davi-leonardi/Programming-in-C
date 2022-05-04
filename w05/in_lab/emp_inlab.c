//==============================================
// Name:           Davi Leonardi Mathey
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR
// Workshop:       5 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 2		

struct Employee
{
	int id;
	int age;
	double salary;
};

int main(void) 
{
	int option = 0;
	int n = 0;
	int i;

	struct Employee emp[SIZE] = { {0} };
    
	printf("---=== EMPLOYEE DATA ===---\n\n");

	do 
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		scanf("%d",&option);
		printf("\n");
		
		switch (option) 
		{
		case 0:	
			printf("Exiting Employee Data Program. Good Bye!!!");
			break;

		case 1: 

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			
			for (i = 0; i < SIZE; i++)
			{
				if (emp[i].id != 0)
				{
					printf("%6d%9d%11.2lf", emp[i].id, emp[i].age, emp[i].salary);
					printf("\n");
				}
			}
			printf("\n");
			break;

		case 2:	
				
			printf("Adding Employee\n");
			printf("===============\n");
			if (n >= SIZE)
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			else
			{
				printf("Enter Employee ID: ");
				scanf("%d", &emp[n].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[n].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[n].salary);
				n++;
			}
			
			printf("\n");

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0; 
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
