#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#include<time.h>


void test01()
{
	int *p=(int*)malloc(sizeof(int)); 
	
	
	printf("&p=%p\n",p);
	
	//ʹ�öѿռ�
	*p=23;
	
	printf("p=%d\n",*p);
	
	//�ͷŶѿռ�
	free(p);
	//p   Ұָ��   ���ܲ�����free��ҪNULL 
	*p=456;
	printf("p=%d\n",*p); 


	p=NULL; 
	 
	*p=456;
	printf("p=%d\n",*p); 
	
	 
}

void test02()
{
	srand((unsigned int)time(NULL));
	
	int *p=(int *)malloc(sizeof(int) * MAX);
	
	for(int i=0;i<MAX;i++)
	{
		p[i]=rand()%100+1;
		printf("%d ",p[i]); 
	}
	
	
	
}

int main()
{
//	test01();
	test02();
	return 0;
 } 
