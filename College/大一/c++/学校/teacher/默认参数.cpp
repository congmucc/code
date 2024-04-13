#include <iostream>

using namespace std;
int max(int a,int b,int c=0);
double area(double a=10,double b=10);
int main()
{
    int a=70,b=65,c=95;
    cout<<max(a,b,c)<<endl;
    cout<<max(a,b)<<endl;
    double m=15,n=20;
    cout<<area(m)<<endl;
    cout<<area(m,n)<<endl;
    cout<<area()<<endl;
    return 0;
}
int max(int a,int b,int c)
{
    if(a<b) a=b;
    if(a<c) a=c;
    return a;
}
double area(double a,double b)
{
    return a*b;
}
