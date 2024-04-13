#include <iostream>

using namespace std;


void an(int n,int p[])
{
        int t,j;
      for(int i=0;i<9;i++)
    {
        for(j=0;j<9-i;j++)
        {
            if(*(p+j)>*(p+j+1))
            {
                t=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=t;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<*(p+i)<<" ";
    }
}
int main()
{

    int a[10];
    int *q;
    q=a;
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }

    an(10,a);
    return 0;
}
