// Nicholas Beaudoin
// Assignment 2
// 3-1-2016

#define _CRT_SECURE_NO_WARNINGS 1
#define CREDITLIMIT -2000

#include <stdio.h>

// displays the list of users options
//displays the users selections and sets the value of the choice
void entryMenu(int *option);

// displays the tpes of account they would like to access and sets the value
// of the chosen accouunt type
void choiceMenu(char *acctType);

// prompts the user for the amount of their deposit and updates their selected account
void makeDeposit(double *bankBal);

// asks the user if they want another transaction
void doMore(char *moreToDo);

// displays the users current account balance for the selected account
void displayBalance(double bankBal);

// prompts the user for the amount of the withdrawal, determines if there are
// sufficient funds and updates the selected account if funds are dispensed
void moneyToSpend(double *bankBal, char acctType);



int main() {

	// declare all variables
	// do NOT declare any pointers
	// initialize bank account variables to amounts specified in assignment
	int option;
	char acctType, moreToDo;
	double checkBal = 897.23,
		savBal = 3750.00,
		creditBal = -750.00;


	printf("\nWelcome to MyBank\n");
	do {
		// display entry menu
		entryMenu(&option);
        printf("%d", option);

		//display choice menu
		choiceMenu(&acctType);
		// get users choice


		// use conditional statements to determine which functions to call
		// and which account balance to pass

		if (option == 1) {
			//deposit - pass balance of account (by pointer)
			switch (acctType) {
			case 'C':
				makeDeposit(&checkBal);
				break;
			case 'S':
				makeDeposit(&savBal);
				break;
			case 'R':
				makeDeposit(&creditBal);
				break;
			}
		}
		else if (option == 2) {
			// withdrawal - pass balance of account(by pointer) and type of account
			switch (acctType) {
			case 'C':
				moneyToSpend(&checkBal, acctType);
				break;
			case 'S':
				moneyToSpend(&savBal, acctType);
				break;
			case 'R':
				moneyToSpend(&creditBal, acctType);
				break;
			}
		}
		else {
			// display balance - pass balance of account
			switch (acctType) {
			case 'C':
				displayBalance(checkBal);
				break;
			case 'S':
				displayBalance(savBal);
				break;
			case 'R':
				displayBalance(creditBal);
				break;
			}
		}



		// call function to ask for another transaction
		doMore(&moreToDo);

	} while (moreToDo == 'y');

	return 0;
}


/*
* function definitions
*/

// displays the list of users options
//displays the users selections and sets the value of the choice
void entryMenu(int * option)
{
	char temp = ' ';
	printf("\nPlease choose from the following menu:\n");
	printf("DEPOSIT ........... 1\n");
	printf("WITHDRAWAL ........ 2\n");
	printf("ACCOUNT BALANCE ... 3\n");
	printf("To transfer money, first select (2) for WITHDRAWAL\n");
	printf("Then (1) for DEPOSIT\n\n");
	printf("Your selection: ");
	scanf(" %c", &temp);

	
    switch(temp){
        case '1':
            *option = 1;
            break;
        case '2':
            *option = 2;
            break;
        case '3':
            *option = 3;
            break;
        default:
            printf("\n***Incorrect Selection***\n\n");
		    entryMenu(option); 
    }
   
}

// displays the tpes of account they would like to access and sets the value
// of the chosen accouunt type
void choiceMenu(char * acctType)
{
	printf("\nType of account\n");
	printf("Choose C for Checking\n");
	printf("Choose S for Savings\n");
	printf("Choose R for Credit\n\n");
	printf("Your selecion: ");
	scanf(" %c", acctType);

	switch (*acctType) {
	case 'c':
	case 'C':
		*acctType = 'C';
		break;
	case 's':
	case 'S':
		*acctType = 'S';
		break;
	case 'r':
	case 'R':
		*acctType = 'R';
		break;
	default:
		printf("\n***Incorrect selection***\n\n");
		choiceMenu(acctType);
	}
}

// prompts the user for the amount of their deposit and updates their selected account
void makeDeposit(double * bankBal)
{
	double deposit;
	printf("\nPlease enter the amount of your deposit: ");
	scanf(" %lf", &deposit);

	*bankBal += deposit;

	printf("\nDon't forget your reciept!\n\n");
}


// asks the user if they want another transaction
void doMore(char * moreToDo)
{
	char temp;

	do {
		printf("Do you wish to make another selection? (y or n): ");
		scanf(" %c", &temp);
	} while (temp != 'y' && temp != 'n');
	*moreToDo = temp;
}


// displays the users current account balance for the selected account
void displayBalance(double bankBal)
{
	printf("You have %.2f in your account\n\n", bankBal);
}


// prompts the user for the amount of the withdrawal, determines if there are
// sufficient funds and updates the selected account if funds are dispensed
void moneyToSpend(double * bankBal, char acctType)
{
	double amount;
	printf("\nPlease enter the amount of your withdrawal: ");
	scanf(" %lf", &amount);

	if (acctType == 'S' || acctType == 'C')
		if (amount <= *bankBal) {
			*bankBal -= amount;
			printf("Please take your cash and reciept\n\n");
		}
		else {
			printf("\n***INSUFFICIENT FUNDS***\n\n");
		}
	else {
		if (*bankBal - amount >= CREDITLIMIT) {
			*bankBal -= amount;
			printf("Please take your cash and reciept\n\n");
		}
		else {
			printf("***INSUFFICIENT CREDIT***\n\n");
		}
	}
}
