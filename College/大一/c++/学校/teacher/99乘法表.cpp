#include <iostream>
using namespace std;
#include<stdio.h>

void algorithm() {
	  
	  for(int i=1;i<10;i++)//行
    {
        for(int j=1;j<=i;j++)//列
        {
            printf("%d * %d = %-4d",i,j,i*j);
        }
        printf("\n");
    }
} 


void f()
{
    int z;
    for(int i=1;i<10;i++)//行
    {
        for(int j=1;j<=i;j++)//列
        {
            z=i*j;
            cout<<i<<'*'<<j<<'='<<z<<'\t';
        }
        cout<<endl;
    }
}
int main()
{
//    f();
    algorithm(); 
    return 0;
}
