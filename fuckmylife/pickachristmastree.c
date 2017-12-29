#include <stdio.h>

typedef struct
{
	float height;
	float price;
} tree_t;

float calculate_ratio(tree_t tree);
tree_t best_price_for_height (tree_t trees[10]);

int main(int argc, char const *argv[])
{
	return 0;
}

float calculate_ratio(tree_t tree)
{
	return tree.price/(100*tree.height);
}

tree_t best_price_for_height (tree_t trees[10])
{
	tree_t best = trees[0];
	float best_ratio = calculate_ratio(best);
	for (int i = 0; i < 10; ++i)
	{
		float current_ratio = calculate_ratio(trees[i]);
		if (current_ratio < best_ratio)
		{
			 best_ratio = current_ratio;
			 best = trees[i];
		}
	}

	return best;
}