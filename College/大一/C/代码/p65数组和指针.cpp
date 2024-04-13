#include<stdio.h>




void test01()
{
	int arr[]={1,2,3,4,5,6,7,8,9,0};
	//数组名是一个常量不允许赋值
	//数组名是数组首元素地址
	//arr=100;//error
	
	int *p=arr;
	
	printf("p = %p\n",p);
	printf("arr = %p\n",arr); 
	printf("*p = %d\n",*p);
	printf("\n");
	
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
	{
		//这三个一样  要没有最后一个p++才一样 
		printf("*(p + i) = %d \n",*(p+i));
		printf("p[i] = %d \n",p[i]);  //因为p=arr   arr是数组首地址 
		printf("arr[i] = %d \n",arr[i]);
		printf("*p++ = %p \n",*p++);  //此时p的地址比arr大了40，因为p++了，前面两个p没有加仅仅通过i来改变p+i的值来取地址 
		printf("\n");
	}
	
	//两个指针相减  得到的结果是两个指针的偏移量（步长）
	//所有的指针相减 相减结果都是int类型的
	
	
//    int step=p-arr;
//	printf("\n");
//	printf("%d ",step); 
	
	
}

//数组作为函数参数会退化为指针  丢失数组的精度  故要在函数后面加一个len 
//看结果的话吧形参的len删了就行 


void parr(int arr[],int len)
{
//	int len=sizeof(arr)/sizeof(arr[0]);

	printf("%d\n",len); // 结果不为10， 
}



void test02()
{
	 int arr[10]={23,4326,6457,856,6,2,8,32,4,5};
	 int len=sizeof(arr)/sizeof(arr[0]);
	 
	 parr(arr,len);
	 
}



int main()
{
	test01();
	
//	test02(); 
	
	return 0;
 } 
