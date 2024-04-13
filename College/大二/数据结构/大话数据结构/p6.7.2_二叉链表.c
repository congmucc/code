#include<stdio.h>


typedef struct BiTNode {         //���ṹ 
	int data;                            //������� 
	struct BiTNode *lchild, *rchild;     //���Һ��ӽ�� 
} BiTNode, *BiTree;


//�������Ľ���  ��ǰ������������н���ֵ  # ��ʾ���� 
void CreateBiTree(BiTree *T) {     //*T����Ϊ����ָ��ĵ�ַ���� 
	int ch;
	
//	scanf("%c",&ch);
	ch = str[index++];
	
	if (ch == "#") {   //�����ǰѶ������Ŀս������ " # " �� # ��ʾ���� 
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



//      ���ֱ��������ǿ�˭�������λ�ã� �ڴ����ݽṹ��ר�Ÿ����λ��������һ������Ҳ�������ԭ�� 
//ǰ�������
void PreOrderTravese(BiTree T) {
	if(T == NULL) {
		return;
	}
	printf("%c",T->data);         //��ʾ������� �ɸ���Ϊ�����Խ��Ĳ��� 
	PreOrderTravese(T->lchild);
	PreOrderTravese(T->rchild);
} 

//��������� 
void InOrderTravese(BiTree T) {
	if(T == NULL) {
		return;
	}
	PreOrderTravese(T->lchild);
	printf("%c",T->data);
	PreOrderTravese(T->rchild);
} 

//���������
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
