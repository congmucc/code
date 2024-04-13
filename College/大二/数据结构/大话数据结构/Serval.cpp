#include<iostream>
#include<stdio.h>
using namespace std;

void test() {
	int n;
    printf("请输入字符串的长度：\n");
    scanf("%d", &n);
	char str[n], sl[17];
	printf("请输入字符串：\n");
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

void test02() {
	int n,i;
	cin>>n;
	char str[n];
	cin>>str;
	cout<<str[5]<<endl;
	cout<<str[4]<<endl;
	cout<<str<<endl;
	for (i = 0; i < n; i++)
	cout<<str[i];
}

int main() {
//	test();
	test02();
	return 0;
}
