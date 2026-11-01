#include <stdio.h>
#include <stdlib.h>     //为了使用system清屏 
#include <conio.h>	    //控制台输入输出，为了使用_kbhit和_getch 
#include <windows.h>	//为了使用Sleep函数 
#include <time.h>	    //设置时间数 

#define WIDTH 20
#define HEIGHT 15

int map[HEIGHT][WIDTH];
int snake_x[100],snake_y[100];
int snake_length = 3;
int dir = 4;    //按上1，然后逆时针走，4是右边
int food_x,food_y;
int score = 0;

//移动光标 
void gotoxy(int x, int y)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//隐藏光标 
void hideCursor()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(h, &info);
    info.bVisible = FALSE;
    SetConsoleCursorInfo(h, &info);
}

//画地图 
void init()
{
	for (int i=0;i<15;i++)
	{
		for (int j=0;j<20;j++)
		{
			if(i==0||i==14||j==0||j==19)
			{
				map[i][j]=1;    //墙 
			}
			else
			{
				map[i][j]=0;    //空地 
			}
		}
	}
}

//添加游戏对象 
void draw()
{
	gotoxy(0,0);
	printf("你的得分：%-3d\n",score);
	
	map[food_y][food_x]=3;    //食物 
	map[snake_y[0]][snake_x[0]]=9;    //蛇头 

	for (int i=1;i<snake_length;i++)
	{
		map[snake_y[i]][snake_x[i]]=2;    //蛇身 
	}

	for (int i=0;i<15;i++)	//打印部分 
	{
		for (int j=0;j<20;j++)
		{
			switch (map[i][j])
			{
				case 0:printf(" ");break;    //空地 0
				case 1:printf("#");break;    //墙 1
				case 2:printf("o");break;    //蛇身 2
				case 9:printf("@");break;    //蛇头 9 
				case 3:printf("*");break;    //食物 3
			}
		}
		printf("\n");
	}
}

//控制行走
void input()
{
	if(_kbhit())
	{
		char ch = _getch();    //读取键盘按键
		
		if((ch=='w'||ch=='W')&&dir!=3) dir=1;
		else if((ch=='a'||ch=='A')&&dir!=4)dir=2;
		else if((ch=='s'||ch=='S')&&dir!=1)dir=3;
		else if((ch=='d'||ch=='D')&&dir!=2)dir=4;
	}
}

//移动
void move()
{
	switch(dir)
	{
		case 1:for(int i=snake_length-1;i>0;i--)
				{
			    	snake_x[i]=snake_x[i-1];
			    	snake_y[i]=snake_y[i-1];
				}
				snake_y[0]-=1;break;
				   
		case 2:for(int i=snake_length-1;i>0;i--)
				{
			    	snake_x[i]=snake_x[i-1];
			    	snake_y[i]=snake_y[i-1];
				}
				snake_x[0]-=1;break;
				   
		case 3:for(int i=snake_length-1;i>0;i--)
				{
			    	snake_x[i]=snake_x[i-1];
			    	snake_y[i]=snake_y[i-1];
				}
				snake_y[0]+=1;break;
				   
		case 4:for(int i=snake_length-1;i>0;i--)
				{
			    	snake_x[i]=snake_x[i-1];
			    	snake_y[i]=snake_y[i-1];
				}
				snake_x[0]+=1;break;
	}
}

//判断死亡 
void died()
{
	if(snake_x[0]==0||snake_y[0]==0||snake_x[0]==19||snake_y[0]==14)
	{
		printf("已死亡！\n");
		exit(0);
	}
	
	for (int i=1;i<snake_length;i++)
	{
		if (snake_y[0]==snake_y[i]&&snake_x[0]==snake_x[i])
		{
			printf("已死亡！\n");
			exit(0);
		}
	}
}

//随机生成食物
void food()
{
	food_x = rand()%18+1;
	food_y = rand()%13+1;
	for (int i=0;i<snake_length;i++)
	{
		if (food_x==snake_x[i]&&food_y==snake_y[i])
		{
			food_x = rand()%18+1;
	        food_y = rand()%13+1;
		}
	}
}

//成长 
void grow()
{
	if (snake_x[0]==food_x&&snake_y[0]==food_y)
	{
		food();
		snake_length += 1;
		snake_x[snake_length-1]=snake_x[snake_length-2];
		snake_y[snake_length-1]=snake_y[snake_length-2];
		score += 5;
	}
} 


//主函数 
int main()
{
	//这里定义了蛇的初始位置 
	snake_x[0]=3; snake_y[0]=7;    //注意：这里的中括号里的数字表示蛇第n+1节 
	snake_x[1]=2; snake_y[1]=7;    //注意：这里默认了行是y轴，列是x轴，原点在左上角！！ 
	snake_x[2]=1; snake_y[2]=7;
	srand(time(NULL));
	food();
	
	while(1)
	{
		hideCursor();
		init();
		input();
		grow();
		move();
		died();
		draw();
	    Sleep(500);
    }
	return 0;
}

