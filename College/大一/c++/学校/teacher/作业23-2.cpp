#include<iostream>
using namespace std;
class Complex
{
public:
	Complex() { real = 1; imag = 0; }
	Complex(double r,double i):real(r),imag(i){}
	void display();
	friend Complex operator + (Complex& c1, Complex& c2);
	friend Complex operator - (Complex& c1, Complex& c2);
	friend Complex operator * (Complex& c1, Complex& c2);
	friend Complex operator / (Complex& c1, Complex& c2);
private:
	double real;
	double imag;
};
void Complex::display()
{
	cout << "(" << real << "," << imag << "i)" << endl;
}
Complex operator + (Complex& c1, Complex& c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
Complex operator - (Complex& c1, Complex& c2)
{
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}
Complex operator * (Complex& c1, Complex& c2)
{
	Complex c3;
	c3.real = c1.real * c2.real - c1.imag * c2.imag;
	c3.imag = c1.imag * c2.real + c1.real * c2.imag;
	return c3;
}
Complex operator / (Complex& c1, Complex& c2)
{
	Complex c3;
	c3.real = (c1.real * c2.real + c1.imag * c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
	c3.imag = (c1.imag * c2.real - c1.real * c2.imag)/(c2.real * c2.real + c2.imag * c2.imag);
	return c3;
}
void cal_Comp(Complex& c1, Complex& c2, int c)
{
	Complex c3;
	switch (c)
	{
	case 1:
		cout << "c1+c2=";
		c3 = c1 + c2;
		c3.display();
		break;
	case 2:
		cout << "c1-c2=";
		c3 = c1 - c2;
		c3.display();
		break;
	case 3:
		cout << "c1*c2=";
		c3 = c1 * c2;
		c3.display();
		break;
	default:
		cout << "c1/c2=";
		c3 = c1 / c2;
		c3.display();
		break;
	}
}
int main()
{
	Complex c1(2.1, 3.2), c2(0.1, 0.5),c3,c4,c5,c6;
	cout << "c1:";
	c1.display();
	cout << "c2:";
	c2.display();
	cout << "**************************" << endl;
	cout << "选择计算类型（选择序号）" << endl;
	cout << "\t1、加法" << endl;
	cout << "\t2、减法" << endl;
	cout << "\t3、乘法" << endl;
	cout << "\t4、除法" << endl;
	cout << "**************************" << endl;
	int i;
	cin >> i;
	cal_Comp(c1, c2, i);
	system("pause");
	return 0;
}
