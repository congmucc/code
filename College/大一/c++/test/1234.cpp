#include<iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int i=0;
	while(1)
	{
	int a=rand()%76+2;
	cout<<a<<endl;;
	i++;
	if(i==7)
	{
		break;
	}
    }
	return 0;
}
