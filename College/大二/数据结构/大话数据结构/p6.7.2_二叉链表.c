#include<stdio.h>


typedef struct BiTNode {         //结点结构 
	int data;                            //结点数据 
	struct BiTNode *lchild, *rchild;     //左右孩子结点 
} BiTNode, *BiTree;


//二叉树的建立  按前数输入二叉树中结点的值  # 表示空树 
void CreateBiTree(BiTree *T) {     //*T是因为二级指针的地址传递 
	int ch;
	
//	scanf("%c",&ch);
	ch = str[index++];
	
	if (ch == "#") {   //这里是把二叉树的空结点变成了 " # " 即 # 表示空树 
		*T = NULL;
	} else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
		    exit();
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild); 
	} 
} 



//      三种遍历法就是看谁的输出的位置， 在大话数据结构上专门给输出位置设置了一个函数也就是这个原因 
//前序遍历法
void PreOrderTravese(BiTree T) {
	if(T == NULL) {
		return;
	}
	printf("%c",T->data);         //显示结点数据 可更改为其他对结点的操作 
	PreOrderTravese(T->lchild);
	PreOrderTravese(T->rchild);
} 

//中序遍历法 
void InOrderTravese(BiTree T) {
	if(T == NULL) {
		return;
	}
	PreOrderTravese(T->lchild);
	printf("%c",T->data);
	PreOrderTravese(T->rchild);
} 

//后序遍历法
 void InOrderTravese(BiTree T) {
	if(T == NULL) {
		return;
	}
	PreOrderTravese(T->lchild);
	PreOrderTravese(T->rchild);
	printf("%c",T->data); 
} 







int main() {
	
	
	
	return 0;
} 
