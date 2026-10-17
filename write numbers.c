#include <stdio.h>

int readint()
{
	int x = 0, ch, f = 1;
	ch = getchar();
	
	while (ch < '0'||ch > '9')
	{
		if (ch==EOF)
	    {
		return EOF;
	    }
	
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	
	while (ch >= '0'&&ch <= '9')
	{
		x=x*10 + (ch-'0');
		ch = getchar();
	}
	
	return x*f;
}

int main()
{
	int x , y;
    x = readint();
    y = readint();
    printf("你打出的数字是%d和%d\n",x,y);
	return 0;
}

