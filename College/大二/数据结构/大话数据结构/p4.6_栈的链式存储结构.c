#include<stdio.h>

typedef int SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr; 

typedef struct LinkStack {
	LinkStackPtr top;
	int count;
}LinkStack;
 
 //入栈  插入元素e为新的栈顶元素
 int PushStack(LinkStack *S, SElemType e) {
 	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
 	s->data = e;
 	s->next = S->top;    //把当前的栈顶元素赋值给新结点的直接后继 
 	S->top = s;          //将新结点s赋值给栈顶指针    可以直接看书中的图  好理解的多 
 	S->count++;
 	return 1;
 } 
 //出栈  若栈不为空  则删除S的栈顶元素  用e返回其值
 int PopStack(LinkStack *S, SElemType *e) {
 	LinkStackPtr p;
 	if (StackEmpty(*S))
 	    return 0;
    *e = S->top->data;
    p = S->top;             //将栈顶结点赋值给p 
    S->top = S->top->next;  //移动栈顶指针移向下一位  指向后一结点   
	free(p);
	S->count--;
	return 1; 
 }
int main() {
	return 0;
}
