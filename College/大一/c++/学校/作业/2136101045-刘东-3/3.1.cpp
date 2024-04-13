#include <iostream>

using namespace std;

int main()
{   int a,b,c,max;
    cin>>a>>b>>c;
    if(a==b==c)
    cout<<"不是适合的数字，有数字相等"<<endl;
    else if(a>b)
        max=a;
    else if(b>a)
        max=b;
    if(c>max)
    cout <<"max="<<c;
    else cout <<"max="<<max;
    return 0;
}
