#include<stdio.h>
#include<stdlib.h>

#define SEQLIST_INIT_SIZE 8

typedef int ElemType;

typedef struct SeqList 
{
    ElemType *base;  //ͷ��ַ 
    int       capecity;  //�����Ĵ�С 
    int       size=NULL;  //˳���ĳ��� 
}SeqList;



//list��ʼ�� 
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
