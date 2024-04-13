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
	LinkList p, s, k;
	p = (LinkList)malloc(sizeof(Node));
	s = (LinkList)malloc(sizeof(Node));
	s->data = 320;
	s->next = NULL;
	p->data = 100;
	p->next = NULL;
	p->next = s;
	k = p;
	printf("%d\n", sizeof(k->data));
	printf("%d\n", sizeof((char*)k->data));
	printf("%d\n", sizeof(p->data));
	printf("p = %d\n", p->data);
	printf("s = %d\n", s->data);
	printf("k = %d\n", k->data);
	free(k);
	k->next = NULL;
	printf("p = %d\n", p->data);
	printf("s = %d\n", s->data);
	printf("k = %d\n", k->data);
}
int main() {

//	test01();
	test02();
	return 0;
}

