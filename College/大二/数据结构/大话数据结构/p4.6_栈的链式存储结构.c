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
 
 //��ջ  ����Ԫ��eΪ�µ�ջ��Ԫ��
 int PushStack(LinkStack *S, SElemType e) {
 	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
 	s->data = e;
 	s->next = S->top;    //�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�� 
 	S->top = s;          //���½��s��ֵ��ջ��ָ��    ����ֱ�ӿ����е�ͼ  �����Ķ� 
 	S->count++;
 	return 1;
 } 
 //��ջ  ��ջ��Ϊ��  ��ɾ��S��ջ��Ԫ��  ��e������ֵ
 int PopStack(LinkStack *S, SElemType *e) {
 	LinkStackPtr p;
 	if (StackEmpty(*S))
 	    return 0;
    *e = S->top->data;
    p = S->top;             //��ջ����㸳ֵ��p 
    S->top = S->top->next;  //�ƶ�ջ��ָ��������һλ  ָ���һ���   
	free(p);
	S->count--;
	return 1; 
 }
int main() {
	return 0;
}
