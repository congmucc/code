#include <iostream>

using namespace std;

double an(int a,int n)
{
    int j=0,k=1,s=0;
    for(;k<=n;k++)
    {  j=j*10+a;
       s+=j;
    }
   return s;
}


int main()
{   int x,y;
    cin>>x>>y;
    double c=an(x,y);
    cout<<c;



    return 0;
}
