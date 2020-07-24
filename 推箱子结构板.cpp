/***************************************************************************************
     项目:小游戏推箱子

	 描述；推箱子游戏基本框架

     修改日期：2019年11月20日

     作者：肖本杰

     工具：vc6.0  

     范围：C语句

     待解决：闪屏，图形化

*************************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
void mape();
void playgeme();
int map[13][14]={
	{0,0,0,0,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0},
	{0,1,1,1,1,0,0,4,4,1,1,1,1,1},
	{0,1,0,0,0,1,0,0,0,1,0,0,0,1},
	{0,1,0,4,0,0,0,4,0,0,0,4,0,1},
	{0,1,0,0,0,1,1,0,1,1,1,1,1,1},
	{1,1,1,1,4,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,4,0,1,0,0,0,5,0,0,1},
	{1,0,4,0,4,0,1,0,1,1,1,1,1,1},
	{1,1,0,0,4,0,1,0,1,3,3,3,1,0},
	{0,1,0,1,1,0,0,0,0,3,3,3,1,0},
	{0,1,0,0,0,0,1,1,3,3,3,3,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	};
int main()
{
	while(1)
	{
     system("CLS");
	mape();
	playgeme();
	}
	return 0;
}
void mape()
{

	int i,j;
	for(i=0;i<13;i++)
	{
		for(j=0;j<14;j++)
		{
			switch(map[i][j])
			{
				case 0:printf("  ");break;
				case 1:printf("■");break;
				case 3:printf("☆");break;
				case 4:printf("□");break;
				case 5:printf("♀");break;
				case 8:printf("♀");break;//人在目的地
				case 7:printf("□");break;//箱子在目的地
			}
		}
		printf("\n");
	}

	
}
void playgeme()
{
	char ch;
	int i,j;
	for(i=0;i<13;i++)
	{
		for(j=0;j<14;j++)
		{
			if(map[i][j]==5||map[i][j]==8)
				break;
		}
	 if(map[i][j]==5||map[i][j]==8)
				break;
	}
	printf("%d  %d",i,j);
	ch=getch();
	switch(ch)
	{
	case 'W':
	case 'w':
		if(map[i-1][j]==0||map[i-1][j]==3)//下一个地方是空地或者目的地
		{
		
			map[i-1][j]+=5;
			map[i][j]-=5;
			
		}
		else if((map[i-1][j]==4||map[i-1][j]==7)&&(map[i-2][j]!=1)&&(map[i-2][j]!=4))
		{
		
			map[i-2][j]+=4;
			map[i-1][j]+=1;
			map[i][j]-=5;
		
		}
		break;
	case 'S':
	case 's':
		if(map[i+1][j]==0||map[i+1][j]==3)//下一个地方是空地或者目的地
		{
		
			map[i+1][j]+=5;
			map[i][j]-=5;
			
		}
		else if((map[i+1][j]==4||map[i+1][j]==7)&&(map[i+2][j]!=1)&&(map[i+2][j]!=4))
		{	
		     	map[i+2][j]+=4;
		    	map[i+1][j]+=1;
		    	map[i][j]-=5;
		}
		break;
	case 'A':
	case 'a':
		if(map[i][j-1]==0||map[i][j-1]==3)//下一个地方是空地或者目的地
		{
			
			map[i][j-1]+=5;
			map[i][j]-=5;
			
		}
		else if((map[i][j-1]==4||map[i][j-1]==7)&&(map[i][j-2]!=1)&&(map[j-2][j]!=4))
		{
		
			map[i][j-2]+=4;
			map[i][j-1]+=1;
			map[i][j]-=5;
			
		
		}
		break;
	case 'd':
	case 'D':
		if(map[i][j+1]==0||map[i][j+1]==3)//下一个地方是空地或者目的地
		{
			
			map[i][j+1]+=5;
			map[i][j]-=5;
		}
		else if((map[i][j+1]==4||map[i][j+1]==7)&&(map[i][j+2]!=1)&&(map[i][j+2]!=4))
		{
		
			map[i][j+2]+=4;
			map[i][j+1]+=1;
			map[i][j]-=5;
		
		}
		break;
}
}