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
	//数组型 
    int *p = new int[5];
	for (int i = 0; i < 5; i++) {
		p[i] = i; 
	}
	
	for (int i = 0; i < 5; i++) {
		cout<<i<<"=="<<p[i]<<endl; 
	}	
	delete []p; 
	
	
	//常量型 
	int *a = new int(3);
	
	//*a = 10;        //或者这个赋值，第一个赋值常用     这个赋值需要上面的new int(3)  变换成 new int  
	cout<<"a = "<<*a<<endl; 
	delete a;
	
	//结构体型
	
	
	//第一种赋值方式 
    //student *stlist = new student[3]{{"abc", 90}, {"bac", 78}, {"ccd", 93}};
    
	student *stu = new student;

    //第二种赋值方式    第一种赋值方式和上面的常量型的有点像 
	stu->name = "june";
	stu->score = 10;
	
	
	

	
	cout<<"name:"<<stu->name<<"\t"<<"score :"<<stu->score<<endl;
	
	return 0;
} 
