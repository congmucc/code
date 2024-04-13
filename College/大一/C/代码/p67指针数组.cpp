#include<stdio.h>





void test01()
{
	int d=10;
	int e=20;
	int *arr1[2]={&d,&e};
	printf("%d\n",*arr1[0]);//这个还好吧 
	
	
//	
//	int *P; 
//	
//	p=&b; 
//	
	
	
	int a[]={1,2,3};
	int b[]={4,5,6};
	int c[]={7,8,9};
	
	//指针数组里面元素存的是指针 
	//指针数组，它是数组，数组的每个元素都是指针类型。 也就是地址？？？？？ 
	int *arr[3]= {a,b,c};
	
	printf("%d\n",arr[0]);   
	printf("%d\n",arr[0][2]);  //  指针数组就是一个特殊的二维数组模型 
	
	
}




void test02()
{
	//指针数组
	int *p[3];
	int a = 1;
	int b = 2;
	int c = 3;
	int i = 0;

	p[0] = &a;
	p[1] = &b;
	p[2] = &c;

	for (i = 0; i < sizeof(p) / sizeof(p[0]); i++ )
	{
		printf("%d, ", *(p[i]));
	}
	printf("\n");
	

}


int main()
{
	test01();
	
	test02(); 
	return 0;
}
