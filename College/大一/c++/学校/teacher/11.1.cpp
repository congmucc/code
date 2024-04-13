#include <iostream>

using namespace std;

int main()
{
    int a[10];
    //输入10个数字
    for(int i=0;i<10;i++)//输入a[0]~a[9]
        cin>>a[i];
    int minnum,j;//最小值下标，j表示最小值
    minnum=0;
    //j=a[minnum];//初始化最小值
    for(int i=1;i<10;i++)
    {
        if(a[i]<a[minnum])
            {
                minnum=i;
                //j=a[i];
            }
    }
    cout<<"最小值："<<a[minnum]<<'\t'<<"下标："<<minnum<<endl;
    return 0;
}
