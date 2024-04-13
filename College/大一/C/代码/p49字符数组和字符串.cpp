#include<stdio.h>


void test01()
{
	//定义字符数组
    char arr[5]={'h','e','l','l','o'};  //这个其实是错的，因为这时候应该留一个存\0,不然不会停止
	//多出些这种的    烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫烫號U^札  乱码 
	//在vs里面报错， {} 里面有6个，因为还有一个\0 
	
	//看看  输入和输出  这个例子 
	
    //字符
	char ch='a';
	//字符串  字符串的结束标志为\0   数字0等同于\0  但是不等同于‘0’
	
	//字符串算是字符数组的特例 
	char *arr1 = "hello"; 
    
    
    
    
    printf("%d\n",sizeof(arr));//sizeof(数据类型)
	
	for(int i=0;i<sizeof(arr);i++)
	{
		printf("%c ",arr[i]);
	}
	
}

void test02()
{
	
	char ch[10];
	
	scanf("%s",ch);  //没加&是因为 ch本身就是地址    字符串不要大于10个，test01里面讲了留个\0   vs里面报错  但是不会出现乱码，只会打印到几个字节 
	//Stack around the variable 'ch' was corrupted.   报错代码 
	
	//scanf  接收空格和换行就停止从缓冲区读取数据   例如  写  hello wor    打印出hello  因为wor前面有个空格 
	
	//默认以空格分割 
	
	printf("%s",ch);
	
	
	
}

void test03()
{
	//字符串的拼接
	char ch1[] = "hello";
	char ch2[] = "world";
	char ch3[20];
	
	int i = 0;
	int j = 0;
	while(ch1[i]!='\0')
	{
		ch3[i]=ch1[i];
		i++; 
    }//此时要是直接编译会多出来乱码，就因为没有'\0'   没读到ch3中 
	while(ch2[j]!=0)
	{
		ch3[i+j]=ch2[j];  //这个i+j是因为上面的i是第六位，读到'\0'不会补到ch3中，j=0时，i+j这时候是6  里面啥都没有
		j++;
	}
	
	
	//上文说了0和'\0'一样 
	ch3[i+j]=0;//加入'\0'防止乱码，看test01案例 
	
	printf("%s",ch3);
	 
	 
}



int main()
{
	
//	test01();
//	test02(); 
//  test03();    
	return 0;
 } 
