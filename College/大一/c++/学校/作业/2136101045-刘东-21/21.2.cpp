#include <iostream>

using namespace std;
class student

{
public:
    student(double s,double ca,double da):score(s),countavg(ca),displayavg(da){}
    void average();
    void display();
    void total();
private:
    double score;
    double countavg;
    double displayavg;
    static double sum;

};
void student::total()
{
    sum+=score;
}
void student::average()
{
    sum/3;
}
void student::display()
{
    cout<<"average score"<<": "<<sum/3<<endl;
}
double student::sum=0;
int main()
{
student s[3]={
   student(30,23,45),
   student(20,34,64),
   student(23,34,66)
};
for(int i=0;i<3;i++)
{
    s[i].total();
    s[i].display();
}
return 0;
}
