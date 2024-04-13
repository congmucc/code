#include<stdio.h>

#define MAXSIZE 1000//�������󳤶� 
typedef int ElemType;

typedef struct {
	ElemType data;
	int cur;  //�α�   Ϊ0ʱ��ʾ��ָ�� 
} Component,StaticLinkList[MAXSIZE];

//��һά����space�и���������һ��������  space[0].curΪͷָ�� ��0����ʾ��ָ�� 
int InitList(StaticLinkList space) {
	int i;
	for (i = 0; i < MAXSIZE-1; i++) {
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;//Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0  
	return 0; 
} 

int ListLength(StaticLinkList L) {
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i) {
		i = L[i].cur;
		j++;
	}
	return j;
}

//˳����뾲̬����
//����������Ϊ�գ��򷵻ط���Ľ���±꣬���򷵻�0 
int Malloc_SLL(StaticLinkList space) {
	int i = space[0].cur;//��ǰ����ĵ�һ��Ԫ�ص�cur���ֵ  ����Ҫ���ص�һ�����ÿ��е��±� 
	if (space[0].cur)
	    space[0].cur = space[i].cur;//����Ҫ�ó�һ��������ʹ����  �������ǰ�������һ�������������� 
	return i;
} 

//��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��
int ListInsert(StaticLinkList L, int i, ElemType e) {
	int j, k, l;
	k = MAXSIZE - 1;//k���������һ��Ԫ�ص��±� 
	if (i < i || i > ListLength(L) + 1)
	    return 0;
	j = Malloc_SLL(L);
	if (j) {
		L[j].data = e;
		for (l = 1; l <= i-1; l++) {
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;//��ͷ�巨���� 
		L[k].cur = j;
		return 1; 
	}
	return 0;
} 

//�ͷ�����Ԫ��
void Free_SSL(StaticLinkList space, int i) {
	space[i].cur = space[0].cur;
	space[0].cur = i;
} 
//ɾ����̬���� 
int ListDelete(StaticLinkList L, int i) {
	int j, k;
	if (i < 1 || i > ListLength(L));
	    return 0;
	k = MAXSIZE - 1;
	for (j = 1; j <= i-1; j++) {
		k = L[k].cur;
	} 
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL (L, j);
	return 1;
} 

int main() {
	return 0;
} 
