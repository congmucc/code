#include<stdio.h>


void test() {
	int n;
	printf("�������ַ����ĳ��ȣ�\n");
	scanf("%d\n", &n);
	char str[n], sl[17];
	printf("�������ַ�����\n");
	scanf("%s", str);
	//    for (int i = 0; i < sizeof(str)/sizeof(char); i++) {
	//    	while (str[i] == str[i+1]) {
	//		} 
	//	}
	printf("%s", str[5]);
}



int main() {
	test();
	return 0;
}