#include <stdio.h>
#include <string.h>
#include <math.h>

int string_compare(char *str1, char *str2);

int main(int argc, char const *argv[])
{
	printf("%d\n", string_compare("asd", "asc"));
	printf("%d\n", string_compare("qwe", "qwt"));
	printf("%d\n", string_compare("asd", "asd"));
	return 0;
}

int string_compare(char *str1, char *str2)
{
	int len = strlen(str1);
	for (int i = 0; i < len; ++i)
	{
		if (str1[i] < str2[i])
		{
			return -1;
		}
		else if(str1[i] > str2[i])
		{
			return 1;
		}
	}

	return 0;
}
