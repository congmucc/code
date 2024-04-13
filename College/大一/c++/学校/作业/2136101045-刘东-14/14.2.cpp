#include <iostream>

using namespace std;

int main()
{
    char a[15];
    for(int i=0;i<15;i++)
    {
        cin>>a[i];

    }
    for(int i=0;i<15;i++)
    {
        cout<<a[i]<<" ";
    }
    for(int i=0;i<15;i++)
    {
        if(a[i]>='a'&&a[i]<='z')
           {
               a[i]=219-a[i];
           }
        if(a[i]>='A'&&a[i]<='Z')
            {
                a[i]=155-a[i];
            }
            cout<<a[i]<<" ";
    }

    return 0;
}
