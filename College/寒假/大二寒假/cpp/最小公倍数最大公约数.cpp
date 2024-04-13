#include <iostream>

using namespace std;

int gcd(int,int); //调用最大公约数的函数声明
int lcm(int,int); //调用最小公倍数的函数声明

int main(){
    int num1,num2,g,l;
    cout << "请输入两个数：";
    cin >> num1 >> num2;
    cout << "你输入的两个数为：" << num1 << " " << num2 << endl; // 测试，此行可省略
    g = gcd(num1, num2); //传参求值
    l = lcm(num1, num2); //传参求值
    cout << "他们的最大公约数是：" << g << endl; //输出结果
    cout << "他们的最小公倍数是：" << l << endl; //输出结果
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
    g1 = gcd(m,n); //调用求最大公约数的函数
    b = (m*n) / g1; //最小公倍数=两数之积/最大公约数
    return b; //返回b给main函数中的l
}
