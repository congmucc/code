#include<iostream> 
using namespace std;


bool IsFake(char c, bool light){
	for (int i = 0; i < 3; i++) {
		char *pLeft, *pRight;   //ָ����ƽ���ߵ��ַ��� 
		if (light) {
			pLeft = Left[i];
			pRight = Right[i];
		} else {                //����ٱ����صģ� ��ѳ���������Ҷ�        �� 
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
