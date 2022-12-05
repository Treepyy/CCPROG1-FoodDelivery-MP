// Constants (prices)
#define item1price 60.00
#define item2price 450.00
#define item3price 400.00
#define item4price 220.00
#define item5price 200.00
#define item6price 150.00
#define item7price 30.00
#define item8price 50.00
#define item9price 75.00

/* Function to convert valid characters ('1'-'9') to integers
	Precondition: 'character' is a standard character
	@param character is the character to convert
	@return the corresponding integer value of that character
*/
int convertCharToInt(char character){
	
	int result;
	
	switch(character){
		case '1':
			result = 1;
			break;
		case '2':
			result = 2;
			break;
		case '3':
			result = 3;
			break;
		case '4':
			result = 4;
			break;
		case '5':
			result = 5;
			break;
		case '6':
			result = 6;
			break;
		case '7':
			result = 7;
			break;
		case '8':
			result = 8;
			break;
		case '9':
			result = 9;
			break;
		default :
			result = 11;
			break;
	}
	
	return result;
	
}

/* Function to compute total price of customer orders.
	Precondition: orders1, orders2, orders3 are non-negative and within the range of valid vaues (0-10)
	@param orders1 is the first order
	@param orders2 is the second order
	@param orders3 is the third order
	@return the total price by adding together the prices of each dish
*/
float computePrice(int orders1, int orders2, int orders3){
	
	float total;
	switch(orders1){
		case 1: orders1 = item1price; break; 
		case 2: orders1 = item2price; break; 
		case 3: orders1 = item3price; break; 
		case 4: orders1 = item4price; break; 
		case 5: orders1 = item5price; break; 
		case 6: orders1 = item6price; break; 
		case 7: orders1 = item7price; break; 
		case 8: orders1 = item8price; break; 
		case 9: orders1 = item9price; break; 
		default: orders1 = 0; break;
	}
	
	switch(orders2){
		case 1: orders2 = item1price; break; 
		case 2: orders2 = item2price; break; 
		case 3: orders2 = item3price; break; 
		case 4: orders2 = item4price; break; 
		case 5: orders2 = item5price; break; 
		case 6: orders2 = item6price; break; 
		case 7: orders2 = item7price; break; 
		case 8: orders2 = item8price; break; 
		case 9: orders2 = item9price; break; 
		default: orders2 = 0; break;
	}
	
	switch(orders3){
		case 1: orders3 = item1price; break; 
		case 2: orders3 = item2price; break; 
		case 3: orders3 = item3price; break; 
		case 4: orders3 = item4price; break; 
		case 5: orders3 = item5price; break; 
		case 6: orders3 = item6price; break; 
		case 7: orders3 = item7price; break; 
		case 8: orders3 = item8price; break; 
		case 9: orders3 = item9price; break; 
		default: orders3 = 0; break;
	}
	
	total = orders1 + orders2 + orders3;
	
	return total;
	
}

/* Function to show (printf) prices given an item ID
	Precondition: orderID is within the valid set of values (0-10)
	@param orderID is the order ID (or number) of the given dish
	@return void
*/
void showPrice(int orderID){
	
	switch(orderID){
		case 1: orderID = item1price; break; 
		case 2: orderID = item2price; break; 
		case 3: orderID = item3price; break; 
		case 4: orderID = item4price; break; 
		case 5: orderID = item5price; break; 
		case 6: orderID = item6price; break; 
		case 7: orderID = item7price; break; 
		case 8: orderID = item8price; break; 
		case 9: orderID = item9price; break; 
		default: orderID = 0; break;
	}
	
	if (orderID == 0){
		printf(" ");
	}
	
	else{
		printf("(P%d.00) ", orderID);	
	}
	
}

/* Function to check customer order status, given customer number.
	Precondition: customerNumber must be positive
	@param customerNumber is the customer number of the user
	@param orderStatus[] is the array where order status data is stored
	@return void
*/
void statusCheck(int customerNumber, int orderStatus[]){
	
	switch(orderStatus[customerNumber - 1]){
		case 1: printf("Your order is Booking..."); break;
		case 2: printf("Your order is Waiting..."); break;
		case 3: printf("Your order is Recieved!"); break;
		default: printf("Error: Customer does not exist!"); break;
	}

}

/* Function to convert food item no. to name and print it 
	Precondition: foodID is within the valid set of values (0-10)
	@param foodID is the ID of the dish to display
	@return void
*/
void convertFoodID(int foodID){
	
	switch(foodID){
		
		default: printf("N/A "); break;
		case 1: printf("Cream Stew "); break;
		case 2: printf("Crab Roe Kourayaki "); break;
		case 3: printf("Golden Shrimp Balls "); break;
		case 4: printf("Katsu Sandwich "); break;
		case 5: printf("Shawarma Wrap "); break;
		case 6: printf("Padisarah Pudding "); break;
		case 7: printf("Mineral Water "); break;
		case 8: printf("Orange Juice "); break;
		case 9: printf("Soft Drinks "); break;
		
	}
	
}

/* Header display functions for item menu
	@return void
*/
void displayHeader1(){
	
	printf("\n|----------------------------------------|\n");
	
}

void displayHeader2(){
	
	printf("\n|----------------------------------|\n");
	
}

/* Function to display item menu 
	@return void
*/
void displayMenu(){

	//Foodstuffs
	displayHeader1();
	printf("|        Food         | Price | Item No. |\n");
	printf("|---------------------|-------|----------|\n");
	printf("| Cream Stew          | P60   |        1 |\n");
	printf("| Crab Roe Kourayaki  | P450  |        2 |\n");
	printf("| Golden Shrimp Balls | P400  |        3 |\n");
	printf("| Katsu Sandwich      | P220  |        4 |\n");
	printf("| Shawarma Wrap       | P200  |        5 |\n");
	printf("| Padisarah Pudding   | P150  |        6 |");
	displayHeader1();
	
	//Drinks
	displayHeader2();
	printf("|    Drinks     | Price | Item No. |\n");
	printf("|---------------|-------|----------|\n");
	printf("| Mineral Water | P30   |        7 |\n");
	printf("| Orange Juice  | P50   |        8 |\n");
	printf("| Soft Drinks   | P75   |        9 |");
	displayHeader2();
		
}

/* Function for the 'Order' option
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param orders[][3] is the 2D array where cutomers' orders ID data is kept
	@param isClosed is the variable that determines if the restaurant is closed or not
	@param *pcurrentCustomerData is the pointer to the address of the currentCustomerData variable in main
	@param *ptotalCustomerData is the pointer to the address of the totalCustomerData variable in main
	@param customerNames is the 2D array where customer's names are stored
	@param orderStatus[] is the array where customers' order status are stored
	@param totalServed is the amount of dishes already served by the restaurant
	@param isCooked[][3] is the 2D array where the statuses of if a certain customer's orders are cooked or not is kept
	@param isPacked[][3] is the 2D array where the statuses of if a certain customer's orders are cooked or not is kept
	@param orderType[] is the array where all customers' order types are stored
	@return void
	
*/
void customerOrder(
int orders[][3], int isClosed, int* pcurrentCustomerData, int* ptotalCustomerData, 
char customerNames[][20], int orderStatus[], int totalServed, int isCooked[][3], int isPacked[][3], int orderType[]){

	// Variables for additional customer data
	int currentCustomer = *pcurrentCustomerData;
	int totalCustomers = *ptotalCustomerData;	
	
	// Variables for choosing how many orders to place
	int howManyOrders = 4;
	char choiceOrders;
	
	// Variable for choosing which order to place
	char charOrder;
	
	// Variables for iterative statements
	int i;
	

	if (isClosed == 0 && currentCustomer < 5 && totalCustomers < 10 && totalServed < 20){ 
					
		displayMenu();
		printf("\nYou are customer #%d\n", totalCustomers+1);
		
		// Prompts user to input how many dishes they would like to order
		// If the input is invalid, the process repeats until the user enters a valid input
		while (howManyOrders > 3 || howManyOrders < 0){
			
			printf("How many items would you like to order? (1-3)\n>> ");
			scanf(" %c", &choiceOrders);
			switch(choiceOrders){
				case '1': 
					howManyOrders = 1;
					break;
				case '2':
					howManyOrders = 2;
					break;
				case '3':
					howManyOrders = 3;
					break;
				default:
					howManyOrders = 4;
					break;
			}
			
			if (howManyOrders > 3 || howManyOrders < 0)
				printf("Please enter a value from 1 - 3\n");
			else
				printf("Please enter %d order(s) \n", howManyOrders);
		}
		
		// Order type is determined by how many orders the customer wants to place
		orderType[totalCustomers] = howManyOrders;
				
		for(i = 0; i < howManyOrders; i++){
			while (orders[totalCustomers][i] == 0 || orders[totalCustomers][i] > 10){
				
				printf("Order %d: ", i+1);
				scanf(" %c", &charOrder);
				
				orders[totalCustomers][i] = convertCharToInt(charOrder);
				
				if (orders[totalCustomers][i] == 0 || orders[totalCustomers][i] > 10){
					printf("Please Enter a Valid Order.\n");
				}
				
			}
		}
						
		// Prints the customer's current selected orders		
		printf("Your orders are ");
		for (i = 0; i < howManyOrders; i++){
			convertFoodID(orders[totalCustomers][i]);
			if (i < howManyOrders - 1 && howManyOrders != 1){
				printf(", ");
			}
		}
							
		char choice;
		printf("\nWould you like to proceed with this order? (y/n) \n>> ");
		scanf(" %c", &choice);
		
		// Choice is saved when the user inputs 'y' or 'Y'					
		if (choice == 'Y' || choice == 'y'){
		  						
			printf("\nPlease enter your name \n>> ");
			scanf(" %s", customerNames[totalCustomers]);
			printf("Thank you for ordering %s! Your food will be ready soon.", customerNames[totalCustomers]);		
			orderStatus[totalCustomers] = 1;
			
			// Statements for incrementing current and total customers value
			currentCustomer++;
			*pcurrentCustomerData = currentCustomer;
			totalCustomers++;
			*ptotalCustomerData = totalCustomers;		
						    
		}
		
		// Choice is discarded when the user enters 'n' or any other input outide the previous if statement			
		else{
			// If the customer chooses to discard the order, all values are reset and the current customer can choose again.
			for (i = 0; i < 3; i++){
				orders[totalCustomers][i] = 0;
				isCooked[totalCustomers][i] = 2;
				isPacked[totalCustomers][i] = 2;
				orderType[totalCustomers] = 0;	
			}			
			printf("Your order has been discarded.");	
		}
	}
				
	else if (currentCustomer >= 5){
		printf("Sorry, restaurant is currently full.");
	}
					
	else if (totalCustomers >= 10 || isClosed == 1 || totalServed >= 20){
		printf("Sorry, restaurant is currently closed.");
	}
		
}
/*
	Function for the 'Pay' option.
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param orderStatus[] is the array where customers' order status are stored
	@param isPaidStatus[] is the array where the statuses of if the customer has paid already or not is kept
	@param fCustomersTotal[] is the array where the total costs of the customers' orders are stored
	@param *pfProfits is the pointer to the address of the fProfits variable in main
	@param orders[][3] is the 2D array where cutomers' orders ID data is kept
	@param orderType[] is the array where all customers' order types are stored
	@return void
*/
void customerPay(int orderStatus[], int isPaidStatus[], float fCustomersTotal[], float* pfProfits, int orders[][3], int orderType[], int isCooked[][3], int isPacked[][3]){
	
	// Iterative variable and customer number selection variable
	int i;
	int payNumber;
	
	// Variables for customer wallet and bill
	float customerBudget, total;
	
	// Variable for proceeding with payment
	char proceed;
	
	printf("Please enter your customer number\n>>  ");
	scanf(" %d", &payNumber);
				
	if (payNumber > 0 && payNumber < 11 && isPaidStatus[payNumber - 1] == 0 && orderStatus[payNumber - 1] != 0){
		
		printf("Thank You for Ordering!\n");
		printf("Your Receipt: \n\n");
		printf("-----------------------\n\n");
		printf("%18s","Shimotsukin\n");
		printf("%10s", " 727 Zenith Ave. Manila");
		printf("\n\n-----------------------\n");
		for (i = 0; i < orderType[payNumber - 1]; i++){
			convertFoodID(orders[payNumber - 1][i]);
			printf("... ");
			showPrice(orders[payNumber - 1][i]);
			printf("\n");
		}
		total = computePrice(orders[payNumber - 1][0], orders[payNumber - 1][1], orders[payNumber - 1][2]);
		printf("\n-----------------------\nTotal... P%.2f\n", total);
						
		printf("\nPlease enter the amount of funds\n>> ");
		scanf("%f", &customerBudget);
							
		printf("\nYour total is P%.2f\nWould you like to proceed with this transaction? (y/n)\n>> ", total);
		
		scanf(" %c", &proceed);
		if (proceed == 'Y' || proceed == 'y'){
			
			if (customerBudget - total >= 0){
				printf("\nTransaction completed! ");
				printf("Your change is P%.2f", customerBudget - total);
				fCustomersTotal[payNumber - 1] = total;
				isPaidStatus[payNumber - 1] = 1;
				
				if (orderStatus[payNumber - 1] != 3){
					orderStatus[payNumber - 1] = 2;
				}
				
				*pfProfits += total;
				
				// Once the order has been paid for, the corresponding isCooked and isPacked values are updated.
				// This loop looks through the customer's orders array to see if there is a 0 (empty order)
				// If there is still a 0, the corresponding isCooked and isPacked value will be set to 1 (true), while other non-zero order's statuses are set to 0 (false)
				for(i = 0; i < 3; i++){
					if (orders[payNumber - 1][i] == 0){
						isCooked[payNumber - 1][i] = 1;
						isPacked[payNumber - 1][i] = 1;
					}
					else{
						isCooked[payNumber - 1][i] = 0;
						isPacked[payNumber - 1][i] = 0;
					}
				}
				
			}
			
			else {
				printf("Insufficient funds!");
			}
		}
		
		else{
			printf("Transaction has been discarded.");
		}
	}
				
	else if (isPaidStatus[payNumber - 1 == 1] && orderStatus[payNumber - 1] != 0){
		printf("You have already paid for your order!");
	}
				
	else if (orderStatus[payNumber - 1] == 0){
		printf("Error: Customer does not exist!");
	}
	
	else if (payNumber > 10 || payNumber <= 0){
		printf("Error: Invalid customer number!");
	}
	
	
}

/*
	This function displays and processes the options of  the 'customer' selection. 
	It serves as the 'main' function of the customer menu.
	Precondition: All variables and arrays have values which were defined in the main function
	@param orders[][3] is the 2D array where cutomers' orders ID data is kept
	@param isClosed is the variable that determines if the restaurant is closed or not
	@param *pcurrentCustomerData is the pointer to the address of the currentCustomerData variable in main
	@param *ptotalCustomerData is the pointer to the address of the totalCustomerData variable in main
	@param customerNames is the 2D array where customer's names are stored
	@param orderStatus[] is the array where each customers' order status values are stored
	@param *pfProfits is the pointer to the address of the fProfits variable in main
	@param isPaidStatus[] is the array where the statuses of if the customer has paid already or not is kept
	@param fCustomersTotal[] is the array where the total costs of the customers' orders are stored
	@param totalServed is the amount of dishes already served by the restaurant
	@param isCooked[][3] is the 2D array where the statuses of if a certain customer's orders are cooked or not is kept
	@param isPacked[][3] is the 2D array where the statuses of if a certain customer's orders are cooked or not is kept
	@param orderType[] is the array where all customers' order types are stored
	@return void
*/
void customerActions(
int orders[][3], int isClosed, int* pcurrentCustomerData, int* ptotalCustomerData, char customerNames[][20],
int orderStatus[], float* pfProfits, int isPaidStatus[], float fCustomersTotal[], int totalServed, int isCooked[][3], int isPacked[][3], int orderType[]){ 
	
	// Control variable for menu 
	char cSelection;
	
	// Control variable for checking status
	int statusNumber;
	
	while(cSelection != '4'){
		printf("\n");
		printf("\n");
		printf("Welcome Customer! What would you like to do?");
		printf("\n");
		printf("%s\n", "--------------------");
		printf("> [1] Order\n");
		printf("> [2] Pay\n");
		printf("> [3] Display Status\n");
		printf("> [4] Exit\n");
		
		printf("\nEnter your selection\n >> ");
		scanf(" %c", &cSelection);
		
		switch(cSelection){
			
			case '1': // The 'order' option will only be open when there are less than 5 customers, or if the manager did not close the restaurant.
				
				customerOrder(orders, isClosed, pcurrentCustomerData, 
				ptotalCustomerData, customerNames, orderStatus, totalServed, isCooked, isPacked, orderType);	
				
				break;
			
				
			case '2': // The 'Pay' option
				
				if (isClosed == 0){
					customerPay(orderStatus, isPaidStatus, fCustomersTotal, pfProfits, orders, orderType, isCooked, isPacked);
				}
				else{
					printf("Sorry, restaurant is currently closed.");
				}
				
				break;	
			
				
			case '3': // The 'Display Status' option
				printf("Please enter your customer number: "); 
				scanf("%d", &statusNumber);
				
				if (statusNumber > 10 || statusNumber < 1){
					printf("Error: Customer does not exist!");
				}
				else{
					statusCheck(statusNumber, orderStatus);
				}
				
				break;
			
			
			case '4': // If 'Exit' is chosen, the user is redirected to the Main Menu thru the while loop.
				break;
			
			
			default:
				printf("\nInvalid input. Please select a valid option.\n"); 
				break;
		}
	}
}
