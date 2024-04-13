#include <iostream>
#include <math.h>
using namespace std;
int max(int a,int b)
{   int s;
    s=a>b?a:b;
    return s;
}

int min(int c,int d)
{
     int w;
    w=c<d?c:d;
    return w;
}

int main()
{
    int x,y;
    cin>>x>>y;
    int z=max(x,y);
    cout <<"max="<<z<<"\t";
    int q=min(x,y);
    cout <<"min="<<q;

}
