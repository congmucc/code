#include <iostream>

using namespace std;
void a()
{
    int n,q=1,k=0;
    cout<<"******请输入n的值*******"<<endl;
    cin>>n;//输入n的值
    for(int i=1;i<=n;i++)
    {
      q*=i;
      k+=q;
    }
    cout<<k;
}

int main()
{
    a();
    return 0;
}
