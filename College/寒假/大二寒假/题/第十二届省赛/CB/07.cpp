#include<iostream>
#include<algorithm>
using namespace std;
int dp[110][10006] = {0};
int a[110];
int main()
{
	//����dp�㷨
	int n,sum=0,ans=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	//��ʼdp״̬��ת��
	//��һ��״̬a[1]�ǿ϶����ڵ�
		dp[1][a[1]] = 1;//i��ʾ�ڼ���״̬��a[j]��ʾ����
	for (int i = 2; i <= n; i++)//����״̬���̳�״̬
	{
		int x = a[i];//��ֵ����x���ڱ�д
		for (int j = 1; j <= sum; j++)//����һ��״̬������ǰ״̬
			//��Ҫ�ǿ�����1��dp
		{
			dp[i][j] = dp[i - 1][j];
		}
		dp[i][x] = 1;//���뵱ǰ����״̬
		for (int j = 1; j <= sum; j++)//��ʼ�Ӽ�������
		{
			if (dp[i-1][j] == 1)//���ִ��ʱ�����ӵĲŽ��мӼ�
			{
				dp[i][j + x] = 1;//�ӷ�
				dp[i][abs(j - x)] = 1;//����
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
