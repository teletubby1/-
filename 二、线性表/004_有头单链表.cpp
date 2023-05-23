//��ͷ�ڵ�ĵ�����

#include <stdio.h>
#include <stdlib.h>

//�ṹ��
typedef struct LNode {
    int data;
    LNode* next;
} LNode, * LinkList;

//��������
bool InitList(LinkList& L);     //��ʼ��
bool Empty(LinkList L);         //�п�
bool ListInsert(LinkList& L, int i, int e);//��λ����
bool InsertNextNode(LNode* p, int e);//ָ���ڵ�ĺ�����
bool InsertPriorNode(LNode* p, int e);//ָ���ڵ��ǰ�����������������ɺ�壬�ٽ���������ʵ��ǰ��
bool ListDelete(LinkList& L, int i, int& e);//��ָ��λ��ɾ���ڵ㲢������ֵ
bool DeleteNode(LNode* p);//ɾ��ָ���ڵ�

//���Ի�(����ͷ�ڵ�)
bool InitList(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));//����һ��ͷ�ڵ�
    if (L == NULL)
        return false;//ͷ�ڵ����ʧ�ܣ��������ڴ治��
    L->next = NULL;//ͷ�ڵ�֮����ʱû�нڵ㣬ͷ�ڵ�Ҳ���������
    return true;
}

//�п�
bool Empty(LinkList L) {
    //    if(L->next==NULL)
    //        return true;
    //    else
    //        return false;
    return (L->next == NULL);
}

//��λ����
bool ListInsert(LinkList& L, int i, int e) {
    if (i < 1)return false;//�ж�λ��i�Ƿ�Ϸ�
    LNode* p;//ָ��ָ��ǰɨ�浽�Ľڵ�
    int j = 0;//��¼pָ��Ľڵ��λ��
    p = L;//Lָ��ͷ�ڵ㣬��ͷ��ʼ
    while (p != NULL && j < i - 1) {
        //ѭ��ɨ��
        p = p->next;
        j++;
    }
    if (p == NULL) //iֵ�������������Ϸ�
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    //�����˳�򲻿ɽ���
    s->next = p->next;
    p->next = s; //�����s����p֮��
    return true;
}

//ָ���ڵ�ĺ�����
bool InsertNextNode(LNode* p, int e) {
    if (p == NULL)
        return false;//�ж�ָ���ڵ��Ƿ����
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)return false;//�����ڴ�ʧ��
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//ָ���ڵ��ǰ�����
//����ɺ�壬�ٽ���������ʵ��ǰ��
bool InsertPriorNode(LNode* p, int e) {
    if (p == NULL)return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//��ָ��λ��ɾ���ڵ㲢������ֵ
bool ListDelete(LinkList& L, int i, int& e) {
    if (i < 1)return false;
    LNode* p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    LNode* q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//ɾ��ָ���ڵ�
bool DeleteNode(LNode* p) {
    if (p == NULL)
    {
        return false;
    }
    LNode* q = p->next;//��qָ��*p�ĺ������
    p->data = p->next->data;//�ͺ�����㽻��������
    p->next = q->next;//��*q�������С��Ͽ���
    free(q);//�ͷź������Ĵ洢�ռ�
    return true;
}

//��ֵ����
LNode* LocateElem(LinkList L, int e)
{
    LNode* p = L->next;//�ӵ�1����㿪ʼ����������Ϊe�Ľ��
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;//�ҵ��󷵻ظý��ָ�룬���򷵻�NULL��
}

//��λ����
LNode* GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    LNode* p;//ָ��pָ��ǰɨ�赽�Ľ��
    int j = 0;//��ǰpָ����ǵڼ������
    p = L;//Lָ��ͷ��㣬ͷ����ǵ�0����㣨�������ݣ�
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//���
int Lnegth(LinkList L)
{
    int len = 0;//ͳ�Ʊ�
    LNode* p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//β�巨����������������������
LinkList List_TailInsert(LinkList& L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));//����ͷ���
    LNode* s, * r = L;//rΪ��βָ�룬����β��
    scanf("%d", &x);//�������ֵ
    while (x != 9999)//����9999��ʾ����
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;//rָ���µı�β��㣬��Զ����rָ�����һ����㣬�����ظ�����
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//ͷ�巨����������(���϶�ͷ������β�������
LinkList List_HeadInsert(LinkList& L)//������������
{
    LNode* s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));//����ͷ���
    L->next = NULL;//��ʼΪ������
    scanf("%d", &x);//�������ֵ
    while (x != 9999)//����9999��ʾ����
    {
        s = (LNode*)malloc(sizeof(LNode));//�����½��
        s->data = x;
        s->next = L->next;
        L->next = s;//���½�������У�LΪͷָ��
        scanf("%d", &x);
    }
    return L;
}

void PrintList(LinkList L) {
    //ѭ����ӡ��������
    LNode* p = L->next;//ɨ��ָ��
    int j = 0;
    if (p == NULL)printf("����һ���ձ�\n");
    while (p != NULL) {
        printf("LinkList[%d]=%d\n", j, p->data);
        p = p->next;
        j++;
    }
}
