#include<stdio.h>
#include<string.h>

void test01()
{
	char ch[100];
	
	//  从标准输入读入字符，并保存到s指定的内存空间，直到出现换行符或读到文件结尾为止。
	//  gets(str)与scanf("%s",str)的区别：
    // 	gets(str)允许输入的字符串含有空格
    // 	scanf("%s",str)不允许含有空格
    //  scanf("%[^\n]",ch)  通过正则表达式  忽略空格  接收除了回车之外的所有字符 

	gets(ch);
	
	
	//  标准设备输出s字符串，在输出完成后自动输出一个'\n'。
	
	//puts自带换行
	puts(ch);
	
	
    
}


void test02()
{
	char  ch[100]="hello world";
	//char  ch[]="hello world";   数组大小是12个，字符串还是11个 
	printf("数组大小：%d",sizeof(ch));
	printf("字符串长度：%d",strlen(ch));
	
	int len=0;
	while (ch[len] !='\0')
	{
		len++;
	} 
	 
    //简洁的方法1、 
	//while(ch[len] !='\0')len++; 
    
    //简洁的写法2、
	// 
    
    printf("字符串长度：%d",len);	
	
}


int main()
{
//	test01();
	test02();
	
	return 0;
}
