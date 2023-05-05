//˳�������̬�����ʵ�ַ�ʽ

#include <stdio.h>
#include <stdlib.h>


#define InitSize 100
typedef struct {
    int* data; //ָʾ��̬���������ָ��
    int MaxSize;//˳�����������
    int length;//˳���ǰ�ĳ���
} SeqList;

//��������
bool InitList(SeqList& L);                  //��ʼ��
bool Empty(SeqList L);                      //�п�
bool Full(SeqList L);                       //����
void IncreaseSize(SeqList& L, int len);     //��̬��չ�ռ�
bool ListInsert(SeqList& L, int i, int e);    //����
int GetElem(SeqList L, int i);               //��λ����
int LocateElem(SeqList L, int e);            //��ֵ����
bool ListDelete(SeqList& L, int i, int& e); //ɾ��
void DestroySqList(SeqList& L);             //����


//��ʼ��
bool InitList(SeqList& L) {
    //�� malloc ��������һƬ�����Ĵ洢�ռ�
    L.data = (int*)malloc(InitSize * sizeof(int));
    if (L.data == NULL)
        return false;
    //(int *) ��ָ���ǿ������ת��
    L.length = 0;
    L.MaxSize = InitSize;
    return true;
}

//�п�
bool Empty(SeqList L) {
    return (L.length == 0);
}

//����
bool Full(SeqList L) {
    return (L.length >= L.MaxSize);
}

//��չ�ռ�
void IncreaseSize(SeqList& L, int len) {
    int* p = L.data;
    L.data = (int*)malloc((InitSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
    //malloc �������������ڴ�ռ䣻free ���������ͷ��ڴ�ռ䣻
}

//����
bool ListInsert(SeqList& L, int i, int e) {
    //�жϲ����λ���Ƿ�Ϸ���
    if (i < 1 || i > L.length + 1)
        return false;
    //�жϱ��Ƿ������
//    if (L.length>=L.MaxSize)
//        return fals;
    if (Full(L))
        return false;

    //�����Ԫ�غ���
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}


//��λ����
int GetElem(SeqList L, int i) {
    //�ж��Ƿ�Խ��
    if (i < 0 || i > L.length)
        return -1;
    return L.data[i - 1];
}

//��ֵ����
int LocateElem(SeqList L, int e) {
    //ѭ��������
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            return i + 1; //����λ��
    }
    return -1;
}

//ɾ��
bool ListDelete(SeqList& L, int i, int& e) {
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
//���ڶ�̬���䷽ʽʹ��malloc������ڴ�ռ䣬����Ҫʹ��free�����ֶ��ͷſռ䣡
void DestroySqList(SeqList& L) {
    free(L.data);
    L.data = NULL;
    L.length = 0;
}

//��ӡ����˳���
void PrintSqList(SeqList L) {
    if (L.data == NULL || L.length == 0)
        printf("����һ���ձ�");
    else {
        //ѭ����ӡ
        printf("��ʼ��ӡ˳���\n");
        for (int i = 0; i < L.length; i++) {
            printf("Data[%d]==%d\n", i, L.data[i]);
        }
        printf("��ӡ������\n");
    }
}