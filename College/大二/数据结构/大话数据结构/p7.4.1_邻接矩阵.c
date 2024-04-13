#include<stdio.h>

typedef char VertexType;      //顶点的数据类型应由用户定义 
typedef int EdgeType;         //边上的权值类型应由用户定义 
#define MAXVEX 100            //最大顶点数 应由用户定义 
#define INFINITY 65535        //用65535来代表那个极大值

typedef struct {
	VertexType vexs[MAXVEX];       //顶点表 
	EdgeType arc[MAXVEX][MAXVEX];  //邻接矩阵  可以看作表
	int numNodes, numEdges;        //途中当前的顶点数和边数 
}MGraph; 

//建立无向网图的邻接矩阵表示 
void CreateMGraph(MGraph *G) {
	int i, j, k, w;
	printf("请输入顶点数和边数：\n");
	scanf("%d, %d", &G->numNodes, &G->numEdges); 
	for (i = 0; i < G->numNodes; i++) {              //初始化顶点表 
		scanf("%d", G->vexs[i]);
	}
	for (i = 0; i < G->numNodes; i++) {
		for (j = 0; j < G->numNodes; j++) {
			G->arc[i][j] = INFINITY;                 //初始化邻接矩阵 
		}
	}
	for (k = 0; k < G->numEdges; k++) {              //读入numEdges的边，建立邻接矩阵 
		printf("输入边(vi,vj)上的下标i, 下标j 和权w：\n");
		scanf("%d, %d, %d",&i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];                 //无向图  矩阵对称 
	}
}


int main() {
	return 0;
} 
