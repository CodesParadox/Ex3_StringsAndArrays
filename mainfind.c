#include <stdio.h>
#include <string.h>
#include "txtfind.h"
#define WORD 30
int main()
{
	char Words[WORD];
	getword(Words);
	char ch;
	scanf("%c", &ch);
	// check if the char is valid
	//*** <Options> ***
	//'a' - print the lines with the correct  word
	//'b' - print the similar words for the correct input
	// while (ch != 'a' && ch != 'b')
	// {
	// 	printf("Invalid input char, plz try again\n");
	// 	scanf(" %c", &ch);
	// }
	if (ch == 'a')
	{
		print_lines(Words);
	}

	if (ch == 'b')
	{
		print_similar_words(Words);
	}
}
