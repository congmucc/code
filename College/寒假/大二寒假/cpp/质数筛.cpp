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

//埃氏筛算法 普通晒 

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
int vis[N] = {0};//vis用来判断数字是否访问过
int prime[N] = {0};//prime用来存储筛选出来的素数
int k;

//埃氏素数筛函数
int Eratosthenes_sieve(int n)//这里用了英文全称，平时用sieve等命名就好
{
    int i,j,k;
    k=0;
    memset(vis,0,sizeof(int)*maxn);
    vis[0]=vis[1]=1;
    for(i=2;i<=n;i++)//从最小的素数2开始筛选，2以下就没必要筛选
    {
        if(vis[i]==0)//这个数是目前最小的，且未被访问过的
        {
            prime[k++]=i;//因此这个数是素数,存储起来
            for(j=2;i*j<=n;j++)//这里的改变就是把损坏放入if判断语句之内
                vis[i*j]=1;//只对素数进行倍增筛选，其他基本不变
        }
    }
    return k;//返回范围内素数的个数
}
*/



int main() {
	int n = 100002;
	cout << getTen(n) <<endl;
    int k;
    
	cin >> k;
    
    if (prime(k))
    
	cout << "是质数" << endl;	
	
	return 0;
} 
