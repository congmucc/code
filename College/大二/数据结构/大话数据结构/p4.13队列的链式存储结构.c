#include<stdio.h>
#include<stdlib.h>

typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front, rear;//��ͷ��βָ�� 
}LinkQueue;

//����Ԫ��eΪQ���µĶ�βԪ��
int EnQueue(LinkQueue *Q, QElemType e) {
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
//	if (!s) {    //����ʧ�� 
//		exit(0);
//	}
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s; 
	return 1;
} 

//�����в�Ϊ�գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������1�����򷵻�0
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
