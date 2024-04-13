#include <iostream>
#include<math.h>
using namespace std;

double an1(double x,double y,double z);
double an2(double x,double y ,double z);
double an3(double x,double y ,double z);
int main()
{
    double a,b,c,d;
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    if(d<0)
    {
        an1(a,b,c);
    }
    if(d==0)
    {
        an2(a,b,c);
    }
    if(d>0)
    {
        an3(a,b,c);
    }
   return 0;
}


double an1(double x,double y ,double z)
{
    cout <<"无解";

}

double an2(double x,double y,double z)
{
    double x1,x2,d;
    x1=(-y)/(2*x);
    x2=x1;
    cout <<"x2=x1="<<x2;
}

double an3(double x,double y,double z)
{
    double x1,x2,d;
    x1=(-y+sqrt(d))/(2*x);
    x2=(-y-sqrt(d))/(2*x);
    cout <<"x1="<<x1<<"/n"<<"x2="<<x2;
}
