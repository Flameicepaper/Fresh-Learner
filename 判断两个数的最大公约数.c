#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int min(int x,int y)
	{
		return (x<y)?x:y;
	}
	
	int max(int x,int y)
	{
		return (x<y)?y:x;
	}

int main()
{
	
	
	int m,n,x,y,z;
	if (scanf("%d%d",&m,&n)!=2)
	{
		return 1;
	}
	
	y=max(m,n);
	if ((x=min(m,n))==0)
	{
		printf("%d\n",y);
		return 0;
	}
	
	
	for (;;)
	{
		if(y%x==0)
		{
			break;
		}
		z=y%x;
		y=x;
		x=z;
	}
	printf("%d\n",x);
	return 0;
	
}