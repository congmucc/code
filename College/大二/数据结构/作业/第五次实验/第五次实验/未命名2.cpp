#include<iostream>

using namespace std;

#include<stack>
#include<queue>
#include<algorithm>

//˼��1 ��ջת�� 
void test01() {
	stack<int> s1;
	stack<int> s2;
	cout << "��ջת��" <<endl; 
	cout << "���� 1 2 3 4 5" << endl; 
	for (int i = 1; i <= 5; i++) { 
	    s1.push(i);
    }
    for (int i = 1; i <= 5; i++) { 
	    s2.push(s1.top());
	    s1.pop();
	    //������while��empty()����Ƿ�Ϊ�գ�Ȼ�����s1�����ݴ���s2 
    }
    
    cout << "��ӡ���ݣ�" <<endl; 
    for (int i = 1; i <= 5; i++) { 
	    if (s2.empty()) break;
		cout << s2.top() << endl;
		s2.pop(); 
    }
} 

void test02() {
    queue<int> q1;
    queue<int> q2;
	
	cout << "���� 1 2 3 4 5" << endl; 
	for (int i = 1; i <= 5; i++) { 
	    q1.push(i);
    }
    
    
    while(q1.size()) {
    	if (q1.size() == 1) {
    		cout << q1.front() << endl;
    	    q1.pop();
    	    while(q2.size()) { 
    	    	if (q2.size() == 1) {
    	    	    cout << q2.front() << endl;
					q2.pop();
					break;	
    	    	} 
    	    	q1.push(q2.front());
    	    	q2.pop();
    	    }
		}
		q2.push(q1.front());
		q1.pop();
    }
    //������仰���ᵼ��q2�е������в��࣬��������һ������ 
    if (!q2.empty()) {
    	cout<< q2.front() << endl;
	}
} 

int main() {
	test01();
    test02();	
}
