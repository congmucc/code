#include<stdio.h>



void test01()
{
	char arr[10]={1,2,3,4,5,6,7,8,9,0}; 
	int i=0,j=9;
	
	while(i<j)
	{
		int temp;
		arr[temp]=arr[i];
		arr[i]=arr[j];
		arr[j]=arr[temp];
		
		++i;
		--j;
	}
	
	for(int k=0;k<sizeof(arr)/sizeof(arr[0]);k++)
	{
		printf("%d ",arr[k]);
	 } 
	
}


int main()
{
	
	test01();
	return 0;
 } 
