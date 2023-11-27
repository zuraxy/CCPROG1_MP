#include <stdio.h>
void dayCalc(int Qty, char arr_addOn[])
{
	int secPiece=0, totalDur = 0,i;
	for (i = 0; i < 6;i++)
	{
		switch (arr_addOn[i])
		{
		case 'l':
		case 'L':
			secPiece += 60;
			break;
		case 'p':
		case 'P':
			secPiece += 20;
			break;
		case 'o':
		case 'O':
			secPiece += 30;
			break;
		default:
			break;
		}
	}
	totalDur = secPiece * Qty;
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
