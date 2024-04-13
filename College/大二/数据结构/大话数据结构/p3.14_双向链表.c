#include<stdio.h>

typedef int ElemType;

typedef struct DulNode {
	ElemType data;
	struct DulNode *prior;    //ǰ��ָ�� 
	struct DulNode *next;     //����ָ�� 
	
} DulNode, *DulinkList;

//���� ��p�����֮��������ֻ��ʾ���Ĵ��� 
void DulNodeInsert(DulinkList p, ElemType e) {
	//���Ѿ�������ڴ���
	DulinkList s;
	s->data = e;
	s->prior = p;
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
}
//ɾ��  ͬ��  ��������ϵ���ĸ����Ӧ  �Ƕ�Ӧ����ʱ����ĸ  
void DulNodeDelete(DulinkList p) {
	DulinkList s;
	p->next = s->next;
	s->next->prior = p;
	free(s); 
}


int main() {
	
	return 0;
} 
