#include <iostream>

using namespace std;

int main()
{
    int a[3][3],b[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }


     for(int i=0;i<3;i++)
    {
         for(int j=0;j<3;j++)
            {
                cout<<a[i][j]<<" ";
                if(j==2)
                {
                    cout<<endl;
                }
                b[j][i]=a[i][j];
            }
    }
     for(int i=0;i<3;i++)
    {
         for(int j=0;j<3;j++)
         {
            cout<<b[i][j]<<" ";
            if(j==2)
                {
                    cout<<endl;
                }

         }
    }
    return 0;
}
