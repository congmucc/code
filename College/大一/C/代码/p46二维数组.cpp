#include<stdio.h>


void test01()
{
	int arr[2][3]=
	{
	    {1,2,3},
	    {4,5,6}
	};
	
	printf("��ά����Ĵ�С��%d\n",sizeof(arr));
	printf("��ά�����һ�д�С��%d\n",sizeof(arr[0]));
	printf("��ά�����Ԫ�ش�С��%d\n",sizeof(arr[0][0]));
	
	printf("��ά�����������%d\n",sizeof(arr)/sizeof(arr[0]));
	printf("��ά�����������%d\n",sizeof(arr[0])/sizeof(arr[0][0]));
	
	
	//��ά������׵�ַ
	printf("%p\n",arr);
	printf("%p\n",arr[0]);
	printf("%p\n",&arr[0][0]); 
	
	//����ϸ�ı�ʾ���������λ��ʱ����������һ����ַ������һ��ֵ  ���£�
	printf("\n"); 
	printf("%p\n",arr[0][0]); 
	printf("\n");
	
	
	
}


int main()
{
	
	test01();
	return 0;
 } 
