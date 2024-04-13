#include<stdio.h> 
#include<stdlib.h>

typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//二叉排序树的查找操作 
int SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
	if (!T) {  //若查找不成功，指针p指向查找路径上访问的最后一个结点并返回0 
		*p = f;
		return 0;
	} else if (key == T->data) {  //若查找成功，则指针p指向该数据元素结点， 并返回1 
		*p = T;
		return 1;
	} else if (key < T->data) {
		return SearchBST(T->lchild, key, T, p);   //在子树中继续查找 
	} else {
		return SearchBST(T->rchild, key, T, p);
	}
}

//二叉排序树的插入操作
int InsertBST(BiTree *T, int key) {
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p)) {  //  查找不成功 
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p) {
			*T = s;   //插入s为新的根结点 
		} else if (key < T->data) {
			T->lchild = s;  //插入s为左孩子 
		} else { 
			T->rchild = s;  //插入s为右孩子 
		}
		return 1;
	} else
	    return 0;
} 

int main() {
	return 0;
}
