#include<iostream>
#include<algorithm>
using namespace std;
int dp[110][10006] = {0};
int a[110];
int main()
{
	//采用dp算法
	int n,sum=0,ans=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	//开始dp状态逐渐转移
	//第一个状态a[1]是肯定存在的
		dp[1][a[1]] = 1;//i表示第几个状态，a[j]表示重量
	for (int i = 2; i <= n; i++)//其他状态，继承状态
	{
		int x = a[i];//把值赋给x便于编写
		for (int j = 1; j <= sum; j++)//把上一个状态赋给当前状态
			//主要是看存在1的dp
		{
			dp[i][j] = dp[i - 1][j];
		}
		dp[i][x] = 1;//传入当前数的状态
		for (int j = 1; j <= sum; j++)//开始加减传入数
		{
			if (dp[i-1][j] == 1)//如果执行时有数子的才进行加减
			{
				dp[i][j + x] = 1;//加法
				dp[i][abs(j - x)] = 1;//减法
			}

		}
	
	
	}
	for (int j = 1; j <= sum; j++)
	{
		if (dp[n][j] == 1)
		{
			ans++;
		}
	}
	cout << ans << endl;
}
