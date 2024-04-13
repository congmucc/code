#include <iostream>

using namespace std;

int main()
{

    int a,b,c;
    cin>>a>>b>>c;
    //第一种方法,a始终是最大值
    int max;
    if(a>b)//a和b比较大小，将最大值赋值给max
        max=a;
    else
        max=b;
    if(max<c)//max和c比较大小，将最大值赋值给c
        max=c;
    cout<<max<<endl;//最后输出max的值

    //第二种方法
    //不需要重新给a,b,c赋值，因为a,b,c的值没有发生改变
    if(a<b)//如果a<b，则将b的值赋值给a，此时a等于原先a和原先b中最大值
      a=b;
    if(a<c)//如果a<c，则将b的值赋值给c，此时a等于原先c中最大值
        a=c;
    cout<<a<<endl;
    //第三种方法
    cin>>a>>b>>c;//重新给a,b,c赋值，因为上面a,b,c值已经发生改变了。
    a=(a>b)?a:b;
    a=(a>c)?a:c;
    cout<<a<<endl;
    return 0;
}
