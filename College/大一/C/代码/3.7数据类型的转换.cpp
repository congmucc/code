#include<stdio.h>



void test01()
{
//	1、自动转换(隐式转换)：遵循一定的规则,由编译系统自动完成。
// 	2、强制类型转换：把表达式的运算结果强制转换成所需的数据类型。
    
    int w=2;
    float p=3.14;
    
	//隐式转换
	double sum=p*w;
	printf("%lf\n",sum); 
	
	
	//强制转换 
	int sun= (int)p*w;
	printf("%d",sun); 
	
}

int main()
{
	test01();
	return 0;
 } 
