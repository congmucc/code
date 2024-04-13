#include <iostream>

using namespace std;

int main()
{
    int a,b,q,w,e,r,t;
    cin>>a;
    if(a>=100000) cout<<"error"<<" ";
    else if(a%100000>=10000)
    {
    b=5;
    q=a%10;
    w=(a/10)%10;
    e=(a/100)%10;
    r=(a/1000)%10;
    t=(a/10000)%10;
    cout<<t<<"\t"<<r<<"\t"<<e<<"\t"<<w<<"\t"<<q;
    cout<<"\n"<<q<<"\t"<<w<<"\t"<<e<<"\t"<<r<<"\t"<<t;
    }
    else if(a%10000>=1000)
    {
    b=4;
    q=a%10;
    w=(a/10)%10;
    e=(a/100)%10;
    r=(a/1000)%10;
    cout<<r<<"\t"<<e<<"\t"<<w<<"\t"<<q;
    cout<<"\n"<<q<<"\t"<<w<<"\t"<<e<<"\t"<<r;
    }
    else if(a%1000>=100)
    {
    b=3;
     q=a%10;
    w=(a/10)%10;
    e=(a/100)%10;
    cout<<e<<"\t"<<w<<"\t"<<q;
    cout<<"\n"<<q<<"\t"<<w<<"\t"<<e;
    }
    else if(a%100>=10)
    {
    b=2;
    q=a%10;
    w=(a/10)%10;
    cout<<w<<"\t"<<q;
    cout<<"\n"<<q<<"\t"<<w;
}
    else
    {
    b=1;
    q=a%10;
    cout<<q;
    cout<<"\n"<<q;
    }

    cout<<"\n"<<"Î»Êý£º"<<b;

    return 0;
}
