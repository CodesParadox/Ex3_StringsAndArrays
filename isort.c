#include <stdio.h>
#include "isort.h"

// This function move the numbers 'i' cells to the right
void shift_element(int *arr, int i)
{
	int j = i;
	while (j > 0)
	{
		*(arr + j) = *(arr + j - 1);
		j--;
	}
}
//sort 50 numbers
void insertion_sort(int *arr, int len)
{
	int i, j = 0;
	int pointer1, pointer2;
	int count = 0;
	while (i < len)
	{
		j = i;
		pointer1 = *(arr + i);
		while (j < len - 1)
		{
			pointer2 = *(arr + j + 1);
			if (pointer1 > pointer2)
			{
				pointer1 = pointer2;
				count = j + 1;
			}
			j++;
		}
		int next = *(arr + i);
		if (pointer1 != next)
		{
			shift_element(arr + i, count - i);
			*(arr + i) = pointer1;
		}
		i++;
	}
}
