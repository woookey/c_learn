#include <stdio.h>

int main ( int argc, char* argv[] )
{
	int i = 0;
	for ( i=1; i<argc; i++)
	{
		printf("Arg( %d ) = %s\n", i, argv[i]);
	}

	char *states[] = {"California", "Oregon", "Nevada", "Vancouver"};

	int num_states = 4;
	for ( i=0; i < num_states; i++ )
	{
		printf("State no.%d = %s\n", (i+1), states[i]);
	}

	return 0;
}
