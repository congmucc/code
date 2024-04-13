#include <iostream>
using namespace std;
void f(int n)
{
    int num=0,sum=0;//num表示n为几位数，sum表示累加和
    int a;//记录每一位的数
    while(n>0)
    {
        a=n%10;//取出个位数
        sum+=a;
        num++;
        n=n/10;//循环
    }
    cout<<num<<'\t'<<sum<<endl;
}
int main()
{
    int n;
    cin>>n;
    f(n);
    return 0;
}
