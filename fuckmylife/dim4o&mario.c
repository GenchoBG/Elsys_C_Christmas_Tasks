#include <stdio.h>

int main(int argc, char const *argv[])
{
	int bottles_count;
	scanf("%d", &bottles_count);
	int bottles[bottles_count];
	for (int i = 0; i < bottles_count; ++i)
	{
		scanf("%d", &bottles[i]);
	}

	int optimal_selling_order[bottles_count];
	int winnings = 0;
	int start = 0; // start index
	int end = bottles_count - 1; // end index
	for (int year = 1; year <= bottles_count; ++year)
	{
		int smaller;
		if (bottles[start] > bottles[end])
		{
			smaller = bottles[end];
			optimal_selling_order[year - 1] = end;
			end--;
		}
		else
		{
			smaller = bottles[start];
			optimal_selling_order[year - 1] = start;
			start++;
		}

		winnings += year*smaller;
	}

	printf("Optimal selling order: ");
	for (int i = 0; i < bottles_count; ++i)
	{
		printf("%d ", optimal_selling_order[i]);
	}
	printf("\n");
	printf("Winnings : %d\n", winnings);
	return 0;
}