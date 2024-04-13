#include<stdio.h>

#define MAX_TRUE_SIZE 100

typedef int TElemType; 

typedef struct CTNode {     //结点结构 
	TElemType data;         //结点数据 
	struct CTNode *next;    //孩子结点 
} *ChildPtr;

typedef struct {            //表头结点 
	TElemType data;
	ChildPtr firstchild;    //第一个孩子 
} CTBox;

typedef struct {                 //树结构 
	CTBox nodes[MAX_TRUE_SIZE];  //结点数组 
	int r,n;                     //根的位置和结点数 
} CTree;

int main() {
	return 0;
}
