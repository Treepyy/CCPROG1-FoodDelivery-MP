void displayAllVariables(
int N, int ordersData[][3], int orderType[], char customerNames[][20], int orderStatus[], int isDeliveredStatus[], int isPaidStatus[], 
int isPackedStatus[][3], int managerPackedStatus[][3], int isCookedStatus[][3], float fCustomersTotal[], int currentCustomer,
int totalCustomers, int isSent, int isReceived, int totalServed, float fProfits, int isClosed){
	
	int totalOrders = 0;
	int i, j;
	
	printf("-------------------\nDebugging Menu\n-------------------\n");
	printf("Current N Value: %d\n", N);
	printf("var isClosed is %d\nCurrent customer is %d\nTotal customers is %d\n\n", isClosed, currentCustomer, totalCustomers); 
	printf("Orders Data:\n");
	for(i = 0; i < 10; i++){
		printf("Customer #%d [%d]: ", i+1, i);
		for(j = 0; j < 3; j++){
			printf("%d ", ordersData[i][j]);
		}
		printf("\n");
	}
	printf("\nNames and Status Data:\n");
	for(i = 0; i < 10; i++){
		printf("Name %d = %s\n", i, customerNames[i]);
	}
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("Status %d = %d\n", i, orderStatus[i]);
	} 	
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("isCooked [%d]: ", i);
		for(j = 0; j < 3; j++){
			printf("%d ", isCookedStatus[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("isPacked [%d]: ", i);
		for(j = 0; j < 3; j++){
			printf("%d ", isPackedStatus[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("managerPacked [%d]: ", i);
		for(j = 0; j < 3; j++){
			printf("%d ", managerPackedStatus[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("isDelivered %d = %d\n", i, isDeliveredStatus[i]);
	}
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("isPaid %d = %d\n", i, isPaidStatus[i]);
	}
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("orderType %d = %d\n", i, orderType[i]);
	}
	printf("\n");
	for(i = 0; i < 10; i++){
		totalOrders += orderType[i];
	}
	printf("Total Orders: %d", totalOrders);
	printf("\nTotal Served: %d", totalServed);
	
}
