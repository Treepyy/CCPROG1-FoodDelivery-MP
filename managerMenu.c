/*
	This function displays the loading bar for the 'Send Driver' option
	@return void
*/
void displayManagerProgressBar()
{
	
	int i;
	char a = '-', b = '>';
	
	// Initial loading bar
	for (i = 0; i < 10; i++)
		printf("%c", a);

	// Sets cursor to start of the line
	printf("\r");

	// Loading bar progress
	for (i = 0; i < 10; i++) {
		printf("\b");
		printf("-");
		printf("%c", b);

		// Loading bar interval time (in ms)
		Sleep(200);
	}
	printf("\n");
	
}

/*
	This function displays the loading bar for the 'Send Orders to Chef' option
	@return void
*/
void displaySendingProgress(){
	
	int i;
	char a = '-', b = '>';
	
	// Initial loading bar
	for (i = 0; i < 10; i++)
		printf("%c", a);

	// Sets cursor to start of the line
	printf("\r");

	// Loading bar progress
	for (i = 0; i < 10; i++) {
		printf("%c", b);

		// Loading bar interval time (in ms)
		Sleep(200);
	}
	printf("\n");
}

/*
	Function for the 'Display Served Dishes' option.
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param isDeliveredStatus[] is the array where the status of if a certain customer's orders has already been delivered or not is kept
	@param customerNames is the 2D array where customer's names are sto
	@param orders[][3] is the 2D array where cutomers' orders ID data is kept
	@param totalServed is the number of total dishes served
	@param orderType is the array where all customers' order types are stored
	@return void
*/
void managerDisplayServed(int isDeliveredStatus[], char customerNames[][20], int orders[][3], int totalServed, int orderType[]){
	
	int i, j;
	
	// The total ordered dishes is the sum of the values of the orderType array
	int totalOrdered = 0;
	for (i = 0; i < 10; i++){
		totalOrdered += orderType[i];
	}
	printf("\nTotal Ordered Dishes: %d\n", totalOrdered);
	
	// Served dishes are dishes that have already been packed
	printf("\nTotal Served Dishes: %d\n", totalServed);	
	
	// Displays all customers with an order type that isn't 0 (omits customers that do not yet exist)
	printf("\nCurrent Ordered Dishes: \n");
	for(i = 0; i < 10; i++){
		if (orderType[i] != 0){
			printf("[Customer #%d] [Name: %s]\n", i+1, customerNames[i]);
			for (j = 0; j < orderType[i]; j++){
				printf("No. %d - ", orders[i][j]);
				convertFoodID(orders[i][j]);
				showPrice(orders[i][j]);
				printf(" ");
				if (j == orderType[i] - 1){
					printf("\n");
				}
			}
		}
	}
	
	// Displays all customers with an isDeliveredStatus of 1
	printf("\nCurrent Delivered Dishes: \n");
	for(i = 0; i < 10; i++){
		if (isDeliveredStatus[i] == 1){
			printf("[Customer #%d] [Name: %s]\n", i+1, customerNames[i]);
			for (j = 0; j < orderType[i]; j++){
				printf("No. %d - ", orders[i][j]);
				convertFoodID(orders[i][j]);
				showPrice(orders[i][j]);
				printf(" ");
				if (j == orderType[i] - 1){
					printf("\n");
				}
			}
		}
	}
	
}

/*
	Function for the 'Display Income' option.
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param *fProfits is the pointer to the address of the fProfits variable in main
	@param isPaid[] is the array where the statuses of if the customer has paid already or not is kept
	@param customerNames is the 2D array where customer's names are stored
	@param fCustomersTotal[] is the array where the total costs of the customers' orders are stored
	@return void
*/
void managerDisplayIncome(float fProfits, int isPaid[], char customerNames[][20], float fCustomersTotal[]){
	
	int i;
	
	printf("Total Income for the Day: P%.2f \n\n", fProfits);
	printf("Paid Customers: \n");
	
	for(i = 0; i < 10; i++){
		if (isPaid[i] == 1){
			printf("[Customer #%d] [Name: %s]", i+1, customerNames[i]);
			printf(" [Total: P%.2f]\n", fCustomersTotal[i]);
		}
			
		else{
			printf(" ");
		}
	}
}

/*
	Function for the 'Send Driver' option.
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param isPackedStatus[][3] is the 2D array where the statuses of if a certain ordered dish has already been packed or not is kept
	@param isDeliveredStatus[] is the array where the status of if a certain customer's orders has already been delivered or not is kept
	@param orderStatus[] is the array where each customer's order status values are stored
	@return void
*/
void managerSendDriver(int isPackedStatus[][3], int isDeliveredStatus[], int orderStatus[], int *pCurrentCustomer, int *pTotalDelivered){
	
	int currentCustomer = *pCurrentCustomer;
	int totalDelivered = *pTotalDelivered;
	int deliveryNumber;
	
	printf("Enter customer number to deliver for \n>> ");
	scanf(" %d", &deliveryNumber);
	
	if (isPackedStatus[deliveryNumber - 1][0] == 1 && isPackedStatus[deliveryNumber - 1][1] == 1 && isPackedStatus[deliveryNumber - 1][2] == 1 
		&& isDeliveredStatus[deliveryNumber -1] == 0 && deliveryNumber > 0 && deliveryNumber < 11){
		
		printf("Delivering...\n");
		displayManagerProgressBar();
		
		// If all orders are ready, statuses are set
		isDeliveredStatus[deliveryNumber - 1] = 1;
		orderStatus[deliveryNumber - 1] = 3;
		
		// Current customer is decremented
		currentCustomer--;
		*pCurrentCustomer = currentCustomer;
		
		// Total delivered is incremented
		totalDelivered++;
		*pTotalDelivered = totalDelivered;
		
		printf("Arrived!");
	}
				
	else if ((isPackedStatus[deliveryNumber - 1][0] != 1 || isPackedStatus[deliveryNumber - 1][1] != 1 || isPackedStatus[deliveryNumber - 1][2] != 1) 
			&& deliveryNumber > 0 && deliveryNumber < 11){
		printf("Entered customer\'s order is not ready yet!");
	}
	
	else if (isDeliveredStatus[deliveryNumber -1] == 1){
		printf("Entered customer\'s order has already been delivered!");
	}
	
	else if (deliveryNumber > 10 || deliveryNumber <= 0){
		printf("Invalid customer number!");
	}
	
}

/*
	Function for the 'List Current Customers' option.
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param orderStatus[] is the array where each customer's order status values are stored
	@param customerNames is the 2D array where customer's names are stored
	@param isPackedStatus[][3] is the 2D array where the statuses of if a certain ordered dish has already been packed or not is kept
	@param orders[][3] is the 2D array where cutomers' orders ID data is kept
	@param orderType[] is the array where all customers' order types are stored
	@param isPaid is the array where the statuses of if the customer has paid already or not is kept
	@return void
*/
void managerListCustomers(int orderStatus[], char customerNames[][20], int isPackedStatus[][3], int orders[][3], int orderType[], int isPaid[]){
	
	int i, j;
	
	printf("Current Customer\'s Orders Data:\n");
	for(i = 0; i < 10; i++){
					
		// This conditional makes it so that only existing customers, and customers whose orders are not yet delivered is shown
		if (orderStatus[i] != 0 && orderStatus[i] != 3){
			printf("[Customer #%d] [Name: %s]", i+1, customerNames[i]);
			if (isPaid[i] == 1){
				printf(" [Paid Status: YES]\n");
			}
			else{
				printf(" [Paid Status: NO]\n");
			}
		}
				
		// Displays customers' data based on order type (how many items they ordered)	
		// Only displays customers whose orders haven't been delivered.			
		for (j = 0; j < orderType[i]; j++){
			if (orderStatus[i] != 0 && orderStatus[i] != 3){ 
				convertFoodID(orders[i][j]);
				printf(" ");
				if (j == orderType[i] - 1){
					printf("\n");
				}
			}
		}
	}
}
/*
	Function for the 'List Pending Orders' option.
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param orderStatus[] is the array where each customer's order status values are stored
	@param isCookedStatus[][3] is the 2D array where the statuses of if a certain ordered dish has already been cooked or not is kept
	@param orders[][3] is the 2D array where cutomers' orders ID data is kept
	@param orderType[] is the array where all customers' order types are stored
	@param customerNames is the 2D array where customer's names are stored
	@return void
*/
void managerListPending(int orderStatus[], int isCookedStatus[][3], int orders[][3], int orderType[], char customerNames[][20]){
	
	int i, j;
	
	printf("Pending Orders:\n");
	
	for(i = 0; i < 10; i++){
					
		// This conditional makes it so that only existing customers, and customers whose orders are not yet cooked is shown
		if (isCookedStatus[i][0] == 0 || isCookedStatus[i][1] == 0 || isCookedStatus[i][2] == 0){
			printf("[Customer #%d] [Name: %s]\n", i+1, customerNames[i]);
		}
					
		// Displays customers' data based on order type (how many items they ordered)	
		// Only displays customer's orders that haven't been cooked by the chef
		for (j = 0; j < orderType[i]; j++){
			if (orderStatus[i] != 0 && isCookedStatus[i][j] == 0){ 
				printf("No. %d - ", orders[i][j]);
				convertFoodID(orders[i][j]);
				printf(" ");
				if (j == orderType[i] - 1){
					printf("\n");
				}
			}
		}
	}
}

/*
	Function for the 'Send Orders to Chef' option.
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param *pisSent is the pointer to the isSent variable in main which determines if the manager has sent order data already or not
	@param currentCustomer is the variable that determines which customer is currently being served
	@param chefData[][3] is the 2D array where the chef's copy of the orders data is stored
	@param orders[][3] is the 2D array where cutomers' orders ID data is kept
	@param isCookedStatus[][3] is the 2D array where the statuses of if a certain ordered dish has already been cooked or not is kept
	@return void
*/
void managerSendOrder(int* pisSent, int *pCurrentCustomer, int orders[][3], int isPackedStatus[][3], int managerPackedStatus[][3], int *pisReceived){
	
	int i, j;
	int hasPending = 0;
	
	// Looks through the isPackedData array to see if there is a 0, if true then hasPending will be set to 1
	for(i = 0; i < 10; i++){
		for(j = 0; j < 3; j++){
			if (isPackedStatus[i][j] == 0){
				hasPending = 1;		
			}			
		}
	}
	
	if (*pCurrentCustomer <= 0){
		printf("There are no pending customers yet!");
	}
	else if (hasPending == 0){
		printf("No new customers have paid yet!");
	}
	else if (*pisSent == 1){
		printf("Previous sent orders have not been received yet.");
	}			
	else{
		printf("Sending current saved order info to chef...\n");
		
		displaySendingProgress();
		
		// isPackedStatus is copied to managerPackedStatus (updates the list of pending orders)
		for(i = 0; i < 10; i++){
			for(j = 0; j < 3; j++){
				managerPackedStatus[i][j] = isPackedStatus[i][j];
			}
		}
		
		// isSent (by manager) is set to 1 (true)
		*pisSent = 1;
		// isReceived (by chef) is set to 0 (false)
		*pisReceived = 0;
		
		printf("Done!");
	}
	
}

/*
	Function for the 'Close Restaurant Option'
	Precondition: isClosed is either 0 or 1
	@param *pisClosed is the pointer to the isClosed variable which determines if the restaurant is closed or not
*/
void managerCloseRestaurant(int* pisClosed){
	
	if (*pisClosed == 0){
		printf("The restaurant has been closed.\n");
		*pisClosed = 1;
	}
	else{
		printf("The restaurant is already closed.\n");
	}
	
}
/* 	
	This function displays and processes the options of the 'manager' selection. 
	It serves as the 'main' function of the manager menu.
	Precondition: All variables and arrays have values which were defined in the main function
	@param *pisClosed is the pointer to the isClosed variable that determines if the restaurant is closed already or not
	@param orders[][3] is the 2D array where cutomers' orders ID data is kept
	@param chefData[][3] is the 2D array where the chef's copy of the orders data is stored
	@param customerNames is the 2D array where customer's names are stored
	@param isPackedStatus[][3] is the 2D array where the statuses of if a certain ordered dish has already been packed or not is kept
	@param isDeliveredStatus[] is the array where the status of if a certain customer's orders has already been delivered or not is kept
	@param orderStatus[] is the array where each customer's order status values are stored
	@param *fProfits is the pointer to the address of the fProfits variable in main
	@param isPaid[] is the array where the statuses of if the customer has paid already or not is kept
	@param fCustomersTotal[] is the array where the total costs of the customers' orders are stored
	@param currentCustomer is the variable that determines which customer is currently being served
	@param *pisSent is the pointer to the isSent variable in main which determines if the manager has sent order data already or not
	@param orderType[] is the array where all customers' order types are stored
	@param isCookedStatus[][3] is the 2D array where the statuses of if a certain ordered dish has already been cooked or not is kept
	@param managerPackeddStatus[][3] is the 2D array where the manager's 'is Packed' data is kept
	@param totalServed is the number of total dishes served
	@return void
*/
void managerActions(
int *pisClosed, int orders[][3], char customerNames[][20], int isPackedStatus[][3], int isDeliveredStatus[], 
int orderStatus[], float fProfits, int isPaid[], float fCustomersTotal[], int *pCurrentCustomer, int *pisSent, int orderType[], 
int isCookedStatus[][3], int managerPackedStatus[][3], int totalServed, int *pisReceived, int *pTotalDelivered){ 
	
	char cSelection;
	
	while(cSelection != '9'){
		
		// printf("Test Statement: Value is %d", nClosed);
		
		printf("\n");
		printf("\n");
		printf("Welcome Manager! What would you like to do?");
		printf("\n");
		printf("%s\n", "--------------------");
		printf("> [1] Display Menu for the Day\n");
		printf("> [2] Send Order to Chef\n");
		printf("> [3] List Pending Order\n");
		printf("> [4] List Current Customers and Ordered Food\n");
		printf("> [5] Send Driver\n");
		printf("> [6] Display Income for the Day\n");
		printf("> [7] Display the Dishes Served for the Day\n");
		printf("> [8] Close the restaurant\n");
		printf("> [9] Exit\n");
		
		printf("\nEnter your selection\n >> ");
		scanf(" %c", &cSelection);
		
		switch(cSelection){
			
			case '1': // The 'Display Menu' option
			
				printf("Menu for the Day\n");
				displayMenu();
				break;
				
			case '2': // Sends current saved order data (in orders[][] array) to the chef's orders array (chefData[][])
				
				managerSendOrder(pisSent, pCurrentCustomer, orders, isPackedStatus, managerPackedStatus, pisReceived);
				break;
				
			case '3': // Shows all pending orders
			
				managerListPending(orderStatus, managerPackedStatus, orders, orderType, customerNames);			
				break;
			
			case '4': // Shows all customer's data that haven't been packed
				
				managerListCustomers(orderStatus, customerNames, isPackedStatus, orders, orderType, isPaid);
				break;
				
			case '5': // Delivers a customer's orders, given customer number.
				
				if (*pisClosed == 0){
					managerSendDriver(isPackedStatus, isDeliveredStatus, orderStatus, pCurrentCustomer, pTotalDelivered);
				}
				else{
					printf("Restaurant is currently closed.");
				}
				break;
				
			case '6': // Displays total income, number of paid customers, and total amount paid by each
				
				managerDisplayIncome(fProfits, isPaid, customerNames, fCustomersTotal);
				break;
			
			case '7': // Displays all dishes that have been served (delivered) with their code and price.
				
				managerDisplayServed(isDeliveredStatus, customerNames, orders, totalServed, orderType);	
				break;
			
			case '8': // Closes the restaurent (sets nClosed from 0 to 1)
			
				managerCloseRestaurant(pisClosed);
				break;
			
			case '9':
				break;
				
			default: // If the input is not within the given parameters, 'invalid input' will be displayed and the main menu will be shown again.
				printf("\nInvalid input. Please select a valid option.\n"); 
				break;
		}
	}
}
