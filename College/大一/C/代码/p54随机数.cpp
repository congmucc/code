#include<stdio.h>
#include<time.h>
#include<stdlib.h>



void test01()
{
//	time_t timer =time(NULL);
//	srand((size_t)timer);
    //������������ 
    srand((unsigned int)time(NULL));
//	srand((size_t)time(NULL));
	for(int i=0;i<100;i++)
	{
		printf("%d\n",rand()%51+50);  //50-100  
	}
	
}

void test02()
{
	//˫ɫ��   6������   1-32   1������  1-16 
	srand((unsigned int)time(NULL));
    int arr[6]={0};
	int value=0;
	int flag=0;
	int j=0;
	for(int i=0;i<6;i++)
	{
		value=rand()%32+1;
		//ȥ��
		for(j=0;j<=flag;j++)
		{
			if(value==arr[i])
			{
				break;
			}
		 } 
		 if(j==flag)
		 arr[flag]=value;
		 flag++;
	 } 
	
	
}




int main()
{
	test01();
//	test02();
	
	return 0;
}
