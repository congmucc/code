#include<stdio.h>


void test() {
	int n;
    printf("�������ַ����ĳ��ȣ�\n");
    scanf("%d", &n);
	char str[n], sl[17];
	printf("�������ַ�����\n");
	scanf("%s",str);
//	if (n < 16) {
//		printf("none");
//	} else {
//		for (int i = 0; i < sizeof(str)/sizeof(char); i++) {
//    	while (str[i] == str[i+1]) {
//    		
//		    } 
//	    }
//	}
    int i;
    printf("%c\n",&str[3]);
    printf("%s\n",&str[4]);
    for (i = 0; i < n; i++) {
    	 printf("%s\n",&str[i]);
	} 
}



int main() {
	test();
	return 0;
}
