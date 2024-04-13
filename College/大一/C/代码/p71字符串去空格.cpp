#include<stdio.h>


void remove_space(char *ch)
{
	char str[100]={0};
	int i=0;
	int j=0;
	while(ch[i]!=0)
	{
		if(ch[i]!=' ')
		{
			str[j]=ch[i];
			j++;
		}
		i++;
	}	
	printf("%s",str);


}

void remove_space1(char* ch)
{
	//用来遍历字符串 
	char* ftemp=ch;
	//记录非空格字符串
	char* rtemp=ch;
	while(*ftemp) 
	{
		if(*ftemp!=' ')
		{
			*rtemp=*ftemp;
			*rtemp++;
		}
		ftemp++;
	}
	*rtemp=0;
	
	printf("%s",rtemp);
}



void test01()
{
	char ch[]="  h  e  ll  o w o r ll d   ";
	
//	remove_space(ch);

    remove_space1(ch);
    
    printf("%s\n",ch);
}



int main()
{
	test01();
	
	return 0;
}
