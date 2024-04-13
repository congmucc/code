#include<stdio.h>

#define MAXSIZE 1000

typedef int SElemType;
typedef struct {
	SElemType data[MAXSIZE];
	int top;
}SqStack;

//插入元素e为新的栈顶元素 
int PushStack(SqStack *S, SElemType e) {
	if (S->top == MAXSIZE - 1) { //栈满了 
		return 0;
	}
	S->top++;
	S->data[S->top] = e;
	return 1;
}

//若栈不为空  删除S的栈顶元素  用e返回其值  并返回1  否则返回0 
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
