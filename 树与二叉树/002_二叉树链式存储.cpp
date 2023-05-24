#include<iostream>

using namespace std;

//���崢����������
struct ElemType {
    int value;
};

typedef struct BiTNode {
    ElemType data;//������
    struct BiTNode* lchild, * rchild;//���Һ���ָ��
} BiTNode, * BiTree;

//��ʼ��
void InitTree(BiTree root) {
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = { 1 };
    root->lchild = NULL;
    root->rchild = NULL;
}

//�����½��
bool InsertNode(BiTree T, ElemType val) {
    BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
    p->data = val;
    p->lchild = NULL;
    p->rchild = NULL;
    T->lchild = p;//��Ϊ����
}

//���ʺ���
void visit(BiTree T) {
    printf("%d", T->data.value);
}

//�������
void PreOder(BiTree T) {
    if (T != NULL) {
        visit(T);//���ʸ��ڵ�
        PreOder(T->lchild);//����������
        PreOder(T->rchild);//����������
    }
}

//�������
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);//����������
        visit(T);//���ʸ��ڵ�
        InOrder(T->rchild);//����������
    }
}

//�������
void PostOder(BiTree T) {
    if (T != NULL) {
        PostOder(T->lchild);
        PostOder(T->rchild);
        visit(T);
    }
}

//���ڲ�������ĸ�������
typedef struct LinkNode {
    BiTNode* data;//�����ָ����ǽ��
    struct LinkNode* next;
} LinkNode;

typedef struct {
    LinkNode* front, * rear;//��ͷ��β
} LinkQueue;

void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    //��ʼ��ʱ��front ��rear ��ָ��ͷ�ڵ�
    Q.front->next = NULL;
}

bool EnQueue(LinkQueue& Q, BiTNode* x) {
    //��������ʽ�洢һ�㲻��Ҫ�����������ڴ治��
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    if (s == NULL)return false;
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;//�½ڵ���뵽rear֮��
    Q.rear = s;//�޸ı�βָ��
    return true;
}

bool DeQueue(LinkQueue& Q, BiTNode* x) {
    if (Q.front == Q.rear)return false;//�ӿ�
    LinkNode* p = Q.front->next;//��ָ��p��¼��ͷԪ��
    x = p->data;//��x�������ض�ͷԪ��
    Q.front->next = p->next;//�޸�ͷ�ڵ��nextָ��
    if (Q.rear == p)//�˴������һ���ڵ����
        Q.rear = Q.front;//�޸�rearָ�룬˼��һ��Ϊʲô��
    free(p); //�ͷŽڵ�ռ�
    return true;
}

bool isEmpty(LinkQueue Q) {
    return Q.front == Q.rear ? true : false;
}

//�������
void levelOrder(BiTree T) {
    LinkQueue Q;//��������
    InitQueue(Q);//
    BiTree p;
    EnQueue(Q, T);
    while (!isEmpty(Q)) {
        DeQueue(Q, p);//��ͷ������
        visit(p);
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

//�ǵݹ�ʵ��
//˳��ջ�ṹ��
#define MaxSize 10 //����ջ��Ԫ�ص�������
typedef struct
{
    BiTree data[MaxSize];//��̬������ջ��Ԫ��
    int top;//ջ��ָ��
} SqStack;

//��ʼ��
void InitStack(SqStack& S)
{
    S.top = -1;//��ʼ��ջ��ָ�� ��Ϊ0.��ָ����һ�������λ��
}

//�п�
bool IsEmpty(SqStack S)
{
    if (S.top == -1) return true;//�п�
    else return false;
}

//��ջ
bool Push(SqStack& S, BiTree x)
{
    if (S.top == MaxSize - 1)//ջ��������
        return false;
    S.top = S.top + 1;//�ȼ�1
    S.data[S.top] = x;//��Ԫ����ջ �����еȼ���S.data[++S.top]=x;
    return true;
}

//��ջ
bool Pop(SqStack& S, BiTree& x)
{
    if (S.top == -1) return false;//ջ�գ�����
    x = S.data[S.top];//ջ��Ԫ���ȳ�ջ
    S.top = S.top - 1;//ָ���ټ�һ �����еȼ��� x=S.data[S.top--]
    return true;
}

//�������
void InOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);//��ʼ��ջ
    BiTree p = T;//pΪ����ָ��
    while (p || !IsEmpty(S))
    {
        if (p)
        {
            Push(S, p);//��ǰ�����ջ
            p = p->lchild;//���Ӳ��գ�һֱ������
        }
        else //��ջ����ת���ջ����������
        {
            Pop(S, p); visit(p);//ջ��Ԫ�س�ջ�����ʳ�ջ���
            p = p->rchild;//���������ߣ�p��ֵΪ��ǰ�����Һ���
        }//����whileѭ����������if-else���
    }
}

//�������
void PreOrder2(BiTree T)
{
    SqStack S;
    InitStack(S); BiTree p = T;//��ʼ��ջS��p�Ǳ���ָ��
    while (p || !IsEmpty(S)) //ջ���ջ�p����ʱѭ��
    {
        if (p) //һ·����
        {
            visit(p); Push(S, p);//���ʵ�ǰ��㣬����ջ
            p = p->lchild;//���Ӳ��գ�һֱ������
        }
        else //��ջ����ת���ջ����������
        {
            Pop(S, p);//ջ��Ԫ�س�ջ
            p = p->rchild;//���������ߣ�p��ֵΪ��ǰ�����Һ���
        } //����whileѭ����������if-else���
    }
}

//���������
int treeDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        //�������=Max����������ȣ���������ȣ�+1
        return l > r ? l + 1 : r + 1;
    }
}