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
	//st1.name="����";   //���У���Ϊm_Nmae������һ��������   �޷���ֵ  err
	strcpy(st1.name,"����"); 
	 
	 
	 //�ȶ������ͣ��ٶ�����������ã�
     //struct student s2 = { "mike", 18 };

	 
	struct student s1;

	//�������ͨ������ͨ��������������ṹ���Ա
	strcpy(s1.name, "abc");
	s1.age = 18;
	printf("s1.name = %s, s1.age = %d\n", s1.name, s1.age);

	//�����ָ�������ͨ��->�����ṹ���Ա
	strcpy((&s1)->name, "test");
	(&s1)->age = 22;
	printf("(&s1)->name = %s, (&s1)->age = %d\n", (&s1)->name, (&s1)->age); 


	
	
}



void test02()
{
	struct student st[3];
//	��һ�ָ�ֵ���� 
//	strcpy(st[0].name,"aijodf");
//	printf("%s\n",st[0].name); 

//  �ڶ��ָ�ֵ����
     struct student stu[3]=
	 {
	 	{"jsdfioj",13,99},
	 	{"idofhaf",15,100}
	 };
	printf("�ṹ��������С��%d\n",sizeof(stu));
	printf("�ṹ���Ԫ�ش�С��%d\n",sizeof(stu[0]));
	printf("�ṹ��Ԫ�ظ�����%d\n",sizeof(stu)/sizeof(stu[0]));
	 
	 for(int i=0;i<3;i++)
	 {
	 	printf("���֣�%s\n",stu[i].name);
	 	printf("���䣺%d\n",stu[i].age);
	 	printf("������%d\n",stu[i].score);
	 }
	
	//����     Ӧ����stu[i] 
	
}


//typedef struct studnet1 ss;
//struct student1
//{
//    char name[100];
// } 
 
void test03()
{
	struct student *p=(struct student *)malloc(sizeof(struct student)*3);
//	//������typedef  �Խṹ����һ������
//	 ss *p=(ss *)malloc(sizeof(ss)*3);
    free(p);
    	
	
}

int main()
{
//	test01();     
//	test02();    //���� 
    test03();

	return 0;
 } 
