#include<stdio.h>

#define MAX_TRUE_SIZE 100

typedef int TElemType; 

typedef struct CTNode {     //���ṹ 
	TElemType data;         //������� 
	struct CTNode *next;    //���ӽ�� 
} *ChildPtr;

typedef struct {            //��ͷ��� 
	TElemType data;
	ChildPtr firstchild;    //��һ������ 
} CTBox;

typedef struct {                 //���ṹ 
	CTBox nodes[MAX_TRUE_SIZE];  //������� 
	int r,n;                     //����λ�úͽ���� 
} CTree;

int main() {
	return 0;
}
