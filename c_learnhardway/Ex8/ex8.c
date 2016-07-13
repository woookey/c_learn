#include <stdio.h>

int main( int argc, char* argv[] )
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Lukasz";
	char full_name[] = {'L', 'u', 'k', 'a', 's', 'z', ' ', 'B', 'a', 'r', 'c', 'z', 'y', 'k'};

	printf("Size of int: %ld\n", sizeof(int));
	printf("Size of areas ( int[] ): %ld\n", sizeof(areas));
	printf("Number of ints in areas: %ld\n", sizeof(areas)/sizeof(int));
	printf("The first area is %d, the 2nd %d\n\n", areas[0], areas[1]);

	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name ( char[] ): %ld\n", sizeof(name));
	printf("The number of chars: %ld\n\n", sizeof(name)/sizeof(char));

	printf("The size of full_name ( char[] ): %ld\n", sizeof(full_name));
	printf("The numbers of chars: %ld\n", sizeof(full_name)/sizeof(char));
	printf("The first letter %d, the 2nd %d\n\n", full_name[0], full_name[1]);

	printf("Name: \"%s\", Full name: \"%s\".\n", name, full_name);

	return 0;
}
