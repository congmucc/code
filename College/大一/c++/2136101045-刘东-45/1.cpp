#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;//输入三个边
    if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
    {
        cout<<"直角三角形";
    }
    else if(a==b==c)
    {
        cout<<"等边三角形";
    }
    else if(a==b||b==c||a==c)
    {
        cout<<"等腰三角形";
    }
    else
    {
        cout<<"普通三角形";
    }
    return 0;
}































