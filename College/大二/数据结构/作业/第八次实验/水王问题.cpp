#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main() {
	int D[]= { 1, 1, 1, 2, 4, 2, 2, 3, 3, 3, 5,2,3,2,2,2,2,2,2 }; 
	unordered_map<int, int> hashMap;
	
	int DSize = sizeof(D)/ sizeof(D[0]);
	
	cout << DSize <<endl;
	
	for (int i = 0; i < DSize; i++) {
		hashMap[D[i]]++;
	}
	
//	for (int i = 0; i < hashMap.size(); i++) {
// cout << hashMap[D[i]] << endl;
//	}
	int result = 0, results = 0;
	for (auto iter = hashMap.begin(); iter != hashMap.end(); ++iter) {
         if (result < iter->second) {
         	result = iter->second;
         results = iter->first;
		 } 
	}
	
	if (result > DSize / 2) cout << "сп: " << results << endl;
	else cout << "ц╩сп" <<endl; 
} 
