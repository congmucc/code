#include<iostream>

using namespace std;

#include<vector>

const int N = 1e8; 


int main() {
	vector<int> res(10, 2021);
	int  i = 1, j, k;
	 while (1) {
	 	j = i;
	 	while(j) {
	 		k = j % 10;
	 		
			if (res[k] > 0) res[k]--;
			else break;
	 		
		    j = j / 10;	 		
			
		 }
		 if (j > 0) break;
		 else i++;
	 }
	 
	cout << i - 1;
	
	return 0;
} 
