#include<iostream> 

using namespace std;

#include<vector>

#include<algorithm>
/*
Vector����̬���飬����ʱ������Ҫ�ı������С��
��������ʽ�洢���ڴ�ռ��������ģ����������ڳ���ʱ������ɡ�
�������м���в����ɾ��������������ڴ��Ŀ�����



*/


void print(vector<int> test02) {
	for (int i = 0; i < test02.size(); i++) {
		cout << test02[i] << " ";
	}
	cout<<endl;
}


void test01() {
	
//	vector<string> string_S(10, "null");//Ĭ�ϳ�ʼ��
//    for (int i = 0; i < string_S.size(); i++) {
//    	cout << string_S[i] << " ";
//	}
	vector<int> test02(10);
	for (int i = 0; i < test02.size(); i++) {
		test02[i] = i;
	}
	
	print(test02);
//	
//	//�ڵ�i��Ԫ��ǰ�����k
//	test02.insert(test02.begin() + 2, 5);
//	
//	print(test02);
//	
//	test02.pop_back();
//	
//	print(test02);

//	test02.erase(test02.begin() + 3, test02.begin() + 5);
//	print(test02);
	
//	//v.begin()���ص����������������ָ�������е�һ������
//    //v.end()���ص����������������ָ������Ԫ�ص����һ��Ԫ�ص���һ��λ��
//	cout << "test02.begin() = \t" << *test02.begin() <<endl;
//	cout << "test02.end() = \t" << *test02.end() <<endl;
    
//  test02.erase(test02.begin() + 3);    
//	print(test02);
    
//  test02.resize(5);
//  print(test02);
      
//	reverse(test02.begin(), test02.end());
//	print(test02);  
//    
//    sort(test02.begin(), test02.end());
//	print(test02); 
	    
}


int main() {
	test01();
	return 0;
} 
