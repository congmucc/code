#include <iostream>

using namespace std;
class Date
{
public:
    Date(int y=1949,int m=10,int d=1):Year(y),Month(m),Day(d){}
    //ʹ�ó�ʼ���б���г�ʼ��������ʹ����Ĭ�ϲ���
    void print()
    {
        cout<<Year<<"/"<<Month<<"/"<<Day;//�����Ϣ
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
        Date d(year,month,day);//����һ������d
        birthday=d;//��d��ֵ��birthday
    }
    void setinfo(int num,string name,char sex,int year,int month,int day)
    {
        Num=num;
        Name=name;
        Sex=sex;
        Date d(year,month,day);//����һ������d
        birthday=d;//��d��ֵ��birthday
    }
    void print()//�����Ϣ
    {
        cout<<Num<<"  "<<Name<<"  "<<Sex<<"  ";
        birthday.print();//birthday����print�����������
        cout<<endl;
    }
    ~Docter()
    {
        cout<<"��������"<<endl;
    }
private:
    int Num;//����
    string Name;//����
    char Sex;//�Ա�
    Date birthday;
    //���գ�����������ࡣ�������Զ����Date�����˶���birthday��Ϊ���ݳ�Ա��
    //�ڶ�doctor�������Ķ����ʼ��ʱ����Ҫ��birthday���г�ʼ����������ÿһ���������г�ʼ��
};
int main()
{
    Docter doc[10]={Docter(1001,"zhang",'m',1950,12,20),
                    Docter(1002,"zhao",'f',1995,10,1)};//��ʼ������������
    //����İ˸������ü���������г�ʼ��
    int num,year,month,day;
    string name;
    char sex;
    for(int i=2;i<10;i++)
    {
        cin>>num>>name>>sex>>year>>month>>day;
        doc[i].setinfo(num,name,sex,year,month,day);
    }
    for(int i=0;i<10;i++)
        doc[i].print();//���ÿһ��ҽ������Ϣ
    return 0;
}
