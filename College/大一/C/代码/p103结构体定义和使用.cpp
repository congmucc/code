#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

struct student
{
	char name[100];
	int  age;
	int score;
	
	
};


void test01()
{
	struct student st1;
	//st1.name="张三";   //不行，因为m_Nmae现在是一个数组名   无法赋值  err
	strcpy(st1.name,"张三"); 
	 
	 
	 //先定义类型，再定义变量（常用）
     //struct student s2 = { "mike", 18 };

	 
	struct student s1;

	//如果是普通变量，通过点运算符操作结构体成员
	strcpy(s1.name, "abc");
	s1.age = 18;
	printf("s1.name = %s, s1.age = %d\n", s1.name, s1.age);

	//如果是指针变量，通过->操作结构体成员
	strcpy((&s1)->name, "test");
	(&s1)->age = 22;
	printf("(&s1)->name = %s, (&s1)->age = %d\n", (&s1)->name, (&s1)->age); 


	
	
}



void test02()
{
	struct student st[3];
//	第一种赋值方法 
//	strcpy(st[0].name,"aijodf");
//	printf("%s\n",st[0].name); 

//  第二种赋值方法
     struct student stu[3]=
	 {
	 	{"jsdfioj",13,99},
	 	{"idofhaf",15,100}
	 };
	printf("结构体的数组大小：%d\n",sizeof(stu));
	printf("结构体的元素大小：%d\n",sizeof(stu[0]));
	printf("结构体元素个数：%d\n",sizeof(stu)/sizeof(stu[0]));
	 
	 for(int i=0;i<3;i++)
	 {
	 	printf("名字：%s\n",stu[i].name);
	 	printf("年龄：%d\n",stu[i].age);
	 	printf("分数：%d\n",stu[i].score);
	 }
	
	//排序     应该用stu[i] 
	
}


//typedef struct studnet1 ss;
//struct student1
//{
//    char name[100];
// } 
 
void test03()
{
	struct student *p=(struct student *)malloc(sizeof(struct student)*3);
//	//或者用typedef  对结构体起一个别名
//	 ss *p=(ss *)malloc(sizeof(ss)*3);
    free(p);
    	
	
}

int main()
{
//	test01();     
//	test02();    //数组 
    test03();

	return 0;
 } 
