#include<stdio.h>

#define MAXSIZE 1000

typedef int SElemType;
typedef struct {
	SElemType data[MAXSIZE];
	int top1;//栈1栈顶指针 
	int top2;//栈2栈顶指针 
}SqDoubleStack;

//插入元素e为新的栈顶元素 
int PushStack(SqDoubleStack *S, SElemType e, int stackNumber) {
	if (S->top1+1 == S->top2) {  //两者相差为1的时候栈满 
		return 0;
	}
	if (stackNumber == 1)
	    S->data[++S->top1] = e;
	else if (stackNumber == 2)
	    S->data[++S->top2] = e;
	return 1;
} 

//若栈不为空  则删除S的栈顶元素  用e返回其值  并返回1  否则返回0
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
