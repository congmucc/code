#include<iostream>
using namespace std;
#define max 1000
#include<string.h>
struct Person
{
	string name;
	string number;
	string adds;
	string email;
};
struct tel//通讯录 
{
	struct Person arr[max];
	int sz;//个数 
};

void menu()//菜单 
{
	cout<<"**********************************"<<endl;
	cout<<"功能："<<endl;
	cout<<"用户输入“1”执行添加联系人操作；"<<endl;
	cout<<"用户输入“2”执行查看通讯录操作；"<<endl;
	cout<<"用户输入“3”执行删除通讯录操作；"<<endl;
	cout<<"用户输入“4”执行查找联系人操作；"<<endl;
	cout<<"用户输入“5”执行修改联系人操作；"<<endl;
	cout<<"用户输入“6”执行查看菜单操作；"<<endl;
	cout<<"用户输入“0”执行退出操作；"<<endl;
	cout<<"**********************************"<<endl;
}
void add(tel * aa)
{
	cout<<"place enter:name,number,adds,email"<<endl;
	string name,n,adds,e; 
    cin>>name>>n>>adds>>e;
    aa->arr[aa->sz].name=name;
    aa->arr[aa->sz].number=n;
    aa->arr[aa->sz].adds=adds;
    aa->arr[aa->sz].email=e;
    aa->sz++;
    cout<<"添加成功"<<endl;
}
void show(tel * aa)
{
	
	cout<<"**********************************"<<endl;
	for(int i=0;i<aa->sz;i++)
	{
		cout<<"No."<<(i+1)<<endl;
		cout<<"name: "<<aa->arr[i].name<<"\t";
		cout<<"number: "<<aa->arr[i].number<<"\t";
		cout<<"adds: "<<aa->arr[i].adds<<"\t";
		cout<<"email: "<<aa->arr[i].email<<endl;
	}
    cout<<"**********************************"<<endl;

}
void del(tel * aa)
{
	cout<<"如果不想删除请输入一个空联系人"<<endl;
	cout<<"Please enter the name of the person you want to delete:"<<endl;
	string name; 
	cin>>name;
	
	for(int i=0;i<aa->sz;i++)
	{
		if(name==aa->arr[i].name)
		{
		    cout<<"查找成功，如下："<<endl;
		    cout<<"No."<<(i+1)<<endl;
		    cout<<"name: "<<aa->arr[i].name<<"\t";
		    cout<<"number: "<<aa->arr[i].number<<"\t";
		    cout<<"adds: "<<aa->arr[i].adds<<"\t";
		    cout<<"email: "<<aa->arr[i].email<<endl;
		    for(int j=i;j<aa->sz;j++)
		    {
		        aa->arr[j].name=aa->arr[j+1].name;
		        aa->arr[j].number=aa->arr[j+1].number;
		        aa->arr[j].adds=aa->arr[j+1].adds;
		        aa->arr[j].email=aa->arr[j+1].email;
		    }
		    aa->sz--;
		cout<<"Successful deleted"<<endl;
		break;
		}
		else if(i==(aa->sz-1))
		{
			cout<<"出现错误，无此联系人"<<endl; 
		}
	}
}
void search(tel * aa)
{
	cout<<"Please enter the name of the person you are searching for:"<<endl;
	string name;
	cin>>name;
	for(int i=0;i<aa->sz;i++)
	{
	    if(name==aa->arr[i].name)
	    {
	    	cout<<"查找成功，如下："<<endl;
	    	cout<<"No."<<(i+1)<<endl;
		    cout<<"name: "<<aa->arr[i].name<<"\t";
		    cout<<"number: "<<aa->arr[i].number<<"\t";
		    cout<<"adds: "<<aa->arr[i].adds<<"\t";
		    cout<<"email: "<<aa->arr[i].email<<endl;
		}
	    else if(i==(aa->sz-1))
		{
			cout<<"出现错误，无此联系人"<<endl; 
		}
    }
}
void modify(tel * aa)
{
	cout<<"Please enter the name of the person you want to modify:"<<endl;
	string name,n,num,adds,email;
	cin>>name;
	for(int i=0;i<aa->sz;i++)
	{
	    if(name==aa->arr[i].name)
	    {
	    	cout<<"查找成功，如下："<<endl;
	    	cout<<"No."<<(i+1)<<endl;
		    cout<<"name: "<<aa->arr[i].name<<"\t";
		    cout<<"number: "<<aa->arr[i].number<<"\t";
		    cout<<"adds: "<<aa->arr[i].adds<<"\t";
		    cout<<"email: "<<aa->arr[i].email<<endl;
		    cout<<"==================================================="<<endl;
		    cout<<"place enter:new name,number,adds,email: "<<endl;
		    cin>>n>>num>>adds>>email;
		    aa->arr[i].name=n;
            aa->arr[i].number=num;
            aa->arr[i].adds=adds;
            aa->arr[i].email=email;
		    cout<<"successful modified"<<endl;
		    cout<<"==================================================="<<endl;
		    cout<<"No."<<(i+1)<<endl;
		    cout<<"name: "<<aa->arr[i].name<<"\t";
		    cout<<"number: "<<aa->arr[i].number<<"\t";
		    cout<<"adds: "<<aa->arr[i].adds<<"\t";
		    cout<<"email: "<<aa->arr[i].email<<endl;
		    cout<<"==================================================="<<endl;
		}
	    else if(i==(aa->sz-1))
		{
			cout<<"出现错误，无此联系人"<<endl; 
		}
    }
}
int main()
{
	menu();
    tel aa;
    aa.sz=0;//初始化值 
	while(true)
	{
		cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
		cout<<"请输入数字："<<endl; 
	   	int x; 
		cin>>x;
	    switch(x)
	    {
		    case 1:add(&aa);//用户输入“1”执行添加联系人操作；
			break;
		    case 2:show(&aa);//用户输入“2”执行查看通讯录操作；
			break;
		    case 3:del(&aa);//"用户输入“3”执行删除通讯录操作
			break;
		    case 4:search(&aa);//用户输入“4”执行查找联系人操作；
			break;
		    case 5:modify(&aa);//用户输入“5”执行修改联系人操作；
			break;
			case 6:menu();
		    case 0:
		    cout<<"quit"<<endl;
			return 0; 
		    system("pause");
			break;
		    default:
		    	cout<<"An error occurred"<<endl;
		    	break;
	    }
    }
} 
