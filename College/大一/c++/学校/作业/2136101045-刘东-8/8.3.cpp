#include <iostream>

using namespace std;

int an(int s)
{
    int k=0,i=0,a;
    for(;s>0;i++)
    {

    a=s%10;
    s=s/10;
    k+=a;


    }
    cout<<"����"<<i<<"λ��"<<"\n"<<k;
    return s;
}

int main()
{
    int m;
    cin>>m;
    int k=an(m);
    cout <<k<< endl;
    return 0;
}
