#icnlude<iostream>

using namespace std;


void bubbleSort(int a[], int n){
	for(int i =0 ; i< n - 1; ++i) {
		for(int j = 0; j < n - i - 1; ++j) {
			if(a[j] > a[j+1])
			{
				int tmp = a[j] ; a[j] = a[j+1] ;  a[j+1] = tmp;
			}
		}
	}
}


// �Ľ�һ��
/*
����һ��־�Ա���pos,���ڼ�¼ÿ�����������һ�ν��н�����λ�á�
����posλ��֮��ļ�¼���ѽ�����λ,���ڽ�����һ������ʱֻҪɨ�赽posλ�ü��ɡ�
*/

void Bubble_1 ( int r[], int n) {
	int i= n -1;  //��ʼʱ,���λ�ñ��ֲ���
	while ( i> 0) { 
		int pos= 0; //ÿ�˿�ʼʱ,�޼�¼����
		for (int j= 0; j< i; j++)
			if (r[j]> r[j+1]) {
				pos= j; //��¼������λ�� 
				int tmp = r[j]; r[j]=r[j+1];r[j+1]=tmp;
			} 
		i= pos; //Ϊ��һ��������׼��
	 } 
} 
  


//�Ľ�����
/*
��ͳð��������ÿһ���������ֻ���ҵ�һ�����ֵ����Сֵ,
���ǿ���������ÿ�������н�������ͷ�������ð�ݵķ���һ�ο��Եõ���������ֵ(����ߺ���С��) , �Ӷ�ʹ������������������һ�롣 
*/


void Bubble_2 ( int r[], int n){
	int low = 0; 
	int high= n -1; //���ñ����ĳ�ʼֵ
	int tmp,j;
	while (low < high) {
		for (j= low; j< high; ++j) //����ð��,�ҵ������
			if (r[j]> r[j+1]) {
				tmp = r[j]; r[j]=r[j+1];r[j+1]=tmp;
			} 
		--high;					//�޸�highֵ, ǰ��һλ
		for ( j=high; j>low; --j) //����ð��,�ҵ���С��
			if (r[j]<r[j-1]) {
				tmp = r[j]; r[j]=r[j-1];r[j-1]=tmp;
			}
		++low;					//�޸�lowֵ,����һλ
	} 
}



int main() {
	
	return 0;
}
