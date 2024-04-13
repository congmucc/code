#include<stdio.h>

#define MAXSIZE 1000

typedef int SElemType;
typedef struct {
	SElemType data[MAXSIZE];
	int top1;//ջ1ջ��ָ�� 
	int top2;//ջ2ջ��ָ�� 
}SqDoubleStack;

//����Ԫ��eΪ�µ�ջ��Ԫ�� 
int PushStack(SqDoubleStack *S, SElemType e, int stackNumber) {
	if (S->top1+1 == S->top2) {  //�������Ϊ1��ʱ��ջ�� 
		return 0;
	}
	if (stackNumber == 1)
	    S->data[++S->top1] = e;
	else if (stackNumber == 2)
	    S->data[++S->top2] = e;
	return 1;
} 

//��ջ��Ϊ��  ��ɾ��S��ջ��Ԫ��  ��e������ֵ  ������1  ���򷵻�0
int PopStack(SqDoubleStack *S, SElemType *e, int stackNumber) {
	if (stackNumber == 1) {
		if (S->top1 == -1)
		    return 0;
		*e = S->data[S->top1--];
	} else if (stackNumber == 2) {
	    if (S->top1 == MAXSIZE)
		    return 0;
		*e = S->data[S->top2++];
	}
	return 1;
}

int main() {
	return 0;
}
