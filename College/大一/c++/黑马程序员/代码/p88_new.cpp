#include<iostream>  
using namespace std;

struct student
{
  string name;
  int score;
};



int main() {
	
	int *aa = new int;
	
	*aa = 10;
	
	cout << *aa <<endl;
	//������ 
    int *p = new int[5];
	for (int i = 0; i < 5; i++) {
		p[i] = i; 
	}
	
	for (int i = 0; i < 5; i++) {
		cout<<i<<"=="<<p[i]<<endl; 
	}	
	delete []p; 
	
	
	//������ 
	int *a = new int(3);
	
	//*a = 10;        //���������ֵ����һ����ֵ����     �����ֵ��Ҫ�����new int(3)  �任�� new int  
	cout<<"a = "<<*a<<endl; 
	delete a;
	
	//�ṹ����
	
	
	//��һ�ָ�ֵ��ʽ 
    //student *stlist = new student[3]{{"abc", 90}, {"bac", 78}, {"ccd", 93}};
    
	student *stu = new student;

    //�ڶ��ָ�ֵ��ʽ    ��һ�ָ�ֵ��ʽ������ĳ����͵��е��� 
	stu->name = "june";
	stu->score = 10;
	
	
	

	
	cout<<"name:"<<stu->name<<"\t"<<"score :"<<stu->score<<endl;
	
	return 0;
} 
