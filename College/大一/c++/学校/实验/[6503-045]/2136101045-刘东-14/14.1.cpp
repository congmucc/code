#include <iostream>

using namespace std;

int main()
{
    int a[17];
    int n=17;
    int i,k=0;

    for(int i=0;i<n;i++)
    {
        a[i]=1;

    }

    for(i=0;i<17;i=(i+1)%17)
    {
        if(a[i]==1)
        {
            k++;
            if(k%3==0)
            {
                a[i]=0;
                n--;
            }
        }

        if(n==1)
        {
            break;
        }
    }

    cout<<endl;
    for(int i=0;i<17;i++)
    {
        if(a[i]!=0)
        {
            cout<<i+1<<endl;
        }

    }
cout<<1%17;
    return 0;
}
