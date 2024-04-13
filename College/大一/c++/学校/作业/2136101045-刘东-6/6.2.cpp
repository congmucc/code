#include <iostream>

using namespace std;

int main()
{
    int a,b,c,i;
    for(i=100;i<1000;i++)
    {
    a=i/100;
    b=(i-a*100)/10;
    c=i%10;
    if(i==a*a*a+b*b*b+c*c*c)
    cout<<i<<"\t";
    }

    return 0;
}
