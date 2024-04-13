#include<stdio.h> 

#define MAXSIZE 20


int i; //1 <= i <= ListLength(L)
 
typedef int ElemType;

typedef int Status;//0代表0  0代表1   

typedef struct{
	ElemType data[MAXSIZE];//数组存储的数据元素，最大值为max 
	int length;//线性表的当前长度 
} SqList;



typedef struct Node{
	ElemType data;
	struct Node *next; 
} Node;

//查找元素的位置  形参e 
Status GetElem(SqList L,ElemType *e){
    if(L.length == 0 || i < 1 || i > L.length){   
    	return 0; 
	}
	*e=L.data[i-1];
	return 1;
}

//插入元素
Status ListInsert(SqList *L,int i,ElemType e){
	int k;
	if(L->length == MAXSIZE){   //顺序线性表已满 
		return 0;
	}
	if(i<1 || i > L->length){   //i不在范围内 
		return 0;
	}
	if(i <= L.length){  //插入数据不在表内 
		for(k = L->length-1;k >= i-1;k--){  //将i之后的元素向后移动一位 
			L->data[k+1]=L->data[k];
		} 
	}
	L->data[i-1]=e;
	L->length++;
	return 1; 
}


//删除元素
Status ListDelete(SqList *L,int i,ElemType *e){
	int k;
	if(L->length == 0){  //链表为空 
		return 0;
	}
    if(i < 1||i > L->length){  //删除位置不正确 
    	return 0;
	}
	*e = L->data[i-1]; 
	if(i < L->length){  //如果删除的不是最后的位置
        for(k = i;k<=L->length;k++){
        	L->data[k-1]=L->data[k];
		}
    }
	L->length--;
	return 1;
}




int main(){
	
	return 0;
 } 
