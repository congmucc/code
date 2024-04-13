#include <iostream>

using namespace std;
 const int N=100;//用来定义数组
int main()
{
    int n;
    int a[N][N];
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)//输入n*n的数组
        for(j=0;j<n;j++)
        cin>>a[i][j];
    int sum=0;
    for(i=0;i<n;i++)
        sum+=(a[i][i]+a[i][n-1-i]);
    cout<<"对角线之和："<<sum<<endl;
    return 0;
}
