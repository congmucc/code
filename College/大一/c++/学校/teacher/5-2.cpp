#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    for(int i=100;i<1000;i++)//ѭ���������е���λ������100-999
    {
        a=i%10;
        b=(i/10)%10;
        c=i/100;
        if(i==a*a*a+b*b*b+c*c*c)
            cout<<i<<'\t';
    }
    cout<<endl;
    return 0;
}
