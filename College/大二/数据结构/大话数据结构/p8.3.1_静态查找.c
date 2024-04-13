#include<stdio.h>


//无哨兵顺序查找 
int Sequential_Search(int *a, int n, int key) {
	int i;
	for (i = 0; i < n; i++) {
		if (a[i] == key) {
			return 1;
		}
	}
	return 0;
} 

//有哨兵顺序查找（算是无哨兵的优化 优化了i不与n进行比较） 时间复杂度是（n+1）/2 
int Sequential_Search2(int *a, int n, int key) {
	int i;
	a[0] =key;                //设置a[0]为关键字值，我们称之为哨兵   正常来说没这句代码 
	i = n;                    //循环数组从尾部开始 
	while (a[i] != key) {
		--i;
	}
	return i;                 //返回0则说明查找失败   
} 

//二分查找
int Binary_Search(int *a, int n, int key) {
	int low,high,mid;
	low=1;	/* 定义最低下标为记录首位 */
	high=n;	/* 定义最高下标为记录末位 */
	while(low<=high)
	{
		mid=(low+high)/2;	/* 折半 */
		if (key<a[mid])		/* 若查找值比中值小 */
			high=mid-1;		/* 最高下标调整到中位下标小一位 */
		else if (key>a[mid])/* 若查找值比中值大 */
			low=mid+1;		/* 最低下标调整到中位下标大一位 */
		else
		{
			return mid;		/* 若相等则说明mid即为查找到的位置 */
		}
		
	}
	return 0;
} 

//插值查找   就是把for里面的第一个mid给改变了 
int Interpolation_Search(int *a, int n, int key) {
int low,high,mid;
	low=1;	/* 定义最低下标为记录首位 */
	high=n;	/* 定义最高下标为记录末位 */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* 插值 */
		if (key<a[mid])		/* 若查找值比插值小 */
			high=mid-1;		/* 最高下标调整到插值下标小一位 */
		else if (key>a[mid])/* 若查找值比插值大 */
			low=mid+1;		/* 最低下标调整到插值下标大一位 */
		else
			return mid;		/* 若相等则说明mid即为查找到的位置 */
	}
	return 0;
}

//斐波那契查找
int Fibonacci_Search(int *a, int n, int key) {
    int low,high,mid,i,k=0;
	low=1;	/* 定义最低下标为记录首位 */
	high=n;	/* 定义最高下标为记录末位 */
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
				return mid;		/* 若相等则说明mid即为查找到的位置 */
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
