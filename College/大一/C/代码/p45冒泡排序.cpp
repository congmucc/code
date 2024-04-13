#include<stdio.h>



void test01()
{
	int arr[10]={2,6,7,1,5,9,3,4,8,0};
	 
	
	for(int i=0;i<sizeof(arr)/sizeof(arr[0])-1;i++)    //sizeof(arr)/sizeof(arr[0])-1==9
	{
		for(int j=0;j<sizeof(arr)/sizeof(arr[0])-1-i;j++) //10-1-i   因为数组的下标是从0开始的 
		{
			if(arr[j]<arr[j+1])
			{
				
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
			}
		}
	}
	
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	
}


int main()
{
	
	test01();
	return 0;
}
