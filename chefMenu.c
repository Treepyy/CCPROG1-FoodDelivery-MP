/*
	This function displays the loading bar for the 'Cook' option
	@return void
*/
void displayCookingProgressBar(){
	
	int i;
	char a = '-', b = '#';
	
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
	This function displays the loading bar for the 'Recieve Orders' option
	@return void
*/
void displayReceivingProgressBar(){
	
	int i;
	char a = '-', b = '<';
	
	// Initial loading bar
	for (i = 0; i < 10; i++)
		printf("%c", a);

	// Loading bar progress
	for (i = 0; i < 11; i++) {
		printf("%c", b);
		printf("\b");
		printf("\b");
		
		// Loading bar interval time (in ms)
		Sleep(200);
	}
	printf("\n");
	
}

/*
	Function for the 'Recieve Orders' option.
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param *pCurrentCustomer is the pointer to the variable that determines which customer is currently being served
	@param *pisSent is the pointer to the isSent variable in main which determines if the manager has sent order data already or not
	@param *pisReceived is the is the pointer to the adress of the isReceived variable in main which determines if the chef has received orders already
	@return void
	
*/
void receiveOrders(int* pCurrentCustomer, int* pisSent, int* pisReceived){
	
	if (*pCurrentCustomer <= 0){
		printf("There are no pending customers yet!");
	}
				
	else if (*pisSent == 0){
		printf("Manager has not sent new orders yet!");
	}
				
	else if (*pisSent == 1 && *pCurrentCustomer > 0){
		printf("Receiving orders...\n");
		displayReceivingProgressBar();
		
		// Is received is set to 1 and isSent is set to 0, manager can now send new orders
		*pisReceived = 1;
		*pisSent = 0;
					
		printf("Orders received!");
	}
	
}

/*
	Function to cook N amount of dishes
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param N is the value selected at the beginning which determines how many dishes can be cooked at a time
	@param isCookedData[][3] is the 2D array where the statuses of if a certain ordered dish has already been cooked or not is kept
	@return void
*/
void cookNDishes(int N, /*int ordersData[][3],*/ int isCookedData[][3]){
	
	int i, j, k = 0, l = 0;
	int limit = N;
	int totalCooked = 0;
	int isCooked1D[30];
	
	// Conversion of 2D array ([10][3]) to 1D array ([30])
	// Note: Done so that it would be easier to increment values
	for(i = 0; i < 10; i++) { 
		for(j = 0; j < 3; j++){ 
			isCooked1D[k] = isCookedData[i][j]; 
			k++; 
		} 
	} 
	
	// Increment of isCooked values from 0 (not cooked) to 1 (cooked) based on N
	for(i = 0; i < 30; i++){
		
		// If the loop encounters a 0 and the limit (N) has not been reached, it will turn that 0 into a 1 and reduce the limit by 1
		if (isCooked1D[i] == 0 && limit != 0){
			isCooked1D[i] = 1;
			limit--;
			
			// If it enters this conditional, totalCooked value will be increased by 1
			totalCooked++;
		}
		
		// If the loop encounters a 1 (already cooked) it will retain its value
		else if (isCooked1D[i] == 1){
			isCooked1D[i] = 1;
		}
		
		// If the loop encounters a 2 (order DNE) it will retain its value
		else if (isCooked1D[i] != 0 && limit == 0){
			isCooked1D[i] = 2;
		}
			
	}
	
	// Conversion of [30] 1D array back to [10][3] 2D array
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 3; j++) { 
			isCookedData[i][j] = isCooked1D[l]; 
			l++; 
		} 
	}
	
	printf("Done! %d Dishes Cooked.", totalCooked);
	
}

/*
	Function to pack 1 dish at a time
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param isCookedData[][3] is the 2D array where the statuses of if a certain ordered dish has already been cooked or not is kept
	@param isPackedData[][3] is the 2D array where the statuses of if a certain ordered dish has already been packed or not is kep
	@param *pTotalServed is the pointer to the address of the totalServed variable which determines how many dishes have already been served (packed)
	@param *pCurrentCustomer  is the pointer to the adress of the currentCustomer variable, used to update the currentCustomer variable in main
	@return void
*/
void packDishes(int isCookedData[][3], int isPackedData[][3], int* pTotalServed){
	
	int i, j, k = 0, l = 0;
	int limit = 1;
	int isCooked1D[30];
	int isPacked1D[30];
	int totalServed = *pTotalServed;
	
	// Conversion of 2D array ([10][3]) to 1D array ([30])
	// Note: Done so that it would be easier to increment values
	for(i = 0; i < 10; i++) { 
		for(j = 0; j < 3; j++){ 
			isPacked1D[k] = isPackedData[i][j]; 
			k++; 
		} 
	}
	
	k = 0;
	
	for(i = 0; i < 10; i++) { 
		for(j = 0; j < 3; j++){ 
			isCooked1D[k] = isCookedData[i][j]; 
			k++; 
		} 
	}  
	
	// Increment of isPacked values from 0 (not packed) to 1 (packed) if the corresponding isCooked value is 1 (true)
	// The algorithm for incrementation of values within the array is the same as the cookNDishes function, but the limit for packing is always set to 1
	for(i = 0; i < 30; i++){

		if (isCooked1D[i] == 1 && limit != 0 && isPacked1D[i] == 0){
			isPacked1D[i] = 1;
			limit--;
			
			// totalServed dishes is incremented after a dish has been packed
			totalServed++;
			*pTotalServed = totalServed;
		}
			
		else if (isCooked1D[i] == 1 && isPacked1D[i] == 1){
			isPacked1D[i] = 1;		
		}
		
		else if (isPacked1D[i] == 0 && limit == 0){
			isPacked1D[i] = 0;
		}
		
		else if (isPacked1D[i] == 2){
			isPacked1D[i] = 2;
		}

	}
	
	
	// Conversion of [30] 1D array back to [10][3] 2D array
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 3; j++) { 
			isPackedData[i][j] = isPacked1D[l]; 
			l++; 
		} 
	}
	
	printf("Done!");
	
}

/*
	This function serves to execute the 'Cook N Dishes' option
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param isCookedData[][3] is the 2D array where the statuses of if a certain ordered dish has already been cooked or not is kept
	@param N is the value selected at the beginning which determines how many dishes can be cooked at a time
	@param *pisClosed is the pointer to the isClosed variable that determines if the restaurant is closed already or not
	@param *pisReceived is the is the pointer to the adress of the isReceived variable in main which determines if the chef has received orders already
*/
void cookDishesOption(int isCookedData[][3], int N, int* pisClosed, int *pisReceived){
	
	int i, j;
	
	// the hasPending variable determines if there is still a pending order to cook or not
	int hasPending = 0;
	
	if (*pisClosed == 0){
					
		// Looks through the isCookedData array to see if there is still a 0, if true then hasPending will be set to 1
		for(i = 0; i < 10; i++){
			for(j = 0; j < 3; j++){
				if (isCookedData[i][j] == 0){
					hasPending = 1;		
				}
								
			}
		}
					
		if (*pisReceived == 1 && hasPending == 1 && *pisClosed == 0){
			printf("Cooking...\n");
			displayCookingProgressBar();
			cookNDishes(N, isCookedData);
						
			// hasPending is variable reset to 0
			hasPending = 0;
						
		}
		else if (hasPending == 0){
			printf("No pending dishes left!");
		}
		else if (*pisReceived == 0){
			printf("Please receive orders first.");
		}
	}
				
	else{
		printf("Restaurant is currently closed.");
	}
	
}

/*
	This function serves to execute the 'Pack Orders' option
	Precondition: All variables are positive and within their set range of values, 
	all values within arrays are also within their set range of values
	@param isCookedData[][3] is the 2D array where the statuses of if a certain ordered dish has already been cooked or not is kept
	@param isPackedStatus[][3] is the 2D array where the statuses of if a certain ordered dish has already been packed or not is kept
	@param *ptotalServed is the pointer to the adress of the totalServed variable which determines how many dishes have already been served (packed)
	@param *pCurrentCustomer  is the pointer to the adress of the currentCustomer variable, used to update the currentCustomer variable in main
	@param managerPackedStatus[][3] is the 2D array where the manager's 'is Packed' data is kept
	
*/

void packDishesOption(int isCookedData[][3], int isPackedStatus[][3], int* ptotalServed, int managerPackedStatus[][3]){
	
	int i, j;
	int limit = 1;
	
	/* 
		Looks through the entire isCookedData and isPackedStatus arrays to check if 
		there is an order that is already cooked (isCooked = 1) but not packed (isPacked = 0),
		if there is, it enters the if statement within the loop.
	*/
	
	for (i = 0; i < 10; i++){
		for (j = 0; j < 3; j++){
						
		// If limit is not 0, it means the loop has not entered the conditional yet
		if (limit > 0){
			if(isCookedData[i][j] == 1 && isPackedStatus[i][j] == 0){
								
				// packDishes function is called when there is an order that is already cooked (isCooked = 1) but not packed (isPacked = 0)
				packDishes(isCookedData, isPackedStatus, ptotalServed);
									
				// Limit is decremented to denote that it has passed through this conditional once
				limit--;

				printf(" Customer #%d Order #%d has been packed!", i+1, j+1);
				}
			}
		}
	}
				
	if (limit == 1){
		printf("Order is not cooked yet!");
	}
				
	// Limit is reset to 1 for the next iteration
	limit = 1;
				
	// the new isPackedStatus is copied to managerPackedStatus (updates the list of pending orders)
	for(i = 0; i < 10; i++){
		for(j = 0; j < 3; j++){
			managerPackedStatus[i][j] = isPackedStatus[i][j];
		}
	}	
}

/* 	
	This function displays and processes the options of the 'chef' selection. 
	It serves as the 'main' function of the chef menu.
	Precondition: All variables and arrays have values which were defined in the main function
	@param N is the value selected at the beginning which determines how many dishes can be cooked at a time
	@param isCookedData[][3] is the 2D array where the statuses of if a certain ordered dish has already been cooked or not is kept
	@param *pisReceived is the is the pointer to the adress of the isReceived variable in main which determines if the chef has received orders already
	@param isPackedStatus[][3] is the 2D array where the statuses of if a certain ordered dish has already been packed or not is kept
	@param *pCurrentCustomer  is the pointer to the adress of the currentCustomer variable, used to update the currentCustomer variable in main
	@param *pisSent is the pointer to the isSent variable in main which determines if the manager has sent order data already or not
	@param *ptotalServed is the pointer to the adress of the totalServed variable which determines how many dishes have already been served (packed)
	@param *pisClosed is the pointer to the isClosed variable that determines if the restaurant is closed already or not
	@param managerPackedStatus[][3] is the 2D array where the manager's 'is Packed' data is kept
	@return void
	
*/
void chefActions(
int N, int isCookedData[][3], int* pisReceived, int isPackedStatus[][3], int *pCurrentCustomer ,
int* pisSent, int* ptotalServed, int* pisClosed, int managerPackedStatus[][3]){ 
	
	char cSelection;
	
	while(cSelection != '4'){
		
		if (*ptotalServed >= 20){
			*pisClosed = 1;
		}
		
		printf("\n");
		printf("\n");
		printf("Welcome Chef! What would you like to do?");
		printf("\n");
		printf("%s\n", "--------------------");
		printf("> [1] Recieve Order\n");
		printf("> [2] Cook N Dishes\n");
		printf("> [3] Pack Food\n");
		printf("> [4] Exit\n");
		
		printf("\nEnter your selection\n >> ");
		scanf(" %c", &cSelection);
		
		switch(cSelection){
			
			case '1':  // Option to receive all orders data from chef, this option must be chosen first before the user can access the others.
				
				receiveOrders(pCurrentCustomer, pisSent, pisReceived);
				
				break;
				
			case '2': 
				/* This option cooks N dishes from the pending orders. 
					Cooking Priority: Paid > Lower Customer Number > Higher Customer Number
					e.g. :	if customer#1 is not paid, but customer#2 is paid, customer #2 will have their dishes
							cooked before customer#1, but if customer#1 and customer#3 are both paid, customer#1
							will have their dishes cooked before customer#3
				*/ 
				
				cookDishesOption(isCookedData, N, pisClosed, pisReceived);
				
				break;
				
			case '3':
				/* This option packs 1 dish from orders that are already cooked. 
					Packing Priority: Lower Customer Number > Higher Customer Number
					e.g. :	customer#1 will always have their orders packed first over customer#2 provided that
							all their orders are cooked. only cooked dishes are elegible to be packed.

				*/ 
				if (*pisClosed == 0){	
					packDishesOption(isCookedData, isPackedStatus, ptotalServed, managerPackedStatus);
				}
				else{
					printf("Restaurant is currently closed.");
				}
				break;
			
			case '4': // If 'Exit' is chosen, the user is redirected to the Main Menu.
				break;
				
			default: // If the input is not within the given parameters, 'invalid input' will be displayed and the main menu will be shown again.
				printf("\nInvalid input. Please select a valid option.\n"); 
				break;
		}
	}
}
