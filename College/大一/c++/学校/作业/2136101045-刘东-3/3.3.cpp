#include <iostream>

using namespace std;

int main()
{   double y,x;
    cin >>x;
    if(x<1)
        y=x;
        else if(1<=x<10) y=2*x-1;
        else if(x>=10) y=3*x-11;
    cout <<"Y="<<y;
    return 0;
}
