#include<iostream>
using namespace std;

class Person {
	public:
		int m_age;
		int *m_height;
		
		
		Person(int age, int height) {
			this->m_age = age;
			this->m_height = new int(height);
			cout << "���캯��" <<endl;
		} 
		
		void PersonShow() {
			cout << "Person's age is : " << this->m_age <<endl;
			cout << "Person's height is : " <<this->m_height <<endl;
		}
		
		Person (const Person &p) {
			this->m_age = p.m_age;
			//�����ڴ� 
			this->m_height = new int;
			this->m_height = p.m_height;
//          ���� 
//			this->m_height = new int (*p.m_height);
		}
		~Person() {
			if (m_height != NULL) {
				delete m_height;
				m_height = NULL;
			} 
			cout << "��������" <<endl;
		}
};



int main() {
	Person p1(10,20);
	p1.PersonShow();
	Person p2(p1);
	p2.PersonShow();
	
	return 0; 
}
