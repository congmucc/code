#include<stdio.h> 


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* 存储空间初始分配量 */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

typedef char VertexType; /* 顶点类型应由用户定义 */   
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

//邻接矩阵的结构 
typedef struct {
	VertexType  vers[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes,  numEdges; 
} MGraph;

/*邻接表结构               */

typedef struct EdgeNode {
	int adjvex;
	int weight;
	struct EdgeNode *Next;
} EdgeNode;
 
typedef struct VertexNode {
	int in;
	char data;
	EdgeNode *firstedge;
} VertexNOde, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

/*利用邻接矩阵构建邻接表      */ 
void CreateALGraph(MGraph G, GraphAdjList *GL) {
	int i, j;
	EdgeNode *e;
	
	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));
	
	(*GL)->numVertexes=G.numVertexes;
	(*GL)->numEdges=G.numEdges;
	
	for (i = 0; i < G->numVertexes; i++) {
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vers[i];
		(*GL)->adjList[i].firstedge=NULL; 
	} 
}

    
    
int main() {
	return 0;
}
