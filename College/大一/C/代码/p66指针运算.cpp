#include<stdio.h>


//void my_strcpy(char* dest,char* ch)
//{
//	int i=0;
//	while(ch[i]!=0)
//	{
//		dest[i]=ch[i];
//		i++;
//	}
//	dest[i]=0;
//	
//}

//void my_strcpy(char* dest,char* ch)
//{
//	int i=0;
//	while(*(ch+i)!=0)
//	{
//		*(dest+i)=*(ch+i);
//		i++;
//	 } 
//	 *(dest+i)=0;
//}

void my_strcpy(char* dest,char* ch)
{
	while(*ch)
	{
		*dest=*ch;
		dest++; //指针相加是char类型的相加，每次相加一个字节。 
		*ch++;     //这个*和++两者优先级一样    但是顺序是从右向左 
	}
	*dest=0;
}

//void my_strcpy(char* dest,char* ch)
//{
//	while(*dest++=*ch++); 
//}




void test01()
{
	//字符串的拷贝
	char ch[]="hello world";
	char dest[100];
	my_strcpy(dest,ch);	
	
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = arr;
	printf("sizeof(p) = %d\n", sizeof(p));
	printf("sizeof(*p) = %d\n", sizeof(*p));
	printf("*p = %d\n", *p);
	printf("p = %d\n", p); 
	p++; 
	printf("======================================\n");
	printf("sizeof(p) = %d\n", sizeof(p));
	printf("sizeof(*p) = %d\n", sizeof(*p));
	printf("*p = %d\n", *p);
	printf("p = %d\n", p); 
	
	printf("%s ",dest);
	
	
	
}



int main()
{
	
	test01(); 
	return 0;
 } 
