#include <iostream>

using namespace std;
int max(int m,int n)
{
    return (m>n?m:n);
}
int min(int m,int n)
{
    return (m<n?m:n);
}
int main()
{
    int m,n;
    cin>>m>>n;
    cout<<max(m,n)<<'\t'<<min(m,n)<<endl;
    return 0;
}
