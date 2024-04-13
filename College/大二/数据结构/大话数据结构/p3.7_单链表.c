#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
//创建链表
typedef struct Node {
	ElemType data;
	struct Node* next;
}Node; 
typedef struct Node* LinkList;

//读取链表  从头开始查找，到第i个就停止 
int  GetElem(LinkList L,int i,ElemType* e) {
	int j;
	LinkList p;
	p = L->next;//让p指向链表的第一个结点 
	j = 1;//j为计时器
	while (p && j < i) {//当为p不为空或还没有运行到i时 循环执行 
		p = p->next;
		++j;
	} 
	if (!p || j > i) {
		return 0;//第i个数不存在 
	}
	*e = p->data; //取第i个数据 
	return 1;
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
	while (p->next && j < i) {  //寻找第i个元素   这要用p->next   因为如果用p的话到了最后一次循环就晚了 
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

//单链表的整表创建 （头插法） 
int CreateListHead_1(LinkList *L,int n) {
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));    //生成新的结点
		//头插法 
		p->next = (*L)->next;
	    (*L)->next =p;
	}
} 

//单链表的整表创建（尾插法） 
int CreateListHead_2(LinkList *L,int n) {
	LinkList p,r;    //p为新插入的结点  r为链表中最后的结点  用于尾插 
	int i;
	srand(time(0));    //初始化随机数种子
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node)); 
		//尾插法 
		r->next = p;
		r = p;
	}
	r->next=NULL;
	return 1; 
} 

//单链表的整表删除
int ClearList(LinkList *L) {
	LinkList p,q;
	p = (*L)->next;
	while (p) {
		//这点可以看书 
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
