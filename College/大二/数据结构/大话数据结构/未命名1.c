#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int data;
	struct Node* next;
}Node, *LinkList;


void test01() {
	int* a = (int*)malloc(sizeof(int));
	*a = 10;
	int* b;
	b = a;
	printf("%d\n", *a);
	if (a != NULL) {
		free(b);
		b = NULL;
	}
	printf("%p\n", b);
	printf("%d\n", *a);
}

void test02() {
	LinkList p, s;
	p = (LinkList)malloc(sizeof(Node));
	s = (LinkList)malloc(sizeof(Node));
	s->data = 320;
	s->next = NULL;
	p->data = 100;
	p->next = NULL;
	p->next = s;
}

void test03() {
	int c = 10;
	int* a ;
	*a = c;
	int* b;
	b = a;
	printf("%d\n", *a);
//	if (a != NULL) {
//		free(b);
//		b = NULL;
//	}
	printf("%p\n", b);
	printf("%d\n", *a);
} 

int main() {

//	test01();
//	test02();
	test03(); 
	return 0;
}


