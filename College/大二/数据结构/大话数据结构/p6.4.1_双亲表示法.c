#include<stdio.h>

#define MAX_TRUE_SIZE 100

typedef int TElemType; 

typedef struct PTNode {     //结点结构 
	TElemType data;         //结点数据 
	int parent;             //双亲位置 
} PTNode;

typedef struct {                      //树结构 
	PTNode nodes[MAX_TRUE_SIZE];      //结点数组 
	int r,n;                          //根的位置和结点数 
} PTree;




int main() {
	return 0;
} 
