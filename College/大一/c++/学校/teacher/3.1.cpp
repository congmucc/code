#include <iostream>

using namespace std;

int main()
{

    int a,b,c;
    cin>>a>>b>>c;
    //��һ�ַ���,aʼ�������ֵ
    int max;
    if(a>b)//a��b�Ƚϴ�С�������ֵ��ֵ��max
        max=a;
    else
        max=b;
    if(max<c)//max��c�Ƚϴ�С�������ֵ��ֵ��c
        max=c;
    cout<<max<<endl;//������max��ֵ

    //�ڶ��ַ���
    //����Ҫ���¸�a,b,c��ֵ����Ϊa,b,c��ֵû�з����ı�
    if(a<b)//���a<b����b��ֵ��ֵ��a����ʱa����ԭ��a��ԭ��b�����ֵ
      a=b;
    if(a<c)//���a<c����b��ֵ��ֵ��c����ʱa����ԭ��c�����ֵ
        a=c;
    cout<<a<<endl;
    //�����ַ���
    cin>>a>>b>>c;//���¸�a,b,c��ֵ����Ϊ����a,b,cֵ�Ѿ������ı��ˡ�
    a=(a>b)?a:b;
    a=(a>c)?a:c;
    cout<<a<<endl;
    return 0;
}
