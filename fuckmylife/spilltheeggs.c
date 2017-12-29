#include <stdio.h>

void spill(int width, int height, char arr[][width], int x, int y, char substance);

int main(int argc, char const *argv[])
{
	int width, height;
	scanf("%d", &width);
	scanf("%d", &height);
	getchar(); // c is shit and doesn't work unless you use this ;_;

	char arr[height][width];
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			arr[i][j] = getchar();
		}
		getchar(); // the input is retarded and has a space at the end ;_;
	}

	for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (arr[i][j] == 'O' || arr[i][j] == '*')
            {
            	spill(width, height, arr, i + 1, j, arr[i][j]);
            	spill(width, height, arr, i - 1, j, arr[i][j]);
            	spill(width, height, arr, i, j + 1, arr[i][j]);
            	spill(width, height, arr, i, j - 1, arr[i][j]);
            }
        }
    }

	printf("\n");
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

// O - egg
// * - beans
// @ - shit
// . - nothing
// # - wall
void spill(int width, int height, char arr[][width], int x, int y, char substance)
{
    if (x < 0 || y < 0 || x >= height || y >= width || arr[x][y] == '#' || arr[x][y] == substance)
    {
        return;
    }

    if ((arr[x][y] == 'O' && substance == '*') || (arr[x][y] == '*' && substance == 'O'))
    {
        spill(width, height,, x, y, '@');
        return;
    }

    if (arr[x][y] != '@')
    {
        arr[x][y] = substance;
    }
    else
    {
        return;
    }

    spill(width, height, arr, x + 1, y, substance);
    spill(width, height, arr, x - 1, y, substance);
    spill(width, height, arr, x, y + 1, substance);
    spill(width, height, arr, x, y - 1, substance);
}