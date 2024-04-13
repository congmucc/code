#include<stdio.h>
#include<stdlib.h>

//迷宫问题

struct path
{
	int x;            //横座标
	int y;  		  //纵座标
	struct path *next;
};

typedef struct Link
{
	struct path *head;
}link;


//模拟为栈
void push(link *que, int x, int y)
{
	struct path *p;
	p = (struct path*)malloc(sizeof(struct path));
	p->x = x;
	p->y = y;
	p->next = que->head;;
	que->head = p;
/*
	que->rear->next = p;
	que->rear = p;
	que->rear->next = NULL;
*/
}

void pop(link *que)
{
	//如果不合适将刚入栈的节点删除
	que->head = que->head->next;
}

/*
void pop2(link *que, int *x, int *y)
{
	struct path *temp;
	temp = que->head->next;
	que->head->next = temp->next;      //将temp结点出队
	*x = temp->x;
	*y = temp->y;
	free(temp);
}
*/

void r(int a[5][5], int x, int y, link *que)
{
	if( x < 5 && x >= 0 && y < 5 && y >= 0)
	{
		if(x == 4 && y == 4)
			return;
		if(a[x][y + 1] == 0 && (y + 1) < 5)
		{
			y++;
			push(que, x, y);
			r(a, x, y, que);
			return;
		}
	    if(a[x + 1][y] == 0 && (x + 1) < 5)
		{
			x++;
			push(que, x, y);
			r(a, x, y, que);
			return;
		}
	    if(a[x - 1][y] == 0 && x - 1 >= 0)
		{
			a[x][y] = 1;
			pop(que);
			x--;
			r(a, x, y, que);
			return;
		}
	    if(a[x][y - 1] == 0 && y - 1 >= 0)
		{
			a[x][y] = 1;
			pop(que);
			y--;
			r(a, x, y, que);
			return;
		}
	}
}

int main(void)
{
	int a[5][5];
	int i, j;
	int x, y;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	link *top, *temp;
	top = temp = (link *)malloc(sizeof(link));
	top->head = (struct path *)malloc(sizeof(struct path));
	r(a, 0, 0, top);
	printf("(0, 0)\n");
	//此处数组是为了存储路径，因为使用的是栈结构，所以存储的路径必然是倒序！
	int PATH[25] = {0};
	int count = 0;

	//将栈倒序的路径存储进数组中，二维数组太占用空间所以此处我们使用一维数组，并使用数学方法存储！！
	while(top->head->next != NULL)
	{
		PATH[count] = top->head->x *10 + top->head->y;
		++count;
		top->head = top->head->next;
	}
	for(i = count - 1; i >= 0; --i)
	{	
		int num_x = PATH[i] / 10;  //从数据中提取出X
		int num_y = PATH[i] % 10; //从数组中提取出Y
		//打印路径
		printf("(%d, %d)\n", num_x, num_y);
	}
	return 0;
}        
