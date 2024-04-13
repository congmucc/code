#include<stdio.h>
#include<stdlib.h>

typedef char VertexType;      //�������������Ӧ���û����� 
typedef int EdgeType;         //���ϵ�Ȩֵ����Ӧ���û����� 
#define MAXVEX 100            //��󶥵��� Ӧ���û����� 
#define INFINITY 65535        //��65535�������Ǹ�����ֵ


typedef struct EdgeNode {     //�߱��� 
    int adjvex;              //�ڽӵ��򣬴���ö����Ӧ���±�
	EdgeType info;            //�洢Ȩֵ����������ͼ���Բ�Ҫ
	struct EdgeType *next;    //������һ���ڽӵ� 
}EdgeNode;

typedef struct VertexNode {   //������� 
	VertexType data;          //�����򣬴洢������Ϣ 
	EdgeNode *firstedge;      //�߱�ͷָ�� 
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	int numNodes, numEdges;   //ͼ�е�ǰ�Ķ������ͱ��� 
}GraphAdjList;

void CreateALGraph(GraphAdjList *G) {
	/*invalid type argument of ��->�� (have ��struct qstr_xid_element��)
    ���ִ���һ����û�����C�С�->���롰.���÷��Ĳ�ͬ��
    ��->����ָ��ṹ��ָ���ȡ�ṹ��ĳ�Ա����ʱ���ã�
    ����.������һ��Ľṹ������ȡ�ṹ��ĳ�Ա����ʱ���á�
    ����˵���������ǰ��ָ�����ͣ���ô�á�->���������á�.��
    firstedgeǰҪ�õ㣬��Ϊ����ǰ��ָadjList[i]�ǲ���ָ������,������firstedge�� firstedge��ʱ������һ��������� 
    */
	int i, j, k;
	EdgeNode *e;
	printf("���붥�����ͱ�����\n");
	scanf("%d,%d", &G->numNodes, &G->numEdges);
	for (i = 0; i < G->numNodes; i++) {
		scanf(&G->adjList[i].data);                //���붥����Ϣ 
		G->adjList[i].firstedge = NULL;            //������Ϊ�ձ� 
	} 
	
	for(k = 0; k < G->numEdges; k++) {
			printf("�����(vi,vj)�ϵĶ������:\n");
		scanf("%d,%d",&i,&j); /* �����(vi,vj)�ϵĶ������ */
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ���ڴ�����ռ�,���ɱ߱��� */
		e->adjvex=j;					/* �ڽ����Ϊj */                         
		e->next=G->adjList[i].firstedge;	/* ��e��ָ��ָ��ǰ������ָ��Ľ�� */
		G->adjList[i].firstedge=e;		/* ����ǰ�����ָ��ָ��e */               
		
		e=(EdgeNode *)malloc(sizeof(EdgeNode)); /* ���ڴ�����ռ�,���ɱ߱��� */
		e->adjvex=i;					/* �ڽ����Ϊi */                         
		e->next=G->adjList[j].firstedge;	/* ��e��ָ��ָ��ǰ������ָ��Ľ�� */
		G->adjList[j].firstedge=e;		/* ����ǰ�����ָ��ָ��e */            
	}
}

int main() {
	GraphAdjList g;
	CreateALGraph(&g); 
	return 0;
} 
