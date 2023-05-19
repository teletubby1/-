#include<iostream>

using namespace std;

//˳��洢
#define MAXLEN 255 //Ԥ������󴮳�Ϊ255
//��̬����
typedef struct {
	char ch[MAXLEN]; //ÿ�������洢һ���ַ�
	int length; //����ʵ�ʳ���
}SString;

//����ģʽƥ���㷨
int Index(SString S, SString T)
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] = T.ch[j]) {
			++i; ++j; //�����ȽϺ���ַ�
		}
		else {
			i = i - j + 2;
			j = 1; //ָ��������¿�ʼƥ��
		}
	}
	if (j > T.length)
		return i - T.length;
	else return 0;
}

//KMP�㷨
int Index_KMP(SString S, SString T, int next[])
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			++i;
			++j; //�����ȽϺ���ַ�
		}
		else j = next[j];//ģʽ�������ƶ�������������
	}
	if (j > T.length)
		return i - T.length;//ƥ��ɹ�
	else
		return 0;
}

//��next����
void get_next(SString T, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;//��ʼ��
	while (i, T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i; ++j;
			next[i] = j;//��pi=pj,��next[j+1]=next[j]+1
		}
		else
			j = next[j];
	}
}

//�������nextval����
void get_nextval(SString T, int nextval[])
{
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i; ++j;
			if (T.ch[i] != T.ch[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}