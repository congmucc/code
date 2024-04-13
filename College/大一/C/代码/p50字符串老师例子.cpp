#include<stdio.h>


void test01()
{
	//	C语言中没有字符串这种数据类型，可以通过char的数组来替代；
// 	字符串一定是一个char的数组，但char的数组未必是字符串；
// 	数字0(和字符'\0'等价)结尾的char数组就是一个字符串，但如果char数组没有以数字0结尾，
//  那么就不是一个字符串，只是普通字符数组，所以字符串是一种特殊的char的数组。

	char c1[] = { 'c', ' ', 'p', 'r', 'o', 'g' }; //普通字符数组
	//  如果 char c4[100]={'c', ' ', 'p', 'r', 'o', 'g'} 就正确   因为自动补0了 
	printf("c1 = %s\n", c1); //乱码，因为没有'\0'结束符

	//以'\0'('\0'就是数字0)结尾的字符数组是字符串
	char c2[] = { 'c', ' ', 'p', 'r', 'o', 'g', '\0'}; 
	printf("c2 = %s\n", c2);

	//字符串处理以'\0'(数字0)作为结束符，后面的'h', 'l', 'l', 'e', 'o'不会输出
	char c3[] = { 'c', ' ', 'p', 'r', 'o', 'g', '\0', 'h', 'l', 'l', 'e', 'o', '\0'};
	printf("c3 = %s\n", c3);

}


void test02()
{
	
	// C语言没有字符串类型，通过字符数组模拟
    // C语言字符串，以字符'\0', 数字0

	//不指定长度, 没有0结束符，有多少个元素就有多长
	char buf[] = { 'a', 'b', 'c' };
	printf("buf = %s\n", buf);	//乱码

	//指定长度，后面没有赋值的元素，自动补0
	char buf2[100] = { 'a', 'b', 'c' };
    char buf[1000]={"hello"};
    
    
    char buf[]= {"hello"};  //  也是字符串，和 char buf[]= "hello";一样 
    char buf[]= {"hello","world"};  //  这个是错的，hello和world两个字符串了，两个一起是字符串数组了。改成下面的才对
	char buf[][6]= {"hello","world"};
    
    
	printf("buf2 = %s\n", buf2);

	//所有元素赋值为0
	char buf3[100] = { 0 };

	//char buf4[2] = { '1', '2', '3' };//数组越界

	char buf5[50] = { '1', 'a', 'b', '0', '7' };
	printf("buf5 = %s\n", buf5);

	char buf6[50] = { '1', 'a', 'b', 0, '7' };
	printf("buf6 = %s\n", buf6);

	char buf7[50] = { '1', 'a', 'b', '\0', '7' };
	printf("buf7 = %s\n", buf7);

	//使用字符串初始化，编译器自动在后面补0，常用
	char buf8[] = "agjdslgjlsdjg";

	//'\0'后面最好不要连着数字，有可能几个数字连起来刚好是一个转义字符
	//'\ddd'八进制字义字符，'\xdd'十六进制转移字符
	// \012相当于\n
	char str[] = "\012abc";
	printf("str == %s\n", str);


}


int main()
{   

    //对于arr[max]   多了无法显示'\0'乱码，少了补0
	
	//对于arr[]     得加0（'\0'）来结束，当然 char buf[]= {"hello"};这个例外   视频p50 
	test01();
	
	test02();
	return 0;
}
