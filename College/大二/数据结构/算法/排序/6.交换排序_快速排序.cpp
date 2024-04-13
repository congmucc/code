#include<iostream>

using namespace std;


void print(int a[], int n){
	for(int j= 0; j<n; j++){
		cout<<a[j] <<"  ";
	}
	cout<<endl;
}

//思路一样就是交换的时候把privotKey提出来，最后两个标记相等的时候
//的位置就是privotKey 
int partition(int a[], int low, int high) {
    int privotKey = a[low];								//基准元素
	while(low < high){								    //从表的两端交替地向中间扫描
		while(low < high  && a[high] >= privotKey) --high;  //从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
		a[low] = a[high];
		while (low < high && a[low] <= privotKey) ++low;
		a[high] = a[low];
	}
	a[low] = privotKey;  //此时已经排好了，low == high 
	return low;
}

void quickSort (int a[], int low, int high) {
	if (low <high) {
		int privotLoc = partition(a,  low,  high);  //将表一分为二
		quickSort(a,  low,  privotLoc -1);			//递归对低子表递归排序
		quickSort(a,   privotLoc + 1, high);		//递归对高子表递归排序
	}
}


/*
快速排序的改进
 在本改进算法中,只对长度大于k的子序列递归调用快速排序,让原序列基本有序，然后再对整个基本有序序列用插入排序算法排序。
 实践证明，改进后的算法时间复杂度有所降低，且当k取值为 8 左右时,改进算法的性能最佳。算法思想如下：
 
void qsort_improve(int r[ ],int low,int high, int k){
	if( high -low > k ) { //长度大于k时递归, k为指定的数
		int pivot = partition(r, low, high); // 调用的Partition算法保持不变
		qsort_improve(r, low, pivot - 1,k);
		qsort_improve(r, pivot + 1, high,k);
	} 
} 
void quickSort(int r[], int n, int k){
	qsort_improve(r,0,n,k);//先调用改进算法Qsort使之基本有序
 
	//再用插入排序对基本有序序列排序
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
	cout<<"初始值：";
	print(a,10);
	quickSort(a,0,9);
	cout<<"结果：";
	print(a,10);

	
	return 0;
}
