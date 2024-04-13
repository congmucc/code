
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a,ans[14],acount=0;
int book[14],djg=0;
bool check(int n,int index){  //表示放第 n 个皇后，在第 i 个位置可不可以
	for(int i=1;i<n;i++){
		if(ans[i] == index || abs(n-i)==abs(ans[i]-index)) return false;
	}
	return true;
}
void dfs(int n){
	if(n == a + 1 ){
		if(djg < 3){
		for(int i = 1;i<=a;i++){
		    if(i != 1) cout<<" ";
			cout<<ans[i];	
		}
		cout<<endl;
		}
		djg++;
		acount++;
		return;
	}
	for(int i=1;i<=a;i++){
		if(book[i]==0 && check(n,i)){
			book[i] = 1;
			ans[n] = i;
			dfs(n+1);
			book[i] = 0;
		}
	}
}
int main(){
	cin>>a;
	dfs(1);
	cout<<acount;
	return 0;
}
