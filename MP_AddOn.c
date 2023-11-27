/*
TO DO:
*******************************************
add maybe 5 attempts or break out of loop option. or detect if no more possible position.

USER CANNOT BE STUCK, NO AVAILABLE FOR P OR L OR O ADD CATCH CASES
ADD ANOTHER ADD ON SHOULD DISPLAY OPTIONS + space per promptinvalid space
*/

/******************************************
File Name: MP_AddOn.C

Author: Bon Windel E. Aquino
Last Update: November 27, 2023

Routines to get the user's inputs for 
add on types, placements/positions, and
if applicable, logo colors.
 
The entry point to these routines is the 
getAddOn() routine at the bottom 
of this file. It is called in the main function found in MP_Main.c
******************************************/

#include <stdio.h>
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

/*  This function, given a character, handles invalidPlacementPositions. If applicable, displays current occupant add-on.
	Precondition: Parameter addOn is a character.
	@param addOn is the given character. It is the basis to determine if it is simple invalid or invalid because there is an occupant.
	@return Outputs/results to (a) printed string(s). 
			Invalid/No expected return value. Function (caller) data type is void. 
*/
//This function is called twice in function handleInvalid once in getPlacement.
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

void getAddOnPos (char addOn, int * addOnPos)
{
	printf("Enter ");
	printAddOnType(addOn);
	printf(" placement: ");
	scanf("%d", addOnPos);
}

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

void 
getPlacement (char arr_addOn[], int arr_addOnPos[], int addOnsCount, char addOn) //if addOn is valid, takes its placement
{
	// variable initialization and declaration
	int addOnPos = 0, placeRemainsInvalid = 1, placeIsOccupied, currentOccupantPos = 0; //by default, placeIsInvalid because addOnPosTemporary is 0 is invalid.
	
	//inputs
	getAddOnPos(addOn, &addOnPos);
	
	while (placeRemainsInvalid)
	{
		placeRemainsInvalid = 0;
		placeIsOccupied = isPlaceOccupied (addOnPos, addOnsCount, &currentOccupantPos, arr_addOnPos, arr_addOn);
		switch(addOnPos) //check if 3 and 4 are O coz only L and P are valid. check if 5 and 6 are L and P coz only O is valid
		{
			case 1:
			case 2:
				placeRemainsInvalid = placeIsOccupied;
				break;
			case 3:
			case 4:
				if(addOn!='L'&&addOn!='P')
				{
					invalidPlace(' ');      
					placeRemainsInvalid = 1;
					placeIsOccupied = 0;
				}
				else placeRemainsInvalid = placeIsOccupied;
				break;
			case 5:
			case 6:
				if(addOn!='O')
				{                        
					placeRemainsInvalid = 1;
					placeIsOccupied = 0;
				}
				else placeRemainsInvalid = placeIsOccupied;
				break;
				
			default: 
				placeRemainsInvalid = 1;
				placeIsOccupied = 0;
				break;
		}
		handleInvalid(&addOnPos, placeRemainsInvalid, placeIsOccupied, currentOccupantPos, arr_addOn);
		
		
	}
	
	updateArrayPos(addOnPos, addOnsCount, arr_addOnPos);
	
	//ARRAYS_VISUALIZER
}

void
handleAddOn (char addOn, char arr_addOn[], int arr_addOnPos[], int * addOnsCount)
{
    showPlacementOptions(addOn);
    getPlacement(arr_addOn, arr_addOnPos, *addOnsCount, addOn);
    arr_addOn[*addOnsCount] = addOn;
    *addOnsCount+=1;
}

void 
getColorCount (int addOnsCount, int arr_logoColors[])
{
    int colorCount = 0;
    
	do{
		printf("How many colors (1-5) is the logo? ");
    	scanf("%d",&colorCount);
	} while(colorCount<=0||colorCount>5);
    
	arr_logoColors[addOnsCount-1] = colorCount;
}

void 
getAddOn (char arr_addOn[], int arr_addOnPos[], int arr_logoColors[])
{
	//getAddOn Vars or TriggerFlag
	int addOnsCount = 0; //maybe put to main? so this doesn't get initialized everytime but headache pointers
	char addOn = ' ';
	
	while(addOnsCount == 0||addOnsCount<6)
	{
		printf(ADDON_SELECTION);
		printf("\nEnter add-on: ");
		scanf(" %c", &addOn);
		switch(addOn)
			{
			case 'L':
			case 'l':
				handleAddOn('L', arr_addOn, arr_addOnPos, &addOnsCount);
				getColorCount(addOnsCount, arr_logoColors);
				while(addAnother('L'))
				{
					handleAddOn('L', arr_addOn, arr_addOnPos, &addOnsCount);
					getColorCount(addOnsCount, arr_logoColors);	
				}
				break;
				
			case 'P':
			case 'p':
				handleAddOn('P', arr_addOn, arr_addOnPos, &addOnsCount); 
				while(addAnother('P'))
				{
					handleAddOn('P', arr_addOn, arr_addOnPos, &addOnsCount);  	
				} 
				break;
				
			case 'O':
			case 'o': 
				handleAddOn('O', arr_addOn, arr_addOnPos, &addOnsCount);  
				while(addAnother('O'))
				{
					handleAddOn('O', arr_addOn, arr_addOnPos, &addOnsCount);  	
				}
				break;
			default:
				printf("Invalid choice.");
				addOn = ' ';
				break;
			}
			
		if(addOnsCount == 0)
		{
			if(addOn!=' ')
			{
				printf(" A minimum of one add-on is required. "); 
			}//catch cases of user canceling entirely after this requirement is read.
		}
		else if(!addAnother('+')&&addOn!=' ')
		{
			addOnsCount = 6;
		}
	}
}
