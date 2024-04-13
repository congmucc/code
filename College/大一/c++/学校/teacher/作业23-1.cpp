#include<iostream>
using namespace std;
#define M 10
#define N 10
class Matrix    //矩阵类
{
public:
	void Set_Matrix();//输入矩阵
	friend Matrix operator+(Matrix& m1, Matrix& m2);//友元函数，重载运算符+
	void display();//输出矩阵
	static int m;//矩阵行数
	static int n;//矩阵列数
private:	
	int mat[M][N];//存放矩阵数据
};

void Matrix::Set_Matrix()//输入矩阵
{
	for (int i = 0; i <Matrix::m; i++)
		for (int j = 0; j <Matrix::n; j++)
		{
			cin >> mat[i][j];
		}
}
int Matrix::m = 0;//行数初始化
int Matrix::n = 0;//列数初始化

Matrix operator+(Matrix& m1, Matrix& m2)
{
	Matrix m3;
	
	for (int i = 0; i <Matrix::m; i++)
		for (int j = 0; j < Matrix::n; j++)
			m3.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
	return m3;
}
void Matrix::display()
{
	for (int i = 0; i < Matrix::m; i++)
	{
		for (int j = 0; j < Matrix::n; j++)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int h, c;
	cout << "请输入行数h和列数c（1<=h<=10,1<=c<=10)" << endl;
	cin >> h >> c;
	Matrix::m = h;//设置行数
	Matrix::n = c;//设置列数
	Matrix m1, m2,m3;
	cout << "第1个矩阵：" << endl;
	m1.Set_Matrix();
	cout << "第2个矩阵：" << endl;
	m2.Set_Matrix();
	m3 = m1 + m2;
	cout << "两个矩阵的和：" << endl;
	m3.display();
	system("pause");
	return 0;
}
