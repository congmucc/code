#include<stdio.h>

typedef int ElemType;

typedef struct DulNode {
	ElemType data;
	struct DulNode *prior;    //前驱指针 
	struct DulNode *next;     //后驱指针 
	
} DulNode, *DulinkList;

//插入 第p个结点之后，这里面只显示核心代码 
void DulNodeInsert(DulinkList p, ElemType e) {
	//设已经申请好内存了
	DulinkList s;
	s->data = e;
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
}
//删除  同上  这个和书上的字母不对应  是对应插入时的字母  
void DulNodeDelete(DulinkList p) {
	DulinkList s;
	p->next = s->next;
	s->next->prior = p;
	free(s); 
}


int main() {
	
	return 0;
} 
