#include<stdio.h>


void test01()
{
	int arr[2][3]=
	{
	    {1,2,3},
	    {4,5,6}
	};
	
	printf("二维数组的大小：%d\n",sizeof(arr));
	printf("二维数组的一行大小：%d\n",sizeof(arr[0]));
	printf("二维数组的元素大小：%d\n",sizeof(arr[0][0]));
	
	printf("二维数组的行数：%d\n",sizeof(arr)/sizeof(arr[0]));
	printf("二维数组的列数：%d\n",sizeof(arr[0])/sizeof(arr[0][0]));
	
	
	//二维数组的首地址
	printf("%p\n",arr);
	printf("%p\n",arr[0]);
	printf("%p\n",&arr[0][0]); 
	
	//当详细的表示出来数组的位置时，他都不是一个地址，而是一个值  如下：
	printf("\n"); 
	printf("%p\n",arr[0][0]); 
	printf("\n");
	
	
	
}


int main()
{
	
	test01();
	return 0;
 } 
