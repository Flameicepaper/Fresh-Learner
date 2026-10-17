#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main()
{   
    srand(time(NULL));
    int seconds = rand()%5+1;
    
	while (seconds > 0)
	{
		printf("µπº∆ ±%d√Î£°\n", seconds);
		Sleep(1000);
		seconds = seconds - 1;
	}
	if (seconds == 0)
	printf("Ω· ¯£°\n");
	return 0;
}
