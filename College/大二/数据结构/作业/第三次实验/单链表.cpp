#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef int ElemType;
//��������
typedef struct Node {
	ElemType data;
	struct Node* next;
}Node; 
typedef struct Node* LinkList;

int printList(LinkList *L) {
	LinkList p =  (LinkList)malloc(sizeof(Node));
	
	p = (*L)->next;
	while(p != NULL) {
		cout << p->data << " ";
		cout << "�ڵ��ַ��" << &p->next <<endl;
		p = p->next;
	}
	cout << endl;
	return 1;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* pָ���һ����� */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
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
	while (p->next && j < i) {  
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

//���������������β�巨�� 
int CreateListHead_2(LinkList *L,int n) {
	int A[8]={1,2,3,4,5,100,200,300};
	LinkList p,r;    //pΪ�²���Ľ��  rΪ���������Ľ��  ����β�� 
	int i;

	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node)); 
		//β�巨 
		p->data = A[i];
		r->next = p;
		r = p;
	}
	r->next=NULL;
	return 1; 
} 


void test() {
	LinkList head = (LinkList)malloc(sizeof(Node));
	CreateListHead_2(&head, 8);
	cout << "�����" << endl;
	printList(&head);
	int i = 6, j = 5, e = 586;
	cout << "�ڵ������6��λ�ò�����ֵ586������ʾ�������ʱ�µ����������ڵ���" <<endl;
	ListInsert(&head,i, e);
	cout << "�µĽڵ�����ɣ�" << ListLength(head) <<endl;
	cout << "���ڵ����������ǣ�" << endl; 
	printList(&head);
	ListDelete(&head, j, &e);
	cout << "�Ե�ǰ�������5���ڵ����ɾ��������" << endl;
	cout << "�µĽڵ�����ɣ�" << ListLength(head) <<endl;
	cout << "���ڵ����������ǣ�" << endl; 
	printList(&head);
	
	
}


int main() {
	test();
	return 0;
}
