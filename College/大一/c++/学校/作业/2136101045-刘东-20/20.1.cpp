#include <iostream>

using namespace std;
class Date
{
public:
    Date(int y=1949,int m=10,int d=1):Year(y),Mouth(m),Day(d){}
    void print()
    {
        cout<<Year<<"/"<<Mouth<<"/"<<Day;
    }
private:
    int Year;
    int Mouth;
    int Day;
};
class docter
{
public:
  docter(int id=1001,string name="wang",char sex='f',int year=1949,int month=10,int day=1)
   {
        Id=id;
        Name=name;
        Sex=sex;
        Date d(year,month,day);
        Age=d;
   }
   void sf(int id,string name,char sex,int year,int month,int day)
   {
        Id=id;
        Name=name;
        Sex=sex;
        Date d(year,month,day);
        Age=d;
   }
   void print()
   {
       cout<<Id<<"  "<<Name<<"  "<<Sex;
       Age.print();
       cout<<endl;
   }
       ~docter()
    {
        cout<<"析构函数"<<endl;
    }
private:
    int Id;
    string Name;
    char Sex;
    Date Age;
};


int main()
{
    docter doc[10]={docter(1001,"zhang",'f',1949,10,2),
                    docter(1002,"wang",'f',1950,1,1)};
    int id,year,month,day;
    string name;
    char sex;
    for(int i=2;i<=10;i++)
    {
         cin>>id>>name>>sex>>year>>month>>day;
         doc[i].sf(id,name,sex,year,month,day);
    }
    for(int i=0;i<10;i++)
        doc[i].print();
    return 0;
}
