#include <iostream>

using namespace std;
class Circle
{
public:
    Circle(int a=10);//构造函数
    void setl();//设置半径
    void area();//面积+输出
    int r();//输出半径
    void an();//周长+输出
    bool pr(double);
private:
    int a1;
};
bool Circle::pr(double a2)
{
    if(a1>a2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Circle::Circle(int a)
{
    a1=a;
}
int Circle::r()
{
  return a1;
}
void Circle::setl()
{
    cout<<"*****请输入您的半径*****"<<endl;
    cin>>a1;
}

void Circle::area()
{
    cout<<"面积"<<"：    "<<a1*a1*3.14<<endl;
}
void Circle::an()
{
    cout<<"周长"<<"：    "<<2*a1*3.14<<endl;
}

int main()
{
    Circle b1,b2;
    b1;//默认参数
    cout<<"当半径为10时"<<endl;
    cout<<"半径"<<"；     "<<b1.r()<<endl;
    b1.area();
    b1.an();
     if((b1.pr(5))==true)
    {
        cout<<"类的圆大"<<endl;
    }
    else
    {
        cout<<"类的圆小"<<endl;
    }
    b2;//自己设置一个半径参数
    b2.setl();
    cout<<"半径"<<"；     "<<b2.r()<<endl;
    b2.area();
    b2.an();
    if((b2.pr(5))==true)
    {
        cout<<"类的圆大"<<endl;
    }
    else
    {
        cout<<"类的圆小"<<endl;
    }
    return 0;
}
