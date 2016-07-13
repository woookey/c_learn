#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"
#include <assert.h>


int Monster_attack(void *self, int damage)
{
	assert(self != NULL);
	assert(damage >= 0);

	Monster *monster = self;

	printf("You attack %s!\n", monster->proto.description);

	monster->hit_points -= damage;

	if(monster->hit_points > 0)
	{
		printf("It is still alive.\n");
		return 0;
	}
	else
	{
		printf("It is dead.\n");
		return 1;
	}
}

int Monster_init(void *self)
{
	assert(self != NULL);

	Monster *monster = self;
	monster->hit_points = 10;
	return 1;
}

Object MonsterProto =
{
	.init = Monster_init,
	.attack = Monster_attack
};

void *Room_move(void *self, Direction direction)
{
	assert(self != NULL);
	assert(direction >=0 && direction < NO_DIRECTIONS);

	Room *room = self;
	Room *next = NULL;

	if(direction == NORTH && room->north)
	{
		printf("You go north, into:\n");
		next = room->north;
	}
	else if(direction == SOUTH && room->south)
	{
		printf("You go south, into:\n");
		next = room->south;
	}
	else if(direction == EAST && room->east)
	{
		printf("You go east, into:\n");
		next = room->east;
	}
	else if(direction == WEST && room->west)
	{
		printf("You go west, into:\n");
		next = room->west;
	}
	else
	{
		printf("You can't go that direction.\n");
		next = NULL;
	}

	if(next)
	{
		next->proto.describe(next);
	}

	return next;
}

int Room_attack(void *self, int damage)
{
	Room *room = self;
	Monster *monster = room->bad_guy;

	if(monster)
	{
		monster->proto.attack(monster, damage);
		return 1;
	}
	else
	{
		printf("You flail in the air at nothing. Idiot.\n");
		return 0;
	}
}

Object RoomProto =
{
	.move = Room_move,
	.attack = Room_attack
};

void *Map_move(void *self, Direction direction)
{
	Map *map = self;
	Room *location = map->location;
	Room *next = NULL;

	next = location->proto.move(location, direction);

	if(next)
	{
		map->location = next;
	}

	return next;
}

int Map_attack(void *self, int damage)
{
	Map* map = self;
	Room *location = map->location;

	return location->proto.attack(location, damage);
}

int Map_init(void *self)
{
	Map *map = self;

	// make some rooms for a small map
	//Room *hall = NEW(Room, "The great Hall");
	Room *hall = Object_new(sizeof(Room), RoomProto, "The throne room");
	//Room *throne = NEW(Room, "The throne room");
	Room *throne = Object_new(sizeof(Room), RoomProto, "The throne room");
	//Room *arena = NEW(Room, "The arena, with the minotaur");
	Room *arena = Object_new(sizeof(Room), RoomProto, "The arena with minotaur");
	//Room *kitchen = NEW(Room, "Kitchen, you have the knife");
	Room *kitchen = Object_new(sizeof(Room), RoomProto, "Kitchen, you have the knife");

	//put the bad guy in the arena
	//arena->bad_guy = NEW(Monster, "the evil minotaur");
	arena->bad_guy = Object_new(sizeof(Monster), MonsterProto, "The evil minotaur");

	// setup the map rooms
	hall->north = throne;

	throne->west = arena;
	throne->east = kitchen;
	throne->south = hall;

	arena->east = throne;
	kitchen->west = throne;

	// start the map and the cahracter off in the hall
	map->start = hall;
	map->location = hall;

	return 1;
}

Object MapProto = 
{
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};

int process_input(Map *game)
{
	printf("\n> ");

	char ch = getchar();
	getchar(); //eat ENTER

	int damage = rand() % 4;
	//int damage = -2;
	switch(ch)
	{
		case -1:
		{
			printf("Giving up? You suck.\n");
			return 0;
			break;
		}

		case 'n':
		{
			game->proto.move(game, NORTH);
			break;
		}

		case 's':
		{
			game->proto.move(game, SOUTH);
		}

		case 'e':
		{
			game->proto.move(game, EAST);
			break;
		}

		case 'w':
		{
			game->proto.move(game, WEST);
			break;
		}

		case 'a':
		{
			game->proto.attack(game, damage);
			break;
		}

		case 'l':
		{
			printf("You can go:\n");
			if(game->location->north) printf("NORTH\n");
			if(game->location->south) printf("SOUTH\n");
			if(game->location->east)  printf("EAST\n");
			if(game->location->west)  printf("WEST\n");
			break;
		}

		default:
			printf("What?: %d\n", ch);
	}

	return 1;
}

int main(int argc, char *argv[])
{
	// simple way to setup the randomness
	srand(time(NULL));

	// make our map to work with
	//Map *game = NEW(Map, "The Hall of the Minotaur");
	Map *game = Object_new(sizeof(Map), MapProto, "The Hall of Minotaur");
	printf("You enter the ");
	game->location->proto.describe(game->location);

	while(process_input(game))
	{
		// process the game
	}

	return 0;
}
