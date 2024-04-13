#include<stdio.h> 


#define False 0
#define True 1
#define MAXVEX 9
#define MAXSIZE 9
Boolean visited[MAXVEX];      /* ���ʱ�־������ */
typedef char VertexType;      //�������������Ӧ���û����� 
typedef int EdgeType;         //���ϵ�Ȩֵ����Ӧ���û����� 
#define MAXVEX 100            //��󶥵��� Ӧ���û����� 
#define INFINITY 65535        //��65535�������Ǹ�����ֵ


typedef struct
{
	VertexType vexs[MAXVEX]; /* ����� */
	EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ��󣬿ɿ����߱� */
	int numVertexes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ��� */ 
}MGraph;

/*�õ����еĽṹ�뺯��*********************************************/ 


typedef struct {
	int datas[MAXSIZE];
	int front;     //ͷָ�� 
	int rear;      //βָ�� 
} Queen; 

//��ʼ������ 
int InitQueen(Queen *Q) {
	 Q->front = 0;
	 Q->rear = 0;
	 return 1; 
} 

//������Ϊ�շ���1�����򷵻�0
int QueenEmpty(Queen Q) {
	if (Q.front == Q.rear) {
		return 1;
	} else{
		return 0;
	}
} 

//�����в�Ϊ�գ������Ԫ��e������Q��
int EnQueen(Queen *Q, int e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		   return 0;
	}
	Q->datas[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	
	return 1;
} 

/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
int DeQueue(Queue *Q,int *e) {
	if (Q->front == Q->rear) {
	    return 0;
	}
	
	e = Q->datas[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	
	return 1;
}


/*����***********************************************************/ 

//������ȱ��� 
void DFS(MGraph G, int i) {
	int j;
 	visited[i] = TRUE;
 	printf("%c ", G.vexs[i]);/* ��ӡ���㣬Ҳ������������ */
	for(j = 0; j < G.numVertexes; j++)
		if(G.arc[i][j] == 1 && !visited[j])
 			DFS(G, j);/* ��Ϊ���ʵ��ڽӶ���ݹ���� */
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

/* �ڽӾ���Ĺ�ȱ����㷨 */
void BFSTraverse(MGraph G) {
	int i, j;
	Queue Q;
	for(i = 0; i < G.numVertexes; i++)
       	visited[i] = FALSE;
    InitQueue(&Q);		/* ��ʼ��һ�����õĶ��� */
    for(i = 0; i < G.numVertexes; i++)  /* ��ÿһ��������ѭ�� */
    {
		if (!visited[i])	/* ����δ���ʹ��ʹ��� */
		{
			visited[i]=TRUE;		/* ���õ�ǰ������ʹ� */
			printf("%c ", G.vexs[i]);/* ��ӡ���㣬Ҳ������������ */   
			EnQueue(&Q,i);		/* ���˶�������� */
			while(!QueueEmpty(Q))	/* ����ǰ���в�Ϊ�� */
			{
				DeQueue(&Q,&i);	/* ���Ӷ�Ԫ�س����У���ֵ��i */
				for(j=0;j<G.numVertexes;j++) 
				{ 
					/* �ж��������㣬���뵱ǰ������ڱ���δ���ʹ�  */
					if(G.arc[i][j] == 1 && !visited[j]) 
					{ 
 						visited[j]=TRUE;			/* ���ҵ��Ĵ˶�����Ϊ�ѷ��� */
						printf("%c ", G.vexs[j]);	/* ��ӡ���� */
						EnQueue(&Q,j);				/* ���ҵ��Ĵ˶��������  */
					} 
				} 
			}
		}
	}
} 

int main() {
	return 0;
}
