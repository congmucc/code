#include <iostream>

using namespace std;

int gcd(int,int); //�������Լ���ĺ�������
int lcm(int,int); //������С�������ĺ�������

int main(){
    int num1,num2,g,l;
    cout << "��������������";
    cin >> num1 >> num2;
    cout << "�������������Ϊ��" << num1 << " " << num2 << endl; // ���ԣ����п�ʡ��
    g = gcd(num1, num2); //������ֵ
    l = lcm(num1, num2); //������ֵ
    cout << "���ǵ����Լ���ǣ�" << g << endl; //������
    cout << "���ǵ���С�������ǣ�" << l << endl; //������
    return 0;
}

int gcd(int a,int b){
    int c = b;
	while(a % b!= 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return c;
}

int lcm(int m,int n){
    int g1,b;
    g1 = gcd(m,n); //���������Լ���ĺ���
    b = (m*n) / g1; //��С������=����֮��/���Լ��
    return b; //����b��main�����е�l
}
