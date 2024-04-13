#include<iostream>

using namespace std;

#include<string>


//    https://blog.csdn.net/qq_35426012/article/details/73507086    有例子 
//    1.成员类型是没有默认构造函数的类。若没有提供显示初始化式，则编译器隐式使用成员类型的默认构造函数，若类没有默认构造函数，则编译器尝试使用默认构造函数将会失败
//    2.const成员(常量）或引用类型的成员。因为const对象或引用类型只能初始化，不能在构造函数中对他们赋值 
//    3.成员类型是没有默认构造函数的类使用初始化列表
class Person {
	public :
		int mAge;
		string mName;
		Person (string name, int age): mName(name), mAge(age) {
		};
		void show();
};

void Person::show() {
	cout<< "姓名： " << mName << "\n年龄： " << mAge <<endl; 
}


int main() {
	/*不能写成   
	Person p1;
	p1("小明", 19); 
	因为这是初始化列表，初始化的意思是先给对象一个值，必须的 
	1. 初始化对象
初始化对象是指，为对象分配内存后第一次向内存中填充数据，这个过程会调用构造函数，对象被创建后必须立即初始化。也就是说只要创建对象就会调用构造函数。
    2.初始化和赋值的区别
初始化和赋值都是将数据写入内存中，从表面看，初始化在很多时候都是以复制的方式来实现的，很容易引起混淆。在定义的同时进行复制叫做初始化，定义完成以后再赋值(不管定义的时候有没有赋值)就叫做赋值。初始化只能由一次，赋值可以由很多次。具体可以看下面的示例。
	
int a = 100;  //以赋值的方式初始化
a = 200;  //赋值
a = 300;  //赋值
int b;  //默认初始化
b = 29;  //赋值
b = 39;  //赋值
https://blog.csdn.net/KLKFL/article/details/87871418
	*/
	Person p1("小明", 19);
	p1.show(); 
	return 0;
}
