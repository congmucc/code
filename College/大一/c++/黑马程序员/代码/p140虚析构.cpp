#include<iostream> 

using namespace std;

#include<string>

class Animal {
	public :
		Animal()
	{
		cout<<"Animal�Ĺ��캯��"<<endl;
	}
	
	virtual void speak() = 0;
		
	virtual ~Animal() = 0;
};

Animal::~Animal() {
	cout << "��������" << endl; 
} 


class Cat : public Animal {
	public :
		Cat(string name) {
			cout << "Cat�Ĺ��캯������" <<endl; 
			m_Name = new string(name);
		}
		virtual void speak() {
			cout << *m_Name << "��˵��" << endl;
			cout << "\nm_Name�ĵ�ַ: " << m_Name << "\n" << endl;
		}

		~Cat() {
			if (m_Name != NULL) {
				cout << "Cat��������������" <<endl;
				delete m_Name;
				m_Name = NULL; 
			}
		}
		string *m_Name;
};


void test01() {
	Animal * animal = new Cat("Tom");
	cout << "\nanimal�ĵ�ַ:" <<animal << "\n" << endl;
	animal->speak();
	/*
	û��deleteɾ��animal������ø��Ե��������� 
	�����������±�3�����ʱ�����ã�

    1�������������ڽ�����������ʱ��
    2����������delete ��
    3������i�Ƕ���o�ĳ�Ա��o����������������ʱ������i����������Ҳ�����á�
	
	
	*/
	delete animal;
}

int main() {
	test01();
	
	return 0;
}
