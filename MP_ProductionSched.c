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
	int saysYes = 0;
	char input = ' ';
	printf("Confirm order? ");
	scanf(" %c",&input);
	
	switch(input)
	{
		case 'Y':
		case 'y':
			saysYes = 1;
			break;
		case 'N':
		case 'n':
			saysYes = 0;
			break;
		default:
			break;
	}
	
	return saysYes;
}
