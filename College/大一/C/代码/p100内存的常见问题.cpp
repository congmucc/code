#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

void test01()
{
	
	char* p=(char*)malloc(sizeof(char)*11);
	strcpy(p,"hello world");  //vs����ִ���   ����Ϊ������11���ռ�  ��������\0  �ַ����ܹ���12��  ����Խ��  �������� 
	printf("%s\n",p);
	
	free(p);
	
//	free(p);  ��ʱp�Ѿ���Ұָ����  ���ͷžʹ���   �ѿռ䲻�������ͷ� 
}



void test02()
{ 
//	int *p=(int*)malloc(0);  //����ֱ������0���ֽڵĿռ���ò�Ҫд����	�൱��Ұָ��
//    int *p=(int*)malloc(sizeof(int)*10);   //���������д����sizeof�����������ֽ� 
 } 




void test03()
{
	int *p=(int*)malloc(sizeof(int)*10);
	
	int *temp=p;
	for(int i=0;i<10;i++)
	{
		*p=i;
		//ָ�����  ���ϸı�ָ�뷽��  �ͷŻ���� 
		p++; 
	}
	
	
	//��ʱp�Ѿ�����ԭ��ַ�� 
	free(p);
}

//void fun01(int *p)  //��������һ��  ������ֵ����   ��ʱ�βε�p����Ϊ��ʱ����  ����֮��ֱ������  һ����������֮��test04�����p����NULL 
//{
//	p=(int*)malloc(sizeof(int)*10);
//	
//}

void fun02(int **p)  //��ʱ���ǵ�ַ����  p����ŵ���ʵ��p�ĵ�ַ 
{
	*p=(int*)malloc(sizeof(int)*10);
	
}

int *fun03()
{
	int *p=(int*)malloc(sizeof(int)*10);
	return p;
}


void test04()
{
	int *p=NULL;
//	fun01(p);  //  ֵ����    err 
	fun02(&p);  //  ��ַ���� 
    p=fun03();  //  ����ֵ���� 

	for(int i=0;i<10;i++)
	{
		p[i]=i;
	}
	free(p);
	
	
}

int main()
{
//	test01();
//	test02(); 
//	test03(); 
    test04(); 
    
    
	return 0;
 } 
