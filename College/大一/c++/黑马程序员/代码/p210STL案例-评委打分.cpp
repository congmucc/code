#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
class Person
{
public:
	Person(string name,int score)
	{
		this->m_name=name;
		this->m_score=score;
	}

	string m_name;
	int m_score;
};

void create_Person(vector<Person> &v)
{
	string nameSeed="ABCDE"; 
	for(int i=0;i<5;i++)
	{
		string name="选手";
		name+=nameSeed[i];
		
		int score= 0;
		
		Person p(name,score);
		
		v.push_back(p); 
	}
}

void printV(const vector<Person>&v)
{
	for(vector<Person>::const_iterator it=v.begin();it!=v.end();it++)
	{
		cout<<it->m_name<<"： "<<it->m_score<<endl;;
    }
}

void setScore(vector<Person>&v)
{
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		//将评委的分数 放到deque容器中 
		deque<int>d;
		for(int i=0;i<10;i++)
		{
			
			int score=rand()%41+60;  //  60 ~ 100
			d.push_back(score);
		}
		cout<<it->m_name<<"的"<<"打分"<<endl;
		for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
		{
			cout<<*dit<<" ";
		} 
		cout<<endl;
		cout<<endl; 
		//排序
		sort(d.begin(),d.end()); 
		
		//去除最高分和最低分 
		d.pop_back();
		d.pop_front();
		
		//取平均分
		int sum=0;
		for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
		{
			sum+=*dit;
		} 
		int avg=sum/d.size();
		 
		it->m_score=avg;
		 
    }
}
void test01()
{
	vector<Person>v;
	//选手 
	create_Person(v);
	//测试 
	printV(v);
    //打分 
	setScore(v);
	//展示 
	cout<<"平均分："<<endl;;
	printV(v);     
}

int main()
{
	test01();
	return 0;
}
