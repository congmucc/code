#include<stdio.h>
#include<stdlib.h>

typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front, rear;//队头队尾指针 
}LinkQueue;

//插入元素e为Q的新的队尾元素
int EnQueue(LinkQueue *Q, QElemType e) {
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
//	if (!s) {    //申请失败 
//		exit(0);
//	}
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s; 
	return 1;
} 

//若队列不为空，删除Q的对头元素，用e返回其值，并返回1，否则返回0
int DeQueue(LinkQueue *Q, QElemType *e) {
	QueuePtr p;
	if (Q->front == Q->rear) {
		return 0;
	}
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) 
	    Q->rear = Q->front;
	free(p);
	return 1;
} 

int main() {
	
	return 0;
}
