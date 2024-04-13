#include<stdio.h>

typedef struct enum{     //ö�� 
	Link,                //Link == 0��ʾָ�����Һ���ָ��
	Thread               //Thread == 1��ʾָ��ǰ�����ߺ�̵�����
} PointerTag; 

typedef struct BiThrNode {               //�������������洢���ṹ 
	int data;   
	struct BiThrNode *lchild, *rchild;   //���Һ���ָ�� 
	PointerTag LTag;
	PointerTag RTag;                     //���ұ�־ 
} BiThrNode, *BiThrTree;

BiThrTree pre;          //ʼ��ָ��ոշ��ʹ��Ľ�� 

//�����������������������
void InThreading(BiThrTree p) {
	InThreading(p->lchild);
	if (!p->lchild) {   //û������ 
		p->LTag = Thread;
		p->lchild = pre; 
	} 
	if (!p->rchild) {    //û���Һ��� 
	    pre->RTag = Thread;
		pre->rchild = p; 
	}
	pre = p;
	printf("%c\t",p);
	InThreading(p->rchild);
} 

//Tָ��ͷ��㣬ͷ�������lchildָ���ָ�룬ͷ�������rchildָ�����������
//���һ����㣬�������������������ʾ������T 
int InOrderTraverse_Thr(BiThrTree T) {
	BiThrTree p;
	p = T->lchild;       //pָ������  
	while (p != T) {
		while (p->LTag == Link) 
		    p = p->lchild;
		printf("%c", p->data);
		while (p->RTag == Thread && p->rchild != T) {
		    p->rchild;
		    printf("%c", p->data);
	    }
	    p = p->rchild;              //p������������ 
	}
	return 1; 
} 


int main() {
	return 0;
} 
