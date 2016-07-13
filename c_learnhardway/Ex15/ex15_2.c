
#include <stdio.h>

int getNoOfItems(char *array);

int main(int argc, char* argv[])
{

	int int_items = 3;
	int a_1 = 20;
	int a_2 = 30;
	int a_3 = 40;
	int a[] = {12, 13, 15, 29};
	char b[] = {'l', 'u', 'k', 'a', 's', 'z'};

	int *pt = &a_1;
	printf("a_1 = %d \n", *pt);
	pt = &a_2;
	printf("a_2 = %d \n", *pt);
	pt = &a_3;
	printf("a_3 = %d \n", *pt);

	printf("Number of items in b[] = %d\n", getNoOfItems(b));

	return 0;
}

int getNoOfItems(char *array)
{
	char *ptr = array;
	int count = 0;
	while(*(ptr+count)!='\0')
		count++;

	return count;
}
