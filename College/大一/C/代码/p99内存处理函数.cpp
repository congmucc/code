#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>






void test01()
{
//	void *memset(void *s, int c, size_t n);
//���ܣ���s���ڴ������ǰn���ֽ��Բ���c����
//������
//	s����Ҫ�����ڴ�s���׵�ַ
//	c�������ַ���c��Ȼ����Ϊint����������unsigned char , ��ΧΪ0~255
//	n��ָ����Ҫ���õĴ�С
//����ֵ��s���׵�ַ

	
	int* p=(int*)malloc(sizeof(int)*10);
	//memest()�����ڴ�ռ�ֵ
	memset(p,1,40);
	
	
	for(int i=0;i<10;i++)
	{
		printf("%d\n",p[i]); 
	} 
	
	free(p);
	
	

}


void test02()
{
//	void *memcpy(void *dest, const void *src, size_t n);
//���ܣ�����src��ָ���ڴ����ݵ�ǰn���ֽڵ�dest��ֵ���ڴ��ַ�ϡ�
//������
//	dest��Ŀ���ڴ��׵�ַ
//	src��Դ�ڴ��׵�ַ��ע�⣺dest��src��ָ���ڴ�ռ䲻���ص������ܻᵼ�³��򱨴�
//	n����Ҫ�������ֽ���
//����ֵ��dest���׵�ַ

	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10];
	
	memcpy(b, a, sizeof(a));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", b[i]);
	}
	printf("\n");
	//memcpy(&a[3], a, 5 * sizeof(int)); //err, �ڴ��ص�

	
}


void test03()
{	
//	int memcmp(const void *s1, const void *s2, size_t n);
//���ܣ��Ƚ�s1��s2��ָ���ڴ������ǰn���ֽ�
//������
//	s1���ڴ��׵�ַ1
//	s2���ڴ��׵�ַ2
//	n����Ƚϵ�ǰn���ֽ�
//����ֵ��
//	��ȣ�=0
//	���ڣ�>0
//	С�ڣ�<0


	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int flag = memcmp(a, b, sizeof(a));
	printf("flag = %d\n", flag);

}

int main()
{
	test01();
	test02();
	test03(); 
	return 0;
}
