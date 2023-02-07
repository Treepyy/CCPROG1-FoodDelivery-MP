/*
**************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and
applying the concepts learned. I have constructed the functions and their respective
algorithms and corresponding code by myself. The program was run, tested, and debugged
by my own efforts. I further certify that I have not copied in part or whole or otherwise
plagiarized the work of other students and/or persons.
															
ID# 12279560
**************************************************************************
*/

/*
 Description: A program which simulates a restaurant's food delivery services.
 Programmed by: -, Section S25A
 Last modified: 12/04/2022
 Version: 1.0.0a
 
 [Acknowledgements: 
 Dr. Judith Azcarraga, 
 Carlos Pangaliban @YouTube: A Filipino's Guide to Programming, https://www.youtube.com/playlist?list=PLRBUyvh6wWhEKZ4I9VH8mQz3YB8lRprAS
 Neso Academy @YouTube: C Programming & Data Structures, https://www.youtube.com/playlist?list=PLBlnK6fEyqRhX6r2uhhlubuF5QextdCSM
 Programiz Website, https://www.programiz.com/, ]
*/

// Preprocessor directives
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include "customerMenu.c"
#include "managerMenu.c"
#include "chefMenu.c"
//#include "debugDisplayAllVariables.c"

int main(){
	
	// Statements for choosing N at the start
	int N = 4;
	char choiceN;
	
	printf("The N value determines how many dishes the Chef will cook at a time.\nEnter N value\n>> ");
	while(N > 3 || N < 0){
		
		scanf(" %c", &choiceN);
		
		switch(choiceN){
			case '1': 
				N = 1;
				break;
			case '2':
				N = 2;
				break;
			case '3':
				N = 3;
				break;
			default:
				N = 4;
				break;
		}
		
		if (N > 3 || N < 0)
			printf("Please enter a value from 1 - 3\n>> ");
		else
			printf("Done! The Chef will cook %d dishes at a time.\n\n", N);
	}
	
	// Array for keeping customer orders data in main. All values are initialized to 0.
	// [Column][Row]
	// Array column # : Customer Number
	// Array row 0, 1, 2 : Customer Order
	int ordersData[10][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
	
	// Array for keeping customer order types
	// Type 0 - DNE | Type 1 - one order | Type 2 - two orders | Type 3 - three orders
	int orderType[10] = {0,0,0,0,0,0,0,0,0,0};
	
	// Names: [Max Capacity][Max No. of Characters] | All names are initialized to "N/A".
	char customerNames[10][20] = {"N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A"};
	
	// Arrays for keeping customer order statuses. Values are initialized to 0.
	int orderStatus[10] = {0,0,0,0,0,0,0,0,0,0};
	int isDeliveredStatus[10] = {0,0,0,0,0,0,0,0,0,0};
	int isPaidStatus[10] = {0,0,0,0,0,0,0,0,0,0};
	
	// Arrays for keeping customer's isCooked and isPacked status. Values are initialized to 2 (DNE or Not PAID).
	// status 2 = DNE / Not PAID | status 1 = COOKED | status 0 = NOT COOKED
	int isPackedStatus[10][3] = {{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2}};
	int managerPackedStatus[10][3] = {{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2}};
	
	int isCookedStatus[10][3] = {{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2},{2,2,2}};
	
	// Array for keeping customer total info
	float fCustomersTotal[10] = {0,0,0,0,0,0,0,0,0,0};
	
	// Variables for tracking current and total customer no.
	int currentCustomer = 0;
	int totalCustomers = 0;
	
	int isSent = 0; // Variable for tracking if manager has sent info already or not
	int isReceived = 0; // Variable for tracking if chef has received order or not
	
	// Variable for keeping track of total orders served
	int totalServed = 0;
	
	// Variable for keeping track of total profits from customers paid
	float fProfits = 0;
	
	// Control variable for closing
	int isClosed = 0;
	
	// Control variable for main menu
	char cSelection;
	
	// Variable for total customers delivered to 
	int totalDelivered = 0;
	
	while(cSelection != '4'){
		
		// If total served dishes reaches 20, the restaurant closes
		if (totalServed >= 20){
			isClosed = 1;
		}
		
		// If total delivered reaches 10, the restaurant closes
		if (totalDelivered >= 10){
			isClosed = 1;
		}
		
		// In the case that currentCustomer becomes a negative value, currentCustomer is reset to 0
		if (currentCustomer < 0){
			currentCustomer = 0;
		}
		
		printf("\n");
		printf("%s\n", "--------++++--------");
		printf("%16s","Welcome to\n");
		printf("%16s","Shimotsukin\n");
		printf("\n%s\n", "--------++++--------");
		printf("%15s","Main Menu\n");
		printf("%s\n", "--------------------");
		printf("> [1] Customer\n");
		printf("> [2] Manager\n");
		printf("> [3] Chef\n"); 
		printf("> [4] Exit\n");
	
		printf("\nEnter your selection\n >> ");
		scanf(" %c", &cSelection);
		
		switch(cSelection){
			
			case '1':
				customerActions(ordersData, isClosed, &currentCustomer, &totalCustomers, customerNames, 
				orderStatus, &fProfits, isPaidStatus, fCustomersTotal, totalServed, isCookedStatus, isPackedStatus, orderType); 
				
				break;
				
			case '2':
				managerActions(&isClosed, ordersData, customerNames, isPackedStatus, isDeliveredStatus, orderStatus, fProfits, 
				isPaidStatus, fCustomersTotal, &currentCustomer, &isSent, orderType, isCookedStatus, managerPackedStatus, totalServed, &isReceived, &totalDelivered); 
				
				break;
				
			case '3':
				chefActions(N, isCookedStatus, &isReceived, isPackedStatus, &currentCustomer, &isSent, 
				&totalServed, &isClosed, managerPackedStatus);
				
				break;
			
			case '4': 
				// If 'Exit' is chosen, the program is terminated through a return value in the main function.
				printf("Thank you for visiting us!");
				break;
			
			/*Case for Displaying ALL Variables (debugging)
			case 'd':
				displayAllVariables (N, ordersData, orderType, customerNames, orderStatus, isDeliveredStatus, isPaidStatus, 
									isPackedStatus, managerPackedStatus, isCookedStatus, fCustomersTotal, currentCustomer,
									totalCustomers, isSent, isReceived, totalServed, fProfits, isClosed);
				break;*/
			
			default: 
				// If the input is not within the given parameters, 'invalid input' will be displayed and the main menu will be shown again.
				printf("\nInvalid input. Please select a valid option.\n"); 
				break;
				
		}
	}
	
	return 0;
}
