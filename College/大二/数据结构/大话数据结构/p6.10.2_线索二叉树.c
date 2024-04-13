#include<stdio.h>

typedef struct enum{     //枚举 
	Link,                //Link == 0表示指向左右孩子指针
	Thread               //Thread == 1表示指向前驱或者后继的线索
} PointerTag; 

typedef struct BiThrNode {               //二叉树的线索存储结点结构 
	int data;   
	struct BiThrNode *lchild, *rchild;   //左右孩子指针 
	PointerTag LTag;
	PointerTag RTag;                     //左右标志 
} BiThrNode, *BiThrTree;

BiThrTree pre;          //始终指向刚刚访问过的结点 

//中序遍历法进行中序线索化
void InThreading(BiThrTree p) {
	InThreading(p->lchild);
	if (!p->lchild) {   //没有左孩子 
		p->LTag = Thread;
		p->lchild = pre; 
	} 
	if (!p->rchild) {    //没有右孩子 
	    pre->RTag = Thread;
		pre->rchild = p; 
	}
	pre = p;
	printf("%c\t",p);
	InThreading(p->rchild);
} 

//T指向头结点，头结点左链lchild指向根指针，头结点右链rchild指向中序遍历的
//最后一个结点，中序遍历二叉线索链表示二叉树T 
int InOrderTraverse_Thr(BiThrTree T) {
	BiThrTree p;
	p = T->lchild;       //p指向根结点  
	while (p != T) {
		while (p->LTag == Link) 
		    p = p->lchild;
		printf("%c", p->data);
		while (p->RTag == Thread && p->rchild != T) {
		    p->rchild;
		    printf("%c", p->data);
	    }
	    p = p->rchild;              //p进至右子树根 
	}
	return 1; 
} 


int main() {
	return 0;
} 
