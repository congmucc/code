#include<stdio.h>


void find_str(char *str,int len)
{
	int k=0,i=0;
	char *m_str=str;  //遍历字符串 
	char r_str[]="0";   //记录 
	char fStr[]="llo";  // 查找的字符串 

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
	
	printf("查到在原字符串的第%d位，查找的记录：%s",i-2,r_str);  //2是直接从llo中最后一位减两位过来的 
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
