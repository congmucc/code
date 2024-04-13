#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>


void printIntArray(MyArray <int> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	MyArray <int>arr1(5);
	for (int k = 0; k < 5; k++)
	{
		arr1.Push_Back(k);
	}
	cout << "arr1的输出为：" << endl;
	printIntArray(arr1);

	cout << "arr1的容量为：" <<arr1.getCapacity() << endl;
	cout << "arr1的大小为：" << arr1.getSize() << endl;




	MyArray <int>arr2(arr1);
	cout << "arr2的输出为：" << endl;
	printIntArray(arr2);

	cout << "arr2的容量为：" << arr2.getCapacity() << endl;
	cout << "arr2的大小为：" << arr2.getSize() << endl;




	MyArray <int>arr3(100);
	arr3 = arr1;
	cout << "arr3的输出为：" << endl;
	printIntArray(arr3);

	cout << "arr3的容量为：" << arr3.getCapacity() << endl;
	cout << "arr3的大小为：" << arr3.getSize() << endl;
}

class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray <Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名：" << arr[i].m_Name << " 年龄：" << arr[i].m_Age << endl;
	}
}

void test02()
{
	MyArray <Person>arr(10);
	Person p1("孙悟空", 99999);
	Person p2("孙悟空", 9999);
	Person p3("孙悟空", 999);
	Person p4("孙悟空", 99);
	Person p5("孙悟空", 9);

	//插入数组

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

    //打印数组

	printPersonArray(arr);
}
int main()
{
	//test01();
	test02();
	return 0;
}