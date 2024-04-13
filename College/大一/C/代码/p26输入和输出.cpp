#include<stdio.h>
#include<stdlib.h>

void test01()
{
	char *b="hello world"; //这里面最后有\0,总共12个字符，如果在11位也就是使占位符不遇见\0,他会出现bug  例
//	char  p[11]="hello world"; //这个 
	//占位符，表示输出一个字符串，遇到\0停止 
	printf("%s\n",b);
//	printf("%s\n",p);
	system("pause");

}


void test02()
{
	
//l(字母l)	附加在d,u,x,o前面，表示长整数
//-	左对齐
//m(代表一个整数)	数据最小宽度
//0(数字0)	将输出的前面补上0直到占满指定列宽为止不可以搭配使用-
//m.n(代表一个整数)	m指域宽，即对应的输出项在输出设备上所占的字符数。n指精度，用于说明输出的实型数的小数位数。对数值型的来说，未指定n时，隐含的精度为n=6位。

    int a=12;
    float b=3.1415926;
	printf("===%-3d===",a); //2  3
	printf("===%7.2f===",b);

}


void test03()
{
	
//	printf是输出一个字符串，putchar输出一个char。
	char ch='a';
	
	printf("%c\n",ch);
	
	putchar(ch);
	putchar('B');  //单个字符串 
	putchar(97);  //ascii值 
	putchar('\n');  //转义字符 
	
	
}

void test04()
{
//	char ch;
//	scanf("%c",&ch);
//	printf("%c",ch);
    
    int a,b;
    scanf("%d %d",&a,&b);  //两个%d之间的空格可以设置由空格来写b，而不是只能通过返回键才能进行写b，如果空格换成, 那在缓冲区写入,  可以进行b的书写
	//但是不能进行\n进行分割 会直接重复回车了，少输入数据
	//%3d可以进行输入限制，只能对整形进行约束，浮点型不行 


    printf("%d\t%d",a,b);
    
}

void test05()
{
//	getchar是从标准输入设备读取一个char。
// 	scanf通过%转义的方式可以得到用户通过标准输入设备输入的数据。

	char ch;
	
	
    //接受键盘获取字符 
	ch= getchar();
	
	
   	//用于暂时停留界面 
	putchar(ch);
}

int main()
{
//    test01();
//    test02();
//    test03();

/*==================scanf()=======================*/ 
    
// 	  test04();
//	  test05(); 
	return 0;
}
