#include<iostream> 

using namespace std;

class Student {
	public :
		//���������������ʼ�������壩 
		 static int mAge;
	private :
		static int mB;
};
//�����ʼ��  ����� 
int Student::mAge = 100;
int Student::mB;//����������ʲ���˽�еľ�̬��Ա���� 

void test01() {
	
	//��̬��Ա���� ������ĳ��������  ���ж��󶼹���һ������
	//���ַ��ʷ�ʽ 
	
	//1ͨ��������з���
	Student stu1;
	cout<< stu1.mAge << endl;
	
	//2ͨ���������з���
	cout << Student::mAge <<endl; 
}

class Person {
    public :
    static void func() {
    	cout << "static void func����" << endl;
	}
	
	static int m_A; 
	//  int m_B;    //���ܷ��ʷǾ�̬��Ա���� 
}; 

int Person::m_A = 10;

void test02() {
	/*
	1.���ж�����ͬһ������
	2.��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����   �����ܷ��ʷǾ�̬��Ա���� 
	*/
	//1��ͨ��������з���
	Person p;
	p.func();
	
	//2��ͨ���������з���
	Person::func(); 
	
	
}

int main() {
	
	//��̬��Ա���� 
	test01();
	
	//��̬��Ա����
	test02(); 
	return 0;
}
