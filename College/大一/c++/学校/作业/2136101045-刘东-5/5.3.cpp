#include <iostream>

using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;

    int t;

    int cmax;
    int dmin;
    if(m==n){
        cmax=m;
    }
    else{
         if(m<n){
            t=m;
            m=n;
            n=t;
        }
         if(m%n==0){
            cmax=n;
         }
         else{
                for(int i=t;i>=1;i--) {
                    if(m%i==0 && n%i==0){
                        cmax=i;
                        break;
                    }
                }
            }
        }
        dmin=m*n/cmax;

    cout<<cmax<<'\t'<<dmin<<endl;
    return 0;
}
