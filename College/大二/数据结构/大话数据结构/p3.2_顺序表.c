#include<stdio.h> 

#define MAXSIZE 20


int i; //1 <= i <= ListLength(L)
 
typedef int ElemType;

typedef int Status;//0����0  0����1   

typedef struct{
	ElemType data[MAXSIZE];//����洢������Ԫ�أ����ֵΪmax 
	int length;//���Ա�ĵ�ǰ���� 
} SqList;



typedef struct Node{
	ElemType data;
	struct Node *next; 
} Node;

//����Ԫ�ص�λ��  �β�e 
Status GetElem(SqList L,ElemType *e){
    if(L.length == 0 || i < 1 || i > L.length){   
    	return 0; 
	}
	*e=L.data[i-1];
	return 1;
}

//����Ԫ��
Status ListInsert(SqList *L,int i,ElemType e){
	int k;
	if(L->length == MAXSIZE){   //˳�����Ա����� 
		return 0;
	}
	if(i<1 || i > L->length){   //i���ڷ�Χ�� 
		return 0;
	}
	if(i <= L.length){  //�������ݲ��ڱ��� 
		for(k = L->length-1;k >= i-1;k--){  //��i֮���Ԫ������ƶ�һλ 
			L->data[k+1]=L->data[k];
		} 
	}
	L->data[i-1]=e;
	L->length++;
	return 1; 
}


//ɾ��Ԫ��
Status ListDelete(SqList *L,int i,ElemType *e){
	int k;
	if(L->length == 0){  //����Ϊ�� 
		return 0;
	}
    if(i < 1||i > L->length){  //ɾ��λ�ò���ȷ 
    	return 0;
	}
	*e = L->data[i-1]; 
	if(i < L->length){  //���ɾ���Ĳ�������λ��
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
