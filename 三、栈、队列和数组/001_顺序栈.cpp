#include<iostream>

using namespace std;

//�ṹ��
#define MaxSize 10 //����ջ��Ԫ�ص�������
typedef struct
{
	int data[MaxSize];//��̬������ջ��Ԫ��
	int top;//ջ��ָ��
} SqStack;

//����ջ
typedef struct
{
	int data[MaxSize]; //��̬������ջ��Ԫ��
	int top0; //0��ջջ��ָ��
	int top1; //1��ջջ��ָ��
} ShStack;

//��ʼ������ջ
void InitStack(ShStack& S)
{
	S.top0 = -1;
	S.top1 = MaxSize; 
	//ջ������Ϊtop0+1==top1
}

//��ʼ��
void InitStack(SqStack& S)
{
	S.top = -1;//��ʼ��ջ��ָ�� ��Ϊ0.��ָ����һ�������λ��
}

//�п�
bool StackEmpty(SqStack S)
{
	if (S.top == -1) return true;//�п�
	else return false;
}

//��ջ
bool Push(SqStack& S, int x)
{
	if (S.top == MaxSize - 1)//ջ��������
		return false;
	S.top = S.top + 1;//�ȼ�1
	S.data[S.top] = x;//��Ԫ����ջ �����еȼ���S.data[++S.top]=x;
	return true;
}

//��ջ
bool Pop(SqStack& S, int& x)
{
	if (S.top == -1) return false;//ջ�գ�����
	x = S.data[S.top];//ջ��Ԫ���ȳ�ջ
	S.top = S.top - 1;//ָ���ټ�һ �����еȼ��� x=S.data[S.top--]
	return true;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack& S, int& x)
{
	if (S.top == -1) return false;//ջ�գ�����
	x = S.data[S.top];//ջ��Ԫ�س�ջ
	return true;
}

//ʹ��
void testStack()
{
	SqStack S;//����һ��˳��ջ������ռ䣩
}
