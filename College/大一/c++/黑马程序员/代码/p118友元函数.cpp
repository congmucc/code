#include<iostream> 

using namespace std;

#include<string> 

/*
��ԪĿ�ģ� ��һ����������һ���������һ�����е�˽�г�Ա

��Ԫ����ʵ�֣� 
1��ȫ�ֺ�������Ԫ
2��������Ԫ
3����Ա��������Ԫ 

https://blog.csdn.net/weixin_46098577/article/details/116596183
*/


class Building {
	//1����ȫ�ֺ��������Ԫ���� 
	friend void goodGay(Building *building);
	
	
	public : 
	    string m_SittingRoom;
	    Building() {
		    this->m_SittingRoom = "����";
			this->m_BedRoom = "����"; 
		}
	    
	private:
		string m_BedRoom;
}; 

//ȫ�ֺ���
void goodGay(Building *building) {
	cout << "�û���ȫ�ֺ��������ڷ��ʣ� " <<building->m_SittingRoom << endl;
	cout << "�û���ȫ�ֺ��������ڷ��ʣ� " <<building->m_BedRoom << endl;
}

void test01() {
	Building building;
	goodGay(&building);
}

int main() {
	test01();
	return 0;
}
