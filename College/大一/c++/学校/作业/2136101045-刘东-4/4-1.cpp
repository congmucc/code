#include <iostream>
using namespace std;

int main()
{
    double x,y;
    cin>>x;
    if(x<1)
        y=x;
    else if(1<=x<10)
        y=2*x-1;
    else
        y=3*x-11;
    cout <<y<< endl;
    return 0;
}
