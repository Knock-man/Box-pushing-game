/***************************************************************************************
     ��Ŀ:С��Ϸ������

     �޸����ڣ�2019��11��24��

     ���ߣ�knock-man

     ���ߣ�vc6.0  EasyX_2018;

     ��Χ��C���  ͼ�ο�

     ͼƬ·�������·��

	����˵�����ϣ���/W     �£���/S    ��:��/A  ��:��/D

*************************************************************************************/
 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>//ͼ�ο�ͷ�ļ�
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
void GameInit();
void mape();
void playgeme();
void gotoxy(int x,int y);//��������
IMAGE backImg,wallImg,blankImg,boxImg,darkImg,endImg,peoImg;//ͼƬ��������
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
	};//��ͼ

int main()
{ 
	initgraph(650,700);//����ͼ�ο��С
	GameInit();
	while(1)
	{
	mape();
    playgeme();
	}
	return 0;
}

void gotoxy(int x,int y)//��������
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}

void GameInit()//����ͼƬ����
{
    mciSendString("open.//images//Approaching Nirvana - You.mp3 alias bgm",0,0,0);
	mciSendString("play bgm repeat",0,0,0);
	loadimage(&backImg,".//images//����.JPG",800,800);//��Ե�ַ����ͼƬ
	loadimage(&wallImg,".//images//ǽ��.JPG",50,50);
	loadimage(&blankImg,".//images//�յ�.JPG",50,50);
	loadimage(&boxImg,".//images//����.JPG",50,50);
	loadimage(&peoImg,".//images//��.JPG",50,50);
	loadimage(&endImg,".//images//Ŀ�ĵ�.JPG",50,50);
    
}
void mape()//���Ƶ�ͼ����
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
				case 8:putimage(i*50,j*50,&peoImg);break;//����Ŀ�ĵ�
				case 7:putimage(i*50,j*50,&boxImg);break;//������Ŀ�ĵ�
			}
		}
		printf("\n");
	}EndBatchDraw();


	
}
void playgeme()//���̲�������
{
	char ch;
	int i,j;
	for(i=0;i<13;i++)//�����˵�λ��
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
	ch=getch();//���ܼ�����Ϣ
	switch(ch)
	{
	case 'W':
	case 'w':
	case 72:
	if(map[i][j-1]==0||map[i][j-1]==3)//��һ���ط��ǿյػ���Ŀ�ĵ�
		{
			
			map[i][j-1]+=5;
			map[i][j]-=5;
			
		}
		else if((map[i][j-1]==4||map[i][j-1]==7)&&(map[i][j-2]!=1)&&(map[i][j-2]!=4))//��һ�ط������ӣ������¸��ط��������ӻ���ǽ��
		{
		
			map[i][j-2]+=4;
			map[i][j-1]+=1;
			map[i][j]-=5;
			
		
		}
		break;
	case 'S':
	case 's':
	case 80:
		if(map[i][j+1]==0||map[i][j+1]==3)//��һ���ط��ǿյػ���Ŀ�ĵ�
		{
			
			map[i][j+1]+=5;
			map[i][j]-=5;
		}
		else if((map[i][j+1]==4||map[i][j+1]==7)&&(map[i][j+2]!=1)&&(map[i][j+2]!=4))//��һ�ط������ӣ������¸��ط��������ӻ���ǽ��
		{
		
			map[i][j+2]+=4;
			map[i][j+1]+=1;
			map[i][j]-=5;
		
		}
		break;
	case 'A':
	case 'a':
	case 75:
	if(map[i-1][j]==0||map[i-1][j]==3)//��һ���ط��ǿյػ���Ŀ�ĵ�
		{
		
			map[i-1][j]+=5;
			map[i][j]-=5;
			
		}
		else if((map[i-1][j]==4||map[i-1][j]==7)&&(map[i-2][j]!=1)&&(map[i-2][j]!=4))//��һ�ط������ӣ������¸��ط��������ӻ���ǽ��
		{
		
			map[i-2][j]+=4;
			map[i-1][j]+=1;
			map[i][j]-=5;
		
		}
		break;
	case 'd':
	case 'D':
	case 77:
	if(map[i+1][j]==0||map[i+1][j]==3)//��һ���ط��ǿյػ���Ŀ�ĵ�
		{
		
			map[i+1][j]+=5;
			map[i][j]-=5;
			
		}
		else if((map[i+1][j]==4||map[i+1][j]==7)&&(map[i+2][j]!=1)&&(map[i+2][j]!=4))//��һ�ط������ӣ������¸��ط��������ӻ���ǽ��
		{	
		     	map[i+2][j]+=4;
		    	map[i+1][j]+=1;
		    	map[i][j]-=5;
		}
		break;

}
}
