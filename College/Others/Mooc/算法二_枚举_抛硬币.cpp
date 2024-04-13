#include<iostream> 
using namespace std;


bool IsFake(char c, bool light){
	for (int i = 0; i < 3; i++) {
		char *pLeft, *pRight;   //指向天平两边的字符串 
		if (light) {
			pLeft = Left[i];
			pRight = Right[i];
		} else {                //如果假币是重的， 则把称量结果左右对        换 
			pLeft = Right[i];
			pRight = Left[i];
		}
	}
}

void FindCoin() {
	
	char Left[3][7];
	char Right[3][7];
	char result[3][7];
	
	
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; i++) {
			cin >> Left[i] >> Right[i] >> result[i];
		}
		for (char c= 'A'; c <= 'L' ;c++) {
			if (IsFake(c, true)) {
				cout << c << "is the conterfeit coin and it is light" << endl;
				break;
			} else if (IsFake(c, false)) {
				cout << c << "is the conterfeit coin and it is heavy" << endl;
				break;
			} 
		}
	} 
	
	
	
} 


int main() {
	
	FindCoin();
	return 0;
} 
