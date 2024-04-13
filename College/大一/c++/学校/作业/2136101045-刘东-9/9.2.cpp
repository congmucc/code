#include <iostream>
#include<cmath>
using namespace std;
   int fact(int n)
{
    int i,c;
    for(i=1;i<n;i++)
{
       c=n%i;
       if(c==0)
        break;
}

    if(c==0)
    {
        cout <<"素数";
    }
    else
    {
        cout <<"不是素数";
    }

}
int main()
{
    int x;
    cin>>x;
    fact(x);
    return 0;
}
