#include<stdio.h>
#include<stdlib.h>

typedef char VertexType;      //顶点的数据类型应由用户定义 
typedef int EdgeType;         //边上的权值类型应由用户定义 
#define MAXVEX 100            //最大顶点数 应由用户定义 
#define INFINITY 65535        //用65535来代表那个极大值


typedef struct EdgeNode {     //边表结点 
    int adjvex;              //邻接点域，储存该顶点对应的下标
	EdgeType info;            //存储权值，对于无向图可以不要
	struct EdgeType *next;    //链域，下一个邻接点 
}EdgeNode;

typedef struct VertexNode {   //顶点表结点 
	VertexType data;          //顶点域，存储顶点信息 
	EdgeNode *firstedge;      //边表头指针 
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numNodes, numEdges;   //图中当前的顶点数和边数 
}GraphAdjList;

void CreateALGraph(GraphAdjList *G) {
	/*invalid type argument of ‘->’ (have ‘struct qstr_xid_element’)
    这种错误一般是没有理解C中“->”与“.”用法的不同，
    “->”是指向结构体指针获取结构体的成员变量时所用，
    而“.”则是一般的结构体名获取结构体的成员变量时所用。
    简单来说，如果符号前是指针类型，那么用“->”，否则用“.”
    firstedge前要用点，因为符号前是指adjList[i]是不是指针类型,而不是firstedge， firstedge此时仅仅是一个对象而已 
    */
	int i, j, k;
	EdgeNode *e;
	printf("输入顶点数和边数：\n");
	scanf("%d,%d", &G->numNodes, &G->numEdges);
	for (i = 0; i < G->numNodes; i++) {
		scanf(&G->adjList[i].data);                //输入顶点信息 
		G->adjList[i].firstedge = NULL;            //将表置为空表 
	} 
	
	for(k = 0; k < G->numEdges; k++) {
			printf("输入边(vi,vj)上的顶点序号:\n");
		scanf("%d,%d",&i,&j); /* 输入边(vi,vj)上的顶点序号 */
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* 向内存申请空间,生成边表结点 */
		e->adjvex=j;					/* 邻接序号为j */                         
		e->next=G->adjList[i].firstedge;	/* 将e的指针指向当前顶点上指向的结点 */
		G->adjList[i].firstedge=e;		/* 将当前顶点的指针指向e */               
		
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* 向内存申请空间,生成边表结点 */
		e->adjvex=i;					/* 邻接序号为i */                         
		e->next=G->adjList[j].firstedge;	/* 将e的指针指向当前顶点上指向的结点 */
		G->adjList[j].firstedge=e;		/* 将当前顶点的指针指向e */            
	}
}

int main() {
	GraphAdjList g;
	CreateALGraph(&g); 
	return 0;
} 
