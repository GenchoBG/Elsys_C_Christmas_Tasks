#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
	int hp;
} hero_t;

typedef struct
{
	int hp;
} head_t;

typedef struct
{
	head_t heads[3];
} dragon_t;

void dragon_attack(hero_t* hero);
void hero_attack(dragon_t* dragon);
void get_game_status(dragon_t dragon, hero_t hero);

int main(int argc, char const *argv[])
{
	srand(time(NULL));  

	head_t first = { 75 };
	head_t second = { 75 };
	head_t third = { 75 };
	dragon_t dragon;
	dragon.heads[0] = first;
	dragon.heads[1] = second;
	dragon.heads[2] = third;
	hero_t hero = { 100 };

	get_game_status(dragon, hero);
	while(1)
	{
		hero_attack(&dragon);
		get_game_status(dragon, hero);
		if (dragon.heads[2].hp <= 0)
		{
			printf("HERO WINS\n");
			break;
		}
		dragon_attack(&hero);
		get_game_status(dragon, hero);
		if (hero.hp <= 0)
		{
			printf("DRAGON WINS\n");
			break;
		}
	}
}

void dragon_attack(hero_t* hero)
{
	int damage = rand() % 10 + 1;
	hero->hp-=damage;
}

void hero_attack(dragon_t* dragon)
{
	int damage = rand() % 30 + 1;
	if (rand() % 7 == 0)
	{
		damage = 50;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (dragon->heads[i].hp>0)
		{
			dragon->heads[i].hp -= damage;
			break;
		}
	}
}

void get_game_status(dragon_t dragon, hero_t hero)
{
	printf("Hero hp: %d Dragon: [Head1: %d, Head2: %d, Head3: %d]\n", hero.hp, dragon.heads[0].hp, dragon.heads[1].hp, dragon.heads[2].hp);
}
