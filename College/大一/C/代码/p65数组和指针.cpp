#include<stdio.h>




void test01()
{
	int arr[]={1,2,3,4,5,6,7,8,9,0};
	//��������һ������������ֵ
	//��������������Ԫ�ص�ַ
	//arr=100;//error
	
	int *p=arr;
	
	printf("p = %p\n",p);
	printf("arr = %p\n",arr); 
	printf("*p = %d\n",*p);
	printf("\n");
	
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
	{
		//������һ��  Ҫû�����һ��p++��һ�� 
		printf("*(p + i) = %d \n",*(p+i));
		printf("p[i] = %d \n",p[i]);  //��Ϊp=arr   arr�������׵�ַ 
		printf("arr[i] = %d \n",arr[i]);
		printf("*p++ = %p \n",*p++);  //��ʱp�ĵ�ַ��arr����40����Ϊp++�ˣ�ǰ������pû�мӽ���ͨ��i���ı�p+i��ֵ��ȡ��ַ 
		printf("\n");
	}
	
	//����ָ�����  �õ��Ľ��������ָ���ƫ������������
	//���е�ָ����� ����������int���͵�
	
	
//    int step=p-arr;
//	printf("\n");
//	printf("%d ",step); 
	
	
}

//������Ϊ�����������˻�Ϊָ��  ��ʧ����ľ���  ��Ҫ�ں��������һ��len 
//������Ļ����βε�lenɾ�˾��� 


void parr(int arr[],int len)
{
//	int len=sizeof(arr)/sizeof(arr[0]);

	printf("%d\n",len); // �����Ϊ10�� 
}



void test02()
{
	 int arr[10]={23,4326,6457,856,6,2,8,32,4,5};
	 int len=sizeof(arr)/sizeof(arr[0]);
	 
	 parr(arr,len);
	 
}



int main()
{
	test01();
	
//	test02(); 
	
	return 0;
 } 
