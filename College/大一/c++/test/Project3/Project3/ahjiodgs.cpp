#include<stdio.h>


void test() {
	int n;
	printf("请输入字符串的长度：\n");
	scanf("%d\n", &n);
	char str[n], sl[17];
	printf("请输入字符串：\n");
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