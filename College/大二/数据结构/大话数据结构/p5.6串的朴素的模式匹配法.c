#include<stdio.h>

//返回字串T在主串S中第pos个字符之后的位置，若不存在 则返回值0 
int Index(String S, String T,int pos) {
	int i = pos;  //i用于主串当前位置的下标，若pos不为1  则从pos位置开始匹配 
	int j = 1     //j用于字串T中当前位置下标值 
	while (i <= S.Length() && j <= T.Length()) {//Length为串的长度    这里S[0]和T[0]是信息串，例如要匹配的串的长度  所以说都是从1开始 
	    if (S[i] == T[j]) {
	    	i++;
	    	j++;
		} else {
			i = i - j + 2; //i退回上次匹配首位的下一位置
			j = 1;         //j退回到字串T的首位 
		}
	} 
	if (j > T.Length()) {  //因为T[0]不是数据，对比后肯定j大 
		return i - T.Length();    //注意这是T 
	} else {
		return 0;
	}
}





int main() {
	
    return 0;
} 
