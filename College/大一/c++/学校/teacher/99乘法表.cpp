#include <iostream>
using namespace std;
#include<stdio.h>

void algorithm() {
	  
	  for(int i=1;i<10;i++)//��
    {
        for(int j=1;j<=i;j++)//��
        {
            printf("%d * %d = %-4d",i,j,i*j);
        }
        printf("\n");
    }
} 


void f()
{
    int z;
    for(int i=1;i<10;i++)//��
    {
        for(int j=1;j<=i;j++)//��
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
