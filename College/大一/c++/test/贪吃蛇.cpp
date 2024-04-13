#define _CRT_SECURE_NO_WARNINGS    
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>	
using namespace std;
//设置控制台光标 
void gotoxy(int x,int y);
//介绍 
void instruction();
//欢迎 
void Welcome();
//绘制地图
void creat_map();
//运行游戏 
void RunGame();
//初始化蛇
void InitSnake();
//创造食物
void CreatFoods();
//移动蛇 
void MoveSnake(int direction);
//蛇是否咬到自己
int HitSelf();
//蛇撞墙 
int cantcrosswall();

//蛇本身
typedef struct Snake
{
	int x;
	int y;
	struct Snake* next;	
}snake; 

int        g_score;    //分数 
int        g_speed;    //速度 
int        kk=77;
snake*     q;          //遍历蛇 
snake*     food;       //食物         
snake*     g_psnake;   //蛇头 

//设置控制台光标 
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//初始化蛇
void InitSnake()
{
	//蛇头 
	g_psnake=(snake*)malloc(sizeof(snake));
	g_psnake->x=26;
	g_psnake->y=12;
	g_psnake->next=NULL;
	
	for(int i=1;i<=3;i++)
	{
		snake * p=(snake*)malloc(sizeof(snake));
	    p->x=26+2*i;
	    p->y=12;
	    p->next=NULL;
	    
	    //尾插法
        p->next=g_psnake;
        g_psnake=p;
        
	}
	
	//打印蛇
	snake* temp=g_psnake;
	while(temp)
	{
		gotoxy(temp->x,temp->y);
		cout<<"■";
		temp=temp->next;
	} 
 
}

//创造食物
void CreatFoods()
{
	
    srand(time(NULL));  
	snake* food_1=(snake*)malloc(sizeof(snake));
	food_1->x=rand()%77+2;
	while((food_1->x%2)!=0)
	{ 
	    food_1->x=rand()%77+2;
	}
	food_1->y=rand()%24+1;
    q=g_psnake;
	while(q->next==NULL)
	{
        if(q->x==food_1->x && q->y==food_1->y)
        {
        	free(food_1);
        	CreatFoods();
		}
		q=q->next;
	}
	gotoxy(food_1->x,food_1->y);
	food=food_1; 
	cout<<"*";
} 

//移动蛇 
void MoveSnake(int direction)
{
	snake * head=(snake*)malloc(sizeof(snake));
    switch(direction)
	{
		case 72://上
		    if(kk!=80)
			{
		    head->x=g_psnake->x;
		    head->y=g_psnake->y-1;
			}
			break;
	    case 80://下
	        if(kk!=72)
	        {
	        head->x=g_psnake->x;
		    head->y=g_psnake->y+1;
			}
		    break;
		case 75://左 
		    if(kk!=77)
		    {
		    head->x=g_psnake->x-2;
		    head->y=g_psnake->y; 
			}
			break;
		case 77://右 
		    if(kk!=75)
		    {
		    head->x=g_psnake->x+2;
		    head->y=g_psnake->y;
			}
			break; 
	}
	kk=direction;
	//尾插法 
	head->next=g_psnake;
	g_psnake=head;
	
	//打印 
	gotoxy(head->x,head->y);
	cout<<"■";
	
	//去尾  
	snake* p=g_psnake;
	while(p->next->next)
	{
		p=p->next; 
	}
	gotoxy(p->next->x,p->next->y);
	cout<<"  "<<endl;
	p->next=NULL;
}
//蛇撞自身 
int HitSelf()
{
	snake *self=g_psnake->next;
	while(self!=NULL)
	{
		if(self->x==g_psnake->x && self->y==g_psnake->y)
		{
			return 1;
		}
		self=self->next;
	} 
	return 0;
}
//蛇撞墙 
int cantcrosswall()
{
	if(g_psnake->x==0 || g_psnake->x==80 || g_psnake->y==0 || g_psnake->y==26)
	{
		return 1;
	}
	return 0;
} 
//运行游戏 
void RunGame()
{
    char ch=77;//默认向右 
	while(1)
	{
		if(_kbhit())
		{
			getch();
			ch=getch();
		}
		MoveSnake(ch);
		Sleep(500);
	}
}


//绘制地图
void creat_map()
{
	//80*25（长*宽） 
	gotoxy(80,10);
	cout<<"得分: "<<g_score<<endl;
	gotoxy(80,12);
	cout<<"速度: "<<g_speed<<endl;
	gotoxy(80,14);
	cout<<"不要按其他健"<<endl;
	//设置上下地图 
	for(int i=0;i<=70;i+=1)
	{
		gotoxy(i,0);
		cout<<"■";
		gotoxy(i,25);
		cout<<"■";
	}
	//设置左右地图 
	for(int i=0;i<=25;i+=1)
	{
		gotoxy(0,i);
		cout<<"■";
		gotoxy(70,i);
		cout<<"■";
	}

} 

//欢迎 
void Welcome()
{
	
    cout << "*――――――――――――*" << endl;
    cout << "*                        *" << endl;
    cout << "*                        *" << endl;
    cout << "*       1，游戏说明      *" << endl;
    cout << "*       2，开始游戏      *" << endl;
    cout << "*       3，结束游戏      *" << endl;
    cout << "*                        *" << endl;
    cout << "*                        *" << endl;
    cout << "*――――――――――――*" << endl;
    system("pause");
    system("cls");
}

//介绍 
void instruction()
{

	cout << "*********游戏说明如下：***********" << endl;
    cout << "*                                *" << endl;
    cout << "*  使用↑.↓.←.→控制蛇的移动   *" << endl;
    cout << "*  不能咬到自己                  *" << endl;
    cout << "*  不能撞到墙                    *" << endl;
    cout << "*  按到空格键暂停游戏            *" << endl;
    cout << "**********************************" << endl;
    system("pause");
    system("cls");
}
 
int main()
{
	Welcome();
	creat_map();
	InitSnake();
	CreatFoods();
	RunGame();
	return 0;
}
