 #inlcude<iostream>
using namespace std;

char oriLights[5];    //�ʼ������ 
char lights[5];       //
char result[5];       //��� 


//��c�ĵ�iλ����һλ �������ȥ 
int GetBit(char c, int i) {
	return (c >> i) & 1;
}

//��c�ĵ�iλ�ĳ�v    v�Ľ������Ϊ0����Ϊ1 
void SetBit(char &c, int i, int v) {
	if (v) {
		c |= (1 << i); 
	} else {
		c &= ~(1 << i);
	}
} 

//��c�ĵ�iλ���з�ת    ^Ϊ��������     ��ͬΪ0������Ϊ1   λ����� 
void  FlipBit(char &c, int i) {
	c ^= (1 << i);
}

//�����t����ʼ�Ľ�� 
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

//��ʼ������ 
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
