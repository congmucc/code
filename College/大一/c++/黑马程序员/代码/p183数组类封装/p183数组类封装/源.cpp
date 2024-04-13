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
	cout << "arr1�����Ϊ��" << endl;
	printIntArray(arr1);

	cout << "arr1������Ϊ��" <<arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�СΪ��" << arr1.getSize() << endl;




	MyArray <int>arr2(arr1);
	cout << "arr2�����Ϊ��" << endl;
	printIntArray(arr2);

	cout << "arr2������Ϊ��" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�СΪ��" << arr2.getSize() << endl;




	MyArray <int>arr3(100);
	arr3 = arr1;
	cout << "arr3�����Ϊ��" << endl;
	printIntArray(arr3);

	cout << "arr3������Ϊ��" << arr3.getCapacity() << endl;
	cout << "arr3�Ĵ�СΪ��" << arr3.getSize() << endl;
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
		cout << "������" << arr[i].m_Name << " ���䣺" << arr[i].m_Age << endl;
	}
}

void test02()
{
	MyArray <Person>arr(10);
	Person p1("�����", 99999);
	Person p2("�����", 9999);
	Person p3("�����", 999);
	Person p4("�����", 99);
	Person p5("�����", 9);

	//��������

	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

    //��ӡ����

	printPersonArray(arr);
}
int main()
{
	//test01();
	test02();
	return 0;
}