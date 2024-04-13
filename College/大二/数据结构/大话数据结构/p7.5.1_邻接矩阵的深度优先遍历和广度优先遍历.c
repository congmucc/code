#include<stdio.h> 


#define False 0
#define True 1
#define MAXVEX 9
#define MAXSIZE 9
Boolean visited[MAXVEX];      /* 访问标志的数组 */
typedef char VertexType;      //顶点的数据类型应由用户定义 
typedef int EdgeType;         //边上的权值类型应由用户定义 
#define MAXVEX 100            //最大顶点数 应由用户定义 
#define INFINITY 65535        //用65535来代表那个极大值


typedef struct
{
	VertexType vexs[MAXVEX]; /* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];/* 邻接矩阵，可看作边表 */
	int numVertexes, numEdges; /* 图中当前的顶点数和边数 */ 
}MGraph;

/*用到队列的结构与函数*********************************************/ 


typedef struct {
	int datas[MAXSIZE];
	int front;     //头指针 
	int rear;      //尾指针 
} Queen; 

//初始化队列 
int InitQueen(Queen *Q) {
	 Q->front = 0;
	 Q->rear = 0;
	 return 1; 
} 

//若队列为空返回1，否则返回0
int QueenEmpty(Queen Q) {
	if (Q.front == Q.rear) {
		return 1;
	} else{
		return 0;
	}
} 

//若队列不为空，则添加元素e到队列Q中
int EnQueen(Queen *Q, int e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		   return 0;
	}
	Q->datas[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	
	return 1;
} 

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
int DeQueue(Queue *Q,int *e) {
	if (Q->front == Q->rear) {
	    return 0;
	}
	
	e = Q->datas[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	
	return 1;
}


/*结束***********************************************************/ 

//深度优先遍历 
void DFS(MGraph G, int i) {
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);/* 打印顶点，也可以其它操作 */
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);/* 对为访问的邻接顶点递归调用 */
}

void DFSTraverse(MGraph G) {
	int i;
	for (i = 0; i < G.numVertexes; i++)
	visited[i] = False;
	for (i = 0; i < G.numVertexes; i++) {
		if (!visited[i]) {
			DFS(G, i);
		}
	}
}

/* 邻接矩阵的广度遍历算法 */
void BFSTraverse(MGraph G) {
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);		/* 初始化一辅助用的队列 */
    for(i = 0; i < G.numVertexes; i++)  /* 对每一个顶点做循环 */
    {
		if (!visited[i])	/* 若是未访问过就处理 */
		{
			visited[i]=TRUE;		/* 设置当前顶点访问过 */
			printf("%c ", G.vexs[i]);/* 打印顶点，也可以其它操作 */   
			EnQueue(&Q,i);		/* 将此顶点入队列 */
			while(!QueueEmpty(Q))	/* 若当前队列不为空 */
			{
				DeQueue(&Q,&i);	/* 将队对元素出队列，赋值给i */
				for(j=0;j<G.numVertexes;j++) 
				{ 
					/* 判断其它顶点，若与当前顶点存在边且未访问过  */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* 将找到的此顶点标记为已访问 */
						printf("%c ", G.vexs[j]);	/* 打印顶点 */
						EnQueue(&Q,j);				/* 将找到的此顶点入队列  */
					} 
				} 
			}
		}
	}
} 

int main() {
	return 0;
}
