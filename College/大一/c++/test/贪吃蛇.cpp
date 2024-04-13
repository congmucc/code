#define _CRT_SECURE_NO_WARNINGS    
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>	
using namespace std;
//���ÿ���̨��� 
void gotoxy(int x,int y);
//���� 
void instruction();
//��ӭ 
void Welcome();
//���Ƶ�ͼ
void creat_map();
//������Ϸ 
void RunGame();
//��ʼ����
void InitSnake();
//����ʳ��
void CreatFoods();
//�ƶ��� 
void MoveSnake(int direction);
//���Ƿ�ҧ���Լ�
int HitSelf();
//��ײǽ 
int cantcrosswall();

//�߱���
typedef struct Snake
{
	int x;
	int y;
	struct Snake* next;	
}snake; 

int        g_score;    //���� 
int        g_speed;    //�ٶ� 
int        kk=77;
snake*     q;          //������ 
snake*     food;       //ʳ��         
snake*     g_psnake;   //��ͷ 

//���ÿ���̨��� 
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//��ʼ����
void InitSnake()
{
	//��ͷ 
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
	    
	    //β�巨
        p->next=g_psnake;
        g_psnake=p;
        
	}
	
	//��ӡ��
	snake* temp=g_psnake;
	while(temp)
	{
		gotoxy(temp->x,temp->y);
		cout<<"��";
		temp=temp->next;
	} 
 
}

//����ʳ��
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

//�ƶ��� 
void MoveSnake(int direction)
{
	snake * head=(snake*)malloc(sizeof(snake));
    switch(direction)
	{
		case 72://��
		    if(kk!=80)
			{
		    head->x=g_psnake->x;
		    head->y=g_psnake->y-1;
			}
			break;
	    case 80://��
	        if(kk!=72)
	        {
	        head->x=g_psnake->x;
		    head->y=g_psnake->y+1;
			}
		    break;
		case 75://�� 
		    if(kk!=77)
		    {
		    head->x=g_psnake->x-2;
		    head->y=g_psnake->y; 
			}
			break;
		case 77://�� 
		    if(kk!=75)
		    {
		    head->x=g_psnake->x+2;
		    head->y=g_psnake->y;
			}
			break; 
	}
	kk=direction;
	//β�巨 
	head->next=g_psnake;
	g_psnake=head;
	
	//��ӡ 
	gotoxy(head->x,head->y);
	cout<<"��";
	
	//ȥβ  
	snake* p=g_psnake;
	while(p->next->next)
	{
		p=p->next; 
	}
	gotoxy(p->next->x,p->next->y);
	cout<<"  "<<endl;
	p->next=NULL;
}
//��ײ���� 
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
//��ײǽ 
int cantcrosswall()
{
	if(g_psnake->x==0 || g_psnake->x==80 || g_psnake->y==0 || g_psnake->y==26)
	{
		return 1;
	}
	return 0;
} 
//������Ϸ 
void RunGame()
{
    char ch=77;//Ĭ������ 
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


//���Ƶ�ͼ
void creat_map()
{
	//80*25����*�� 
	gotoxy(80,10);
	cout<<"�÷�: "<<g_score<<endl;
	gotoxy(80,12);
	cout<<"�ٶ�: "<<g_speed<<endl;
	gotoxy(80,14);
	cout<<"��Ҫ��������"<<endl;
	//�������µ�ͼ 
	for(int i=0;i<=70;i+=1)
	{
		gotoxy(i,0);
		cout<<"��";
		gotoxy(i,25);
		cout<<"��";
	}
	//�������ҵ�ͼ 
	for(int i=0;i<=25;i+=1)
	{
		gotoxy(0,i);
		cout<<"��";
		gotoxy(70,i);
		cout<<"��";
	}

} 

//��ӭ 
void Welcome()
{
	
    cout << "*�D�D�D�D�D�D�D�D�D�D�D�D*" << endl;
    cout << "*                        *" << endl;
    cout << "*                        *" << endl;
    cout << "*       1����Ϸ˵��      *" << endl;
    cout << "*       2����ʼ��Ϸ      *" << endl;
    cout << "*       3��������Ϸ      *" << endl;
    cout << "*                        *" << endl;
    cout << "*                        *" << endl;
    cout << "*�D�D�D�D�D�D�D�D�D�D�D�D*" << endl;
    system("pause");
    system("cls");
}

//���� 
void instruction()
{

	cout << "*********��Ϸ˵�����£�***********" << endl;
    cout << "*                                *" << endl;
    cout << "*  ʹ�á�.��.��.�������ߵ��ƶ�   *" << endl;
    cout << "*  ����ҧ���Լ�                  *" << endl;
    cout << "*  ����ײ��ǽ                    *" << endl;
    cout << "*  �����ո����ͣ��Ϸ            *" << endl;
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
