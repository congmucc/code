#include <iostream>

using namespace std;

int main()
{
    double a,b,c,d;
    for(a=0;a<=15;a++)
    {
        for(b=0;b<=25;b++)
        {
                for(c=0;c<=100;c++)
                {
        if((a*5+b*3+c/3==100)&&(a+b+c==100))
        {
            cout<<a<<" "<<b<<" "<<c<<"\n";
        }
                }
        }
    }

    return 0;
}

