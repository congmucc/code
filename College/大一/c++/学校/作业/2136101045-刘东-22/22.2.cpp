#include <iostream>

using namespace std;

class Garden
{
public:

    Garden(double r=10,double p=3.14):radius(r),pl(p){}


    void kl()
    {
        cout<<"������뾶"<<endl;
        cin>>radius;
    }
   double radiu()
{
     return(radius*radius*pl);
};
   double co()
{
    return(2*pl*radius);
};
private:
    double radius;
    double pl;

};


int main()
{
   Garden a1(10);
   cout<<"����r==10��"<<endl;
   cout<<"���"<<a1.radiu()<<endl;
   cout<<"�ܳ�"<<a1.co()<<endl;
   Garden a2;
  a2.kl();
   cout<<"���"<<a2.radiu()<<endl;
   cout<<"�ܳ�"<<a2.co()<<endl;

   return 0;
}
