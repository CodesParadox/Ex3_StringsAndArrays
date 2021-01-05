#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LINE 256
#define WORD 30

int getword(char w[])
{
	//printf("enter string");
	char c = getchar();
	int count = 0;
	while (c != ' ' && c != '\n' && c != EOF && c != '\t' && count < WORD)
	{
		w[count] = c;
		count++;
		c = getchar();
	}
	w[count] = '\0';
	if (c == EOF)
	{
		return EOF;
	}
	return count;
}

int getLine(char s[])
{
	char c = getchar();
	int count = 0;
	s[count] = c;
	while (c != '\n' && c != EOF && count < LINE)
	{
		count++;
		c = getchar();
		s[count] = c;
	}
	s[count] = '\0';
	if (c == EOF)
	{
		return EOF;
	}
	return count;
}
// Check if str2 contain str1. if True return 1, otherwise return 0.
int substring(char *str1, char *str2)
{
	int count = 0;
	int jni = 0;
	if (strlen(str1) < strlen(str2))
	{ // if str1 length is smaller then str2
		return 0;
	}
	for (int j = 0; j < strlen(str1); j++)
	{
		if (str1[j] == str2[0])
		{
			for (int i = 0; i < strlen(str2); i++)
			{ // efshar gam im while need to check what better
				jni = j + i;
				if (str1[jni] == str2[i])
				{
					count++;
				}
			}
			if (count == strlen(str2))
			{
				return 1;
			}
		}
		count = 0;
	}
	if (count != 0)
	{
		return true;
	}
	return false;
}

int similar(char *s, char *t, int n)
{
	int i = 0;
	int j = 0;
	if (strlen(s) > strlen(t))
	{
		while (i < strlen(s) && j < strlen(t))
		{

			if (s[i] == t[j])
			{
				j++;
				i++;
			}
			else
			{
				i++;
				n--;
			}
		}
		if (n > 0)
			return 1;
		return 0;
	}
	return 0;
}

void print_lines(char *str)
{
	char text[LINE];
	int booline = true;
	int liner = getLine(text);
	while (liner != EOF)
	{
		liner = getLine(text);
		if (substring(text, str) == booline)
		{
			printf("%s\n", text);
		}
	}
}

void print_similar_words(char *str)
{
	char Words[WORD];
	int WordsLength = getword(Words);
	while (WordsLength != EOF)
	{
		int checkmax = similar(Words, str, 1); //check similar words til 1 letter miss
		int checkmin = similar(Words, str, 0); // check similar words
		if ((checkmax) || (checkmin))
		{
			printf("%s\n", Words);
		}
	}
}