#include<iostream> 

using namespace std;

#include<string>

class Animal {
	public :
		Animal()
	{
		cout<<"Animal的构造函数"<<endl;
	}
	
	virtual void speak() = 0;
		
	virtual ~Animal() = 0;
};

Animal::~Animal() {
	cout << "纯虚析构" << endl; 
} 


class Cat : public Animal {
	public :
		Cat(string name) {
			cout << "Cat的构造函数调用" <<endl; 
			m_Name = new string(name);
		}
		virtual void speak() {
			cout << *m_Name << "在说话" << endl;
			cout << "\nm_Name的地址: " << m_Name << "\n" << endl;
		}

		~Cat() {
			if (m_Name != NULL) {
				cout << "Cat的析构函数调用" <<endl;
				delete m_Name;
				m_Name = NULL; 
			}
		}
		string *m_Name;
};


void test01() {
	Animal * animal = new Cat("Tom");
	cout << "\nanimal的地址:" <<animal << "\n" << endl;
	animal->speak();
	/*
	没有delete删除animal不会调用各自的析构函数 
	析构函数在下边3种情况时被调用：

    1，对象生命周期结束，被销毁时；
    2，主动调用delete ；
    3，对象i是对象o的成员，o的析构函数被调用时，对象i的析构函数也被调用。
	
	
	*/
	delete animal;
}

int main() {
	test01();
	
	return 0;
}
