#include<stdio.h>


void test01()
{
	int a = 10;
	int *p = &a; //一级指针
	*p = 100; //*p就是a

	int **q = &p;
	//*q就是p
	//**q就是a
	
	
	//或者另一种赋值方法更好理解
	//int **q;
	//*q=&p; 
    //*为解地址 


	int ***t = &q;
	//*t就是q
	//**t就是p
	//***t就是a

	
}


void test02()
{
	int a[]={1,2,3};
	int b[]={4,5,6};
	int c[]={7,8,9};
	
	
	//指针数组对应于二级指针 
	int *arr[]= {a,b,c};
	
	//指针数组和二级指针建立关系     
    int **p=arr;
    //一级指针加偏移量相当于跳过了一个元素
	printf("%d\n",*(*p+1));//arr[0][1]
    
    
    //二级指针加偏移量相当于跳过了一个一维数组大小 
    printf("%d\n",**(p+1)); //arr[1][0]
     printf("%d\n",**p+2);
     
	//p是最外边的    改变p是变化最小的 （就是一维数组，改元素就更深入了）    
	//*p是中间的 
	//**p是最里边的    改变**p是变化最大的   改变方式是**p+1  而不是**(p+1)   后者是第一种 
	//如果***p    则也是最里边的 
    //参考一级指针里面的*p  和p	
}

void test03()
{
	
	//pp  二级指针变量的值 
	//*pp一级指针的值 
	//**pp变量的值 
	int a=10;
	int b=20;
	int *p=&a;
	int **pp=&p;
	int ***ppp=&pp;
	//*ppp==pp==&p;
	//**ppp==*pp==p==&a;
	//***ppp==**pp==*p==a; 
	
	//***ppp表示最里面的   ppp==&pp； 
	
	
	*pp=&b;//等价于*p=&b;
	
	printf("%d\n",*p); 
	
}


 

int main()
{
	test01();
//	test02(); 
	test03();
	return 0;
 } 
