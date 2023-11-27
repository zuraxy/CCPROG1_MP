#include <stdio.h>
void 
dayCalc(char arr_addOn[], int qty, int * secondsPerPiece, int * productionTime, int * daysUntilPickUp)
{
	int counter;
	char addOnType = ' ';
	for (counter = 0; counter < 6; counter++)
	{
		addOnType = arr_addOn[counter];
		switch (addOnType)
		{
		case 'L':
			*secondsPerPiece += 60;
			break;
		case 'P':
			*secondsPerPiece += 20;
			break;
		case 'O':
			*secondsPerPiece += 30;
			break;
		default:
			break;
		}
	}
	*productionTime = *secondsPerPiece * qty;
	*daysUntilPickUp = 2 + (*productionTime / 43200);
}

void 
convertTime(int productionTime, int * hours, int * mins, int * sec)
{
	*hours = productionTime/3600;
	productionTime-=*hours*3600;
	*mins = productionTime/60;
	productionTime-=*mins*60;
	*sec = productionTime;
}

void
displayOrderTimeInfo(int qty, char arr_addOn[])
{
	int secondsPerPiece = 0, 
		productionTime = 0, 
		daysUntilPickUp = 0, 
		hours = 0, 
		mins = 0, 
		sec = 0;
		
	dayCalc(arr_addOn, qty, &secondsPerPiece, &productionTime, &daysUntilPickUp);
	convertTime(productionTime, &hours, &mins, &sec);
	printf("Production Time: %d hours %d minutes %d seconds\n", hours, mins, sec);
	printf("Order can be picked up after %d days\n\n",daysUntilPickUp);
}

int 
confirmOrder()
{
	int saysYes = 0, invalidOption=1;
	char input = ' ';
	
	
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
	return saysYes;
}
