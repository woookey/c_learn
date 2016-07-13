#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
	//char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create( int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	//who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	//free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	//printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main( int argc, char* argv[] )
{
	/**
	 Make two people structures
	*/
	struct Person *joe = Person_create(32, 64, 140);
	struct Person *frank = Person_create(20, 72, 180);
	struct Person *mrNobody = malloc(sizeof(struct Person));
//	free(mrNobody);
	/**
	 Print them out and where they are in memory
	*/
	printf("Size of Person structure: %ld\n\n", sizeof(struct Person));
	printf("Joe is at momeory location %p: \n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p: \n", frank);
	Person_print(frank);

	joe->age -= 12;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->height +=12;
	frank->weight -=30;
	Person_print(frank);

	Person_destroy(frank);
	Person_destroy(joe);
	//Person_destroy(NULL);

	return 0;
}
