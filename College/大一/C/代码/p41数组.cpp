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
		//�м����4���ֽڣ�int�ͣ����ʵ�ַ���4����ַ����Ϊ�����ڴ�����׵�ַ
		printf("%p ",&arr[j]);
	}
	printf("\n");
	// ��������һ����ַ����  ָ�������׵�ַ�ĳ���  �ʿ���ֱ��дarr��ʾ�������飨��������һ���Ǳ�ʾ����������׵�ַ��
	// arr[0]��ʾ�������ݣ������ǵ�ַ�� 
	
	
	//�������ڴ���ռ�õ��ڴ�Ϊ = �������� * Ԫ�ظ��� 
	printf("�������ڴ���ռ�õĴ�С��%d\n",sizeof(arr));
	printf("����Ԫ�ش�С��%d\n",sizeof(arr[0]));
	printf("����Ԫ�ظ�����%d\n",sizeof(arr)/sizeof(arr[0]));
    
}


int main()
{
	test01();
	return 0;
}
