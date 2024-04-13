//#include<stdio.h>
//#include<string.h>
//
//
//typedef struct Test {
//	int js;
//	int jsc;
//} *test;
//
//void test01() {
//	test d1;
//	//printf(d1);
//	
//}
//
//
//void test02() {
//	char* ch = "Welcome\72Fu\0jian!\n";
//	printf("%d",strlen(ch));
//}
//int main() {
//	
////	test01();
//    test02();
//	return 0;
//}



#include <stdio.h>
#include <stdlib.h>

void fun(int *tmp)
{
	printf("%d\n",tmp); 
	*tmp = 100;
}

int main(int argc, char *argv[])
{
	int *p = NULL;
	p = (int *)malloc(sizeof(int));

    printf("%d\n",p); 

	fun(p); //µØÖ·´«µÝ
	printf("*p = %d\n", *p); //ok£¬*pÎª100

	return 0;
}

