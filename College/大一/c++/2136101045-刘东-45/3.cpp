#include <iostream>

using namespace std;
class Circle
{
public:
    Circle(int a=10);//���캯��
    void setl();//���ð뾶
    void area();//���+���
    int r();//����뾶
    void an();//�ܳ�+���
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
    cout<<"*****���������İ뾶*****"<<endl;
    cin>>a1;
}

void Circle::area()
{
    cout<<"���"<<"��    "<<a1*a1*3.14<<endl;
}
void Circle::an()
{
    cout<<"�ܳ�"<<"��    "<<2*a1*3.14<<endl;
}

int main()
{
    Circle b1,b2;
    b1;//Ĭ�ϲ���
    cout<<"���뾶Ϊ10ʱ"<<endl;
    cout<<"�뾶"<<"��     "<<b1.r()<<endl;
    b1.area();
    b1.an();
     if((b1.pr(5))==true)
    {
        cout<<"���Բ��"<<endl;
    }
    else
    {
        cout<<"���ԲС"<<endl;
    }
    b2;//�Լ�����һ���뾶����
    b2.setl();
    cout<<"�뾶"<<"��     "<<b2.r()<<endl;
    b2.area();
    b2.an();
    if((b2.pr(5))==true)
    {
        cout<<"���Բ��"<<endl;
    }
    else
    {
        cout<<"���ԲС"<<endl;
    }
    return 0;
}
