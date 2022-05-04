//==============================================
// Name:           Davi Leonardi Mathey	
// Student Number: 154979199
// Email:          dleonardi-mathey@myseneca.ca
// Section:        NRR
// Workshop:       5 (at-home)
//==============================================
/*
1.	Start program
2.	Define no warnings
3.	Include library < stdio.h>
4.	Define constant “SIZE” and set to 4
5.	Declare struct Employee with 3 elements, id, age, and salary
6.	Start main function
7.	Declare the following variable and set them in a safe state : option, n, searchId, found, nBeforeRemoval.
8.	Declare iterators I and j.
9.	Set all elements of struct Employee to 0
10.	Output the title to the user
11.	Display the menu with 5 possible option, if none of the options is correctly selected, print an error message and keep asking valid input
12.	If option 1 is selected, show all the employee’s data(elements of the struct Employee), and keep repeating until there is no employee left
	a.Go back to step #11
13.	If option 2 is selected, print the title of the section “adding employee”
	a.If the number of employees is greater or equal than the const SIZE : print an error message
	b.If the number of employees is lower than the const SIZE :
		i.If an employee has been removed recently : overwrite the old data with the new employee’s data
		ii.Ask input of data to the user for the new employee added(data = struct’s elements)
	c.Increase the employee’s counter
	d.Go back to step #11
14.	If option 3 is selected, print the title of the section “Update Employee’s salary”
	a.Ask for the employee’s id until a valid answer is provided; while no valid input is given, show error message.
	b.Show the employee’s idand salary
	c.Request a new salary for the employee
	d.Overwrite the old salary with the new one
	e.Go back to step #11
15.	If option 4 is selected, print the title of the section “Remove Employee”
	a.Ask for the employee’s id until a valid answer is provided; while no valid input is given, show error message.
	b.Show the employee’s id which will be removed
	c.Set employee’s id to zero, and decrease the number of employees
	d.Go back to step #11
16.	If option 0 is selected, show a message, and exit the program
	a.Return 0 to the system
17.	Stop 
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 4		

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
	int j;
	int searchId = 0, found = 0, removal = 0, nBeforeRemoval;

	struct Employee emp[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		scanf("%d", &option);
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
				
				nBeforeRemoval = n;

				if (removal)
				{
					n = j;
				}

				printf("Enter Employee ID: ");
				scanf("%d", &emp[n].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[n].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[n].salary);
				
				if (removal)
				{
					removal = 0;
					n = nBeforeRemoval + 1;
				}
				n++;
			}

			printf("\n");

			break;

		case 3:

			printf("Update Employee Salary\n");
			printf("======================\n");
			printf("Enter Employee ID: ");
			scanf("%d", &searchId);

			do
			{
				for (j = 0; j < SIZE && !found; j++)
				{
					if (emp[j].id == searchId)
					{
						found = 1;
						j--;
					}
				}

				if (!found)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
					printf("Enter Employee ID: ");
					scanf("%d", &searchId);
				}

			} while (!found);

			printf("The current salary is %.2lf\n", emp[j].salary);
			printf("Enter Employee New Salary: ");
			scanf("%lf", &emp[j].salary);

			printf("\n");

			found = 0;

			break;

		case 4:

			printf("Remove Employee\n");
			printf("===============\n");
			printf("Enter Employee ID: ");
			scanf("%d", &searchId);

			do
			{
				for (j = 0; j < SIZE && !found; j++)
				{
					if (emp[j].id == searchId)
					{
						found = 1;
						j--;
					}
				}

				if (!found)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
					printf("Enter Employee ID: ");
					scanf("%d", &searchId);
				}

			} while (!found);

			found = 0;

			printf("Employee %d will be removed\n", emp[j].id);
			
			printf("\n");

			removal = 1;
			emp[j].id = 0;
			n--;

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}