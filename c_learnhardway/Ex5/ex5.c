#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 5689.4532;
	char initial = 'L';
	char name[] = "Lukasz";
	char surname[] = "Barczyk";

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("You have an initial %c.\n", initial);
	printf("You have a first name %s.\n", name);
	printf("You have a surname %s.\n", surname);
	printf("\n\nMy whole name is %s %c %s", name, initial, surname);
	return 0;
}
