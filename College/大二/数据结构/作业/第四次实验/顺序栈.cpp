#include<iostream> 

using namespace std;

const int MAXSIZE = 1e4;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int Status;


typedef struct {
	int data[MAXSIZE];
	int top;
} SqStack;

//��ӡԪ�� 
Status visit(int c) {
	cout << c << " ";
	return OK;
}

//��ʼ��ջ 
Status InitStack(SqStack *S) {
	S->top = -1;
	return OK;
}

//�ж�ջ�ĳ��� 
int StackLength(SqStack S) {
	return S.top + 1;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(SqStack S) { 
        if (S.top == -1)
                return TRUE;
        else
                return FALSE;
}

//�õ�ջ��Ԫ�� 
Status GetTop(SqStack S, int *e) {
	if (S.top == -1) return ERROR;
	else *e = S.data[S.top];
	return OK;
}

//����Ԫ��e��Ϊջ��Ԫ��
Status Push(SqStack *S, int e) {
	if (S->top == MAXSIZE - 1) {
		return ERROR;
	} 
	S->top++;
	S->data[S->top] = e;
	return OK;
} 

//ɾ��ջ��Ԫ��
Status Pop(SqStack *S) {
	if (S->top == -1) return ERROR;
	S->top--;
	return OK;
} 

//��ջ����ջ����ʾÿ��Ԫ��
Status StackTraverse(SqStack S) {
        int i;
        i=0;
        while (i <= S.top) {
                visit(S.data[i++]);
        }
        cout << endl;
        return OK;
}



int main() {
	SqStack s;
	if(InitStack(&s)==OK)
        for(int j = 0;j < 4;j++)
                Push(&s,j);
    cout << "��1��	����0123��ջ���ٳ�ջ����ӡ�����" << endl;
	cout << "���룺" <<endl;
	StackTraverse(s);
	int t = 0;
	cout << "��ջ��" << endl; 
	while (t <= s.top) {
		int e;
		GetTop(s, &e);
		Pop(&s);
		cout << e << " ";
	}
	cout << endl;
    
    cout << "��2��	��ջ��Ԫ�س�ջ�����ʣ��Ԫ�ز���ӡ����� " << endl; 
    if(InitStack(&s)==OK)
        for(int j = 0;j < 4;j++)
                Push(&s,j);
	Pop(&s);
    StackTraverse(s);
    
    cout << "��3��	�жϴ�ʱջ�Ƿ�Ϊ�գ�" <<endl;
    if (StackEmpty(s) == 1) cout << "��ջ" << endl;
    else cout << "��Ϊ��ջ" << endl;
	
	cout << "��4��	�жϴ�ʱջ�ĳ��ȣ�" <<endl;
	cout << StackLength(s) << endl;
	
	cout << "��5��	�жϴ�ʱջ��Ԫ�ش�С��" <<endl;
	int e;
	GetTop(s, &e);
	cout << e << endl;
    return 0; 
 } 
