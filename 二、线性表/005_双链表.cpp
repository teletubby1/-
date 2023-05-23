//����ͷ�ڵ�汾����˫����

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;//������
    struct DNode* prior, * next;//ǰָ��ͺ�ָ��
} DNode, * DLinkList;

//��������
bool InitDLinkList(DLinkList& L);//��ʼ��
bool Empty(DLinkList L);//�п�
bool InsertNextElem(DNode* p, DNode* s);//ָ���ڵ�ĺ�����
bool DeleteNextNode(DNode* p);//ɾ��P�ڵ�ĺ�̽ڵ�
bool DestroyList(DLinkList& L);//����������
bool PrintNextElems(DNode* p);//��P��������
bool PrintPriorElems(DNode* p);//��P����ǰ����
bool PrintPriorElemsOverHead(DNode* p);//��P����ǰ����������ͷ�ڵ㣩

//��ʼ��
bool InitDLinkList(DLinkList& L) {
    L = (DNode*)malloc(sizeof(DNode));//����һ��ͷ�ڵ�
    if (L == NULL)
        return false;
    L->prior == NULL;//ͷ�ڵ�ǰ��ָ�붼ָ���
    L->next == NULL;
    return true;
}

//�п�
bool Empty(DLinkList L) {
    return (L->next == NULL);
}

//ָ���ڵ�ĺ�����
bool InsertNextElem(DNode* p, DNode* s) {
    s->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = s;//��ֹ����p����û�к�̽������
    }
    s->prior = p;
    p->next = s;
}

//ɾ��P�ڵ�ĺ�̽ڵ�
bool DeleteNextNode(DNode* p) {
    if (p == NULL)return false;//p�ڵ�Ϊ��
    DNode* q = p->next;
    if (q == NULL)return false;//P�ڵ�û�к��
    p->next = q->next;
    if (q->next != NULL)//q�������һ���ڵ�
        q->next->prior = p;
    free(q);//�ֶ��ͷ��ڴ�ռ�
    return true;
}

//����������
bool DestroyList(DLinkList& L) {
    //ѭ��ɾ�����ͷ�ÿ���ڵ�
    while (L->next != NULL)
        DeleteNextNode(L);
    free(L);//�ͷ�ͷ�ڵ�
    L = NULL;//ͷָ��ָ��NULL

}

//��P��������
bool PrintNextElems(DNode* p) {
    if (p == NULL)return false;//
    while (p != NULL) {
        printf("��ǰ�ڵ��ֵ��:%d", p->data);
        p = p->next;
    }
    return true;
}

//��P����ǰ����
bool PrintPriorElems(DNode* p) {
    if (p == NULL)return false;//
    while (p != NULL) {
        printf("��ǰ�ڵ��ֵ��:%d", p->data);
        p = p->prior;
    }
    return true;
}

//��P����ǰ����������ͷ�ڵ㣩
bool PrintPriorElemsOverHead(DNode* p) {
    if (p == NULL)return false;//
    while (p->prior != NULL) {
        printf("��ǰ�ڵ��ֵ��:%d", p->data);
        p = p->prior;
    }
    return true;
}
