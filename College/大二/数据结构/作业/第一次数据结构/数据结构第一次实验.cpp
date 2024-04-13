#include<iostream>
#include<stdio.h>

#include <windows.h>
using namespace std;


void test1()
{
    
 
    
}

typedef struct Node{
	int data;
	struct Node*next;
} linkList;

void test01(int N) {
	cout << "ѭ������" << endl; 
	for (int i = 1; i <= N; i++) {
		cout << i << " ";
	}
	cout << endl;
} 

void test02(int N, int t) {
	if (t > N) return;
	cout << t << " ";
	test02(N, t + 1);
}

linkList* createlinkList(int n) {
	linkList *head = new Node;
	head->data = 0;
	head->next = NULL;
	linkList *r = new Node;
	r = head;
	for (int i = 1; i <= n; i++) {
		linkList *p = new Node;
		p->data = i;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return head;
}


void test03(int N) {
	cout << "�������" << endl; 
	linkList *head = createlinkList(N);
	linkList *p = new Node;
	p = head->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	} 
	delete p;
	delete head;
}

int main() {
    DWORD star_time, end_time;
    
	int N;
	cin >> N;
	star_time = GetTickCount();
	//ѭ�� 
	test01(N);
	end_time = GetTickCount();
	auto t1 = (end_time - star_time);
    
	
	star_time = GetTickCount();
	cout << "�ݹ����" << endl; 
	//�ݹ� 
	test02(N, 1);
	cout << endl;
	end_time = GetTickCount();
	auto t2 = (end_time - star_time);
    
    
    star_time = GetTickCount();
	//���� 
	test03(N);
	cout << endl;
	end_time = GetTickCount();
	auto t3 = (end_time - star_time);
	cout << "ѭ������ʱ��Ϊ��" << t1 << "ms." << endl;
	cout << "�ݹ�����ʱ��Ϊ��" << t2 << "ms." << endl;
    cout << "��������ʱ��Ϊ��" << t3 << "ms." << endl;
	
	
	return 0;
} 
