#include<stdio.h>


void find_str(char *str,int len)
{
	int k=0,i=0;
	char *m_str=str;  //�����ַ��� 
	char r_str[]="0";   //��¼ 
	char fStr[]="llo";  // ���ҵ��ַ��� 

	while(*m_str)
	{
		i++;
		m_str++;
		if(*m_str==fStr[k])
		{
			r_str[k]=fStr[k]; 
			k++;
			if(k==(sizeof(fStr)/sizeof(char)-1))
     		{
			
		    	break;
	    	}
		}
		else
		{
			k=0;
		}
	} 
	
	printf("�鵽��ԭ�ַ����ĵ�%dλ�����ҵļ�¼��%s",i-2,r_str);  //2��ֱ�Ӵ�llo�����һλ����λ������ 
}



void test01()
{
	char str[]="hello world";
	
	int str_len = sizeof(str)/sizeof(char);
	
	find_str(str,str_len);
	
}



int main()
{
	
	test01();
	return 0;
 } 
