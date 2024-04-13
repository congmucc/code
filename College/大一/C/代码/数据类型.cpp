#include<stdio.h>


int main()
{
	int a = 10;
	
	short b = 20;
	
	long c = 30;
	
	long long d=40;
	
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%d\n",d);
	
    printf("整型：%d\n",sizeof(a));     //1字节BETY==8bit(比特) 
	printf("短整型：%d\n",sizeof(b));
	printf("长整型：%d\n",sizeof(c));
	printf("长长整型：%d\n",sizeof(d));
	
	return 0;
 } 
