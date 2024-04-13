#include<stdio.h>
#include<stdlib.h>



int main()
{
//	int a[10]={};
//	for(int i=0;i<5;i++)
//	{
//		a[i]=i;
//		printf("%p\n",a[i]);
//	 } 
//	
//	free(a);
//	
	    int arr[10]={1,2,3,4,5,6,7,8,9,0};	
	for(int j=0;j<sizeof(arr)/sizeof(arr[0]);j++)
	{
		//中间相差4个字节（int型），故地址相差4个地址，因为数组内存的是首地址
		printf("%p \n",&arr[j]);
	}

	
	
	return 0;
}
