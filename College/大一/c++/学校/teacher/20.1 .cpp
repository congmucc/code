#include <iostream>

using namespace std;
class Date
{
public:
    Date(int y=1949,int m=10,int d=1):Year(y),Month(m),Day(d){}
    //使用初始化列表进行初始化，并且使用了默认参数
    void print()
    {
        cout<<Year<<"/"<<Month<<"/"<<Day;//输出信息
    }
private:
    int Year;
    int Month;
    int Day;
};
class Docter
{
public:
    Docter(int num=1001,string name="wang",char sex='f',int year=1949,int month=10,int day=1)
    {
        Num=num;
        Name=name;
        Sex=sex;
        Date d(year,month,day);//声明一个对象d
        birthday=d;//将d赋值给birthday
    }
    void setinfo(int num,string name,char sex,int year,int month,int day)
    {
        Num=num;
        Name=name;
        Sex=sex;
        Date d(year,month,day);//声明一个对象d
        birthday=d;//将d赋值给birthday
    }
    void print()//输出信息
    {
        cout<<Num<<"  "<<Name<<"  "<<Sex<<"  ";
        birthday.print();//birthday调用print函数进行输出
        cout<<endl;
    }
    ~Docter()
    {
        cout<<"析构函数"<<endl;
    }
private:
    int Num;//工号
    string Name;//姓名
    char Sex;//性别
    Date birthday;
    //生日，利用了组合类。利用了自定义的Date声明了对象birthday作为数据成员。
    //在对doctor类声明的对象初始化时，需要对birthday进行初始化，即对其每一个变量进行初始化
};
int main()
{
    Docter doc[10]={Docter(1001,"zhang",'m',1950,12,20),
                    Docter(1002,"zhao",'f',1995,10,1)};//初始化化两个变量
    //其余的八个，利用键盘输入进行初始化
    int num,year,month,day;
    string name;
    char sex;
    for(int i=2;i<10;i++)
    {
        cin>>num>>name>>sex>>year>>month>>day;
        doc[i].setinfo(num,name,sex,year,month,day);
    }
    for(int i=0;i<10;i++)
        doc[i].print();//输出每一个医生的信息
    return 0;
}
