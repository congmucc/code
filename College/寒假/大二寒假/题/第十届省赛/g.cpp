#include<bits/stdc++.h>
using namespace std;
int Ai[100005];
int main(){
	int N;
	int deep = 1; //��� 
	int sum = 0; //ÿ�еĺ� 
	long long max_sum = -100000000000; //���ĺ� 
	int max_deep = 1;
	cin>>N;
	for(int i = 1; i <= N; ++i){
		cin>>Ai[i];
		sum += Ai[i];
		if (i == pow(2, deep) - 1) {
			if (max_sum < sum) {
				max_deep = deep;
				max_sum = sum;
			}
			sum = 0;
			deep ++;
		}
	}
	cout<<max_deep<<endl;
	return 0;
}
