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

/*  This function calculates for productionTime and daysUntilPickup
	Precondition: Parameter is of correct data type
	@param arr_addOn[] is used to determine the add ons, a factor for how each shirt production duration
	@param qty is multiplied with secondsPerPiece to obtain total productionTime
	@param *productionTime is used to access and store values
			in productionTime variable found in function displayOrderTimeInfo 
	@param int *daysUntilPickUp is used to access and store values 
				in daysUntilPickUp variable found in function displayOrderTimeInfo 
	@return Outputs/results to modified variables productionTime and daysUntilPickUp
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function displayOrderTimeInfo 
void 
dayCalc(char arr_addOn[], int qty, int * productionTime, int * daysUntilPickUp)
{
	int counter, secondsPerPiece;
	char addOnType = ' ';
	for (counter = 0; counter < 6; counter++)
	{
		addOnType = arr_addOn[counter];
		switch (addOnType)
		{
		case 'L':
			secondsPerPiece += 60;
			break;
		case 'P':
			secondsPerPiece += 20;
			break;
		case 'O':
			secondsPerPiece += 30;
			break;
		default:
			break;
		}
	}
	*productionTime = secondsPerPiece * qty;
	*daysUntilPickUp = 2 + (*productionTime / 43200);
}

/*  This function converts time into corresponding hours mins and seconds
	Precondition: Parameter is of correct data type
	@param productionTime is the productionTime being converted to hh:mm:ss
	@param *hours is where corresponding hours will be stored
	@param *mins is where corresponding minutes will be stored
	@param *sec is where corresponding seconds will be stored
	@return Outputs/results to modified hours mins, and sec variables
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by displayOrderTimeInfo function 
void 
convertTime(int productionTime, int * hours, int * mins, int * sec)
{
	*hours = productionTime/3600;
	productionTime-=*hours*3600;
	*mins = productionTime/60;
	productionTime-=*mins*60;
	*sec = productionTime;
}

/*  This function completes the displayOrderTimeInfo by calling functions.
	Precondition: Parameter is of correct data type
	@param qty is passed as parameter to dayCalc function
	@param arr_addOn[] is passed as parameter to dayCalc function
	@return Outputs/results to complete display of orderTimeInfo
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used and called in main 
void
displayOrderTimeInfo(int qty, char arr_addOn[])
{
	//declare and initialize variables
	int	productionTime = 0, 
		daysUntilPickUp = 0, 
		hours = 0, 
		mins = 0, 
		sec = 0;
		
	//function calls
	dayCalc(arr_addOn, qty, &productionTime, &daysUntilPickUp);
	convertTime(productionTime, &hours, &mins, &sec);
	
	//display the production time in hours minutes and seconds and the soonestPickUpDate
	printf("Production Time: %d hours %d minutes %d seconds\n", hours, mins, sec);
	printf("Order can be picked up after %d days\n\n",daysUntilPickUp);
}

/*  This function evaluates if the user wants to confirm their order or not.
	Precondition: Parameters are of correct data type.
	@param Not Applicable (N/A).
	@return Outputs/results to 1 (true) if user saysYes and 0 (false) otherwise. 
			Expected return value is an integer. 
*/
//This function is used and called in main 

int 
confirmOrder()
{
	//variable declaration and initialization
	int saysYes = 0, invalidOption=1;
	char input = ' ';
	
	//infinite loop as long as option is neither y nor n
	while(invalidOption)
	{
		printf("Confirm order? ");
		scanf(" %c",&input);
		switch(input)
		{
			case 'Y':
			case 'y':
				invalidOption=0;
				saysYes = 1;
				break;
			case 'N':
			case 'n':
				invalidOption=0;
				saysYes = 0;
				break;
			default:
				printf("invalid option. Accepted responses are Y/y/n/N.\n");
				break;
		}
	}
	
	//return if true or false.
	return saysYes;
}
