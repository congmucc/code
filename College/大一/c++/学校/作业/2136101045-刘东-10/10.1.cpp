#include <iostream>

using namespace std;
int an(int a);
int main()
{
    int a;
    cin>>a;
    an(a);
    return 0;
}

int an(int a)
{
    int i;
    for(i=1;i<=a;i++)
    {
        if(a%i==0)
        cout<<i<<" ";
    }
}
