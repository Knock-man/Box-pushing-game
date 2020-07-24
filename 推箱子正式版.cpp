/***************************************************************************************
     项目:小游戏推箱子

     修改日期：2019年11月24日

     作者：knock-man

     工具：vc6.0  EasyX_2018;

     范围：C语句  图形库

     图片路径：相对路径

	操作说明：上：↑/W     下：↓/S    左:←/A  右:→/D

*************************************************************************************/
 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>//图形库头文件
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
void GameInit();
void mape();
void playgeme();
void gotoxy(int x,int y);//清屏函数
IMAGE backImg,wallImg,blankImg,boxImg,darkImg,endImg,peoImg;//图片定义类型
int map[13][14]={
	{0,0,0,0,1,1,1,1,1,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0},
	{0,1,1,1,1,0,0,4,0,1,1,1,1,1},
	{0,1,0,0,0,1,0,0,0,1,0,0,0,1},
	{0,1,0,4,0,0,0,4,0,0,0,4,0,1},
	{0,1,0,0,0,1,1,0,1,1,1,1,1,1},
	{1,1,1,1,0,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,4,0,1,0,0,0,5,0,0,1},
	{1,0,0,0,0,0,1,0,1,1,1,1,1,1},
	{1,1,4,0,4,0,1,0,1,3,3,3,1,0},
	{0,1,0,1,1,0,0,0,0,0,3,3,1,0},
	{0,1,0,0,0,0,1,0,0,0,3,3,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	};//地图

int main()
{ 
	initgraph(650,700);//设置图形库大小
	GameInit();
	while(1)
	{
	mape();
    playgeme();
	}
	return 0;
}

void gotoxy(int x,int y)//清屏函数
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}

void GameInit()//载入图片函数
{
    mciSendString("open.//images//Approaching Nirvana - You.mp3 alias bgm",0,0,0);
	mciSendString("play bgm repeat",0,0,0);
	loadimage(&backImg,".//images//背景.JPG",800,800);//相对地址载入图片
	loadimage(&wallImg,".//images//墙壁.JPG",50,50);
	loadimage(&blankImg,".//images//空地.JPG",50,50);
	loadimage(&boxImg,".//images//箱子.JPG",50,50);
	loadimage(&peoImg,".//images//人.JPG",50,50);
	loadimage(&endImg,".//images//目的地.JPG",50,50);
    
}
void mape()//绘制地图函数
{
    BeginBatchDraw();
    putimage(0,0,&backImg);
	int i,j;
	for(i=0;i<13;i++)
	{
		for(j=0;j<14;j++)
		{
			switch(map[i][j])
			{
				case 0:putimage(i*50,j*50,&blankImg);break;
				case 1:putimage(i*50,j*50,&wallImg);break;
				case 3:putimage(i*50,j*50,&endImg);break;
				case 4:putimage(i*50,j*50,&boxImg);break;
				case 5:putimage(i*50,j*50,&peoImg);break;
				case 8:putimage(i*50,j*50,&peoImg);break;//人在目的地
				case 7:putimage(i*50,j*50,&boxImg);break;//箱子在目的地
			}
		}
		printf("\n");
	}EndBatchDraw();


	
}
void playgeme()//键盘操作函数
{
	char ch;
	int i,j;
	for(i=0;i<13;i++)//定义人的位置
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
	ch=getch();//接受键盘信息
	switch(ch)
	{
	case 'W':
	case 'w':
	case 72:
	if(map[i][j-1]==0||map[i][j-1]==3)//下一个地方是空地或者目的地
		{
			
			map[i][j-1]+=5;
			map[i][j]-=5;
			
		}
		else if((map[i][j-1]==4||map[i][j-1]==7)&&(map[i][j-2]!=1)&&(map[i][j-2]!=4))//下一地方是箱子，但下下个地方不是箱子或者墙壁
		{
		
			map[i][j-2]+=4;
			map[i][j-1]+=1;
			map[i][j]-=5;
			
		
		}
		break;
	case 'S':
	case 's':
	case 80:
		if(map[i][j+1]==0||map[i][j+1]==3)//下一个地方是空地或者目的地
		{
			
			map[i][j+1]+=5;
			map[i][j]-=5;
		}
		else if((map[i][j+1]==4||map[i][j+1]==7)&&(map[i][j+2]!=1)&&(map[i][j+2]!=4))//下一地方是箱子，但下下个地方不是箱子或者墙壁
		{
		
			map[i][j+2]+=4;
			map[i][j+1]+=1;
			map[i][j]-=5;
		
		}
		break;
	case 'A':
	case 'a':
	case 75:
	if(map[i-1][j]==0||map[i-1][j]==3)//下一个地方是空地或者目的地
		{
		
			map[i-1][j]+=5;
			map[i][j]-=5;
			
		}
		else if((map[i-1][j]==4||map[i-1][j]==7)&&(map[i-2][j]!=1)&&(map[i-2][j]!=4))//下一地方是箱子，但下下个地方不是箱子或者墙壁
		{
		
			map[i-2][j]+=4;
			map[i-1][j]+=1;
			map[i][j]-=5;
		
		}
		break;
	case 'd':
	case 'D':
	case 77:
	if(map[i+1][j]==0||map[i+1][j]==3)//下一个地方是空地或者目的地
		{
		
			map[i+1][j]+=5;
			map[i][j]-=5;
			
		}
		else if((map[i+1][j]==4||map[i+1][j]==7)&&(map[i+2][j]!=1)&&(map[i+2][j]!=4))//下一地方是箱子，但下下个地方不是箱子或者墙壁
		{	
		     	map[i+2][j]+=4;
		    	map[i+1][j]+=1;
		    	map[i][j]-=5;
		}
		break;

}
}
