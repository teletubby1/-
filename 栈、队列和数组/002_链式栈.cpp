//��ջ��ʵ��
#include <stdio.h>
#include <stdlib.h>

# define MaxSize 10
typedef struct LinkNode {
    int data;
    struct LinkNode* next;
} *LinkStack;

//��������
bool InitStack(LinkStack& LS);//��ʼ��
bool Push(LinkStack& LS, int t);//��ջ �ο�ͷ�巨����������
bool Pop(LinkStack& LS, int& x);//��ջ,����ӡ��ջ��Ԫ��
bool GetTop(LinkStack LS, int& x);//��ȡջ��Ԫ�أ�ջ

//��ʼ��
bool InitStack(LinkStack& LS) {
    LS = (LinkNode*)malloc(sizeof(LinkNode));//����һ��ͷ�ڵ�
    if (LS == NULL) {
        return false;
    }
    LS->next = NULL;
    return true;
}

//��ջ
bool Push(LinkStack& LS, int t) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    if (s == NULL)return false;
    s->data = t;
    s->next = LS->next;
    LS->next = s;
    return true;
}

//��ջ
bool Pop(LinkStack& LS, int& x) {
    //�ж�
    if (LS->next == NULL)return false;//ջ��,���������
    LinkNode* q;
    q = LS->next;
    LS->next = q->next;
    x = q->data;
    free(q);
    return true;
}

//��ȡջ��Ԫ��
bool GetTop(LinkStack LS, int& x) {
    if (LS == NULL)return false;
    x = LS->next->data;
    return true;
}
