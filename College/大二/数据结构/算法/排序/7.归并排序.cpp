#include<iostream> 
using namespace std;

//这点可以看b站上的“请叫我AXin ”的归并排序的视频 ，比较好 

void print(int a[], int n){
	for(int j= 0; j<n; j++){
		cout<<a[j] <<"  ";
	}
	cout<<endl;
}

//合并
void merge(int arr[], int tempArr[], int left, int mid, int right) {
	//标记左半区域的第一个未排序的元素 
	int l_pos = left;
	//标记右半区域的第一个未排序的元素 
	int r_pos = mid + 1;
	//临时数组元素的下标 
	int pos = left;
	
	//合并
	while (l_pos <= mid && r_pos <= right) {
		if (arr[l_pos] < arr[r_pos]) 
			tempArr[pos++] = arr[l_pos++];
		else
		    tempArr[pos++] = arr[r_pos++];
	} 
	
	//当一个区合并完全后，另一个区应直接插入 
	//左区插入 
	while (l_pos <= mid) {
		tempArr[pos++] = arr[l_pos++];
	} 
	//右区插入
	while (r_pos <= right) {
		tempArr[pos++] = arr[r_pos++];
	} 
	
    //把临时的数组拷贝到arr[]
	while (left <= right) {
		arr[left] = tempArr[left];
		left++;
	} 
	
} 



//归并排序 
//划分 
void msort(int arr[], int tempArr[], int left, int right) {
	//如果只有一个元素，那么就不需要继续划分
    //只有一个元素的区域本身就是有序的，只需要被归并即可
	if (left < right) {
		int mid = (left + right) / 2;
	    //划分两个区域 
	    msort(arr, tempArr, left, mid);
	    msort(arr, tempArr, mid + 1, right);
	    //合并两个区域
		merge(arr, tempArr, left, mid, right); 
	} 
}


//归并排序的入口 
void mergeSort(int arr[], int n) {
    //分配一个数组
	int *tempArr = new int[n];
	if (tempArr) { //分配成功
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
	cout<<"结果：";
	print(arr, 10);  
	return 0;
} 
