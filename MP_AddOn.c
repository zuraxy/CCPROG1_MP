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

/*
TO DO:
*******************************************
add maybe 5 attempts or break out of loop option. or detect if no more possible position.

USER CANNOT BE STUCK, NO AVAILABLE FOR P OR L OR O ADD CATCH CASES
ADD ANOTHER ADD ON SHOULD DISPLAY OPTIONS + space per promptinvalid space
*/

#define OPTION_FOR_ALL " placement options:\n1 - left chest\n2 - right chest"
#define OPTION_LOGO_PATCH "\n3 - left sleeve\n4 - right sleeve\n\n"
#define OPTION_POCKET "\n5 - bottom left\n6 - bottom right\n\n"
#define ADDON_SELECTION "\nAdd-on options:\nL - Logo\nP - Patch\nO - pOcket\n"
#define ARRAYS_VISUALIZER printf("\n!@#$%^&*()\ninput accepted.\n addOn is %c\n addOnPos is %d\n addOnsCount is %d\n",arr_addOn[addOnsCount], arr_addOnPos[addOnsCount], addOnsCount); printf("\n!@#$%^&*()\ncurrent array looks like this: \n");	printf("arr_addOn[0] = %c, arr_addOn[1] = %c, arr_addOn[2] = %c, arr_addOn[3] = %c, arr_addOn[4] = %c, arr_addOn[5] = %c\n", arr_addOn[0], arr_addOn[1], arr_addOn[2], arr_addOn[3], arr_addOn[4], arr_addOn[5]); printf("arr_addOnPos[0] = %d, arr_addOnPos[1] = %d, arr_addOnPos[2] = %d, arr_addOnPos[3] = %d, arr_addOnPos[4] = %d, arr_addOnPos[5] = %d\n", arr_addOnPos[0], arr_addOnPos[1], arr_addOnPos[2], arr_addOnPos[3], arr_addOnPos[4], arr_addOnPos[5]);

/*  This function, given a character, prints the corresponding add-on type in full.
	Precondition: Parameter addOn is a character.
	@param addOn is the received character. It is used to specify the add on type in full.
	@return Outputs/results to a printed string. 
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is called in functions showPlacementOptions, addAnother, invalidPlace, and getAddOnPos.
void 
printAddOnType (char addOn)
{
	//prints corresponding string based on addOn.
	switch (addOn)
	{
		case 'L':
			printf("logo");
			break;
		case 'P':
			printf("patch");
			break;
		case 'O':
			printf("pocket");
			break;
		case '+':
			printf("add-on");
			break;
		default:
			//if invalid, print nothing. do nothing.
			break;
	}
}

/*  This function, given a character, prints the corresponding placement options.
	Precondition: Parameter addOn is a character.
	@param addOn is the received character. It is the basis in displaying corresponding placement options.
	@return Outputs/results to printed strings. 
			Invalid/No expected return value. Function (caller) data type is void.
*/
//This function is called in function handleAddOn
void 
showPlacementOptions (char addOn)
{
	//initial placement options. Available to all add-ons.
	printf("\n");
	printAddOnType(addOn);
	printf(OPTION_FOR_ALL);
	
	//displays options EXCLUSIVE to corresponding add-ons.
	switch(addOn)
	{
		case 'L':
		case 'P':
			printf(OPTION_LOGO_PATCH); 
			break;
		case 'O':
			printf(OPTION_POCKET); //OPTIONS EXCLUSIVE TO POCKET
			break;
		default:
			break;
	}
}

/*  This function, given user's choice, evaluates if the choice is invalid.
	Precondition: Parameter choice is a character.
	@param choice is the user's previous input. It is the character being evaluated.
	@return Outputs/results to 1 (true) if choice is invalid and 0 (false) otherwise. 
			Expected return value is an integer. 
*/
//This function is called in function addAnother 
int
choiceIsInvalid (char choice)
{
	int invalid = 1;
	switch(choice)
	{
		case 'Y':
		case 'y':
		case 'N':
		case 'n':
			invalid = 0;
			break;
		default:
			invalid = 1;
			break;
	}
	return invalid;
}

/*  This function, given user's choice, evaluates if the choice is Yes.
	Precondition: Parameter choice is a character.
	@param choice is the user's previous input. It is the character being evaluated.
	@return Outputs/results to 1 (true) if choice is yes and 0 (false) otherwise. 
			Expected return value is an integer. 
*/
//This function is called in function addAnother
int 
choiceIsYes (char choice)
{
	int choiceIsYes = 0;
	switch(choice)
	{
		case 'Y':
		case 'y':
			choiceIsYes = 1;
			break;
		case 'N':
		case 'n':
			choiceIsYes = 0;
			break;
		default:
			break;
	}
	return choiceIsYes;
}

/*  This function, asks for user's choice and evaluates if the user chooses to add another add-on.
	Precondition: Parameter addOn is a character.
	@param addOn is the user's previous input. It is the character being evaluated.
	@return Outputs/results to 1 (true) if choice is yes and 0 (false) otherwise. 
			Expected return value is an integer. 
*/
//This function is called in function getAddOn 4 times.
int 
addAnother (char addOn)
{
	//Declare and initialize variables.
    char option = ' ';
	int  addMore = 0;
    
    //Ask for and get inputs.
    printf("\nAdd another ");
   	printAddOnType(addOn);
    printf("? ");
    scanf(" %c", &option);
    
    //Loop and ask for input infinitely until input becomes valid.
    while (choiceIsInvalid(option))
    {
        printf("\nInvalid option. Do you want to add another "); //if full slots, don't be stuck on add another ? or input valid placement. user cannot be stuck.
        printAddOnType(addOn);
		printf("? [Y/N]: ");
        scanf(" %c",&option);
    }
    
    //evaluate if user wants to add more.
    if (choiceIsYes(option))
    {
    	addMore = 1;
	}
	
	else
	{
		addMore = 0;
	}
	
	return addMore;
}

/*  This function, given a character, handles invalidPlacementPositions. If applicable, displays current occupant add-on.
	Precondition: Parameter addOn is a character.
	@param addOn is the given character. It is the basis to determine if it is simple invalid or invalid because there is an occupant.
	@return Outputs/results to (a) printed string(s). 
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is called twice in function handleInvalid once in getPlacement.
void
invalidPlace (char addOn)
{
	printf("\nInvalid placement.");
	
	switch(addOn)
	{
		case 'L':
		case 'P':
		case 'O':
			printf(" Already indicated to place a ");
			printAddOnType(addOn);
			break;
		default:
			break;
	}
}

/*  This function, evaluates if a placement position is available or occupied.
	Precondition: Parameters addOnPos and addOnsCount are integers,
			  Parameter currentOccupantPos is a pointer integer,
			  Parameter arr_addOnPos[] is an integer array,
			  Parameter arr_addOn is a character array.
	@param addOnPos is the user's previous input to be evaluated if available.
	@param addOnsCount is the current addOns quantity. It helps manipulate arrays as an index.
	@param *currentOccupantPos is used to track the current add-on occupying the space.
	@param arr_addOnPos[] is the array containing the data about the add-ons' placementpositions.
	@param arr_addOn[] is the array storing the characters representing the add-ons.
	@return Outputs/results to 1 (true) if place is indeed occupied and 0 (false) otherwise. 
			Expected return value is an integer. 
*/
//This function is called in function getPlacement.
int
isPlaceOccupied (int addOnPos, int addOnsCount, int * currentOccupantPos, int arr_addOnPos[], char arr_addOn[])
{
    int counter, placeIsTaken=0;

    for (counter=0;counter<addOnsCount;counter++)
    {
        if (addOnPos == arr_addOnPos[counter])
        {
        	*currentOccupantPos = counter;
            placeIsTaken = 1;
            counter = addOnsCount;
        }

        else
        {
            placeIsTaken = 0;
        }
    }
    return placeIsTaken;
}

/*  This function updates and swaps values in the array arr_addOnPos[] if
	user's placement position is equal to latter values in the array
	since default array value is set to [1,2,3,4,5,6],
	i.e first input = 6; array swaps 1 and 6 and becomes [6,2,3,4,5,1] 
	Precondition: Parameters addOnPos, addOnsCount, and array arr_addOnPos are integers.
	@param addOnPos contains the value of accepted user's input for placement position
	@param addOnsCount contains the value of addOns currently in the shirt.
	@param arr_addOnPos[] is the array containing all the specific positions of the addOns.
	@return Outputs/results to array arr_addOnPos being updated, if applicable. 
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is called in function getPlacement.
void
updateArrayPos (int addOnPos, int addOnsCount, int arr_addOnPos[])
{
    int initialCounter;

    for (initialCounter=addOnsCount;initialCounter<=6;initialCounter++)
    {
        if (addOnPos==arr_addOnPos[initialCounter])
        {
            arr_addOnPos[initialCounter]=arr_addOnPos[addOnsCount];
        }
    }

    arr_addOnPos[addOnsCount] = addOnPos;
}

/*  This function gets user input for placement position and updates *addOnPos accordingly.
	Precondition: Parameter *addOnPos is an integer pointer.
	@param char addOn prints the add on represented by the character through function printAddOnType
	@param *addOnPos is used to store user input in variable addOnPos declared in function getPlacement
	@return Outputs/results to said variable addOnPos being updated.
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is called in function getPlacement.
void 
getAddOnPos (char addOn, int * addOnPos)
{
	printf("Enter ");
	printAddOnType(addOn);
	printf(" placement: ");
	scanf("%d", addOnPos);
}

/*  This function manages invalid user input for placement position and asks user again for valid placement.
	Precondition: Parameter *addOnPos is an integer pointer, 
	parameters placeRemainsInvalid, placeIsOccupied, currentOccupantPos are integers, and arr_addOn is a character array.
	@param *addOnPos is used to access addOnPos variable in function getPlacement and store input there.
	@param placeRemainsInvalid is used to check if user input is valid.
	@param placeIsOccupied is used to create printf variations - whether or not simple invalid or invalid because occupied.
	@param currentOccupantPos is used to track which add-on occupies the position indicated in previous user input.
	@param arr_addOn[] is used to read/write in the array containing the specific add-ons.
	@return Outputs/results to strings being printed and a prompt for valid user input.
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is called in function getPlacement.
void 
handleInvalid (int * addOnPos, int placeRemainsInvalid, int placeIsOccupied, int currentOccupantPos, char arr_addOn[])
{
	if (placeRemainsInvalid)
	{
		if (placeIsOccupied)
		{
			invalidPlace(arr_addOn[currentOccupantPos]);
		}
		else
		{	
			invalidPlace(' '); 
		}
		printf("\nEnter valid placement: ");
		scanf("%d",addOnPos);
	}
}

/*  This function gets the user's input for placement, repeats prompt if it is invalid and once valid, updates array accordingly.
	Precondition: Parameters are of correct data type. 
	parameters placeRemainsInvalid, placeIsOccupied, currentOccupantPos are integers, and arr_addOn is a character array.
	@param arr_addOn[] is passed as a parameter to 'child' functions that this 'parent' function calls.
	@param arr_addOnPos[] is similarly passed as a parameter to 'child' functions that this 'parent' function calls.
	@param addOnsCount is qty of addOns placed. It is passed as a parameter to 'child' functions that this 'parent' function calls.
	@param addOn is the chosen add-on and is also passed as a parameter to 'child' functions this 'parent' function calls.
	@return Outputs/results to arr_addOnPos being updated accordingly once user's input is valid.
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is called in function handleAddOn
void 
getPlacement (char arr_addOn[], int arr_addOnPos[], int addOnsCount, char addOn)
{
	// variables declaraed and initialized.
	int addOnPos = 0, placeRemainsInvalid = 1, placeIsOccupied = 0, currentOccupantPos = 0; 
	
	//get input.
	getAddOnPos(addOn, &addOnPos);
	
	//while user input is invalid, check if occupied or is within range of options. If both returns falls, go out of loop.
	while (placeRemainsInvalid)
	{
		//after while loop entry, re-assign to false. naturally breaks out of loop if placement is not seen as invalid.
		placeRemainsInvalid = 0;
		
		//call isPlaceOccupied function to check if user's input placement option is already occupied.
		placeIsOccupied = isPlaceOccupied (addOnPos, addOnsCount, &currentOccupantPos, arr_addOnPos, arr_addOn);
		
		//If the placement position selected by user is within options provided, check if place is occupied. Otherwise, invalid.
		switch(addOnPos)
		{
			//option 1 and option 2 are naturally available to the 3 add-ons. Only thing left to validate is if position is free.
			case 1:
			case 2:
				placeRemainsInvalid = placeIsOccupied;
				break;
				
			//option 3 and 4 is EXCLUSIVE to logo and patch.	
			case 3:
			case 4:
				//if add on is neither logo or patch, invalid. 
				if(addOn!='L'&&addOn!='P')
				{
					invalidPlace(' ');      
					placeRemainsInvalid = 1;
					
					//placeIsOccupied is set to 0 to avoid unnecessary display of occupant add-on.
					placeIsOccupied = 0; 
				}
				
				//else, if it is either, then just check if place is occupied because it's the only thing left to verify/validate.
				else 
				{
					placeRemainsInvalid = placeIsOccupied;	
				}
				break;
			
			//same case as 3 and 4 but this time, 5 and 6 is EXCLUSIVE to pocket.
			case 5:
			case 6:
				if(addOn!='O')
				{                        
					placeRemainsInvalid = 1;
					
					//placeIsOccupied is set to 0 to avoid unnecessary display of occupant add-on.
					placeIsOccupied = 0;
				}
				
				else 
				{
					placeRemainsInvalid = placeIsOccupied;	
				}
				break;
				
			default: 
				placeRemainsInvalid = 1;
				
				//placeIsOccupied is set to 0 to avoid unnecessary display of occupant add-on.
				placeIsOccupied = 0;
				break;
		}
		//Since placeRemainsInvalid, handleInvalid. This func prints additional context and info then asks for valid input.
		handleInvalid(&addOnPos, placeRemainsInvalid, placeIsOccupied, currentOccupantPos, arr_addOn);
	}
	updateArrayPos(addOnPos, addOnsCount, arr_addOnPos);
}

/*  This function deals with repeated routines of function calls and value assignments in function getAddOn
	Precondition: Parameters are of correct data type. 
	@param addOn is passed in functions called and is assigned to array arr_addOn once placement is valid.
	@param arr_addOn[] is passed as a parameter in function calls and is updated accordingly.
	@param arr_addOnPos[] is passed as a parameter when calling function getPlacement
	@param *addOnsCount is used as an index to arr_addOn and is incremented when processes are done.
	@return Outputs/results to arr_addOnPos being updated accordingly once user's input is valid.
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is called 6 times in function processAddOn
void
handleAddOn (char addOn, char arr_addOn[], int arr_addOnPos[], int * addOnsCount)
{
    showPlacementOptions(addOn);
    getPlacement(arr_addOn, arr_addOnPos, *addOnsCount, addOn);
    arr_addOn[*addOnsCount] = addOn;
    *addOnsCount+=1;
}

/*  This function gets the logo color count and assigns the value to arr_logoColors
	Precondition: Parameters are of correct data type. 
	@param addOnsCount is used as an index for arr_logoColors
	@param arr_logoColors[] is an array storing the value for logo colors.
	@return Outputs/results to arr_logoColors being updated once input is valid.
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is called twice in function processAddOn
void 
getColorCount (int addOnsCount, int arr_logoColors[])
{
    int colorCount = 0;
    
	while(colorCount<=0||colorCount>5)
	{
		printf("How many colors (1-5) is the logo? ");
    	scanf("%d",&colorCount);
	} 
    
	arr_logoColors[addOnsCount-1] = colorCount;
}

/*  This function, evaluates if there are options left based on addOnsCount and array arr_addOnPos.
	Precondition: Parameters are of correct data type.
	@param addOn is used to check if that addOn has available positions.
	@param addOnsCount is used as index to check the data in array arr_addOnPos.
	@param arr_addOnPos[] containing the occupied placement positions.
	@return Outputs/results to 0 (false) if there are no options and >0 (true) otherwise.
			Expected return value is an integer. 
*/
//This function is called 6 times in function processAddOn.
int 
thereAreOptionsLeft(char addOn, int addOnsCount, int arr_addOnPos[])
{
	//Variable declarations and initialization
	int availableLogoPatchOptions = 4, availablePocketOptions = 4, optionsLeft = 4, valToEvaluate;
	
	//Use addOnsCount as index to cycle through arr_addOnPos
	for(;addOnsCount > 0; addOnsCount--)
	{
		//set dynamic valtoEvaluate - addOnsCount changes per for loop iteration.
		valToEvaluate = arr_addOnPos[addOnsCount-1];
		
		//once value is evaluated as a particular position, subtract option from addons affected.
		switch(valToEvaluate)
		{
			case 1:
			case 2:
				availableLogoPatchOptions--;
				availablePocketOptions--;
				break;
			case 3:
			case 4:
				availableLogoPatchOptions--;
				break;
			case 5:
			case 6:
				availablePocketOptions--;
				break;
		}
	}
	
	//prepare to return the optionsLeft for the specific add on
	switch(addOn)
	{
		case 'L':
			optionsLeft = availableLogoPatchOptions;
			break;
		case 'P':
			optionsLeft = availableLogoPatchOptions;
			break;
		case 'O':
			optionsLeft = availablePocketOptions;
			break;
	}
	
	return optionsLeft;
}

/*  This function completes the task of processing add ons by calling functions that
	were modularized to perform subdivided tasks.
	Precondition: Parameters are of correct data type. 
	@param arr_addOn[] is passed to functions requiring it.
	@param arr_addOnPos[] is passed as a parameter to function calls.
	@param arr_logoColors[] is passed to function that need it.
	@return Outputs/results to printed strings, and function calls while modifying
			arr_addOn, arr_addOnPos, and arr_logoColors arrays.
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is called in main
void 
processAddOn (char arr_addOn[], int arr_addOnPos[], int arr_logoColors[])
{
	//declare and initialize variables.
	int addOnsCount = 0;
	char addOn = ' ';
	
	//minimum of 1 add-on and maximum of 6 add-ons
	while(addOnsCount == 0 || addOnsCount<6)
	{
		//print defined string and ask for input
		printf(ADDON_SELECTION);
		printf("\nEnter add-on: ");
		scanf(" %c", &addOn);
		
		//Do actions depending on the type of add on
		switch(addOn)
		{
			case 'L':
			case 'l':
				//if there are options left, get valid placement position then add 1 to addOnsCount
				if(thereAreOptionsLeft('L', addOnsCount, arr_addOnPos))
				{
					handleAddOn('L', arr_addOn, arr_addOnPos, &addOnsCount);
					
					//consequently, get logo color since this is case L.
					getColorCount(addOnsCount, arr_logoColors);
					
					//thereafter, as long as there are options, ask if user wants to add more logo
					while(thereAreOptionsLeft('L', addOnsCount, arr_addOnPos)&&addAnother('L'))
					{
						handleAddOn('L', arr_addOn, arr_addOnPos, &addOnsCount);
						getColorCount(addOnsCount, arr_logoColors);	
					}
				}
				
				//If there are no options left, display following string
				else
				{
					printf("Unable to add more. All slots for chosen add-on are occupied");
				}
				break;
				
			case 'P':
			case 'p':
				//as long as there are remaining options get valid placement position then add 1 to addOnsCount
				if(thereAreOptionsLeft('P', addOnsCount, arr_addOnPos))
				{
					handleAddOn('P', arr_addOn, arr_addOnPos, &addOnsCount);
					
					//after first prompt, check if there are options. If there are, ask if user wants to add more.
					while(thereAreOptionsLeft('P', addOnsCount, arr_addOnPos)&&addAnother('P'))
					{
						handleAddOn('P', arr_addOn, arr_addOnPos, &addOnsCount);  	
					}
				}
				
				//without options available, print string.
				else
				{
					printf("Invalid. All slots for chosen add-on are occupied.");
				}
				
				break;
				
			case 'O':
			case 'o':
				//if there are options left, get valid placement position and add 1 to addOnsCount
				if(thereAreOptionsLeft('O', addOnsCount, arr_addOnPos))
				{ 
					handleAddOn('O', arr_addOn, arr_addOnPos, &addOnsCount);
					
					//after first prompt, check if there are remaining slots for add-on. If there are, ask if user wants to add more.
					while(thereAreOptionsLeft('O', addOnsCount, arr_addOnPos)&&addAnother('O'))
					{
						handleAddOn('O', arr_addOn, arr_addOnPos, &addOnsCount);  	
					}
				}
				
				//without any unoccupied slots, print ff:
				else
				{
					printf("Invalid. All slots for chosen add-on are occupied.");
				}
				break;
				
			default:
				//if specified add on is not L, P, or O, then print ff:
				printf("Invalid choice.");
				addOn = ' ';
				break;
		}
		
		//user cannot decline if there are no add-ons placed
		if(addOnsCount == 0)
		{
			if(addOn!=' ')
			{
				printf(" A minimum of one add-on is required. "); 
			}//catch cases of user canceling entirely after this requirement is read.
		}
		// if there are addOns placed and it's less than 6, 
		// and user DOES NOT WANT TO ADD ANOTHER and value is not default, break out of loop by maxing addOnsCount.
		else if(addOnsCount<6&&!addAnother('+')&&addOn!=' ')
		{
			addOnsCount = 6;
		}
	}
}
