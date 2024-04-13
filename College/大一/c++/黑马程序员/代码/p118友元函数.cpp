#include<iostream> 

using namespace std;

#include<string> 

/*
友元目的： 让一个函数或者一个类访问另一个类中的私有成员

友元三种实现： 
1，全局函数作友元
2，类作友元
3，成员函数作友元 

https://blog.csdn.net/weixin_46098577/article/details/116596183
*/


class Building {
	//1，将全局函数变成友元函数 
	friend void goodGay(Building *building);
	
	
	public : 
	    string m_SittingRoom;
	    Building() {
		    this->m_SittingRoom = "客厅";
			this->m_BedRoom = "卧室"; 
		}
	    
	private:
		string m_BedRoom;
}; 

//全局函数
void goodGay(Building *building) {
	cout << "好基友全局函数，正在访问： " <<building->m_SittingRoom << endl;
	cout << "好基友全局函数，正在访问： " <<building->m_BedRoom << endl;
}

void test01() {
	Building building;
	goodGay(&building);
}

int main() {
	test01();
	return 0;
}
