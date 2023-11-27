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

/*  This function prints a given symbol for charCount number of times
	Precondition: Parameter is of correct data type
	@param symbol is the character that will be processed/printed repeatedly.
	@param charCount is the count or number of times the symbol will be printed.
	@return Outputs/results to multiple character prints.
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by functions 
void
charPrinter(char symbol, int charCount)
{
	int ctr;
	for(ctr=0;ctr<charCount;ctr++)
	{
		printf("%c",symbol);
	}
}

/*  This function sets a sizeMultiplier, based on given size.
	this will be used for further formulas.
	Precondition: Parameters are of correct data type.
	@param size is the basis for the sizeMultiplier
	@return Outputs/results depends on size. A value corresponding to a size is returned. 
			Expected return value is an integer. 
*/
//This function is used in and called by function printShirt
int
sizeConverter(char size)
{
	int sizeMultiplier;
	switch(size)
	{
		case 'S':
			sizeMultiplier=1;
			break;
		case 'M':
			sizeMultiplier=2;
			break;
		case 'L':
			sizeMultiplier=3;
			break;
		case 'X':
			sizeMultiplier=4;
			break;
		default:
			break;
	}
	return sizeMultiplier;
}

/*  This function places corresponding add-on to shirt by printing or embedding it to shirt.
	Precondition: Parameter is of correct data type
	@param arr_addOn[] is used to access the specific add-ons
	@param arr_addOnPos[] is used to access the add-ons' placement positions
	@param truePos is the parameter to check if value array equals it.
	@return Outputs/results to a corresponding character embedded into the shirt
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called four times by function printSleeve and twice by function printBody
void
addOnPlacer(char arr_addOn[], int arr_addOnPos[], int truePos)
{
	int addOnCtr;
	for(addOnCtr=0;addOnCtr<=6;addOnCtr++)
	{
		//if value in array equals intended position, print the character and break out of loop.
		if(arr_addOnPos[addOnCtr]==truePos)
		{	
			printf("%c",arr_addOn[addOnCtr]);
			addOnCtr=7;
		}
	}
}

/*  This function prints the topmost structure of the shirt
	Precondition: Parameter is of correct data type
	@param xCount is the count of the Xs in the top structure of the shirt
	@return Outputs/results to spaces and character xs being printed.
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by functions 
void
printTop(int xCount)
{
	charPrinter(' ',3);
	charPrinter('x',xCount);
	charPrinter(' ',4);
	charPrinter('x',xCount); 
	charPrinter(' ',3);
}

/*  This function handles neckLine and prints corresponding neckLine 
	Precondition: Parameter is of correct data type
	@param sleeveLineNumber is the line number of the sleeve calling this function
	@param neckLine is the type of neckline and is basis for pattern
	@return Outputs/results to neckLine being printed
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function printSleeve
void 
dealWithCollarNeckLine(int sleeveLineNumber, char neckLine)
{
	switch(sleeveLineNumber)
	{
		//this is when sleeve line number 1 is the caller
		case 1:
			//decide pattern and print based on neckLine type
			if(neckLine=='V')
			{
				printf("x  x");
			}
			else if(neckLine=='R')
			{
				charPrinter('x', 4);
			}
			break;
		
		//on the other hand, this is when sleeve line 2 is the caller
		case 2:
			//decide pattern and print based on neckLine type
			if(neckLine=='V')
			{
				charPrinter('x', 2);
			}
			else if(neckLine=='R')
			{
				charPrinter(' ', 2);
			}
			break;
		default:
			break;
	}
}

/*  This function handles the printing of the sleeves and the corresponding add-ons
	Precondition: Parameter is of correct data type
	@param xCount is the number of xs the used by printTop. used to print spaces. 
	@param neckLine is passed as a parameter in function dealWithCollarNeckLine
	@param arr_addOn[] is passed as parameter to function addOnPlacer
	@param arr_addOnPos[] is passed as a parameter to function addOnPlacer
	@return Outputs/results to sleeves, collar, and corresponding addons being printed
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function printShirt
void
printSleeve(int xCount, char neckLine, char arr_addOn[], int arr_addOnPos[])
{
	//first line sleeve
		printf("\n  x");
		charPrinter(' ',xCount);
		dealWithCollarNeckLine(1, neckLine); 
		charPrinter(' ',xCount);
		printf("x  \n");
	
	//second line sleeve
	printf(" x ");
	addOnPlacer(arr_addOn, arr_addOnPos, 4);
	charPrinter(' ',xCount);
	dealWithCollarNeckLine(2, neckLine);
	charPrinter(' ',xCount);
	addOnPlacer(arr_addOn, arr_addOnPos, 3);
	printf(" x \n");
	
	//third line sleeve
	charPrinter('x',4);
	printf(" ");
	addOnPlacer(arr_addOn, arr_addOnPos, 2);
	charPrinter(' ',xCount*2-2);
	addOnPlacer(arr_addOn, arr_addOnPos, 1);
	printf(" ");
	charPrinter('x',4);
	printf("\n");
}

void
printBody(int convertedSize, char arr_addOn[], int arr_addOnPos[])
{
	int lineNumber, bodyHeight = convertedSize*2+3;
	for(lineNumber=0;lineNumber<bodyHeight;lineNumber++)
	{
		printf("   x");
		if(lineNumber!=bodyHeight-1)
		{
			charPrinter(' ',convertedSize*4+6);
			printf("x\n");
		}
		
		else
		{
			printf(" ");
			addOnPlacer(arr_addOn, arr_addOnPos, 6);
			charPrinter(' ',convertedSize*4+2);
			addOnPlacer(arr_addOn, arr_addOnPos, 5);
			printf(" x\n");
		}
	}
}

/*  This function prints the bottom part of the shirt
	Precondition: Parameter is of correct data type
	@param xCount is used to adapt to the scale of the top structure printed/
	@return Outputs/results to the bottom part of the shirt being printed
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by function printShirt
void
printBottom(int xCount)
{
	printf("   ");
	charPrinter('x',xCount*2+4);
}

/*  This function completes the ASCII mock shirt printing by calling all the functions
	tasked with dealing their modularized parts.
	Precondition: Parameter is of correct data type
	@param size is passed as a parameter to function sizeConverter
	@param neckLine is passed as a parameter to function printSleeve
	@param arr_addOn[] is used as a parameter to functions printSleeve and printBody
	@param arr_addOnPos[] is used as a parameter to functions printSleeve and printBody
	@return Outputs/results to
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is used in and called by functions 
void
printShirt(char size, char neckLine, char arr_addOn[], int arr_addOnPos[])
{
	int convertedSize, xCount;
	convertedSize = sizeConverter(size); //formula for bodyHeight
	xCount = convertedSize*2+2; //this is the formula for xCount based on size
	
	printf("Mock Shirt: \n");
	printTop(xCount);
	printSleeve(xCount, neckLine, arr_addOn, arr_addOnPos);
	printBody(convertedSize, arr_addOn, arr_addOnPos);
	printBottom(xCount);
	printf("\n\n");
}
