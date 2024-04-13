#include<iostream> 
#include<stdlib.h>
#include<cmath> 

using namespace std;

const int N = 1e4+10;


void print(int n, int a[N]) {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


int getTen(int n) {
	for (int i = 2; i * i < n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

//����ɸ�㷨 ��ͨɹ 

bool prime(int n) {
	if (n == 1 || n == 2) {
		return true;
	}
	int isPrime[N] = {0};

	for (int i = 2; i <= n; i++) {
		if (!isPrime[i]) {
			for (int j = 2; i * j <= n; j++) {
				isPrime[i * j] = 1;
			}
		}
	}
	
	print(n, isPrime);
		
	if (isPrime[n] == 0) {
		return true;
	} else {
		return false;
	}
}
 
/*
int vis[N] = {0};//vis�����ж������Ƿ���ʹ�
int prime[N] = {0};//prime�����洢ɸѡ����������
int k;

//��������ɸ����
int Eratosthenes_sieve(int n)//��������Ӣ��ȫ�ƣ�ƽʱ��sieve�������ͺ�
{
    int i,j,k;
    k=0;
    memset(vis,0,sizeof(int)*maxn);
    vis[0]=vis[1]=1;
    for(i=2;i<=n;i++)//����С������2��ʼɸѡ��2���¾�û��Ҫɸѡ
    {
        if(vis[i]==0)//�������Ŀǰ��С�ģ���δ�����ʹ���
        {
            prime[k++]=i;//��������������,�洢����
            for(j=2;i*j<=n;j++)//����ĸı���ǰ��𻵷���if�ж����֮��
                vis[i*j]=1;//ֻ���������б���ɸѡ��������������
        }
    }
    return k;//���ط�Χ�������ĸ���
}
*/



int main() {
	int n = 100002;
	cout << getTen(n) <<endl;
    int k;
    
	cin >> k;
    
    if (prime(k))
    
	cout << "������" << endl;	
	
	return 0;
} 
