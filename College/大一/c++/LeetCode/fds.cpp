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
		//�м����4���ֽڣ�int�ͣ����ʵ�ַ���4����ַ����Ϊ�����ڴ�����׵�ַ
		printf("%p \n",&arr[j]);
	}

	
	
	return 0;
}
