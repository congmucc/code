#include<bits/stdc++.h> 
#include<set>
using namespace std;



int main () {
	
	unordered_set<int> res;
	
	string str;
	int sum = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		for (int j = i; j < str.size(); j++) {
			for (int k = i; k <= j; k ++) {
				if (str[k] <= 'z' && str[k] >= 'a') res.insert(str[k]);
			}
			sum += res.size();
		    res.clear();
		}
		
	}
	cout << sum;
	
	return 0;
}
