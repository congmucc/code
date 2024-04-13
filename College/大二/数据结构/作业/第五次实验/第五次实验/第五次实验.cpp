#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int Status; 

typedef struct QNode {
	int data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front, rear;
} LinkQueue;

int visit(int c) {
	cout << c << " ";
	return 1;
}


/* 构造一个空队列Q */
Status InitQueue(LinkQueue *Q) { 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		ERROR;
	Q->front->next=NULL;
	return OK;
}


/* 若Q为空队列,则返回TRUE,否则返回FALSE */
int QueueEmpty(LinkQueue Q) { 
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
Status GetHead(LinkQueue Q, int *e) { 
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}

/* 插入元素e为Q的新的队尾元素 */
Status EnQueue(LinkQueue *Q,int e) { 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* 存储分配失败 */
		return ERROR;
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	
	Q->rear=s;	
	return OK;
}

/* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
Status DeQueue(LinkQueue *Q,int *e) {
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		
	*e=p->data;				
	Q->front->next=p->next;
	if(Q->rear==p)		
		Q->rear=Q->front;
	free(p);
	return OK;
}


/* 从队头到队尾依次对队列Q中每个元素输出 */
Status QueueTraverse(LinkQueue Q) {
	QueuePtr p;
	p=Q.front->next;
	while(p)
	{
		 visit(p->data);
		 p=p->next;
	}
	cout << endl;
	return OK;
}


int main() {
	
	int e;
	LinkQueue q;
	InitQueue(&q);
	for (int i = 1; i <= 10; i++) {
		EnQueue(&q, i);
	}
	cout << "（1）输入1-10的数字组成普通线性队列；" << endl;
	QueueTraverse(q);
	
	
	cout << "（2）判断此时队列的队首元素；" << endl;
	GetHead(q, &e);
	cout << e <<endl;
	
	cout << "（3）打印出队列操作后的队首元素；" << endl;
	DeQueue(&q, &e);
	GetHead(q, &e);
	cout << e <<endl;
	return 0;
} 
