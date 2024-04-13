#include<stdio.h>


//���ڱ�˳����� 
int Sequential_Search(int *a, int n, int key) {
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] == key) {
			return 1;
		}
	}
	return 0;
} 

//���ڱ�˳����ң��������ڱ����Ż� �Ż���i����n���бȽϣ� ʱ�临�Ӷ��ǣ�n+1��/2 
int Sequential_Search2(int *a, int n, int key) {
	int i;
	a[0] =key;                //����a[0]Ϊ�ؼ���ֵ�����ǳ�֮Ϊ�ڱ�   ������˵û������ 
	i = n;                    //ѭ�������β����ʼ 
	while (a[i] != key) {
		--i;
	}
	return i;                 //����0��˵������ʧ��   
} 

//���ֲ���
int Binary_Search(int *a, int n, int key) {
	int low,high,mid;
	low=1;	/* ��������±�Ϊ��¼��λ */
	high=n;	/* ��������±�Ϊ��¼ĩλ */
	while(low<=high)
	{
		mid=(low+high)/2;	/* �۰� */
		if (key<a[mid])		/* ������ֵ����ֵС */
			high=mid-1;		/* ����±��������λ�±�Сһλ */
		else if (key>a[mid])/* ������ֵ����ֵ�� */
			low=mid+1;		/* ����±��������λ�±��һλ */
		else
		{
			return mid;		/* �������˵��mid��Ϊ���ҵ���λ�� */
		}
		
	}
	return 0;
} 

//��ֵ����   ���ǰ�for����ĵ�һ��mid���ı��� 
int Interpolation_Search(int *a, int n, int key) {
int low,high,mid;
	low=1;	/* ��������±�Ϊ��¼��λ */
	high=n;	/* ��������±�Ϊ��¼ĩλ */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* ��ֵ */
		if (key<a[mid])		/* ������ֵ�Ȳ�ֵС */
			high=mid-1;		/* ����±��������ֵ�±�Сһλ */
		else if (key>a[mid])/* ������ֵ�Ȳ�ֵ�� */
			low=mid+1;		/* ����±��������ֵ�±��һλ */
		else
			return mid;		/* �������˵��mid��Ϊ���ҵ���λ�� */
	}
	return 0;
}

//쳲���������
int Fibonacci_Search(int *a, int n, int key) {
    int low,high,mid,i,k=0;
	low=1;	/* ��������±�Ϊ��¼��λ */
	high=n;	/* ��������±�Ϊ��¼ĩλ */
	while(n>F[k]-1)
		k++;
	for (i=n;i<F[k]-1;i++)
		a[i]=a[n];
	
	while(low<=high)
	{
		mid=low+F[k-1]-1;
		if (key<a[mid])
		{
			high=mid-1;		
			k=k-1;
		}
		else if (key>a[mid])
		{
			low=mid+1;		
			k=k-2;
		}
		else
		{
			if (mid<=n)
				return mid;		/* �������˵��mid��Ϊ���ҵ���λ�� */
			else 
				return n;
		}
		
	}
	return 0;
	
}

int main() {
	int arr[11]={0,1,16,24,35,47,59,62,73,88,99};
	printf("%d",Sequential_Search2(arr, 10, 1));
	return 0;
} 
