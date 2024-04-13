#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef int ElemType;
//创建链表
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
		cout << "节点地址：" << &p->next <<endl;
		p = p->next;
	}
	cout << endl;
	return 1;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p指向第一个结点 */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

//链表的头插法   
int ListInsert(LinkList* L,int i,ElemType e) {
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while (p && j < i) {    //寻找第i个结点 
		p = p->next;
		++j;
	} 
	if (!p || j > i) {
		return 0;
	}
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	//头插法 
	s->next = p->next;
	p->next = s;
	return 1;
} 

//链表的删除 
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
	//链表的删除 
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return 1;	
} 

//单链表的整表创建（尾插法） 
int CreateListHead_2(LinkList *L,int n) {
	int A[8]={1,2,3,4,5,100,200,300};
	LinkList p,r;    //p为新插入的结点  r为链表中最后的结点  用于尾插 
	int i;

	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node)); 
		//尾插法 
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
	cout << "插入后：" << endl;
	printList(&head);
	int i = 6, j = 5, e = 586;
	cout << "在单链表第6个位置插入数值586，并显示单链表此时新的情况，比如节点数" <<endl;
	ListInsert(&head,i, e);
	cout << "新的节点数变成：" << ListLength(head) <<endl;
	cout << "现在的链表数据是：" << endl; 
	printList(&head);
	ListDelete(&head, j, &e);
	cout << "对当前单链表第5个节点进行删除操作：" << endl;
	cout << "新的节点数变成：" << ListLength(head) <<endl;
	cout << "现在的链表数据是：" << endl; 
	printList(&head);
	
	
}


int main() {
	test();
	return 0;
}
