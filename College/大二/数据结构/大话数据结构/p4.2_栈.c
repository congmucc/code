#include<stdio.h>

#define MAXSIZE 1000

typedef int SElemType;
typedef struct {
	SElemType data[MAXSIZE];
	int top;
}SqStack;

//����Ԫ��eΪ�µ�ջ��Ԫ�� 
int PushStack(SqStack *S, SElemType e) {
	if (S->top == MAXSIZE - 1) { //ջ���� 
		return 0;
	}
	S->top++;
	S->data[S->top] = e;
	return 1;
}

//��ջ��Ϊ��  ɾ��S��ջ��Ԫ��  ��e������ֵ  ������1  ���򷵻�0 
int PopStack(SqStack *S, SElemType *e) {
	if (S->top == -1) {
		return 0;
	}
	*e = S->data[S->top];
	S->top--;
	return 1; 
} 

int main() {
	return 0;
} 
