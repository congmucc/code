#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <stdlib.h>
#include<time.h>	
#include<iostream>
using namespace std;


#define U 1
#define D 2
#define L 3 
#define R 4      //�ߵ�״̬��U���� ��D���£�L:�� R����

//���ÿ���̨��� 
void gotoxy(int x, int y);
//���� 
void instruction();
//��ӭ 
void Welcome();
//���Ƶ�ͼ
void creat_map();
//��ȡ�����ź�
void KeyboardControl();
//����ʳ��
void CreateFoods();
//��Ϸ����
void GameOver();
//��Ϸ����
void Speedup();
//��Ϸ����
void SpeedDown();
//��ʼ����
void InitSnake();
//�ƶ���
void MoveSnake();


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
int        score=0;      //�÷�
int        status; 
int        sleeptime=200;  //��Ϸ������ߵ��ƶ��ٶȣ�
snake*     q;          //������ 
snake*     food;       //ʳ��         
snake*     g_psnake;   //��

//���ÿ���̨��� 
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//��ʼ����
void InitSnake()
{
	snake* g_psnake= (snake*)malloc(sizeof(snake));
	g_psnake->x = 26;
	g_psnake->y = 12;
	g_psnake->next = NULL;
	for (int i = 1; i <= 3; i++)
	{
		snake* p= (snake*)malloc(sizeof(snake));
		p->x = 26 + 2 * i;
		p->y = 12;
		p->next = NULL;
		//ͷ�巨
		p->next = g_psnake->next;
		g_psnake->next = p;
	}
	//��ӡ��
	snake* temp = g_psnake;
	while (temp)
	{
		gotoxy(temp->x, temp->y);
		cout << "��";
		temp = temp->next;
	}

}

//����ʳ��
void CreateFoods()
{

	srand(time(NULL));
	snake* food_1 = (snake*)malloc(sizeof(snake));
	food_1->x = rand() % 77 + 2;
	while ((food_1->x % 2) != 0)
	{
		food_1->x = rand() % 77 + 2;
	}
	food_1->y = rand() % 24 + 1;
	q = g_psnake;
	while (q->next == NULL)
	{
		if (q->x == food_1->x && q->y == food_1->y)
		{
			free(food_1);
			CreateFoods();
		}
		q = q->next;
	}
	gotoxy(food_1->x, food_1->y);
	food = food_1;
	cout << "*";
}

//��Ϸ����
void GameOver()
{
	system("cls");
	printf("GAME OVER!");
	gotoxy(40,9);
	printf("��ĵ÷��ǣ�%d", score);
}

//��Ϸ����
void Speedup()
{
	if (sleeptime >=50)
	{
		sleeptime = sleeptime - 10;
	}
}

//��Ϸ����
void SpeedDown()
{
	if (sleeptime <= 200)
	{
		sleeptime = sleeptime + 10;
	}
}

//��ȡ�����ź�
void KeyboardControl()
{
	status = R;

	while(1)
	{
		if (GetAsyncKeyState(VK_UP) && status != D)
		{
			status = U;
		}
		else if (GetAsyncKeyState(VK_DOWN) && status != U)
		{
			status = D;
		}
		else if (GetAsyncKeyState(VK_LEFT) && status != R)
		{
			status = L;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && status != L)
		{
			status = R;
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			while (1)
			{
				Sleep(300);
				if (GetAsyncKeyState(VK_SPACE))
				{
					break;
				}
			}
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			GameOver();
			break;
		}
		else if (GetAsyncKeyState(VK_F1))
		{
			Speedup();
		}
		Sleep(sleeptime);
		MoveSnake();
	}
	gotoxy(30, 57);
	system("pause");
}

//�ƶ���
void MoveSnake()
{
	snake* nexthead;
	cantcrosswall();
	nexthead = (snake*)malloc(sizeof(snake));
	if (status == U)
	{
		nexthead->x = g_psnake->x;
		nexthead->y = g_psnake->y-1;
		//ͷ�巨
		nexthead->next= g_psnake->next;
		g_psnake->next = nexthead;
		q = g_psnake;             //������
		if (nexthead->x == food->x && nexthead->y == food->y)//�Ե�ʳ��
		{
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score = score + 1;
			Speedup();
			CreateFoods();
		}
		else
		{
			while (q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				printf("��");
				free(q->next);
				q->next = NULL;
			}
			gotoxy(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}
	if (status==D)
	{
		nexthead->x = g_psnake->x;
		nexthead->y = g_psnake->y + 1;
		//ͷ�巨
		nexthead->next = g_psnake->next;
		g_psnake->next = nexthead;
		q = g_psnake;
		if (nexthead->x == food->x && nexthead->y == food->y)
		{
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score = score + 1;
			Speedup();
			CreateFoods();
		}
		else
		{
			while (q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				printf("��");
				free(q->next);
				q->next = NULL;
			}
			gotoxy(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}
	if (status == L)
	{
		nexthead->x = g_psnake->x - 2;
		nexthead->y = g_psnake->y;
		//ͷ�巨
		nexthead->next = g_psnake->next;
		g_psnake->next = nexthead;
		q = g_psnake;             //������
		if (nexthead->x == food->x && nexthead->y == food->y)//�Ե�ʳ��
		{
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score = score + 1;
			Speedup();
			CreateFoods();
		}
		else
		{
			while (q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				printf("��");
				free(q->next);
				q->next = NULL;
			}
			gotoxy(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}
	if (status == R)
	{
		nexthead->x = g_psnake->x + 2;
		nexthead->y = g_psnake->y;
		//ͷ�巨
		nexthead->next = g_psnake->next;
		g_psnake->next = nexthead;
		q = g_psnake;             //������
		if (nexthead->x == food->x && nexthead->y == food->y)//�Ե�ʳ��
		{
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("��");
				q = q->next;
			}
			score = score + 1;
			Speedup();
			CreateFoods();
		}
		else
		{
			while (q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				printf("��");
				free(q->next);
				q->next = NULL;
			}
			gotoxy(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}
    if (HitSelf() == 1 || cantcrosswall() == 1)       //�ж��Ƿ��ҧ���Լ�
    {
	    GameOver();
	}

}
//���Ƿ�ҧ���Լ�
int HitSelf()
{
	snake* self = g_psnake->next;
	while (self != NULL)
	{
		if (self->x == g_psnake->x && self->y == g_psnake->y)
		{
			return 1;
			GameOver();
		}
		self = self->next;
	}
	return 0;
}
//��ײǽ 
int cantcrosswall()
{
	if (g_psnake->x == 0 || g_psnake->x == 80 || g_psnake->y == 0 || g_psnake->y == 26)
	{
		return 1;
		GameOver();
	}
	return 0;
}



//���Ƶ�ͼ
void creat_map()
{
	//80*25����*�� 
	gotoxy(80, 10);
	cout << "�÷�: " << g_score << endl;
	gotoxy(80, 12);
	cout << "�ٶ�: " << g_speed << endl;
	gotoxy(80, 14);
	cout << "��Ҫ��������" << endl;
	//�������µ�ͼ 
	for (int i = 0; i <= 70; i += 1)
	{
		gotoxy(i, 0);
		cout << "��";
		gotoxy(i, 25);
		cout << "��";
	}
	//�������ҵ�ͼ 
	for (int i = 0; i <= 25; i += 1)
	{
		gotoxy(0, i);
		cout << "��";
		gotoxy(70, i);
		cout << "��";
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

int main()
{
	Welcome();
	creat_map();
	InitSnake();
	CreateFoods();
	KeyboardControl();
	MoveSnake();
	return 0;
}
