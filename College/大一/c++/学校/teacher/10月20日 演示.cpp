#include <iostream>

using namespace std;
double exp(int x,int n)
{
    double s=1;
    for(int i=1;i<=n;i++)
        s*=x;
    return s;
}
int main()
{
    int x,n;
    cin>>x>>n;
    double s=exp(x,n);
    cout<<s<<endl;
    return 0;
}
