/*************************************************************************** 
This is to certify that this project is my own work, based on my personal efforts in studying and 
applying the concepts learned. I have constructed the functions and their respective algorithms 
and corresponding code by myself. The program was run, tested, and debugged by my own 
efforts. I further certify that I have not copied in part or whole or otherwise plagiarized the 
work of other students and/or persons.
 								Bon Windel E. Aquino, DLSU ID# 12305979 
***************************************************************************/

/******************************************
File Name: MP_GetInputs.C

Author: Bon Windel E. Aquino
Last Update: November 27, 2023

Routines to get the user input for Quantity,
neckLine, and Shirt size 

The entry point to these routines is the 
getQtyNeckSize() routine at the bottom 
of this file. It is called in the main function found in MP_Main.c
******************************************/

#include <stdio.h>
#define ARR_PRICECHECKER printf("arr_addOnsPrice[0] is %.2f\narr_addOnsPrice[1] is %.2f\narr_addOnsPrice[2] is %.2f\narr_addOnsPrice[3] is %.2f\narr_addOnsPrice[4] is %.2f\narr_addOnsPrice[4] is %.2f\narr_addOnsPrice[5] is %.2f\n",arr_addOnsPrice[0],arr_addOnsPrice[1],arr_addOnsPrice[2],arr_addOnsPrice[3],arr_addOnsPrice[4],arr_addOnsPrice[5]);

/*  This function prints spaces until total space occupied is 45.
	Precondition: Parameter is of correct data type
	@param occupiedSpace is used to determine how much space left to print until total occupied is 45 spaces.
	@return Outputs/results to multiple printed spaces
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by functions printShirtDetails, printAddOnDetails, grandTotalCalc
void 
printSpacesBeforeP(int occupiedSpace)
{
	int spaceToOccupy = 45;

	for(;occupiedSpace<spaceToOccupy;occupiedSpace++)
	{
		printf(" ");
	}
}

/*  This function is used to determine a numbers' digit count. 
	This function is necessary to determine the number of spaces occupied by qty
	Precondition: Parameter is of correct data type.
	@param number is the number where digitCount is going to be extracted from
	@return Outputs/results to the number of digits present in a number
			Expected return value is an integer. 
*/
//This function is called 6 times in printShirtDetails
int
digitCount(int number)
{
	int digits=0;
	
	do 
	{
	    number /= 10;
	    digits++;
	} while (number != 0);
	
	return digits;
}

/*  This function calculates the basePrice of a shirt - one without any add ons.
	Precondition: Parameters are of correct data type.
	@param size is used, especially if size is x, to determine if the price will be increased
	@param qty is used as basis for the shirts price per piece.
	@return Outputs/results to the shirts' base price without any add-ons
			Expected return value is a float.
*/
//This function is called in functions perUnitCalc and orderSummary.
float 
basePrice(char size, int qty)
{
	float basePrice = 1;
	
	if(size=='X')
	{
		basePrice = 1.1;
	}
	
	switch(qty)
	{
		case 5 ... 299:
			basePrice*=100;
			break;
		case 300 ... 500:
			basePrice*=80;
			break;
		default:
			basePrice*=75;
			break;
	}
	
	return basePrice;
}

/*  This function, based on a given size, prints a string and adds on to the space occupied
	Precondition: Parameters are of correct data type
	@param size is used to determine the string to print and the space occupied.
	@param *occupiedSpace is used to add the spaces it used unto the variable occupiedSpace found in function printShirtDetails
	@return Outputs/results to printed string and variable occupiedSpace being incremented accordingly
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function printShirtDetails
void 
printSize(char size, int * occupiedSpace)
{
	switch(size)
	{
		case 'S':
			printf("Small ");
			*occupiedSpace+=6;
			break;
		case 'M':
			printf("Medium ");
			*occupiedSpace+=7;
			break;
		case 'L':
			printf("Large ");
			*occupiedSpace+=6;
			break;
		case 'X':
			printf("Extra Large ");
			*occupiedSpace+=12;
			break;
		default:
			break;
	}
}

/*  This function prints corresponding string according to neckLine and adds on to the space occupied
	Precondition: Parameters are of correct data type.
	@param neckLine is used as basis to print corresponding string and the number of space it will occupy
	@param *occupiedSpace is used to add unto the the variable occupiedSpace in function printShirtDetails
	@return Outputs/results to printed string and modified incremented occupiedSpace
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is used in and called by function printShirtDetails
void 
printNeck(char neckLine, int * occupiedSpace)
{
	switch(neckLine)
	{
		case 'V':
			printf("V-neck ");
			*occupiedSpace+=7;
			break;
		case 'R':
			printf("Round-neck ");
			*occupiedSpace+=11;
			break;
		default:
			break;
	}
}

/*  This function prints shirt details or qty, size, neckline, and basePrice
	Precondition: Parameters are of correct data type
	@param size is passed as a parameter to printSize function. prints size in full.
	@param neckLine is passed as a parameter to printNeck function. prints neck in full.
	@param qty is displayed when printing the first line.
	@param baseShirtPrice is also displayed and rounded off to 2 decimal places.
	@return Outputs/results to shown shirtDetails
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function orderSummary
void 
printShirtDetails(char size, char neckLine, int qty, float baseShirtPrice)
{	
	int occupiedSpace=0;
	
	//prints qty/pieces and updates occupiedSpace accordingly
	printf("%d pcs of ",qty);
	occupiedSpace+=digitCount(qty)+8;
		
	//calls functions and prints size and neck in full
	printSize(size, &occupiedSpace);
	printNeck(neckLine, &occupiedSpace);
	
	//print string and update occupied space accordingly 
	printf("shirt with");
	occupiedSpace+=10;
	
	//prints the spaces before P and thereafter prints base price
	printSpacesBeforeP(occupiedSpace);
	printf("P %10.2f @\n", baseShirtPrice);		
}

/*  This function handles and computes for the logo price depending on quantity and number of colors
	Precondition: Parameters are of correct data type
	@param arr_logoColors[] is used to determine the base logo cost as it depends on the qty of colors
	@param arr_addOnsPrice[] is used to store the logo's cost/price
	@param *logoSum is used to access variable logoSum and increment it accordingly.
	@param counter is used as index to manipulate array arr_logoColors
	@param qty is used to set addOnMultiplier or the discounter for logos
	@return Outputs/results to arr_addOnsPrice and *logosum being updated accordingly
	Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by functions 
void
handleLogoPrice(int arr_logoColors[], float arr_addOnsPrice[], float * logoSum, int counter, int qty)
{
	float logoCost = 0;
	float logoMultiplier = 1;
	
	//SetlogoMultiplier or discounter for logos
	if(qty>500)
	{
		logoMultiplier = 0.75;
	}
	else if(qty>=300)
	{
		logoMultiplier = 0.9;
	}
	
	//Check for number of colors in a logo
	if(arr_logoColors[counter]==1)
	{
		logoCost = 18;
	}
	else if(arr_logoColors[counter]==2)
	{
		logoCost = 20;
	}
	else if(arr_logoColors[counter]>=3&&arr_logoColors[counter]<=5)
	{
		logoCost = 25;
	}
	
	//calculate for logoCost by applying discounter
	logoCost*=logoMultiplier;
	
	//use final logo cost and store in arr_addOnsPrice
	arr_addOnsPrice[counter] = logoCost;
	
	//add logoCost to variable logoSum
	*logoSum+=logoCost;
}

/*  This function handles overall addOnsPrice
	Precondition: Parameters are of correct data type.
	@param arr_addOn[] is used to determine specific add-on type
	@param arr_logoColors[] is used to store and access number of logo colors
	@param arr_addOnsPrice[] is used to store the price of each add on
	@param qty is passed as a parameter to handleLogoPrice
	@return Outputs/results to arr_addOnsPrice being updated and returns addOnsTotalPrice
			Expected return value is a float. 
*/
//This function is used in and called by function perUnitCalc
float 
addOnsPrice(char arr_addOn[], int arr_logoColors[], float arr_addOnsPrice[], int qty)
{
	float logoSum=0, addOnsTotalPrice=0;
	int patchSum=0, pocketSum=0, counter;
	
	//cycle through array and modify addOnsPrice and variables according to corresponding character.
	for (counter = 0; counter < 6; counter++)
	{
		switch (arr_addOn[counter])
		{
		case 'L':
			handleLogoPrice(arr_logoColors, arr_addOnsPrice, &logoSum, counter, qty);
			break;
		case 'P':
			arr_addOnsPrice[counter] = 15;
			patchSum+=15;
			break;
		case 'O':
			arr_addOnsPrice[counter] = 5;
			pocketSum+=5;
			break;
		default:
			break;
		}
	}
	
	addOnsTotalPrice = logoSum + patchSum + pocketSum;
	return addOnsTotalPrice;
}

/*  This function calculates how much each unit costs by calling specified functions
	Precondition: Parameter are of correct data type
	@param arr_addOn[] is passed as a parameter to addOnsPrice function call
	@param arr_logoColors[] is passed as a parameter to addOnsPrice function call
	@param arr_addOnsPrice[] is passed as a parameter to addOnsPrice function call
	@param size is passed as a parameter to basePrice function call
	@param qty is passed to basePrice and addOnsPrice function calls
	@param *price is used to assign a value to variable price found in function order Summary
	@return Outputs/results to multiple printed spaces
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function orderSummary
void 
perUnitCalc(char arr_addOn[], int arr_logoColors[], float arr_addOnsPrice[], char size,  int qty, float * price)
{
	*price = basePrice(size,qty) + addOnsPrice(arr_addOn, arr_logoColors, arr_addOnsPrice, qty);
}

/*  This function prints corresponding addOnType and increments occupiedSpace accordingly
	Precondition: Parameters are of correct data type
	@param addOnType is used as basis to print a string and occupiedSpace increment accordingly
	@param *occupiedSpace is used to increment variable occupiedSpace found in function printAddOnDetails
	@return Outputs/results to printed string and an incremented variable occupiedSpace
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function printAddOnDetails
void 
addOnTypePrinter(char addOnType, int * occupiedSpace)
{
	switch(addOnType)
	{
		case 'L':
			printf("   Logo");
			*occupiedSpace+= 7;
			break;
		case 'P':
			printf("   Patch");
			*occupiedSpace+= 8;
			break;
		case 'O':
			printf("   Pocket");
			*occupiedSpace+= 9;
			break;
		default:
			break;
	}
}

/*  This function prints a string and increments occupiedSpace according to truePos
	Precondition: Parameters are of correct data type
	@param truePos is used to determine space to print and how much to increment in occupiedSpace
	@param *occupiedSpace is used to increment variable occupiedSpace found in printAddOnDetails
	@return Outputs/results to printed string and an incremented occupiedSpace
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function printAddOnDetails
void printTruePosition(int truePos, int * occupiedSpace)
{
	switch(truePos)
	{
		case 1:
			printf("left chest");
			*occupiedSpace+= 10;
			break;
		case 2:
			printf("right chest");
			*occupiedSpace+= 11;
			break;
		case 3:
			printf("left sleeve");
			*occupiedSpace+= 11;
			break;
		case 4:
			printf("right sleeve");
			*occupiedSpace+= 12;
			break;
		case 5:
			printf("bottom left of shirt");
			*occupiedSpace+= 20;
			break;
		case 6:
			printf("bottom right of shirt");
			*occupiedSpace+= 21;
			break;
		default:
			break;
	}
}

/*  This function prints string(s) and increments occupiedSpace accordingly
	Precondition: Parameters are of correct data type
	@param colorQty is the number of color(s) a logo is composed of
	@param *occupiedSpace is used to increment variable occupiedSpace found in printAddOnDetails 
	@return Outputs/results to printed string(s) and an incremented variable occupiedSpace
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by printAddOnDetails 
void
printColorCount(int colorQty, int * occupiedSpace)
{
	if(colorQty>0)
	{
		printf(", %d color",colorQty);
		*occupiedSpace+=9;
		// if plural, add s and increment occupiedSpace by 1
		if(colorQty>1)
		{
			printf("s");
			*occupiedSpace+=1;
		}
	}
}

/*  This function prints details regarding add-on details thru string prints and function calls 
	Precondition: Parameters are of correct data type
	@param arr_addOn[] is passed as a parameter to function addOnTypePrinter
	@param arr_addOnPos[] is passed as a parameter to function printTruePosition
	@param arr_logoColors[] is passed as a parameter to function printColorCount
	@param arr_addOnsPrice[] is used to access and display corresponding price of each add-on
	@return Outputs/results to addOnDetails being printed
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by functions 
void
printAddOnDetails(char arr_addOn[], int arr_addOnPos[], int arr_logoColors[], float arr_addOnsPrice[])
{
	int counter, spaceOccupied;
	for (counter=0;counter<6;counter++)
	{
		spaceOccupied = 0;
		if(arr_addOn[counter]!=' ')
		{
			addOnTypePrinter(arr_addOn[counter], &spaceOccupied);
			printf(" on ");
			spaceOccupied+=4;
			printTruePosition(arr_addOnPos[counter], &spaceOccupied);
			printColorCount(arr_logoColors[counter], &spaceOccupied);
			printSpacesBeforeP(spaceOccupied);
			printf("P %10.2f @\n", arr_addOnsPrice[counter]);
		}
	}
}

/*  This function calculates for the bill amount due or the grand total.
	Precondition: Parameters are of correct data type
	@param *price is displayed then used to access and modify variable price in main
	@param qty is displayed then used and multiplied with perUnitPrice to obtain total due.
	@return Outputs/results to printed strings and the grand total or amount due.
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function orderSummary
void
grandTotalCalc(float * price, int qty)
{	
	printf("----------------------------------------------------------------------\n");
	//printfull 45 spaces and then print P followed by price rounded to 2 decimal places and the quantity.
	printSpacesBeforeP(0);
	printf("P %10.2f @  x  %d\n",*price, qty);
	
	//update the price and obtain grand total by multiplying perUnitPrice with quantity. Finally, display the grand total.
	*price = *price*qty;
	printf("                    Total Bill for Order:    P %10.2f\n",*price);
}

/*  This function deals and completes order summary through function calls
	Precondition: Parameters are of correct data type
	@param arr_addOn[] is passed as a parameter to functions perUnitCalc, and printAddOnDetails
	@param arr_addOnPos[] is passed as a parameter to function printAddOnDetails
	@param arr_logoColors[] is passed as a parameter to functions perUnitCalc, and printAddOnDetails
	@param arr_addOnsPrice[] is passed as a parameter to functions perUnitCalc, and printAddOnDetails
	@param size is passed as a parameter to functions basePrice, perUnitCalc, and printShirtDetails
	@param neckLine is passed as a parameter to function printShirtDetails
	@param qty is passed as a parameter to functions basePrice, perUnitCalc, printShirtDetails, and grandTotalCalc
	@param *price is passed as a parameter to functions basePrice, perUnitCalc, and grandTotalCalc
	@return Outputs/results to complete order summary
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used and called in main 
void 
orderSummary(char arr_addOn[], int arr_addOnPos[], int arr_logoColors[], float arr_addOnsPrice[], char size, char neckLine, int qty, float * price)
{
	//stand-alone/self-explanatory function calls
	float baseShirtPrice = basePrice(size, qty);
	perUnitCalc(arr_addOn, arr_logoColors, arr_addOnsPrice, size,  qty, price);
	
	printf("\nOrder Summary:\n");
	printShirtDetails(size, neckLine, qty, baseShirtPrice);
	printAddOnDetails(arr_addOn, arr_addOnPos, arr_logoColors, arr_addOnsPrice);
	grandTotalCalc(price, qty);
	
}

/*  This function handles changeBreakdown
	Precondition: Parameters are of correct data type
	@param price is the price that will be used with amountGiven to calculate for change.
	@return Outputs/results in the changeBreakdown being displayed
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by main
void
changeBreakdown(float price)
{
	//arrays and variable declaration
	float arr_Denomination[14] = {1000, 500, 200, 100, 50, 20, 10, 5, 1, 0.5, 0.25, 0.10, 0.05, 0.01};
	float change, amountGiven, actualDenomination;
	int counter = 0,
	denominationCount = 0;
	
	//User input. repeat until valid.
	printf("\nAmount paid by customer: ");
	scanf("%f",&amountGiven);
	while(amountGiven<price)
	{
		printf("\nInvalid.\nEnter valid amount paid by customer (must be higher than total cost %f): ",price);
		scanf("%f",&amountGiven);
	}
	
	//calculate for change given amountGiven and price
	change = amountGiven-price;
	
	//print change and prepare for change denomination breakdown
	printf("Total change: P %.2f\nBreakdown of change:\n", change);
	while (change>0)
	{
		//cycle through array to assign values to these variables
		actualDenomination = arr_Denomination[counter];
		denominationCount = change/actualDenomination;
		
		//if divisible and remaining change is greater than 1, print denomination as a whole number
		if(denominationCount>=1&&change>=1)
		{
			printf("  Php %4.f - %d\n", actualDenomination, denominationCount);
		}
		
		//if divisible and remaining change is less than 0, denomination printed is rounded to 2 decimal places
		else if(denominationCount>=1&&change<1)
		{
			printf("  Php %4.2f - %d\n", actualDenomination, denominationCount);
		}
		
		//update remaining change and add increment counter by 1 to keep cycling through array
		change-=actualDenomination*denominationCount;
		counter++;
	}
	printf("\n");
}


