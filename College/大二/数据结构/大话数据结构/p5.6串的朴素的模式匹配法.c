#include<stdio.h>

//�����ִ�T������S�е�pos���ַ�֮���λ�ã��������� �򷵻�ֵ0 
int Index(String S, String T,int pos) {
	int i = pos;  //i����������ǰλ�õ��±꣬��pos��Ϊ1  ���posλ�ÿ�ʼƥ�� 
	int j = 1     //j�����ִ�T�е�ǰλ���±�ֵ 
	while (i <= S.Length() && j <= T.Length()) {//LengthΪ���ĳ���    ����S[0]��T[0]����Ϣ��������Ҫƥ��Ĵ��ĳ���  ����˵���Ǵ�1��ʼ 
	    if (S[i] == T[j]) {
	    	i++;
	    	j++;
		} else {
			i = i - j + 2; //i�˻��ϴ�ƥ����λ����һλ��
			j = 1;         //j�˻ص��ִ�T����λ 
		}
	} 
	if (j > T.Length()) {  //��ΪT[0]�������ݣ��ԱȺ�϶�j�� 
		return i - T.Length();    //ע������T 
	} else {
		return 0;
	}
}





int main() {
	
    return 0;
} 
