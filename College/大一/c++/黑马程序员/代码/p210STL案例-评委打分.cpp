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
		string name="ѡ��";
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
		cout<<it->m_name<<"�� "<<it->m_score<<endl;;
    }
}

void setScore(vector<Person>&v)
{
	for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
	{
		//����ί�ķ��� �ŵ�deque������ 
		deque<int>d;
		for(int i=0;i<10;i++)
		{
			
			int score=rand()%41+60;  //  60 ~ 100
			d.push_back(score);
		}
		cout<<it->m_name<<"��"<<"���"<<endl;
		for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
		{
			cout<<*dit<<" ";
		} 
		cout<<endl;
		cout<<endl; 
		//����
		sort(d.begin(),d.end()); 
		
		//ȥ����߷ֺ���ͷ� 
		d.pop_back();
		d.pop_front();
		
		//ȡƽ����
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
	//ѡ�� 
	create_Person(v);
	//���� 
	printV(v);
    //��� 
	setScore(v);
	//չʾ 
	cout<<"ƽ���֣�"<<endl;;
	printV(v);     
}

int main()
{
	test01();
	return 0;
}
