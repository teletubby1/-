#include<iostream>

using namespace std;

struct ElemType {
    int value;
};

typedef struct ThreadNode {
    ElemType data;//������
    struct ThreadNode* lchild, * rchild;//���Һ���ָ��
    int ltag, rtag;//����������־
} ThreadNode, * ThreadTree;

ThreadNode* pre = NULL;//ȫ�ֱ��������ݴ浱ǰ���ʽ���ǰ��

void visit(ThreadNode* q) {
    if (q->lchild == NULL) {//������Ϊ�գ�����ǰ������
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {//����ǰ�����ĺ������
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

//���������������һ�߱���һ��������
void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

//��������������������T
void CreatInThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {//�ǿն���������������
        InThread(T);//��������������
        if (pre->rchild == NULL) {
            pre->rtag = 1;//���������������һ�����
        }
    }
}

//�����������������̲İ棩
void InThread_CSKaoYan(ThreadTree p, ThreadTree& pre) {
    if (p != NULL) {
        InThread_CSKaoYan(p->lchild, pre);//�ݹ飬������������
        if (p->lchild == NULL) {//������Ϊ�գ�����ǰ������
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild == p;//����ǰ�����ĺ�����
            pre->rtag = 1;
        }
        pre = p;
        InThread_CSKaoYan(p->rchild, pre);
    }
}

//�����������������������̲İ汾��
void CreatInThread_CSKaoYan(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        InThread_CSKaoYan(T, pre);
        pre->rchild = NULL;//˼����Ϊʲô�������һ�����ʱû���ж�rchild �Ƿ�ΪNULL��
        pre->rtag = 1;//����Ϊ���һ�������Һ��ӱ�Ϊ�ա�
    }
}

//������������һ�߱���һ��������
void PreThread(ThreadTree T) {
    if (T != NULL) {
        visit(T);
        if (0 == T->ltag) {//lchild����ǰ������
            PreThread(T->lchild);
        }
        PreThread(T->rchild);
    }
}

//��������������������T
void CreatPreThread(ThreadTree T) {
    pre == NULL;
    if (T != NULL) {
        PreThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1;//������������һ�����
        }
    }
}

//�����������������̳̰汾��
void PreThread_CSKaoYan(ThreadTree p, ThreadTree& pre) {
    if (p != NULL) {
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild == p;//����ǰ�����ĺ�����
            pre->rtag = 1;
        }
        pre = p;
        if (0 == p->ltag) {
            PreThread_CSKaoYan(p->lchild, pre);
        }
        PreThread_CSKaoYan(p->rchild, pre);
    }
}

//�����������������������̲İ汾��
void CreatPreThread_CSKaoYan(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        PreThread_CSKaoYan(T, pre);
        if (pre->rchild = NULL)//������������һ�����
            pre->rtag = 1;
    }
}

//��������������
void PostThread(ThreadTree T) {
    if (T != NULL) {
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
}

//������������������T
void CreatPostThread(ThreadTree T) {
    pre == NULL;
    if (T != NULL) {
        PostThread(T);
        if (pre->rchild == NULL) {
            pre->rtag = 1;//������������һ�����
        }
    }
}

//�����������������̳̰汾��
void PostThread_CSKaoYan(ThreadTree p, ThreadTree& pre) {
    if (p != NULL) {
        PostThread_CSKaoYan(p->lchild, pre);
        PostThread_CSKaoYan(p->rchild, pre);
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild == p;//����ǰ�����ĺ�����
            pre->rtag = 1;
        }
        pre = p;
    }
}
//�����������������������̲İ汾��
void CreatPostThread_CSKaoYan(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) {
        PostThread_CSKaoYan(T, pre);
        if (pre->rchild = NULL)//������������һ�����
            pre->rtag = 1;
    }
}

//����������������������
//�ҵ���PΪ���������У���һ������������Ľ��
ThreadNode* FirstNode(ThreadNode* p) {
    //ѭ���ҵ������½�㣨��һ����Ҷ��㣩
    while (0 == p->ltag) {
        p = p->lchild;
    }
    return p;
}

//�������������������ҵ����p�ĺ�̽��
ThreadNode* NextNode(ThreadNode* p) {
    //���������������½��
    if (0 == p->rtag)return FirstNode(p->rchild);
    else return p->rchild;
}

//�������������������������������������ʵ�ֵķǵݹ��㷨�����ռ临�Ӷ�ΪO(1)��
void InOrder(ThreadNode* T) {
    for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p)) {
        visit(p);
    }
}

//��������������������ǰ��
//�ҵ���pΪ���������У����һ������������Ľ��
ThreadNode* LastNode(ThreadNode* p) {
    //ѭ���ҵ������½�㣨��һ����Ҷ��㣩
    while (0 == p->rtag)p = p->rchild;
    return p;
}

//�������������������ҵ����p��ǰ�����
ThreadNode* PreNode(ThreadNode* p) {
    //�������������ҽ��
    if (0 == p->ltag)return LastNode(p->lchild);
    else return p->lchild;
}

//�������������������������������
void RevInOrder(ThreadNode* T) {
    for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p)) {
        visit(p);
    }
}