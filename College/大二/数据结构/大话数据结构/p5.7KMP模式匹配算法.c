#include<stdio.h>

//可以看视频 
void get_next(String T, int *next) {
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0]) {  //T[0]是字串T的长度 
		if (j == 0 || T[i] == T[j]) {  //T[i]表示后缀的单个字符
		    ++i;                       //T[j]表示前缀的单个字符 
			++j; 
			next[i] = j; 
		} else {
			j = next[j];
		}
	}
}

void get_nextval(String T, int *nextval) {    //跟书上的变量不一样 
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < T[0]) {  //T[0]是字串T的长度 
		if (j == 0 || T[i] == T[j]) {  //T[i]表示后缀的单个字符
		    ++i;                       //T[j]表示前缀的单个字符 
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



//返回字串T在主串S中的第pos个字符后的位置，若不存在，则函数返回值为0 
int Index_KMP(String S, String T, int pos) {
	int i = pos;  //i用于主串S当前位置下标值，若pos不为1，则从pos位置开始匹配 
	int j = 1;    //j用于字串T中当前位置下标值
	int next[225];
	get_next(T, next);  //对T分析  得到next数组 
	while (i <= S[0] && j<= T[0]) {
		if (j == 0 || S[i] == T[j]) {
			++i;
			++j;
		} else {
			j = next[j];  //j退回到合适的位置， i的值不变 
		}
	}
	if (j > T[0]) {
		return i - T[0];   //T[0]是要匹配的串的长度 
	} else {
		return 0;
	} 
}


int main() {
	return 0; 
}
