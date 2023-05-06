#include<iostream>

using namespace std;

//�ṹ��
typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct
{
	LinkNode* front, * rear;//��ͷ��βָ��
}LinkQueue;

//��ʼ��
void InitQueue(LinkQueue& Q)
{
	//��ʼʱ front��rear��ָ��ͷ���
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//�п�
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else return false;
}

//���
void EnQueue(LinkQueue& Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;//�½ڵ���뵽rear����
	Q.rear = s;//�޸ı�βָ��
}

//����
bool DeQueue(LinkQueue& Q, int& x)
{
	if (Q.front == Q.rear) return false;//�п�
	LinkNode* p = Q.front->next;
	x = p->data;//�ñ���x���ض�ͷԪ��
	Q.front->next = p->next;//�޸�ͷ����nextָ��
	if (Q.rear == p)//�˴������һ��������
		Q.rear = Q.front;//�޸�rearָ��
	free(p);//�ͷŽ��ռ�
	return true;
}

//ʵ����
void testLinkQueue()
{
	LinkQueue Q;//����һ������
	InitQueue(Q);//��ʼ������
}

//����ͷ���汾
//��ʼ��������ͷ��㣩
void InitQueue2(LinkQueue& Q)
{
	//��ʼʱ��front��rear��ָ��NULL
	Q.front = NULL;
	Q.rear = NULL;
}
//�пգ�����ͷ��㣩
bool IsEmpty2(LinkQueue Q)
{
	if (Q.front == NULL) return true;
	else return false;
}
//��ӣ�����ͷ��㣩
void EnQueue2(LinkQueue& Q, int x)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL)//�ڿ������в����һ��Ԫ��
	{
		Q.front = s;
		Q.rear = s;
	}
	else
	{
		Q.rear->next = s;
		Q.rear = s;
	}
}
//���ӣ�����ͷ��㣩
bool DeQueue2(LinkQueue& Q, int& x)
{
	if (Q.front == NULL) return false;
	LinkNode* p = Q.front;//pָ��˴γ��ӵĽ��
	x = p->data;//�ñ���x���ض�ͷԪ��
	Q.front = p->next;//�޸�frontָ��
	if (Q.rear == p)//�˴������һ��������
	{
		Q.front = NULL;
		Q.rear = NULL;
	}
	free(p);//�ͷŽ��
}


int main()
{
	return 0;
}