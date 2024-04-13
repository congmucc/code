#include<stdio.h>








int main()
{
	int i;
	for(i=0;i<10;i++)
	{
		if(i==5)
		{
			printf("里面：%d\n",i);
			break;
		}
		
	}
	
	printf("外面：%d\n",i);
	return 0;
 } 
