#include <iostream>
using namespace std;
double an(int a,int n)
{
    double s=0,an=0;
    for(int i=0;i<n;i++)
    {
        an=an*10+a;//aaa...a
        s+=an;
    }
    return s;
}
int main()
{
    int a,n;
    cin>>a>>n;
    cout<<an(a,n)<<endl;
    return 0;
}
