#include<stdio.h>
#include<iostream>

using namespace std;
#define MAXSIZE 100
typedef int QElemType;

typedef struct {
	QElemType data[MAXSIZE];
	int front;  //头指针 
	int rear;   //尾指针  若队列不空  指向队尾元素的下一个位置 
} SqQueue;
 
//初始化队列 
int InitQueue(SqQueue *Q) {
	Q->front = 0;
	Q->rear = 0;
	return 1;
} 

//返回Q的元素的个数， 也就是队列的当前长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front+MAXSIZE) % MAXSIZE;
} 

/* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
int GetHead(SqQueue Q,int *e)
{
	if(Q.front==Q.rear) /* 队列空 */
		return 0;
	*e=Q.data[Q.front];
	return 1;
}

//循环入队  若队未满  则插入元素e为Q新的队尾元素
int EnQueue(SqQueue *Q, QElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)  //队满的判断 
	    return 0;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;  //rear指针向后移动一位 若到最后转到数组的头部 
    return 1; 
} 

//若队列不为空 则删除Q中队头元素 用e返回其值
int DeQueue(SqQueue *Q, QElemType *e) {
	if (Q->front == Q->rear) {
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
} 


/* 从队头到队尾依次对队列Q中每个元素输出 */
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
	 cout << "（4）由于普通线性队列的限制，此时尝试使用循环队列来解决上述问题。" << endl; 
	 cout << "（1）输入1-10的数字组成普通线性队列；" << endl;
	 QueueTraverse(q);
	 
	 cout << "（2）判断此时队列的队首元素；" << endl;
	 GetHead(q, &e);
	 printf("%d \n", e);
	 
	 cout << "（3）打印出队列操作后的队首元素；" << endl;
	 DeQueue(&q, &e);
	 GetHead(q, &e);
	 printf("%d \n", e);
	
	return 0;
} 

