#include <iostream>

using namespace std;
class Date
{
public:
   void setdate()
   {
       cin>>Year>>Month>>Day;
   }
   void showdate()
   {
       cout<<Year<<"/"<<Month<<"/"<<Day<<endl;
   }
   int numday();
private:
    int Year;
    int Month;
    int Day;
};
int Date::numday()
   {
       int num=0;
       bool flag=false;//如果是闰年为true，否则为false。
       if((Year% 4==0 && Year %100!=0) || (Year %400==0))
            flag=true;
       for(int i=1;i<Month;i++)
       {
           if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
            num+=31;
           else if(i==4 ||i==6 || i==9 || i==11)
            num+=30;
           else if(flag)
            num+=29;
           else
            num+=28;
       }
       num+=Day;
       return num;
   }
int main()
{
    Date d1;
    d1.setdate();
    d1.showdate();
    cout<<d1.numday()<<endl;
    return 0;
}
