#include <iostream>

using namespace std;

int main()
{
    string s;
    int n1=0,n2=0,n3=0,n4=0,n5=0;
    getline(cin,s);
for(int i=1;i<=s.length();i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			n1++;
		}
		else if(s[i]>='a'&&s[i]<='z')
		{
			n2++;
		}
		else if(s[i]==' ')
		{
			n3++;
		}
		else if(s[i]>='1'&&s[i]<='9')
		{
			n4++;
		}
		else
		{
			n5++;
		}
	}
	cout<<"��д��ĸ��"<<n1<<endl;
	cout<<"Сд��ĸ��"<<n2<<endl;
	cout<<"���֣�"<<n4<<endl;
	cout<<"�ո�"<<n3<<endl;
	cout<<"�����ַ���"<<n5<<endl;

    return 0;
}
