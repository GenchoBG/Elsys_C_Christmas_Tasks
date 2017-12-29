#define DECORATION_COUNT 10

#include <stdio.h>

typedef struct 
{
	char type;
	int size;
} decoration_t;

decoration_t pick_best_ball (decoration_t[DECORATION_COUNT]);

int main(int argc, char const *argv[])
{
	return 0;
}

decoration_t pick_best_ball (decoration_t decorations[DECORATION_COUNT])
{
	for (int i = 0; i < DECORATION_COUNT; ++i)
	{
		if (decorations[i].type == 'B' && decorations[i].size > 5)
		{
			return decorations[i];
		}
	}

	decoration_t some_retarded_value_so_it_doesnt_give_me_an_warning_c_is_trash;
	return some_retarded_value_so_it_doesnt_give_me_an_warning_c_is_trash;
}