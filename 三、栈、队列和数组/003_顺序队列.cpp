#include<iostream>

using namespace std;

#define MaxSize 10 //���������Ԫ�ص�������
typedef struct
{
	int data[MaxSize];//�þ�̬�����Ŷ���Ԫ�ء�
	int front, rear;//��ͷָ��Ͷ�βָ��
} SqQueue;

//��ʼ������
void InitQueue(SqQueue& Q)
{
	//��ʼ����ͷ��βָ��ָ��0
	Q.front = Q.rear = 0;//��βָ��ʼ��ָ����һ�������λ��
}

//�п�
bool QueueEmpty(SqQueue Q)
{
	if (Q.rear == Q.front) return true;
	else return false;
}

//ʵ����
void testQueue()
{
	SqQueue Q;
	InitQueue(Q);
}

//���
bool EnQueue(SqQueue& Q, int x)
{
	if ((Q.rear+1)%MaxSize==Q.front)//�ж϶���
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1)%MaxSize;//��βָ���1ȡģ����ѭ�����е���ʽ���д洢
}

//����
bool DeQueue(SqQueue& Q, int& x)
{
	if (Q.rear == Q.front)//�п�
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;//��ͷ����
	return true;
}

//��ȡ��ͷԪ��
bool GetHead(SqQueue& Q, int& x)
{
	if (Q.rear == Q.front)//�п�
		return false;
	x = Q.data[Q.front];
	return true;
}

int main()
{
	return 0;
}