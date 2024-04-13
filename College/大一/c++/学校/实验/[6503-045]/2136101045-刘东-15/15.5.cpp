#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch[100],foot=0,i=0;
	cin>>ch;
	while(i<100)
	{
		if(ch[i]=='\0')
		{
			foot=i-1;
			break;
		}
		i++;
	}
	for(;foot>=0;foot--)
	{
		cout<<ch[foot];
	}
	cout<<endl;
	return 0;
}
