#include<stdio.h>

//���Կ���Ƶ 
void get_next(String T, int *next) {
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0]) {  //T[0]���ִ�T�ĳ��� 
		if (j == 0 || T[i] == T[j]) {  //T[i]��ʾ��׺�ĵ����ַ�
		    ++i;                       //T[j]��ʾǰ׺�ĵ����ַ� 
			++j; 
			next[i] = j; 
		} else {
			j = next[j];
		}
	}
}

void get_nextval(String T, int *nextval) {    //�����ϵı�����һ�� 
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < T[0]) {  //T[0]���ִ�T�ĳ��� 
		if (j == 0 || T[i] == T[j]) {  //T[i]��ʾ��׺�ĵ����ַ�
		    ++i;                       //T[j]��ʾǰ׺�ĵ����ַ� 
			++j;
			if (T[i] != T[j]) 
			nextval[i] = j;
			else
			nextval[i] = nextval[j]; 
		} else {
			j = next[j];
		}
	}
}



//�����ִ�T������S�еĵ�pos���ַ����λ�ã��������ڣ���������ֵΪ0 
int Index_KMP(String S, String T, int pos) {
	int i = pos;  //i��������S��ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� 
	int j = 1;    //j�����ִ�T�е�ǰλ���±�ֵ
	int next[225];
	get_next(T, next);  //��T����  �õ�next���� 
	while (i <= S[0] && j<= T[0]) {
		if (j == 0 || S[i] == T[j]) {
			++i;
			++j;
		} else {
			j = next[j];  //j�˻ص����ʵ�λ�ã� i��ֵ���� 
		}
	}
	if (j > T[0]) {
		return i - T[0];   //T[0]��Ҫƥ��Ĵ��ĳ��� 
	} else {
		return 0;
	} 
}


int main() {
	return 0; 
}
