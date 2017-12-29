#include <stdio.h>
#include <string.h>

int to_integer(char*);

int main(int argc, char const *argv[])
{
	int sum = 0;
	for (int i = 1; i < argc; ++i)
	{
		sum += to_integer((char*)argv[i]);
	}
	printf("%d\n", sum);
	return 0;
}

int to_integer(char* str)
{
	int num = 0;
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		int digit = str[i] - '0';
		num = 10*num + digit;
	}
	return num;
}