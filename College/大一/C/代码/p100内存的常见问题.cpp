#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

void test01()
{
	
	char* p=(char*)malloc(sizeof(char)*11);
	strcpy(p,"hello world");  //vs会出现错误   是因为申请了11个空间  但是算上\0  字符串总共有12个  导致越界  产生错误 
	printf("%s\n",p);
	
	free(p);
	
//	free(p);  此时p已经是野指针了  再释放就错了   堆空间不允许多次释放 
}



void test02()
{ 
//	int *p=(int*)malloc(0);  //不能直接申请0个字节的空间最好不要写数字	相当于野指针
//    int *p=(int*)malloc(sizeof(int)*10);   //最好这样子写，用sizeof函数来计算字节 
 } 




void test03()
{
	int *p=(int*)malloc(sizeof(int)*10);
	
	int *temp=p;
	for(int i=0;i<10;i++)
	{
		*p=i;
		//指针叠加  不断改变指针方向  释放会出错 
		p++; 
	}
	
	
	//此时p已经不是原地址了 
	free(p);
}

//void fun01(int *p)  //两个级别一样  现在是值传递   此时形参的p仅仅为临时变量  用完之后直接销毁  一个周期完了之后test04里面的p还是NULL 
//{
//	p=(int*)malloc(sizeof(int)*10);
//	
//}

void fun02(int **p)  //此时才是地址传递  p里面放的是实参p的地址 
{
	*p=(int*)malloc(sizeof(int)*10);
	
}

int *fun03()
{
	int *p=(int*)malloc(sizeof(int)*10);
	return p;
}


void test04()
{
	int *p=NULL;
//	fun01(p);  //  值传递    err 
	fun02(&p);  //  地址传递 
    p=fun03();  //  返回值传递 

	for(int i=0;i<10;i++)
	{
		p[i]=i;
	}
	free(p);
	
	
}

int main()
{
//	test01();
//	test02(); 
//	test03(); 
    test04(); 
    
    
	return 0;
 } 
