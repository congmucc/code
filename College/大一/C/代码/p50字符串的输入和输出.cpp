#include<stdio.h>
#include<string.h>

void test01()
{
	char ch[100];
	
	//  �ӱ�׼��������ַ��������浽sָ�����ڴ�ռ䣬ֱ�����ֻ��з�������ļ���βΪֹ��
	//  gets(str)��scanf("%s",str)������
    // 	gets(str)����������ַ������пո�
    // 	scanf("%s",str)�������пո�
    //  scanf("%[^\n]",ch)  ͨ��������ʽ  ���Կո�  ���ճ��˻س�֮��������ַ� 

	gets(ch);
	
	
	//  ��׼�豸���s�ַ������������ɺ��Զ����һ��'\n'��
	
	//puts�Դ�����
	puts(ch);
	
	
    
}


void test02()
{
	char  ch[100]="hello world";
	//char  ch[]="hello world";   �����С��12�����ַ�������11�� 
	printf("�����С��%d",sizeof(ch));
	printf("�ַ������ȣ�%d",strlen(ch));
	
	int len=0;
	while (ch[len] !='\0')
	{
		len++;
	} 
	 
    //���ķ���1�� 
	//while(ch[len] !='\0')len++; 
    
    //����д��2��
	// 
    
    printf("�ַ������ȣ�%d",len);	
	
}


int main()
{
//	test01();
	test02();
	
	return 0;
}
