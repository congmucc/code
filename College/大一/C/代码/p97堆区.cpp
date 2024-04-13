#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#include<time.h>


void test01()
{
	int *p=(int*)malloc(sizeof(int)); 
	
	
	printf("&p=%p\n",p);
	
	//使用堆空间
	*p=23;
	
	printf("p=%d\n",*p);
	
	//释放堆空间
	free(p);
	//p   野指针   还能操作，free后要NULL 
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
