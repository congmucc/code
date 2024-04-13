#include<stdio.h>
#include<iostream>

using namespace std;
#define MAXSIZE 100
typedef int QElemType;

typedef struct {
	QElemType data[MAXSIZE];
	int front;  //ͷָ�� 
	int rear;   //βָ��  �����в���  ָ���βԪ�ص���һ��λ�� 
} SqQueue;
 
//��ʼ������ 
int InitQueue(SqQueue *Q) {
	Q->front = 0;
	Q->rear = 0;
	return 1;
} 

//����Q��Ԫ�صĸ����� Ҳ���Ƕ��еĵ�ǰ����
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front+MAXSIZE) % MAXSIZE;
} 

/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
int GetHead(SqQueue Q,int *e)
{
	if(Q.front==Q.rear) /* ���п� */
		return 0;
	*e=Q.data[Q.front];
	return 1;
}

//ѭ�����  ����δ��  �����Ԫ��eΪQ�µĶ�βԪ��
int EnQueue(SqQueue *Q, QElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)  //�������ж� 
	    return 0;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;  //rearָ������ƶ�һλ �������ת�������ͷ�� 
    return 1; 
} 

//�����в�Ϊ�� ��ɾ��Q�ж�ͷԪ�� ��e������ֵ
int DeQueue(SqQueue *Q, QElemType *e) {
	if (Q->front == Q->rear) {
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
} 


/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
int QueueTraverse(SqQueue Q) { 
	if (Q.front==Q.rear) return 0; 
	int i;
	i=Q.front;
	while((i+ MAXSIZE) % MAXSIZE!=Q.rear)
	{
		printf("%d ",Q.data[i]);
		i++;
	}
	printf("\n");
	return 1;
}

int main() {
	int e;
	SqQueue q;
	InitQueue(&q);
	 for (int i = 1; i <= 10; i++) {
	 	EnQueue(&q, i);
	 }
	 cout << "��4��������ͨ���Զ��е����ƣ���ʱ����ʹ��ѭ������������������⡣" << endl; 
	 cout << "��1������1-10�����������ͨ���Զ��У�" << endl;
	 QueueTraverse(q);
	 
	 cout << "��2���жϴ�ʱ���еĶ���Ԫ�أ�" << endl;
	 GetHead(q, &e);
	 printf("%d \n", e);
	 
	 cout << "��3����ӡ�����в�����Ķ���Ԫ�أ�" << endl;
	 DeQueue(&q, &e);
	 GetHead(q, &e);
	 printf("%d \n", e);
	
	return 0;
} 

