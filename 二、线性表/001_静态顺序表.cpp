//˳�������̬�����ʵ�ַ�ʽ

#include <stdio.h>

#define MaxSize 50

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//��������
void InitList(SqList& L);                           //��ʼ��
bool Empty(SqList L);                               //�п�
bool ListInsert(SqList& L, int i, int e);           //����
bool ListDelete(SqList& L, int i, int& e);          //ɾ��
int GetElem(SqList L, int i);                       //��λ����
int LocateElem(SqList L, int e);                    //��ֵ����
bool LocateChangeElem(SqList& L, int e, int em);    //��ֵ�޸�
bool getChangeElem(SqList& L, int i, int em);       //��λ�޸�

void PrintSqList(SqList L);                         //��ӡ����
void testModule();                                  //����ģ��

//��ʼ��
void InitList(SqList& L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0;//������Ԫ�صĳ�ʼֵĬ������Ϊ0
        //��һ����ʵ����ʡ�ԣ�����ʡ��֮���п����ܵ��ڴ���"������"��Ӱ��
    }
    L.length = 0;

}

//�ж��Ƿ�Ϊ��
bool Empty(SqList L) {
    return (L.length == 0);
}

//����
bool ListInsert(SqList& L, int i, int e) {
    //�жϲ����λ���Ƿ�Ϸ���
    if (i < 1 || i > L.length + 1)
        return false;
    //�жϱ��Ƿ������
    if (L.length >= MaxSize)
        return false;

    //�����Ԫ�غ���
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//ɾ��
bool ListDelete(SqList& L, int i, int& e) {
    //�ж�i��λ���Ƿ�Ϸ�
    if (i < 0 || i > L.length) {
        return false;
    }
    //ȡ����Ҫ��ɾ������
    e = L.data[i - 1];
    //����������ǰ��
    for (int j = i; j <= L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    //���Ա��ȼ�һ
    L.length--;
    return true;
}

//����
//��λ����
int GetElem(SqList L, int i) {
    //�ж��Ƿ�Խ��
    if (i < 0 || i > L.length)
        return -1;
    return L.data[i - 1];
}

//��ֵ����
int LocateElem(SqList L, int e) {
    //ѭ��������
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1; //����λ��
    }
    return -1;
}

//�Ȳ��Һ��ֵ
//�ɴ˷�Ϊ���ַ�ʽ���Ȱ�λ���Һ��ֵ�����Ȱ�ֵ���Һ��ֵ
//�Ȱ�ֵ���Һ��ֵ
bool LocateChangeElem(SqList& L, int e, int em) {
    //��ֵ���ҵõ�λ��
    int bitOrder = LocateElem(L, e);
    //��ֵ
    if (bitOrder != -1) {
        L.data[bitOrder] = em;
        return true;
    }
    else {
        return false;
    }
}

//�Ȱ�λ����Һ��ֵ
bool getChangeElem(SqList& L, int i, int em) {
    //����λ��,�����ж�i�Ƿ�Ϸ�
    if (i < 0 || i >= L.length)return false;

    //������������ʵ�ֵķ�ʽ������ֱ������i����
    L.data[i] = em;
    return true;

}

//��ӡ����˳���
void PrintSqList(SqList L) {
    //ѭ����ӡ
    printf("��ʼ��ӡ˳���\n");
    for (int i = 0; i < L.length; i++) {
        printf("Data[%d]==%d\n", i, L.data[i]);
    }
    printf("��ӡ������\n");
}