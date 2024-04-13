#include <iostream>


using namespace std;
int an(int f);
int main()
{
    int f;
    cin >>f;
    an(f);
    cout<<an(f);
    return 0;
}

int an(int f)
 {
     int c;
     if(f==1||f==2)
    return 1;
        else
    f=an(f-1)+an(f-2);
   return f;
 }
