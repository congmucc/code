#include<iostream>
using namespace std;
#define M 10
#define N 10
class Matrix    //������
{
public:
	void Set_Matrix();//�������
	friend Matrix operator+(Matrix& m1, Matrix& m2);//��Ԫ���������������+
	void display();//�������
	static int m;//��������
	static int n;//��������
private:	
	int mat[M][N];//��ž�������
};

void Matrix::Set_Matrix()//�������
{
	for (int i = 0; i <Matrix::m; i++)
		for (int j = 0; j <Matrix::n; j++)
		{
			cin >> mat[i][j];
		}
}
int Matrix::m = 0;//������ʼ��
int Matrix::n = 0;//������ʼ��

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
	cout << "����������h������c��1<=h<=10,1<=c<=10)" << endl;
	cin >> h >> c;
	Matrix::m = h;//��������
	Matrix::n = c;//��������
	Matrix m1, m2,m3;
	cout << "��1������" << endl;
	m1.Set_Matrix();
	cout << "��2������" << endl;
	m2.Set_Matrix();
	m3 = m1 + m2;
	cout << "��������ĺͣ�" << endl;
	m3.display();
	system("pause");
	return 0;
}
