#include<stdio.h>
#include<stdlib.h>

#define SEQLIST_INIT_SIZE 8

typedef int ElemType;

typedef struct SeqList 
{
    ElemType *base;  //头地址 
    int       capecity;  //容量的大小 
    int       size=NULL;  //顺序表的长度 
}SeqList;



//list初始化 
void InitSeqList(SeqList *list)
{
	list->base=(ElemType *)malloc(sizeof(ElemType)*SEQLIST_INIT_SIZE);
	list->capecity=SEQLIST_INIT_SIZE;
	list->size=0;
	
	printf("%p",list);
}



int main()
{
	SeqList mylist;	
	InitSeqList(&mylist); 
	
	
	return 0;
}
