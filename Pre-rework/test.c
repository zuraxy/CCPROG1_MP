#include <stdio.h>


void
finalPointerGet(int*pointer)
{
	printf("(7) pointer is: %d\n",pointer); //to here SO PRINT POINTER 
	printf("(8) *pointer is: %d\n\n",*pointer);
}

void
pointerGetter1(int*pointer)
{
	printf("(14) pointer is: %d\n",pointer);
	printf("(15) *pointer is: %d\n",*pointer);
	printf("(16) *pointer is: %d\n\n",&pointer);
	
	printf("(18) finalPointerGetFunctionCall with asterisk *\n");
	finalPointerGet(*pointer); //here SO PASS POINTER COZ PARAMETER ACCEPTED IS POINTER
	
	printf("(19) finalPointerGetFunctionCall with ampersand &\n");
	finalPointerGet(&pointer);
	
	printf("(20) finalPointerGetFunctionCall without any");
	finalPointerGet(pointer);
}

int main()
{
	int pointer = 1;
	pointerGetter1(&pointer);
	return 0;
}

