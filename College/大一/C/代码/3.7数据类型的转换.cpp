#include<stdio.h>



void test01()
{
//	1���Զ�ת��(��ʽת��)����ѭһ���Ĺ���,�ɱ���ϵͳ�Զ���ɡ�
// 	2��ǿ������ת�����ѱ��ʽ��������ǿ��ת����������������͡�
    
    int w=2;
    float p=3.14;
    
	//��ʽת��
	double sum=p*w;
	printf("%lf\n",sum); 
	
	
	//ǿ��ת�� 
	int sun= (int)p*w;
	printf("%d",sun); 
	
}

int main()
{
	test01();
	return 0;
 } 
