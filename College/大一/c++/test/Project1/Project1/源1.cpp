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
#define R 4      //蛇的状态，U：上 ；D：下；L:左 R：右

//设置控制台光标 
void gotoxy(int x, int y);
//介绍 
void instruction();
//欢迎 
void Welcome();
//绘制地图
void creat_map();
//获取键盘信号
void KeyboardControl();
//创造食物
void CreateFoods();
//游戏结束
void GameOver();
//游戏加速
void Speedup();
//游戏减速
void SpeedDown();
//初始化蛇
void InitSnake();
//移动蛇
void MoveSnake();


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
int        score=0;      //得分
int        status; 
int        sleeptime=200;  //游戏间隔（蛇的移动速度）
snake*     q;          //遍历蛇 
snake*     food;       //食物         
snake*     g_psnake;   //蛇

//设置控制台光标 
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//初始化蛇
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
		//头插法
		p->next = g_psnake->next;
		g_psnake->next = p;
	}
	//打印蛇
	snake* temp = g_psnake;
	while (temp)
	{
		gotoxy(temp->x, temp->y);
		cout << "■";
		temp = temp->next;
	}

}

//创造食物
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

//游戏结束
void GameOver()
{
	system("cls");
	printf("GAME OVER!");
	gotoxy(40,9);
	printf("你的得分是：%d", score);
}

//游戏加速
void Speedup()
{
	if (sleeptime >=50)
	{
		sleeptime = sleeptime - 10;
	}
}

//游戏减速
void SpeedDown()
{
	if (sleeptime <= 200)
	{
		sleeptime = sleeptime + 10;
	}
}

//获取键盘信号
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

//移动蛇
void MoveSnake()
{
	snake* nexthead;
	cantcrosswall();
	nexthead = (snake*)malloc(sizeof(snake));
	if (status == U)
	{
		nexthead->x = g_psnake->x;
		nexthead->y = g_psnake->y-1;
		//头插法
		nexthead->next= g_psnake->next;
		g_psnake->next = nexthead;
		q = g_psnake;             //遍历蛇
		if (nexthead->x == food->x && nexthead->y == food->y)//吃到食物
		{
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
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
				printf("■");
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
		//头插法
		nexthead->next = g_psnake->next;
		g_psnake->next = nexthead;
		q = g_psnake;
		if (nexthead->x == food->x && nexthead->y == food->y)
		{
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
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
				printf("■");
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
		//头插法
		nexthead->next = g_psnake->next;
		g_psnake->next = nexthead;
		q = g_psnake;             //遍历蛇
		if (nexthead->x == food->x && nexthead->y == food->y)//吃到食物
		{
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
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
				printf("■");
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
		//头插法
		nexthead->next = g_psnake->next;
		g_psnake->next = nexthead;
		q = g_psnake;             //遍历蛇
		if (nexthead->x == food->x && nexthead->y == food->y)//吃到食物
		{
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
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
				printf("■");
				free(q->next);
				q->next = NULL;
			}
			gotoxy(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}
    if (HitSelf() == 1 || cantcrosswall() == 1)       //判断是否会咬到自己
    {
	    GameOver();
	}

}
//蛇是否咬到自己
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
//蛇撞墙 
int cantcrosswall()
{
	if (g_psnake->x == 0 || g_psnake->x == 80 || g_psnake->y == 0 || g_psnake->y == 26)
	{
		return 1;
		GameOver();
	}
	return 0;
}



//绘制地图
void creat_map()
{
	//80*25（长*宽） 
	gotoxy(80, 10);
	cout << "得分: " << g_score << endl;
	gotoxy(80, 12);
	cout << "速度: " << g_speed << endl;
	gotoxy(80, 14);
	cout << "不要按其他健" << endl;
	//设置上下地图 
	for (int i = 0; i <= 70; i += 1)
	{
		gotoxy(i, 0);
		cout << "■";
		gotoxy(i, 25);
		cout << "■";
	}
	//设置左右地图 
	for (int i = 0; i <= 25; i += 1)
	{
		gotoxy(0, i);
		cout << "■";
		gotoxy(70, i);
		cout << "■";
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
