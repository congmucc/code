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

//打印元素 
Status visit(int c) {
	cout << c << " ";
	return OK;
}

//初始化栈 
Status InitStack(SqStack *S) {
	S->top = -1;
	return OK;
}

//判断栈的长度 
int StackLength(SqStack S) {
	return S.top + 1;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S) { 
        if (S.top == -1)
                return TRUE;
        else
                return FALSE;
}

//得到栈顶元素 
Status GetTop(SqStack S, int *e) {
	if (S.top == -1) return ERROR;
	else *e = S.data[S.top];
	return OK;
}

//插入元素e作为栈顶元素
Status Push(SqStack *S, int e) {
	if (S->top == MAXSIZE - 1) {
		return ERROR;
	} 
	S->top++;
	S->data[S->top] = e;
	return OK;
} 

//删除栈顶元素
Status Pop(SqStack *S) {
	if (S->top == -1) return ERROR;
	S->top--;
	return OK;
} 

//从栈顶到栈底显示每个元素
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
    cout << "（1）	输入0123入栈后再出栈并打印输出；" << endl;
	cout << "输入：" <<endl;
	StackTraverse(s);
	int t = 0;
	cout << "出栈：" << endl; 
	while (t <= s.top) {
		int e;
		GetTop(s, &e);
		Pop(&s);
		cout << e << " ";
	}
	cout << endl;
    
    cout << "（2）	对栈顶元素出栈后输出剩余元素并打印输出； " << endl; 
    if(InitStack(&s)==OK)
        for(int j = 0;j < 4;j++)
                Push(&s,j);
	Pop(&s);
    StackTraverse(s);
    
    cout << "（3）	判断此时栈是否为空；" <<endl;
    if (StackEmpty(s) == 1) cout << "空栈" << endl;
    else cout << "不为空栈" << endl;
	
	cout << "（4）	判断此时栈的长度；" <<endl;
	cout << StackLength(s) << endl;
	
	cout << "（5）	判断此时栈顶元素大小。" <<endl;
	int e;
	GetTop(s, &e);
	cout << e << endl;
    return 0; 
 } 
