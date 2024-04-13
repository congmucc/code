#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>






void test01()
{
//	void *memset(void *s, int c, size_t n);
//功能：将s的内存区域的前n个字节以参数c填入
//参数：
//	s：需要操作内存s的首地址
//	c：填充的字符，c虽然参数为int，但必须是unsigned char , 范围为0~255
//	n：指定需要设置的大小
//返回值：s的首地址

	
	int* p=(int*)malloc(sizeof(int)*10);
	//memest()重置内存空间值
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
//功能：拷贝src所指的内存内容的前n个字节到dest所值的内存地址上。
//参数：
//	dest：目的内存首地址
//	src：源内存首地址，注意：dest和src所指的内存空间不可重叠，可能会导致程序报错
//	n：需要拷贝的字节数
//返回值：dest的首地址

	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10];
	
	memcpy(b, a, sizeof(a));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", b[i]);
	}
	printf("\n");
	//memcpy(&a[3], a, 5 * sizeof(int)); //err, 内存重叠

	
}


void test03()
{	
//	int memcmp(const void *s1, const void *s2, size_t n);
//功能：比较s1和s2所指向内存区域的前n个字节
//参数：
//	s1：内存首地址1
//	s2：内存首地址2
//	n：需比较的前n个字节
//返回值：
//	相等：=0
//	大于：>0
//	小于：<0


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
