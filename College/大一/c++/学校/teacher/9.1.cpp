#include <iostream>
#include<cmath>
using namespace std;
void de0();
void de1(double a,double b);
void de2(double a,double b,double de);
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    double de=sqrt(b*b-4*a*c);
    if(de<0)
        de0();
    else if(de==0)
    {
        de1(a,b);
    }
    else
    {
       de2(a,b,de);
    }
    return 0;
}
void de0()
{
    cout<<"error"<<endl;
}
void de1(double a,double b)
{
    double x=-b/(2*a);
    cout<<x<<endl;
}
void de2(double a,double b,double de)
{
     double x1=(-b+de)/(2*a);
        double x2=(-b-de)/(2*a);
        cout<<x1<<x2<<endl;
}
