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
	
    printf("���ͣ�%d\n",sizeof(a));     //1�ֽ�BETY==8bit(����) 
	printf("�����ͣ�%d\n",sizeof(b));
	printf("�����ͣ�%d\n",sizeof(c));
	printf("�������ͣ�%d\n",sizeof(d));
	
	return 0;
 } 
