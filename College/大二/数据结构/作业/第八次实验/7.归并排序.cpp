#include<iostream> 
#include<algorithm>
using namespace std;


void print(int a[], int n){
	for(int j= 0; j<n; j++){
		cout<<a[j] <<"  ";
	}
	cout<<endl;
}

//�ϲ�
void merge(int arr[], int tempArr[], int left, int mid, int right) {
	//����������ĵ�һ��δ�����Ԫ�� 
	int l_pos = left;
	//����Ұ�����ĵ�һ��δ�����Ԫ�� 
	int r_pos = mid + 1;
	//��ʱ����Ԫ�ص��±� 
	int pos = left;
	
	//�ϲ�
	while (l_pos <= mid && r_pos <= right) {
		if (arr[l_pos] < arr[r_pos]) 
			tempArr[pos++] = arr[l_pos++];
		else
		    tempArr[pos++] = arr[r_pos++];
	} 
	
	//��һ�����ϲ���ȫ����һ����Ӧֱ�Ӳ��� 
	//�������� 
	while (l_pos <= mid) {
		tempArr[pos++] = arr[l_pos++];
	} 
	//��������
	while (r_pos <= right) {
		tempArr[pos++] = arr[r_pos++];
	} 
	
    //����ʱ�����鿽����arr[]
	while (left <= right) {
		arr[left] = tempArr[left];
		left++;
	} 
	
} 



//�鲢���� 
//���� 
void msort(int arr[], int tempArr[], int left, int right) {
	//���ֻ��һ��Ԫ�أ���ô�Ͳ���Ҫ��������
    //ֻ��һ��Ԫ�ص��������������ģ�ֻ��Ҫ���鲢����
	if (left < right) {
		int mid = (left + right) / 2;
	    //������������ 
	    msort(arr, tempArr, left, mid);
	    msort(arr, tempArr, mid + 1, right);
	    //�ϲ���������
		merge(arr, tempArr, left, mid, right); 
	} 
}


//�鲢�������� 
void mergeSort(int arr[], int n) {
    //����һ������
	int *tempArr = new int[n];
	if (tempArr) { //����ɹ�
        msort(arr, tempArr, 0, n - 1);
        delete []tempArr;
	} else {
		cout << "error: failed to allocate Memory" <<endl;
	}
}


bool sw(int a, int b) {
	return a > b;
}

int main() {
	int arr[12] = {1,3,5,46,11,22,37,45,44,78,67,98};
    print(arr, 12);
	mergeSort(arr, 12);
	cout<<"�����";
	reverse(arr, arr+12); 
	
	
//	sort(arr, arr+12, sw); 
	
	print(arr, 12);  
	return 0;
} 
