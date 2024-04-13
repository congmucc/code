#include <iostream>

using namespace std;
class Person
{
public:
    Person();
    Person(string n,int a);
    string getname(){return name;}
    int getage(){return age;}
    void setname(string n){name=n;}
    void setage(int a){age=a;}
    void showinfo()
    {
        cout<<name<<","<<age<<endl;
    }
    ~Person()
    {
        cout<<name<<","<<age<<endl;
    }
private:
    string name;
    int age;
};
Person::Person()
{
    name="he";
    age=18;
}
Person::Person(string n,int a):name(n),age(a){}

int main()
{
    Person p1;
    Person p2("wang",18);
    cout<<p1.getname()<<endl;
    p1.setname("zhang");
    cout<<p1.getname()<<endl;
    return 0;
}
