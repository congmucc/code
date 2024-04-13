#include<iostream> 

using namespace std;

#include<vector>

#include<algorithm>
/*
Vector：动态数组，运行时根据需要改变数组大小。
以数组形式存储，内存空间是连续的，索引可以在常数时间内完成。
但是在中间进行插入和删除操作，会造成内存块的拷贝。



*/


void print(vector<int> test02) {
	for (int i = 0; i < test02.size(); i++) {
		cout << test02[i] << " ";
	}
	cout<<endl;
}


void test01() {
	
//	vector<string> string_S(10, "null");//默认初始化
//    for (int i = 0; i < string_S.size(); i++) {
//    	cout << string_S[i] << " ";
//	}
	vector<int> test02(10);
	for (int i = 0; i < test02.size(); i++) {
		test02[i] = i;
	}
	
	print(test02);
//	
//	//在第i个元素前面插入k
//	test02.insert(test02.begin() + 2, 5);
//	
//	print(test02);
//	
//	test02.pop_back();
//	
//	print(test02);

//	test02.erase(test02.begin() + 3, test02.begin() + 5);
//	print(test02);
	
//	//v.begin()返回迭代器，这个迭代器指向容器中第一个数据
//    //v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
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
