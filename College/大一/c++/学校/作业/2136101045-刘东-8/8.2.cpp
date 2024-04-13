#include <iostream>
#include<cmath>
using namespace std;
   int fact(int n)
{
    int s=1;

    for (int a=1;a<=n;a++)
        s=a*s;
    return s;
}
int main()
{
    int x;
    cin>>x;
    int k=fact(x);
    cout <<k;
    return 0;
}
