#include <iostream>

using namespace std;
 const int N=100;//������������
int main()
{
    int n;
    int a[N][N];
    cin>>n;
    int i,j;
    for(i=0;i<n;i++)//����n*n������
        for(j=0;j<n;j++)
        cin>>a[i][j];
    int sum=0;
    for(i=0;i<n;i++)
        sum+=(a[i][i]+a[i][n-1-i]);
    cout<<"�Խ���֮�ͣ�"<<sum<<endl;
    return 0;
}
