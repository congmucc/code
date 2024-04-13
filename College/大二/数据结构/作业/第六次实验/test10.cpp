#include<bits/stdc++.h>

using namespace std;

int main() {
	string str;
	string temp;
	int k;
	
	cin >> str; 
	cin >> k;a
	int i = 0;
	int left = 0, right = k;
	while (right < str.size() || left < k) {
	    if (left < k) temp += str[left++];
		if (right < str.size()) str[i++] = str[right++];
	}
	left = 0;
	for (; i < str.size(); i++) str[i] = temp[left++];
	cout << str << endl;
	
	
	return 0;
}
