#include<iostream>
using namespace std;
struct Student
{
	int num;
	float score;
	struct Student *next;
};
int main()
{
	Student a,b,c,*p,*q;
	a.num=1001;a.score=89.5;
	b.num=1002;b.score=75;
	c.num=1003;c.score=60;
	q=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	p=q;
	do
	{
		cout<<p->num<<" "<<p->score<<endl;
		p=p->next;
	}while(p!=NULL);
	
	return 0;
}
