#include <iostream>

using namespace std;
class person
{
public:
person();
person(string n,int a);
string getname()
{
    return name;
    }
int getage()
{
    return age;
    }
void setname(string n)
{
    name=n;
    }
void setage(int a)
{
    age=a;
    }
void showinfo()
    {
        cout<<name<<","<<age<<endl;
    }
        ~person()
    {
        cout<<name<<","<<age<<endl;
    }
private:
    string name;
    int age;
};
person::person()
{
    name="he";
    age=18;
}
person::person(string n,int a):name(n),age(a){}
int main()
{
   person p1;
   person p2("wang",18);
   cout<<p1.getname()<<endl;
   p1.setname("zhang");
    cout<<p1.getname()<<endl;
    return 0;
}
