#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;//����������
    if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
    {
        cout<<"ֱ��������";
    }
    else if(a==b==c)
    {
        cout<<"�ȱ�������";
    }
    else if(a==b||b==c||a==c)
    {
        cout<<"����������";
    }
    else
    {
        cout<<"��ͨ������";
    }
    return 0;
}































