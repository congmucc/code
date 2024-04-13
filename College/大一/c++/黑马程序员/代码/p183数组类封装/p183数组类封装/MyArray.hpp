#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造
	MyArray(int capacity)
	{
		//cout << "有参构造" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "深拷贝" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator=     防止浅拷贝

	MyArray &operator=(const MyArray &arr)
	{

		//cout << "重载=" << endl;
		//先判断原来的堆区是否有内存，如果有就释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int j = 0; j < this->m_Size; j++)
		{
			this->pAddress[j] = arr.pAddress[j];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T &val)
	{
		//判断容量大小是否相等
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		//尾插法
		this->pAddress[this->m_Size] = val;//更新数组大小
		this->m_Size++;
	}

	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，逻辑上的尾删
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//返回数组的容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组的大小
	int getSize()
	{
		return this->m_Size;
	}


	//通过下标方式访问数组元素
	T& operator[](int index)
	{
		return this->pAddress[index];
	}


	//析构
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "析构" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:

	T* pAddress;//指针指向堆区开辟的真实数组

	int m_Capacity;//数组容量

	int m_Size;//数组大小，就是现在有几个数
};