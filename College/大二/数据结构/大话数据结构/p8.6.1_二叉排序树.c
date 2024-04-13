#include<stdio.h> 
#include<stdlib.h>

typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//�����������Ĳ��Ҳ��� 
int SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
	if (!T) {  //�����Ҳ��ɹ���ָ��pָ�����·���Ϸ��ʵ����һ����㲢����0 
		*p = f;
		return 0;
	} else if (key == T->data) {  //�����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬 ������1 
		*p = T;
		return 1;
	} else if (key < T->data) {
		return SearchBST(T->lchild, key, T, p);   //�������м������� 
	} else {
		return SearchBST(T->rchild, key, T, p);
	}
}

//�����������Ĳ������
int InsertBST(BiTree *T, int key) {
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p)) {  //  ���Ҳ��ɹ� 
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p) {
			*T = s;   //����sΪ�µĸ���� 
		} else if (key < T->data) {
			T->lchild = s;  //����sΪ���� 
		} else { 
			T->rchild = s;  //����sΪ�Һ��� 
		}
		return 1;
	} else
	    return 0;
} 

int main() {
	return 0;
}
