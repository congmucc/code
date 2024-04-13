#include<iostream>
using namespace std;
#include<string>
bool door[210]; 



void test01() {
	string s;
	cin >> s;
    for (int i = 0; i < s.size(); i++) {
    	cout << char(s[i] + 3);
	}
}


void test02() {
	int N;
	int cnt = 0;
	for (int i = 2; i * i < N; i++) {
		while (N % i == 0) {
			N /= i;
			cnt++;
		}
	}
	if (N != 1) {
		cnt++;
	}
	cout << cnt << endl;
}

void test03() {
	int N;
	cin >> N;
	int cnt = 0;
	int j = 0;
	for (int i = 1; i <= N; i++) {
		for (j = i; j <= 2*N; j += i) {
			door[j] = !door[j];
		}
	}
//	for (int i = 1; i <= N; i++) {
//		j = i;
//			for (int k = 1; ; k++) {
//				door[j] = !door[j];
//				j += i;
//				if (j > 2*N) {
//				break;
//				}
//			}
//	}
	for (int i = 0; i <= 2*N; i++) {
		if (door[i]) cnt++;
	}
	cout << cnt << endl;
	
}



int main() {
//	test01();
//	test02();
    test03();
/*
4题是背包问题，5题是动态规划，6题是深搜。学了再看。 
*/ 
	return 0;
} 
