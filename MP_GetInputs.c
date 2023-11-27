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

/*  This function takes user input for shirt quantity and assigns it to the variable qty found in main.
	Precondition: User's input is an integer.
	@param *qty is an integer pointer used to access variable quantity in main.
	@return Outputs/results to (a) printed string(s) and a taken user input used to modify variable qty in main.
			Invalid/No expected return value. Function (caller) data type is void. 
*/
void 
getQuantity (int * qty) //This 'child' function is used in and called by 'parent' function getQtyNeckSize.
{
	//User prompt. Take input and assign to variable in main.
	printf("Enter the number of shirts you want to order (5pcs minimum): ");
	scanf("%d",qty);
	
	/*Check if minimum of 5 is met. If condition is not met, prompt again. 
	Repeat until minimum of 5 is met.*/
	while (*qty<5)
	{
		printf("\nToo low. The minimum order that can be accepted is 5.\nEnter valid quantity: ");
		scanf("%d",qty);
	}
}

/*  This function takes user input for shirts' neckline and assigns it to the variable neckLine found in main.
	Precondition: User's input is a character.
	@param *neckLine is a character pointer used to access the variable neckLine in main.
	@return Outputs/results to (a) printed strings and a taken user input to modify variable neckLine in main.
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This 'child' function is used in and called by 'parent' function getQtyNeckSize.
void 
getNeckLine (char * neckLine) 
{
	//User prompt. Take input and assign to variable in main.
	printf("\nEnter the shirts' neckLine. V-neck or Round neck (V/R): ");
	scanf(" %c",neckLine);
	
	//Check if input is a valid selected option. If invalid, ask for input until selected option is valid.
	while (*neckLine!='v'&&*neckLine!='V'&&*neckLine!='R'&&*neckLine!='r')
	{
		printf("\nInvalid.\nValid ptions are: V/v/r/R. Enter a valid neckLine: ");
		scanf(" %c",neckLine);		
	}
	
	/*To lessen uppercase and lowercase converters/checkers,
	neckline assignment directly deals and converts input neckline to uppercase.*/ 
	switch (*neckLine)
	{
		case 'v':
			*neckLine = 'V';
			break;
		case 'r':
			*neckLine = 'R';
			break;
		default:
			break;
	}
}

/*  This function takes user input for shirts' size and assigns it to the variable size found in main.
	Precondition: User's input is a character.
	@param *size is a character pointer used to access the variable size in main.
	@return Outputs/results to (a) printed string(s) and a taken user input used to modify variable size in main. 
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This 'child' function is used in and called by 'parent' function getQtyNeckSize.
void 
getSize (char * size) 
{
	//User prompt. Take input and assign to variable in main.
	printf("\nEnter the the shirts' size. S(small), M(medium), L(large), or X(extra large): ");
	scanf(" %c",size);
	
	//Check if input is valid. If invalid, ask for new size input until user input corresponds to a valid size.
	while (*size!='s'&&*size!='S'&&*size!='M'&&*size!='m'&&*size!='l'&&*size!='L'&&*size!='X'&&*size!='x')
	{
		printf("\nInvalid.\nValid options are: s/S/M/m/l/L/X/x\nEnter a valid size: ");
		scanf(" %c",size);
	}
	
	/*To lessen uppercase and lowercase converters/checkers, 
	  size assignment directly deals and converts input size to uppercase.*/ 
	switch (*size)
	{
		case 's':
			*size = 'S';
			break;
		case 'm':
			*size = 'M';
			break;
		case 'l':
			*size = 'L';
			break;
		case 'x':
			*size = 'X';
			break;
		default:
			break;
	}
}

/*  This function calls 'child' functions to modularize and compartmentalize the project.
	Precondition: Parameters *qty, *neckLine, and *size are the correct data type and can indeed access said variables in main.
	@param *qty, *neckLine, and *size are respectively integer, character, and character pointers used to access the variables qty, neckLine, and size in main.
	@return Outputs/results to a printed string and functions being called. 
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is called in main.
void
getQtyNeckSize (int * qty, char * neckLine, char * size) 
{
	/*prints a description to notify user and 
	get user to expect series of inputs.*/
	printf("\n\nOrder Form\n"); 
	
	//call 'child' functions.
	getQuantity(qty);
	getNeckLine(neckLine);
	getSize(size);
}
