#include<stdio.h>

#define MAX_TRUE_SIZE 100

typedef int TElemType; 

typedef struct PTNode {     //���ṹ 
	TElemType data;         //������� 
	int parent;             //˫��λ�� 
} PTNode;

typedef struct {                      //���ṹ 
	PTNode nodes[MAX_TRUE_SIZE];      //������� 
	int r,n;                          //����λ�úͽ���� 
} PTree;




int main() {
	return 0;
} 
