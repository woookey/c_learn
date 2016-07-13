#ifndef EX14_H
#define EX14_H

#include <string.h>

void print_letters(char arg[]);
void print_arguments(int argc, char *argv[]);



void print_arguments(int argc, char*argv[])
{
	int i = 0;

	for (i=0; i<argc; i++)
	{
		print_letters(argv[i]);
	}
}

void print_letters(char arg[])
{
	int i = 0;

	int len = strlen(arg);

	for(i=0; i<len; i++)
	{
		char ch=arg[i];

		if(isalpha(ch) || isblank(ch) || isdigit(ch) || isalnum(ch))
		{
			printf("'%c' == %d ", ch, ch);
		}
	}

	printf("\n");
}

#endif
