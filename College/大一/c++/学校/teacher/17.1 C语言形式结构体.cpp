//下面程序是采用C语言类型的结构体 C++结构体和类是相似的
#include <iostream>
using namespace std;
struct Date
{
    int Year;
    int Month;
    int Day;
};
   void setdate(Date & d)
   {
       cin>>d.Year>>d.Month>>d.Day;
   }
   void showdate(Date & d)
   {
       cout<<d.Year<<"/"<<d.Month<<"/"<<d.Day<<endl;
   }
int numday(Date & d)
   {
       int num=0;
       bool flag=false;//如果是闰年为true，否则为false。
       if((d.Year% 4==0 && d.Year %100!=0) || (d.Year %400==0))
            flag=true;
       for(int i=1;i<d.Month;i++)
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
       num+=d.Day;
       return num;
   }
int main()
{
    Date d1;
    setdate(d1);
    showdate(d1);
    cout<<numday(d1)<<endl;
    return 0;
}
