#include<iostream>

using namespace std;

#define SIZE 10
int UFSets[SIZE];//����Ԫ������

//��ʼ��
void Initial(int S[])
{
	for (int i = 0; i < SIZE; i++)
		S[i] = -1;
}

//�飬�ҵ�x�������ϣ�����x�������ڵ㣩
int Find(int S[], int x)
{
	while (S[x] >= 0)
		x = S[x];
	return x;//���ڵ�S[]С��0
}

//���Ż���ѹ��·��
int Find2(int S[], int x)
{
	int root = x;
	while (S[root] >= 0) root = S[root];//ѭ���ҵ���
	while (x != root) //ѹ��·��
	{
		int t = S[x];//tָ��x�ĸ��ڵ�
		S[x] = root;//xֱ�ӹҵ����ڵ���
		x = t;
	}
	return root;
}

//�������������ϸ��ڵ㴫�룬�ϲ�Ϊһ��
void Union(int S[], int Root1, int Root2)
{
	//�ж�Ϊ��ͬ����
	if (Root1 == Root2) return;
	//����Root2���ӵ���һ��Root1����
	S[Root2] = Root1;
}

//���Ż�����С���ϲ����������ø��ڵ�ľ���ֵ��ʾ���Ľ������
void Union2(int S[], int Root1, int Root2)
{
	if (Root1 == Root2) return;
	if (S[Root2] > S[Root2]) //Root2���󣬾���ֵ��С���������С
	{
		S[Root1] += S[Root2];//�ۼӽ������
		S[Root2] = Root1;//С���ϲ�������
	}
	else
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
}
