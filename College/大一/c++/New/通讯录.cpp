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
struct tel//ͨѶ¼ 
{
	struct Person arr[max];
	int sz;//���� 
};

void menu()//�˵� 
{
	cout<<"**********************************"<<endl;
	cout<<"���ܣ�"<<endl;
	cout<<"�û����롰1��ִ�������ϵ�˲�����"<<endl;
	cout<<"�û����롰2��ִ�в鿴ͨѶ¼������"<<endl;
	cout<<"�û����롰3��ִ��ɾ��ͨѶ¼������"<<endl;
	cout<<"�û����롰4��ִ�в�����ϵ�˲�����"<<endl;
	cout<<"�û����롰5��ִ���޸���ϵ�˲�����"<<endl;
	cout<<"�û����롰6��ִ�в鿴�˵�������"<<endl;
	cout<<"�û����롰0��ִ���˳�������"<<endl;
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
    cout<<"��ӳɹ�"<<endl;
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
	cout<<"�������ɾ��������һ������ϵ��"<<endl;
	cout<<"Please enter the name of the person you want to delete:"<<endl;
	string name; 
	cin>>name;
	
	for(int i=0;i<aa->sz;i++)
	{
		if(name==aa->arr[i].name)
		{
		    cout<<"���ҳɹ������£�"<<endl;
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
			cout<<"���ִ����޴���ϵ��"<<endl; 
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
	    	cout<<"���ҳɹ������£�"<<endl;
	    	cout<<"No."<<(i+1)<<endl;
		    cout<<"name: "<<aa->arr[i].name<<"\t";
		    cout<<"number: "<<aa->arr[i].number<<"\t";
		    cout<<"adds: "<<aa->arr[i].adds<<"\t";
		    cout<<"email: "<<aa->arr[i].email<<endl;
		}
	    else if(i==(aa->sz-1))
		{
			cout<<"���ִ����޴���ϵ��"<<endl; 
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
	    	cout<<"���ҳɹ������£�"<<endl;
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
			cout<<"���ִ����޴���ϵ��"<<endl; 
		}
    }
}
int main()
{
	menu();
    tel aa;
    aa.sz=0;//��ʼ��ֵ 
	while(true)
	{
		cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
		cout<<"���������֣�"<<endl; 
	   	int x; 
		cin>>x;
	    switch(x)
	    {
		    case 1:add(&aa);//�û����롰1��ִ�������ϵ�˲�����
			break;
		    case 2:show(&aa);//�û����롰2��ִ�в鿴ͨѶ¼������
			break;
		    case 3:del(&aa);//"�û����롰3��ִ��ɾ��ͨѶ¼����
			break;
		    case 4:search(&aa);//�û����롰4��ִ�в�����ϵ�˲�����
			break;
		    case 5:modify(&aa);//�û����롰5��ִ���޸���ϵ�˲�����
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
