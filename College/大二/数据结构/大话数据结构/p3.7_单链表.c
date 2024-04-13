#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
//��������
typedef struct Node {
	ElemType data;
	struct Node* next;
}Node; 
typedef struct Node* LinkList;

//��ȡ����  ��ͷ��ʼ���ң�����i����ֹͣ 
int  GetElem(LinkList L,int i,ElemType* e) {
	int j;
	LinkList p;
	p = L->next;//��pָ������ĵ�һ����� 
	j = 1;//jΪ��ʱ��
	while (p && j < i) {//��Ϊp��Ϊ�ջ�û�����е�iʱ ѭ��ִ�� 
		p = p->next;
		++j;
	} 
	if (!p || j > i) {
		return 0;//��i���������� 
	}
	*e = p->data; //ȡ��i������ 
	return 1;
}

//�����ͷ�巨   
int ListInsert(LinkList* L,int i,ElemType e) {
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while (p && j < i) {    //Ѱ�ҵ�i����� 
		p = p->next;
		++j;
	} 
	if (!p || j > i) {
		return 0;
	}
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	//ͷ�巨 
	s->next = p->next;
	p->next = s;
	return 1;
} 

//�����ɾ�� 
int ListDelete(LinkList *L,int i,ElemType *e) {
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i) {  //Ѱ�ҵ�i��Ԫ��   ��Ҫ��p->next   ��Ϊ�����p�Ļ��������һ��ѭ�������� 
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i) {
		return 0; 
	}
	//�����ɾ�� 
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return 1;	
} 

//������������� ��ͷ�巨�� 
int CreateListHead_1(LinkList *L,int n) {
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));    //�����µĽ��
		//ͷ�巨 
		p->next = (*L)->next;
	    (*L)->next =p;
	}
} 

//���������������β�巨�� 
int CreateListHead_2(LinkList *L,int n) {
	LinkList p,r;    //pΪ�²���Ľ��  rΪ���������Ľ��  ����β�� 
	int i;
	srand(time(0));    //��ʼ�����������
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node)); 
		//β�巨 
		r->next = p;
		r = p;
	}
	r->next=NULL;
	return 1; 
} 

//�����������ɾ��
int ClearList(LinkList *L) {
	LinkList p,q;
	p = (*L)->next;
	while (p) {
		//�����Կ��� 
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return 1;
} 

int main() {
	
	return 0;
}
