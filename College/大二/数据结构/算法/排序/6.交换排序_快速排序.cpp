#include<iostream>

using namespace std;


void print(int a[], int n){
	for(int j= 0; j<n; j++){
		cout<<a[j] <<"  ";
	}
	cout<<endl;
}

//˼·һ�����ǽ�����ʱ���privotKey�������������������ȵ�ʱ��
//��λ�þ���privotKey 
int partition(int a[], int low, int high) {
    int privotKey = a[low];								//��׼Ԫ��
	while(low < high){								    //�ӱ�����˽�������м�ɨ��
		while(low < high  && a[high] >= privotKey) --high;  //��high ��ָλ����ǰ���������ൽlow+1 λ�á����Ȼ�׼Ԫ��С�Ľ������Ͷ�
		a[low] = a[high];
		while (low < high && a[low] <= privotKey) ++low;
		a[high] = a[low];
	}
	a[low] = privotKey;  //��ʱ�Ѿ��ź��ˣ�low == high 
	return low;
}

void quickSort (int a[], int low, int high) {
	if (low <high) {
		int privotLoc = partition(a,  low,  high);  //����һ��Ϊ��
		quickSort(a,  low,  privotLoc -1);			//�ݹ�Ե��ӱ�ݹ�����
		quickSort(a,   privotLoc + 1, high);		//�ݹ�Ը��ӱ�ݹ�����
	}
}


/*
��������ĸĽ�
 �ڱ��Ľ��㷨��,ֻ�Գ��ȴ���k�������еݹ���ÿ�������,��ԭ���л�������Ȼ���ٶ������������������ò��������㷨����
 ʵ��֤�����Ľ�����㷨ʱ�临�Ӷ��������ͣ��ҵ�kȡֵΪ 8 ����ʱ,�Ľ��㷨��������ѡ��㷨˼�����£�
 
void qsort_improve(int r[ ],int low,int high, int k){
	if( high -low > k ) { //���ȴ���kʱ�ݹ�, kΪָ������
		int pivot = partition(r, low, high); // ���õ�Partition�㷨���ֲ���
		qsort_improve(r, low, pivot - 1,k);
		qsort_improve(r, pivot + 1, high,k);
	} 
} 
void quickSort(int r[], int n, int k){
	qsort_improve(r,0,n,k);//�ȵ��øĽ��㷨Qsortʹ֮��������
 
	//���ò�������Ի���������������
	for(int i=1; i<=n;i ++){
		int tmp = r[i]; 
		int j=i-1;
		while(tmp < r[j]){
			r[j+1]=r[j]; j=j-1; 
		}
		r[j+1] = tmp;
	} 
 
} 

*/
int main() {
	int a[10] = {3,1,5,7,2,4,9,6,10,8};
	cout<<"��ʼֵ��";
	print(a,10);
	quickSort(a,0,9);
	cout<<"�����";
	print(a,10);

	
	return 0;
}
