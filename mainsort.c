#include "isort.h"
#include <stdio.h>
#include <string.h>
#define SizeOfNum 50

int main()
{
	int NumArr[SizeOfNum];
	int i = 0;
	int *pointernum = NumArr;
	while (i < SizeOfNum)
	{
		printf("Insert Number: ");
		scanf(" %d", pointernum++);
		i++;
		printf("Free Storage: %d of 50\n", SizeOfNum - i);
	}
	insertion_sort(NumArr, SizeOfNum);
	pointernum = NumArr;
	for (int j = 0; j < SizeOfNum - 1; j++)
	{
		printf("%d, ", *pointernum);
		pointernum++;
	}
	printf("%d \n", *(NumArr + SizeOfNum - 1));
	printf("\n");
}