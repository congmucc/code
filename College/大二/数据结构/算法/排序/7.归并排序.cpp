#include<iostream> 
using namespace std;

//�����Կ�bվ�ϵġ������AXin ���Ĺ鲢�������Ƶ ���ȽϺ� 

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

int main() {
	int arr[10] = {3,1,5,7,2,4,9,6,10,8};
    print(arr, 10);
	mergeSort(arr, 10);
	cout<<"�����";
	print(arr, 10);  
	return 0;
} 
