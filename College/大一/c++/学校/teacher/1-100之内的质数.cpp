#include <iostream>

using namespace std;

int main()
{
    bool flag;
    for(int i=2;i<=100;i++)
    {
        flag=false;
        for(int j=i-1;j>1;j--)
        {
            if(i%j==0)
                {flag=true;break;}
        }
        if(!flag)
            cout<<i<<endl;
        else
            continue;
    }
    return 0;
}
