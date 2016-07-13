#include <stdio.h>
#include "Enu.h"

enum sth
{
	sth_zero,
	sth_two
};

int main()
{
	enum sth a = sth_zero;
	enum overshoot x = NO_OVERSHOOT;

	printf("A = %d", a);
	printf("X = %d", (int)x);
	return 0;
}
