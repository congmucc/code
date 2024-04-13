#include <iostream>

using namespace std;

int main()
{
    int f;
    cin>>f;
    if(f>=90)
        cout<<'A'<<endl;
    else if(f>=80)
        cout<<'B'<<endl;
    else if(f>=70)
        cout<<'C'<<endl;
    else if(f>=60)
        cout<<'D'<<endl;
    else
        cout<<'E'<<endl;
    switch(f/10){
        case 9:cout<<'A'<<endl;break;
        case 8:cout<<'B'<<endl;break;
        case 7:cout<<'c'<<endl;break;
        case 6:cout<<'D'<<endl;break;
        default:
            cout<<'E'<<endl;break;
    }

    return 0;
}
