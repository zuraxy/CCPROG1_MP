#include <stdio.h>
#include "MP_GetInputs.c"
#include "MP_AddOn.c"
#include "MP_PriceCalcOrderSummary.c"
#include "MP_ProductionSched.c"
#include "MP_ASCII-Printer.c"
#define MAIN_MENU "Main Menu\n1 - Order\n2 - Show Order Summary for the day\n3 - Start New Day\n4 - Shutdown for Maintenance\n\nEnter Option: "
#define CANCELED "Order not confirmed. Select an option again.\n"
#define DAY_SUMMARY "\nOrder Summary for the day:\nTotal number of shirts ordered: %d\nTotal amount received: P%.2f\n\n", arr_dayShirtsCount[dayCount-1], arr_totalReceived[dayCount-1]
#define END "Program terminating for maintenance..."
#define CHECKER1 printf("arr_addOnType \n[0]: %c \n[1]: %c \n[2]: %c \n[3]: %c \n[4]: %c \n[5]: %c\n\n", arr_addOn[0], arr_addOn[1], arr_addOn[2], arr_addOn[3], arr_addOn[4], arr_addOn[5]);printf("arr_addOnPos\n[0]: %d\n[1]: %d\n[2]: %d\n[3]: %d\n[4]: %d\n[5]: %d\n\n", arr_addOnPos[0], arr_addOnPos[1], arr_addOnPos[2], arr_addOnPos[3], arr_addOnPos[4], arr_addOnPos[5]);printf("arr_logoColors \n[0]: %d\n[1]: %d\n[2]: %d\n[3]: %d\n[4]: %d\n[5]: %d\n\n", arr_logoColors[0], arr_logoColors[1], arr_logoColors[2], arr_logoColors[3], arr_logoColors[4], arr_logoColors[5]);printf("mock small: \n"); printShirt('S', 'V', arr_addOn, arr_addOnPos); printf("\n\n");printf("mock medium: \n"); printShirt('M', 'V', arr_addOn, arr_addOnPos); printf("\n\n");printf("mock large: \n"); printShirt('L', 'V', arr_addOn, arr_addOnPos); printf("\n\n");printf("mock XLarge: \n"); printShirt('X', 'V', arr_addOn, arr_addOnPos); printf("\n\n");printf("mock small: \n"); printShirt('S', 'R', arr_addOn, arr_addOnPos); printf("\n\n");printf("mock medium: \n"); printShirt('M', 'R', arr_addOn, arr_addOnPos); printf("\n\n");printf("mock large: \n"); printShirt('L', 'R', arr_addOn, arr_addOnPos); printf("\n\n"); printf("mock XLarge: \n"); printShirt('X', 'R', arr_addOn, arr_addOnPos); printf("\n\n");

void 
resetArrays(char arr_addOn[], int arr_addOnPos[], int arr_logoColors[], float arr_addOnsPrice[])
{
	int counter;
	for(counter = 0; counter<6; counter++)
	{
		arr_addOn[counter] = ' ';
		arr_addOnPos[counter] = counter+1;
		arr_logoColors[counter] = 0;
		arr_addOnsPrice[counter] = 0;  
	}
}
	
int main()
{
	//variable declarations + initializations. Put which calling function
	int qty = 0,
		option = 0,
		dayCount = 1,
		shouldContinue = 1;
	int arr_dayShirtsCount[999];
	int arr_addOnPos[6] = { 1, 2, 3, 4, 5, 6 }; //reason for pos is to track which ones are first placed or inputted by user instead of non linear array pos use
	int arr_logoColors[6] = { 0, 0, 0, 0, 0, 0 };
	float arr_addOnsPrice[6] = { 0, 0, 0, 0, 0, 0 };
	float arr_totalReceived[999];
	
	char arr_addOn[6] = { ' ',' ',' ',' ',' ',' ' };
	char neckLine = ' ';
	char size = ' ';
	float price = 0;
	arr_dayShirtsCount[0] = 0;
	arr_totalReceived[0] = 0;
	
	while(shouldContinue)
	{
		printf(MAIN_MENU);
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				resetArrays(arr_addOn, arr_addOnPos, arr_logoColors, arr_addOnsPrice);
				getQtyNeckSize(&qty, &neckLine, &size);
				processAddOn(arr_addOn, arr_addOnPos, arr_logoColors);
				orderSummary(arr_addOn, arr_addOnPos, arr_logoColors, arr_addOnsPrice, size, neckLine, qty, &price);
				arr_dayShirtsCount[dayCount-1] += qty; printf(" ");
				arr_totalReceived[dayCount-1] += price;
				printShirt(size, neckLine, arr_addOn, arr_addOnPos);
				//CHECKER1
				displayOrderTimeInfo(qty, arr_addOn);
				if(confirmOrder())
				{	
					changeBreakdown(price);
				}
				else
				{
					printf(CANCELED);
				}
				break;
				
			case 2:
				printf(DAY_SUMMARY);
				break;
			case 3:
				printf("Starting new day...\n\n");
				dayCount++;
				break;
			case 4:
				shouldContinue = 0;
				printf(END);
				break;
		}
	}
	
	return 0;
}
