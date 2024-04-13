#include<stdio.h>

#define MAXSIZE 5
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
int main() {
	
	return 0;
} 
