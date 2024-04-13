#include<iostream>
using namespace std;
class CPU
{
public:
	virtual void Calculate() = 0;
};

class VideoCard
{
public:
	virtual void Display() = 0;
};

class Memory
{
public:
	virtual void Storage() = 0;
};


class Computer
{
public:
	Computer(CPU * cpu,VideoCard * vc,Memory * mem)
	{
		m_cpu=cpu;
		m_vc=vc;
		m_mem=mem;
	}
	void work()
	{
		m_cpu->Calculate();
		
		m_vc->Display();
		
		m_mem->Storage();
	}
	~Computer()
	{
		
		if(m_cpu!=NULL)
		{
			delete m_cpu;
			m_cpu=NULL; 
			cout<<"m_cpu堆区内存释放"<<endl;
		}
		if(m_vc!=NULL)
		{
			delete m_vc;
			m_vc=NULL; 
		    cout<<"m_vc堆区内存释放"<<endl;
		}
		if(m_mem!=NULL)
		{
			delete m_mem;
			m_mem=NULL; 
		    cout<<"m_mem堆区内存释放"<<endl;
		}
	}
	
private:
	CPU * m_cpu;
	VideoCard * m_vc;
	Memory * m_mem;
};

class Intel : public CPU, public VideoCard,public Memory 
{
public:
	void Calculate()
	{
		cout<<"Intel的cpu开始计算"<<endl; 
	}
	void Display()
	{
		cout<<"Intel的显卡开始显示"<<endl;
	}
	void Storage()
	{
		cout<<"Intel的内存条开始存储"<<endl;
	}
	
};

class Lenovo : public CPU, public VideoCard,public Memory 
{
public:
	void Calculate()
	{
		cout<<"Intel的cpu开始计算"<<endl; 
	}
	void Display()
	{
		cout<<"Intel的显卡开始显示"<<endl;
	}
	void Storage()
	{
		cout<<"Intel的内存条开始存储"<<endl;
	}
};

void test01()
{
	CPU *intelcpu=new Intel;
	VideoCard *intelvc=new Intel;
	Memory *intelmem=new Intel;
	Computer *computer1=new Computer(intelcpu,intelvc,intelmem);
	computer1->work();
	delete computer1;
	
}

int main()
{
	test01();
	return 0;
} 
