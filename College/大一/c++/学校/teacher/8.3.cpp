#include <iostream>
using namespace std;
void f(int n)
{
    int num=0,sum=0;//num��ʾnΪ��λ����sum��ʾ�ۼӺ�
    int a;//��¼ÿһλ����
    while(n>0)
    {
        a=n%10;//ȡ����λ��
        sum+=a;
        num++;
        n=n/10;//ѭ��
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
