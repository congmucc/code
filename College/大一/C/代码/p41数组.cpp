#include<stdio.h>



void test01()
{
//	int arr[10];
//	for(int i=0;i<10;i++)
//	{
//		scanf("%d ",&arr[i]);
//	}
    int arr[10]={1,2,3,4,5,6,7,8,9,0};	
	for(int j=0;j<sizeof(arr)/sizeof(arr[0]);j++)
	{
		//中间相差4个字节（int型），故地址相差4个地址，因为数组内存的是首地址
		printf("%p ",&arr[j]);
	}
	printf("\n");
	// 数组名是一个地址常量  指向数组首地址的常量  故可以直接写arr表示整个数组（仅仅有这一个是表示整个数组的首地址）
	// arr[0]表示的是数据，而不是地址了 
	
	
	//数组在内存中占用的内存为 = 数据类型 * 元素个数 
	printf("数组在内存中占用的大小：%d\n",sizeof(arr));
	printf("数组元素大小：%d\n",sizeof(arr[0]));
	printf("数组元素个数：%d\n",sizeof(arr)/sizeof(arr[0]));
    
}


int main()
{
	test01();
	return 0;
}
