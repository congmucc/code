#include<stdio.h>

typedef char VertexType;      //�������������Ӧ���û����� 
typedef int EdgeType;         //���ϵ�Ȩֵ����Ӧ���û����� 
#define MAXVEX 100            //��󶥵��� Ӧ���û����� 
#define INFINITY 65535        //��65535�������Ǹ�����ֵ

typedef struct {
	VertexType vexs[MAXVEX];       //����� 
	EdgeType arc[MAXVEX][MAXVEX];  //�ڽӾ���  ���Կ�����
	int numNodes, numEdges;        //;�е�ǰ�Ķ������ͱ��� 
}MGraph; 

//����������ͼ���ڽӾ����ʾ 
void CreateMGraph(MGraph *G) {
	int i, j, k, w;
	printf("�����붥�����ͱ�����\n");
	scanf("%d, %d", &G->numNodes, &G->numEdges); 
	for (i = 0; i < G->numNodes; i++) {              //��ʼ������� 
		scanf("%d", G->vexs[i]);
	}
	for (i = 0; i < G->numNodes; i++) {
		for (j = 0; j < G->numNodes; j++) {
			G->arc[i][j] = INFINITY;                 //��ʼ���ڽӾ��� 
		}
	}
	for (k = 0; k < G->numEdges; k++) {              //����numEdges�ıߣ������ڽӾ��� 
		printf("�����(vi,vj)�ϵ��±�i, �±�j ��Ȩw��\n");
		scanf("%d, %d, %d",&i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];                 //����ͼ  ����Գ� 
	}
}


int main() {
	return 0;
} 
