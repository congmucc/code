#include<stdio.h> 


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9 /* �洢�ռ��ʼ������ */
#define MAXEDGE 15
#define MAXVEX 9
#define INFINITY 65535

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */

typedef char VertexType; /* ��������Ӧ���û����� */   
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

//�ڽӾ���Ľṹ 
typedef struct {
	VertexType  vers[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes,  numEdges; 
} MGraph;

/*�ڽӱ�ṹ               */

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

/*�����ڽӾ��󹹽��ڽӱ�      */ 
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
