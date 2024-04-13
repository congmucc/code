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


/* ����һ���ն���Q */
Status InitQueue(LinkQueue *Q) { 
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		ERROR;
	Q->front->next=NULL;
	return OK;
}


/* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
int QueueEmpty(LinkQueue Q) { 
	if(Q.front==Q.rear)
		return 1;
	else
		return 0;
}

/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
Status GetHead(LinkQueue Q, int *e) { 
	QueuePtr p;
	if(Q.front==Q.rear)
		return ERROR;
	p=Q.front->next;
	*e=p->data;
	return OK;
}

/* ����Ԫ��eΪQ���µĶ�βԪ�� */
Status EnQueue(LinkQueue *Q,int e) { 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) /* �洢����ʧ�� */
		return ERROR;
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	
	Q->rear=s;	
	return OK;
}

/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
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


/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
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
	cout << "��1������1-10�����������ͨ���Զ��У�" << endl;
	QueueTraverse(q);
	
	
	cout << "��2���жϴ�ʱ���еĶ���Ԫ�أ�" << endl;
	GetHead(q, &e);
	cout << e <<endl;
	
	cout << "��3����ӡ�����в�����Ķ���Ԫ�أ�" << endl;
	DeQueue(&q, &e);
	GetHead(q, &e);
	cout << e <<endl;
	return 0;
} 
