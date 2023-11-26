#include <stdio.h>

void
capitalize(char letter)
{
	switch(letter)
	{
		case 'r':
			break;
		case 'v':
			break;
		case 's':
			break;
		case 'm':
			break;
		case 'l':
			break;
		case 'x':
			break;
	}
}

void 
getQuantity(int * qty)
{
	printf("Enter the number of shirts you want to order (5pcs minimum): ");
	scanf("%d",qty);
	
	while (*qty<5)
	{
		printf("\nToo low. The minimum order that can be accepted is 5.\nEnter valid quantity: ");
		scanf("%d",qty);
	}
}

void 
getNeckLine(char * neckLine)
{
	//Input prompt
	printf("\nEnter the shirts' neckLine. V-neck or Round neck (V/R): ");
	scanf(" %c",neckLine);
	
	while(*neckLine!='v'&&*neckLine!='V'&&*neckLine!='R'&&*neckLine!='r')
	{
		printf("\nInvalid.\nValid ptions are: V/v/r/R. Enter a valid neckLine: ");
		scanf(" %c",neckLine);		
	}
	
	switch(*neckLine)
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

void 
getsize(char * size)
{
	printf("\nEnter the the shirts' size. S(small), M(medium), L(large), or X(extra large): ");
	scanf(" %c",size);
	
	while(*size!='s'&&*size!='S'&&*size!='M'&&*size!='m'&&*size!='l'&&*size!='L'&&*size!='X'&&*size!='x')
	{
		printf("\nInvalid.\nValid options are: s/S/M/m/l/L/X/x\nEnter a valid size: ");
		scanf(" %c",size);
	}
	
	switch(*size)
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

void
getQtyNeckSize(int*qty, char*neckLine, char*size)
{
	printf("\n\nOrder Form\n");
	getQuantity(qty);
	getNeckLine(neckLine);
	getsize(size);
}
