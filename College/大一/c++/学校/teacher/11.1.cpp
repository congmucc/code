#include <iostream>

using namespace std;

int main()
{
    int a[10];
    //����10������
    for(int i=0;i<10;i++)//����a[0]~a[9]
        cin>>a[i];
    int minnum,j;//��Сֵ�±꣬j��ʾ��Сֵ
    minnum=0;
    //j=a[minnum];//��ʼ����Сֵ
    for(int i=1;i<10;i++)
    {
        if(a[i]<a[minnum])
            {
                minnum=i;
                //j=a[i];
            }
    }
    cout<<"��Сֵ��"<<a[minnum]<<'\t'<<"�±꣺"<<minnum<<endl;
    return 0;
}
