#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i < argc; i++)
	{
		printf("arg %d: %s, address: %#08x\n", i, argv[i], &argv[i]);
	}

	char *states[] = {"California", "Oregon", "Washington", "Texas"};
	int num_states = 4;

	for (i = 0; i < num_states; i++)
	{
		printf("state %d: %s, address: %#08x\n", i, states[i], &states[i]);
	}


	//Copying

	int max = 0;
	if (argc <= num_states)
	{
		max = argc;
	}
	else
	{
		max = num_states;
	}

	for (i=0; i<max; i++)
	{
		states[i] = argv[i];
	}

	printf("\nAfter copying...\n");
	for (i=0; i<num_states; i++)
	{
		printf("states %d: %s, address: %#08x\n", i, states[i], &states[i]);
	}

	//printing addresses
	
	return 0;
}
