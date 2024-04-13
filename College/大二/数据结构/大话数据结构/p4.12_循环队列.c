#include<stdio.h>

#define MAXSIZE 5
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
int main() {
	
	return 0;
} 
