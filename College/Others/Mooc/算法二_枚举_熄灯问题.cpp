 #inlcude<iostream>
using namespace std;

char oriLights[5];    //最开始的行数 
char lights[5];       //
char result[5];       //结果 


//让c的第i位到第一位 并输出出去 
int GetBit(char c, int i) {
	return (c >> i) & 1;
}

//把c的第i位改成v    v的结果可能为0或者为1 
void SetBit(char &c, int i, int v) {
	if (v) {
		c |= (1 << i); 
	} else {
		c &= ~(1 << i);
	}
} 

//把c的第i位进行反转    ^为异或运算符     相同为0，相异为1   位方面的 
void  FlipBit(char &c, int i) {
	c ^= (1 << i);
}

//输出第t个开始的结果 
void OutputResult (int t, char result[]) {
	cout << "PUZZLE #" << t <<endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			cout << GetBit(result[i], j);
			if (j < 5)
			    cout << " "; 
		}
		cout << endl;
	}
} 

//初始化矩阵 
void test() {
   int T;
   cin >> T;
   for (int t = 1; t <= T; t++) {
   	for (int i = 0; i < 5; i++) {
   		for (int j = 0; j < 6; j++) {
   			int s;
   			cin >> s;
   			SetBit(oriLight[i], j, s);
		   }
		for (int n = 0; n < 64; n++) {
			int switchs = n;
			for (int i = 0)
		}
	   }
   }
}
int main() {
	test(); 
}
