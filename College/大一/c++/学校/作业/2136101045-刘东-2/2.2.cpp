#include <iostream>

using namespace std;

int main()
{   double s1,s2,c1,c2,r1,r2,P=3.1415926;
    cin >>r1>>r2;
    s1=P*r1*r1;
    s2=P*r2*r2;
    c1=2*P*r1;
    c2=2*P*r2;
    cout << "r1=" <<r1<<",s1="<<s1<<",c1="<<c1<<endl;
    cout << "r2=" <<r2<<",s2="<<s2<<",c2="<<c2<<endl;
    return 0;
}
