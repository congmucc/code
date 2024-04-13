#include<bits/stdc++.h>

using namespace std;

void getNext(int* next, const string& s) {
        next[0] = 0;
        int i = 1, j = 0;
        while (i <= s.size()) {
        	if (j == 0 || s[i] == s[j]) next[i++] = j++;
        	else j = next[j];
        } 
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }


int main() {
	string haystack, needle;
	cin >> haystack >> needle;
	
	cout << strStr(haystack, needle); 
	
	return 0;
}
