#include <stdio.h>

void
charPrinter(char symbol, int charCount)
{
	int ctr;
	for(ctr=0;ctr<charCount;ctr++)
	{
		printf("%c",symbol);
	}
}

int
sizeConverter(char size)
{
	int sizeMultiplier;
	switch(size)
	{ // no need breaks coz of return?
		case 'S':
		case 's':
			sizeMultiplier=1;
			break;
		case 'M':
		case 'm':
			sizeMultiplier=2;
			break;
		case 'L':
		case 'l':
			sizeMultiplier=3;
			break;
		case 'X':
		case 'x':
			sizeMultiplier=4;
			break;
		default:
			break;
	}
	return sizeMultiplier;
}

void
addOnPlacer(char arr_addOn[], int arr_addOnPos[], int truePos)
{
	int addOnCtr;
	for(addOnCtr=0;addOnCtr<=6;addOnCtr++)
	{
		if(arr_addOnPos[addOnCtr]==truePos)
		{	
			printf("%c",arr_addOn[addOnCtr]);
			addOnCtr=7;
		}
	}
}

void
printTop(int xCount)
{
	charPrinter(' ',3);
	charPrinter('x',xCount);
	charPrinter(' ',4);
	charPrinter('x',xCount); 
	charPrinter(' ',3);
	// test printf("\n\nsummary: \n size = %c or %d\n space = %d\n xCount = %d \n\n",size,sizeConverter(size),3,xCount);
}

void 
dealWithCollarNeckLine(int sleeveLineNumber, char neckLine)
{
	switch(sleeveLineNumber)
	{
		case 1:
			if(neckLine=='V')
			{
				printf("x  x");
			}
			else if(neckLine=='R')
			{
				charPrinter('x', 4);
			}
			break;
		case 2:
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

void
printBottom(int xCount)
{
	printf("   ");
	charPrinter('x',xCount*2+4);
}

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
