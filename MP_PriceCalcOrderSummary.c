void 
printSpacesBeforeP(int occupiedSpace)
{
	int spaceToPrint = 45;

	for(occupiedSpace;occupiedSpace<spaceToPrint;occupiedSpace++)
	{
		printf(" ");
	}
}

int
digitCount(int number)
{
	int digits=0;
	
	do 
	{
	    number /= 10;
	    digits++;
	} while (number != 0);
	
	return digits;
}

float 
basePrice(char size, int qty)
{
	float basePrice = 1;
	
	if(size=='X')
	{
		basePrice = 1.1;
		printf("entered here. basePrice is now %.2f", basePrice);
	}
	
	switch(qty)
	{
		case 5 ... 299:
			basePrice*=100;
			printf("basePrice*=100 is %.2f",basePrice);
			break;
		case 300 ... 500:
			basePrice*=80;
			printf("basePrice*=80 is %.2f",basePrice);
			break;
		default:
			basePrice*=75;
			printf("basePrice*=75 is %.2f",basePrice);
			break;
	}
	
	return basePrice;
}


void 
printSize(char size, int * occupiedSpace)
{
	switch(size)
	{
		case 'S':
			printf("Small ");
			*occupiedSpace+=6;
			break;
		case 'M':
			printf("Medium ");
			*occupiedSpace+=7;
			break;
		case 'L':
			printf("Large ");
			*occupiedSpace+=6;
			break;
		case 'X':
			printf("Extra Large ");
			*occupiedSpace+=12;
			break;
		default:
			break;
	}
}

void 
printNeck(char neckLine, int * occupiedSpace)
{
	switch(neckLine)
	{
		case 'V':
			printf("V-neck ");
			*occupiedSpace+=7;
			break;
		case 'R':
			printf("Round-neck ");
			*occupiedSpace+=11;
			break;
		default:
			break;
	}
}

void 
printShirtDetails(char size, char neckLine, int qty, float baseShirtPrice)
{	
	int occupiedSpace=0;
	
	printf("%d pcs of ",qty);
	occupiedSpace+=digitCount(qty)+8;
		
	printSize(size, &occupiedSpace);
	printNeck(neckLine, &occupiedSpace);
	
	printf("shirt with");
	occupiedSpace+=10;
	
	printSpacesBeforeP(occupiedSpace);
	printf("P %10.2f @\n", baseShirtPrice);		
}

void
handleLogoPrice(int arr_logoColors[], float arr_addOnsPrice[], float * logoSum, int counter, int qty)
{
	float logoCost = 0;
	float logoMultiplier = 1;
	
	//SetlogoMultiplier
	if(qty>500)
	{
		logoMultiplier = 0.75;
		printf("Multip set to 0.75\n");
	}
	else if(qty>=300)
	{
		logoMultiplier = 0.9;
		printf("Multip set to 0.9\n");
	}
	
	if(arr_logoColors[counter]==1)
	{
		logoCost = 18;
		printf("logo sum is going to be increased by %.2f\n", 18*logoMultiplier);
	}
	else if(arr_logoColors[counter]==2)
	{
		logoCost = 20;
		printf("logo sum is going to be increased by %.2f\n", 20*logoMultiplier);
	}
	else if(arr_logoColors[counter]>=3&&arr_logoColors[counter]<=5)
	{
		logoCost = 25;
		printf("logo sum is going to be increased by %.2f\n", 25*logoMultiplier);
	}
	
	printf("logoCost preMultips is %.2f",logoCost);
	logoCost*=logoMultiplier;
	printf("logoCost after multiplier is now %.2f",logoCost);
	arr_addOnsPrice[counter] = logoCost;
	printf("arr_addOnsPrice[0] is %.2f\narr_addOnsPrice[1] is %.2f\narr_addOnsPrice[2] is %.2f\narr_addOnsPrice[3] is %.2f\narr_addOnsPrice[4] is %.2f\narr_addOnsPrice[4] is %.2f\narr_addOnsPrice[5] is %.2f\n",arr_addOnsPrice[0],arr_addOnsPrice[1],arr_addOnsPrice[2],arr_addOnsPrice[3],arr_addOnsPrice[4],arr_addOnsPrice[5]);
	*logoSum+=logoCost;
}

float 
addOnsPrice(char arr_addOn[], int arr_logoColors[], float arr_addOnsPrice[], int qty)
{
	float logoSum=0, addOnsTotalPrice=0;
	int patchSum=0, pocketSum=0, counter;
	
	for (counter = 0; counter < 6; counter++)
	{
		switch (arr_addOn[counter])
		{
		case 'L':
			handleLogoPrice(arr_logoColors, arr_addOnsPrice, &logoSum, counter, qty);
			break;
		case 'P':
			arr_addOnsPrice[counter] = 15;
			patchSum+=15;
			printf("patch sum which is now %d was increased by 15\n", patchSum);
			break;
		case 'O':
			arr_addOnsPrice[counter] = 5;
			pocketSum+=5;
			printf("pocket sum which is now %d was increased by 5\n", pocketSum);
			break;
		default:
			break;
		}
	}
	
	addOnsTotalPrice = logoSum + patchSum + pocketSum;
	printf("\naddOnsTotal = logoSum + patchSum + pocketSum\n%.2f = %.2f + %d + %d\n\n", addOnsTotalPrice, logoSum, patchSum, pocketSum);
	return addOnsTotalPrice;
}

void 
perUnitCalc(char arr_addOn[], int arr_logoColors[], float arr_addOnsPrice[], char size,  int qty, float * price)
{
	*price = basePrice(size,qty) + addOnsPrice(arr_addOn, arr_logoColors, arr_addOnsPrice, qty);
}

void 
addOnTypePrinter(char addOnType, int * occupiedSpace)
{
	switch(addOnType)
	{
		case 'L':
			printf("   Logo");
			*occupiedSpace+= 7;
			break;
		case 'P':
			printf("   Patch");
			*occupiedSpace+= 8;
			break;
		case 'O':
			printf("   Pocket");
			*occupiedSpace+= 9;
			break;
		default:
			break;
	}
}

void printTruePosition(int truePos, int * occupiedSpace)
{
	switch(truePos)
	{
		case 1:
			printf("left chest");
			*occupiedSpace+= 10;
			break;
		case 2:
			printf("right chest");
			*occupiedSpace+= 11;
			break;
		case 3:
			printf("left sleeve");
			*occupiedSpace+= 11;
			break;
		case 4:
			printf("right sleeve");
			*occupiedSpace+= 12;
			break;
		case 5:
			printf("bottom left of shirt");
			*occupiedSpace+= 20;
			break;
		case 6:
			printf("bottom right of shirt");
			*occupiedSpace+= 21;
			break;
		default:
			break;
	}
}

void
printColorCount(int colorQty, int * occupiedSpace)
{
	if(colorQty>0)
	{
		printf(", %d color",colorQty);
		*occupiedSpace+=9;
		if(colorQty>1)
		{
			printf("s");
			*occupiedSpace+=1;
		}
	}
}

void
printAddOnDetails(char arr_addOn[], int arr_addOnPos[], int arr_logoColors[], float arr_addOnsPrice[])
{
	int counter, spaceOccupied;
	for (counter=0;counter<6;counter++)
	{
		spaceOccupied = 0;
		if(arr_addOn[counter]!=' ')
		{
			addOnTypePrinter(arr_addOn[counter], &spaceOccupied);
			printf(" on ");
			spaceOccupied+=4;
			printTruePosition(arr_addOnPos[counter], &spaceOccupied);
			printColorCount(arr_logoColors[counter], &spaceOccupied);
			printSpacesBeforeP(spaceOccupied);
			printf("P %10.2f @\n", arr_addOnsPrice[counter]);
		}
	}
}

void
grandTotalCalc(float * price, int qty)
{	
	printf("----------------------------------------------------------------------\n");
	printSpacesBeforeP(0);
	printf("P %10.2f @  x  %d\n",*price, qty);
	*price = *price*qty;
	printf("                    Total Bill for Order:    P %10.2f\n",*price);
}

//
void 
orderSummary(char arr_addOn[], int arr_addOnPos[], int arr_logoColors[], float arr_addOnsPrice[], char size, char neckLine, int qty, float * price)
{
	int charactersCount = 0;
	float baseShirtPrice = basePrice(size, qty);
	perUnitCalc(arr_addOn, arr_logoColors, arr_addOnsPrice, size,  qty, price);
	
	printf("\nOrder Summary:\n");
	printShirtDetails(size, neckLine, qty, baseShirtPrice);
	printAddOnDetails(arr_addOn, arr_addOnPos, arr_logoColors, arr_addOnsPrice);
	grandTotalCalc(price, qty);
}

void
changeBreakdown(float price)
{
	float arr_Denomination[14] = {1000, 500, 200, 100, 50, 20, 10, 5, 1, 0.5, 0.25, 0.10, 0.05, 0.01};
	float change, amountGiven, actualDenomination;
	int counter = 0,
	denominationCount = 0;
	
	printf("Amount paid by customer: ");
	scanf("%f",&amountGiven);
	
	while(amountGiven<price)
	{
		printf("Invalid.\nEnter valid amount paid by customer (must be higher than total cost %f): ",price);
		scanf("%f",&amountGiven);
	}
	
	change = amountGiven-price, actualDenomination;
	
	printf("Total change: P %.2f\nBreakdown of change:\n", change);

	while (change>0)
	{
		actualDenomination = arr_Denomination[counter];
		denominationCount = change/actualDenomination;
		
		if(denominationCount>=1&&change>=1)
		{
			printf("  Php %4.f - %d\n", actualDenomination, denominationCount);
		}
		else if(denominationCount>=1&&change<1)
		{
			printf("  Php %4.2f - %d\n", actualDenomination, denominationCount);
		}
		
		printf("\n");
		
		//Change Has To Be Bigger
		change-=actualDenomination*denominationCount;
		counter++;
	}
}
