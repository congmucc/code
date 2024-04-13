#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;//������
    struct LNode *next;
}LNode,*LinkList;
//LNode*�ǽṹ��ָ�룬��LinkList��ȫ�ȼ۵�
//����3,4,5,6,7,9999
//ͷ�巨
void list_head_insert(LNode* &L)
{
    L= (LinkList)malloc(sizeof(LNode));//����ͷ���ռ䣬ͷָ��ָ��ͷ���
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LNode *s;//����ָ��������½��
    while(x!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;//s��nextָ��ԭ������ĵ�һ�����
        L->next=s;//ͷ����next��ָ���½��
        scanf("%d",&x);
    }
}
//β�巨�½�����
void list_tail_insert(LNode* &L)
{
    L= (LinkList)malloc(sizeof(LNode));//����ͷ���ռ䣬ͷָ��ָ��ͷ���
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LNode *s,*r=L;//s������ָ��������½�㣬rʼ��ָ������β��
    while(x!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));//Ϊ�½������ռ�
        s->data=x;
        r->next=s;//�½���β����nextָ��
        r=s;//rҪָ���µ�β��
        scanf("%d",&x);
    }
    r->next=NULL;//��β����nextΪNULL
}

void print_list(LinkList L)
{
    L=L->next;
    while(L!=NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}

//��λ�ò���
LinkList GetElem(LinkList L,int SearchPos)
{
	printf("getElem�еģ�%p\n", &(L->next)); 
    int j=0;
    if(SearchPos<0)
    {
        return NULL;
    }
    while(L&&j<SearchPos)
    {
        L=L->next;
        j++;
    }
    return L;
}
//��ֵ����
LinkList LocateElem(LinkList L,ElemType SearchVal)
{
    while(L)
    {
        if(L->data==SearchVal)//����ҵ���Ӧ��ֵ���ͷ����Ǹ����ĵ�ַ
        {
            return L;
        }
        L=L->next;
    }
    return NULL;
}

bool ListFrontInsert(LinkList L,int i,ElemType InsertVal)
{
    LinkList p= GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    LinkList q;
    q=(LinkList) malloc(sizeof(LNode));//Ϊ�½������ռ�
    q->data=InsertVal;
    q->next=p->next;
    p->next=q;
    return true;
}
bool listDelete(LinkList L,int i,ElemType &e)
{
	printf("listDelete�еģ�%p\n", &(L->next)); 
    LinkList p= GetElem(L,i-1);
    if(NULL==p)
    {
        return false;
    }
    
    LinkList q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    return true;
}

//ͷ�巨��β�巨���½�����
int main() {
    LinkList L,search;//L������ͷָ�룬�ǽṹ��ָ������
//    list_head_insert(L);//�������ݿ���Ϊ3 4 5 6 7 9999,ͷ�巨�½�����
    list_tail_insert(L);
    print_list(L);//�����ӡ
//    //��λ�ò���
//    search=GetElem(L,2);
//    if(search!=NULL)
//    {
//        printf("Succeeded in searching by serial number\n");
//        printf("%d\n",search->data);
//    }
//    search=LocateElem(L,6);//��ֵ��ѯ
//    if(search!=NULL)
//    {
//        printf("Search by value succeeded\n");
//        printf("%d\n",search->data);
//    }
//    bool ret;
//    ret=ListFrontInsert(L,8,99);//�½���i�Ľ���λ��
//    print_list(L);
    ElemType e;
    printf("������1�еģ�%p\n", &(L->next));
    listDelete(L,1,e);
    printf("������2�еģ�%p\n", &(L->next));
    print_list(L);
    printf("%d",e);
    return 0;
}
