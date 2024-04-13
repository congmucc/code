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
	cout << "ͷ�ڵ��ַ��" << &L <<endl;
	p = (*L)->next;
	while(p != NULL) {
		cout << p->data << " ";
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
	LinkList p,r;    //pΪ�²���Ľ��  rΪ���������Ľ��  ����β�� 
	int i;

	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i = 1; i <= n; i++) {
		p = (LinkList)malloc(sizeof(Node)); 
		//β�巨 
		p->data = i;
		r->next = p;
		r = p;
	}
	r->next=(*L)->next;
	return 1; 
} 


void test01(LinkList *L, int m) {
	LinkList r, p;
	p = (LinkList)malloc(sizeof(Node)); 
	int i = 1;
	p = *L;
	while(p->next != p) {
		if (i == m) {
			r = p->next;
	    	cout << p->next->data << " "; 
	    	p->next = r->next;
	    	i = 1;
	    	continue;
	    }
	    i++;
	    p = p->next;
	}
	cout << p->data << endl;  //������һ������ 
}

void test02(int n, int m) {
	int a[n];
	for (int i = 0; i < n; i++) {
        a[i] = i + 1; 
	}
	int p = n;
	int t = 0;
	while(p != 1) {
		for (int j = 1; j <= 5; j++) {
			if (j == 5) {
				cout << a[t] << " ";
				for (int i = t; i <= p; i++) {
					a[t] = a[t + 1];
				}
				p--;
				t--;
			}
			t = (t + 1) % p;
		}
	}
	cout << a[0] << endl;
	
	
} 



int test03(int sum,int value,int n)
{
    if(n==1)
        return (sum+value-1)%sum;
    else
        return (test03(sum-1,value,n-1)+value)%sum;
}



void test() {
	LinkList head = (LinkList)malloc(sizeof(Node));
	int n = 6, m = 5;
	CreateListHead_2(&head, n);
	
    //˼��1 
    cout << "1.����ѭ������ķ�ʽ�����" << endl; 
	test01(&head, m);
	
	//˼��2 
	cout << "2.��˳������飩�����" << endl; 
	test02(n, m);
	
	//˼��3
	cout << "3.�õݹ�����" << endl; 
	for(int i=1;i<=n;i++)
	{
		cout << test03(n,m,i)+1 << " ";
	}
        

	
}



int main() {
	test();
	return 0;
}
