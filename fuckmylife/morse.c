#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	//https://cboard.cprogramming.com/c-programming/72485-ive-written-simple-code-convert-text-morse-need-some-advise.html
	//този масив е копиран от тук и буквите са изтрити
	char morse_code[][26] = {
        ".-",       /* A*/
        "-...",     /* B*/
        "-.-.",     /* C*/
        "-..",      /* D*/
        ".",        /* E*/
        "..-.",     /* F*/
        "--.",      /* G*/
        "....",     /* H*/
        "..",       /* I*/
        ".---",     /* J*/
        "-.-",      /* K*/
        ".-..",     /* L*/
        "--",       /* M*/
        "-.",       /* N*/
        "---",      /* O*/
        ".--.",     /* P*/
        "--.-",     /* Q*/
        ".-.",      /* R*/
        "...",      /* S*/
        "-",        /* T*/
        "..-",      /* U*/
        "...-",     /* V*/
        ".--",      /* W*/
        "-..-",     /* X*/
        "-.--",     /* Y*/
        "--..",     /* Z*/
    };

    for (int i = 1; i < argc; ++i)
    {
    	int len = strlen(argv[i]);

    	for (int j = 0; j < len; ++j)
    	{
    		char current = argv[i][j];
    		int index;
    		if (current >= 'a' && current <= 'z')
    		{
    			index = current - 'a';
    			
    		}
    		else if (current >= 'A' && current <= 'Z')
    		{
    			index = current - 'A';
    		}
    		printf("%s\n", morse_code[index]);
    	}

    	printf("\n");
    }
}