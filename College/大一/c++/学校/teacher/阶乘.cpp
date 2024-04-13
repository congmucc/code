#include <iostream>
using namespace std;
double  fact(int n)
{
    double s=1;
    for(int i=1;i<=n;i++)//1*2*3...*n
        s*=i;
    return s;
}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}
