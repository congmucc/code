
#include<iostream>
using namespace std;
 
bool isleap(int y)
{
	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return true;
	return false;
}
int main()
{
	int y1 = 1921, y2 = 2020;
	int days = 0; //记录天数
	 //加一是因为不加多加1年 
	for(int i = y1 + 1; i <= y2; i++)
	{
		if(isleap(i)) days += 366;
		else days += 365;
	}
	
	days -= 22;
	
	cout << days << endl;
	
	long long ans = days * 24 * 60;
	cout << ans << endl;
	return 0;
}
