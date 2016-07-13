/**
 Static Stack implementation
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>


#define MAX_SIZE 10
#define NOT_INITIALISED 0

struct Element
{
	int x;
};

struct Stack
{
	struct Element elements[MAX_SIZE];
	int top_element;
};

struct Stack *createEmptyStack(void)
{
	struct Stack *st = malloc(sizeof(struct Stack));

	int i = 0;
	for(i=0; i<MAX_SIZE; i++)
	{
		struct Element m_element =
		{
			.x = NOT_INITIALISED
		};
		st->elements[i] = m_element;
	}
	st->top_element = 0;

	return st;
}

void showStackElements( struct Stack *st)
{
	int i;
	for(i=0; i < st->top_element; i++)
	{
		printf("Element %d = %d\n", i, st->elements[i].x);
	}
}

void push(struct Stack *st, struct Element *el)
{
	assert(st != NULL);

	if(st->top_element >= MAX_SIZE-1)
	{
		printf("Too many objects on Stack\n");
	}
	else
	{
		st->elements[st->top_element] = *el;
		st->top_element += 1;
	}

	printf("Added element[%d] = %d on Stack\n", st->top_element, el->x);
}

struct Element *pop(struct Stack *st)
{
	struct Element *el = malloc(sizeof(struct Element));

	assert(st != NULL);

	if (st->top_element == 0)
	{
		el = NULL;
		printf("Empty stack\n");
	}
	else
	{
		*el = *(st->elements[st->top_element]);
		st->top_element -= 1;
		printf("Removed element[%d] = %d from Stack\n", st->top_element+1, el.x);
	}

	return el;
}

int main(int argc, char *argv[])
{
	printf("Program starts\n");


	struct Stack *st = createEmptyStack();
	showStackElements(st);
	struct Element el=
	{
		.x=10
	};

	struct Element *add = &el;

	push(st, add);
	struct Element *x = pop(st);

	showStackElements(st);

	return 0;
}
