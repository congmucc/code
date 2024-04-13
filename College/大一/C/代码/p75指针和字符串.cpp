#include<stdio.h>




void test01()
{
	char ch[]="hello world";
	
//	char *p=ch;
//	printf("%s\n",p);
//	printf("%c\n",*(p+1));
	
	
	char *p="hello world";
	ch[2]='m';
	p[2]='m';
	printf("%s\n",ch);
	printf("%s\n",p);
	
}


int main()
{
	test01();
	
	return 0;
}
