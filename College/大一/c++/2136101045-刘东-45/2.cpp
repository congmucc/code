#include <iostream>

using namespace std;
void a()
{
    int n,q=1,k=0;
    cout<<"******������n��ֵ*******"<<endl;
    cin>>n;//����n��ֵ
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
