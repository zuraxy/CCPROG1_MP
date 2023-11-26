#include <stdio.h>
#define OPTION_FOR_ALL " placement options:\n1 - left chest\n2 - right chest"
#define OPTION_LOGO_PATCH "\n3 - left sleeve\n4 - right sleeve\n\n"
#define OPTION_POCKET "\n5 - bottom left\n6 - bottom right\n\n"
#define ADDON_SELECTION "\nAdd-on options:\nL - Logo\nP - Patch\nO - pOcket\n"
/*
TO DO:
*******************************************
maybe add #defines for standard printfs?
add maybe 5 attempts or break out of loop option. or detect if no more possible position.

USER CANNOT BE STUCK, NO AVAILABLE FOR P OR L OR O ADD CATCH CASES
ADD ANOTHER ADD ON SHOULD DISPLAY OPTIONS + space per promptinvalid space
*/

void 
printAddOnType(char addOn)
{
	switch(addOn)
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
			break;
	}
}

void 
showPlacementOptions(char addOn) //is this allowed? 5 and 6 + exclusivity? or required 1234 instead of 1256?
{
	//initial placement options. Available to all add-ons.
	printf("\n");
	printAddOnType(addOn);
	printf(OPTION_FOR_ALL);
	
	//in add-ons Logo and Patch, show EXCLUSIVE 3 AND 4. In add-on Pocket, show EXCLUSIVE 5 AND 6.
	switch(addOn)
	{
		case 'L':
		case 'P':
			printf(OPTION_LOGO_PATCH); //options EXCLUSIVE TO LOGO AND PATCH
			break;
		case 'O':
			printf(OPTION_POCKET); //OPTIONS EXCLUSIVE TO POCKET
			break;
		default:
			break;
	}
}

int
isChoiceInvalid(char choice)
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

int 
isChoiceYes(char choice)
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

int 
addAnother(char addOn)
{
    char option = ' ';
	int  addMore = 0;
    
    printf("\nAdd another ");
   	printAddOnType(addOn);
    printf("? ");
    scanf(" %c", &option);
    
    while(isChoiceInvalid(option))
    {
        printf("\nInvalid option. Do you want to add another "); //if full slots, don't be stuck on add another ? or input valid placement. user cannot be stuck.
        printAddOnType(addOn);
		printf("? [Y/N]: ");
        scanf(" %c",&option);
    }
    
    if(isChoiceYes(option))
    {
    	addMore = 1;
	}
	
	else
	{
		addMore = 0;
	}
	
	return addMore;
}

void
invalidPlace(char addOn) //function dealing with invalid place and attempting to take another valid input
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

int
isPlaceOccupied(int addOnPos, int addOnsCount, int * currentOccupantPos, int arr_addOnPos[], char arr_addOn[])
{
    int counter, placeIsTaken=0;

    for(counter=0;counter<addOnsCount;counter++)
    {
        if(addOnPos == arr_addOnPos[counter])
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
	printf("\nplaceIsTaken: %d",placeIsTaken);
    return placeIsTaken;
}

void
updateArrayPos(int addOnPos, int addOnsCount, int arr_addOnPos[])
{
    int initialCounter;

    for(initialCounter=addOnsCount;initialCounter<=6;initialCounter++)
    {
        if(addOnPos==arr_addOnPos[initialCounter])
        {
            arr_addOnPos[initialCounter]=arr_addOnPos[addOnsCount];
        }
    }

    arr_addOnPos[addOnsCount] = addOnPos;
}

void getAddOnPos(char addOn, int * addOnPos)
{
	printf("Enter ");
	printAddOnType(addOn);
	printf(" placement: ");
	scanf("%d", addOnPos);
}

void 
handleInvalid(int * addOnPos, int placeRemainsInvalid, int placeIsOccupied, int currentOccupantPos, char arr_addOn[])
{
	if(placeRemainsInvalid)
	{
		if(placeIsOccupied)
		{
			printf("entered placeIsOccupied. \n-currentOccupantPos: %d\n-value of arr_addOn[currentOccupantPos]: %c\n",currentOccupantPos, arr_addOn[currentOccupantPos]);
			invalidPlace(arr_addOn[currentOccupantPos]);
		}
		else
		{	
			printf(" Enter in else (unoccupied but invalid).\n");
			invalidPlace(' '); 
		}
		printf("\nEnter valid placement: ");
		scanf("%d",addOnPos);
	}
}

void 
getPlacement(char arr_addOn[], int arr_addOnPos[], int addOnsCount, char addOn) //if addOn is valid, takes its placement
{
	// variable initialization and declaration
	int addOnPos = 0, placeRemainsInvalid = 1, placeIsOccupied, currentOccupantPos = 0; //by default, placeIsInvalid because addOnPosTemporary is 0 is invalid.
	
	//inputs
	getAddOnPos(addOn, &addOnPos);
	
	do //while placeRemainsInvalid is true, loop continuously and ask for valid addOnPos repeatedly
	{
		placeRemainsInvalid = 0;
		placeIsOccupied = isPlaceOccupied(addOnPos, addOnsCount, &currentOccupantPos, arr_addOnPos, arr_addOn);
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
		
		
	} while(placeRemainsInvalid);
	
	updateArrayPos(addOnPos, addOnsCount, arr_addOnPos);
	
	printf("\n!@#$%^&*()\ninput accepted.\n addOn is %c\n addOnPos is %d\n addOnsCount is %d\n",
		arr_addOn[addOnsCount], arr_addOnPos[addOnsCount], addOnsCount);
	printf("\n!@#$%^&*()\ncurrent array looks like this: \n");
	printf("arr_addOn[0] = %c, arr_addOn[1] = %c, arr_addOn[2] = %c, arr_addOn[3] = %c, arr_addOn[4] = %c, arr_addOn[5] = %c\n", arr_addOn[0], arr_addOn[1], arr_addOn[2], arr_addOn[3], arr_addOn[4], arr_addOn[5]);
	printf("arr_addOnPos[0] = %d, arr_addOnPos[1] = %d, arr_addOnPos[2] = %d, arr_addOnPos[3] = %d, arr_addOnPos[4] = %d, arr_addOnPos[5] = %d\n", arr_addOnPos[0], arr_addOnPos[1], arr_addOnPos[2], arr_addOnPos[3], arr_addOnPos[4], arr_addOnPos[5]);
}

void
handleAddOn(char addOn, char arr_addOn[], int arr_addOnPos[], int * addOnsCount)
{
    showPlacementOptions(addOn);
    getPlacement(arr_addOn, arr_addOnPos, *addOnsCount, addOn);
    arr_addOn[*addOnsCount] = addOn;
    *addOnsCount+=1;
}

void 
getColorCount(int addOnsCount, int arr_logoColors[])
{
    int colorCount = 0;
    
	do{
		printf("How many colors (1-5) is the logo? ");
    	scanf("%d",&colorCount);
	} while(colorCount<=0||colorCount>5);
    
	arr_logoColors[addOnsCount-1] = colorCount;
}

void 
getAddOn(char arr_addOn[], int arr_addOnPos[], int arr_logoColors[])
{
	//getAddOn Vars or TriggerFlag
	int addOnsCount = 0; //maybe put to main? so this doesn't get initialized everytime but headache pointers
	char addOn = ' ';
	
	//Print List
	printf(ADDON_SELECTION);
	
	do
	{
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
	} while(addOnsCount == 0||addOnsCount<6);
}
