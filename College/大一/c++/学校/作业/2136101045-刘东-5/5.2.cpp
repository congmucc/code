#include <iostream>

using namespace std;

int main()
{
    int n,sum=1,k=0;
    for(int j=1;j<=20;j++)
    {
        sum=1;
    for(int i=1;i<=j;i++)
    {
        sum*=i;
    }
    k+=sum;
}
    cout<<"n!="<<k;
    return 0;
}
