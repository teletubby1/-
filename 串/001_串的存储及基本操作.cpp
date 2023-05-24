#include<iostream>

using namespace std;

//˳��洢
#define MAXLEN 255 //Ԥ������󴮳�Ϊ255
//��̬����
typedef struct {
	char ch[MAXLEN]; //ÿ�������洢һ���ַ�
	int length; //����ʵ�ʳ���
}SString;
//��̬����
typedef struct {
	char* ch; //����������洢����chָ�򴮵Ļ���ַ
	int length; //���ĳ���
}HString;
//��ʽ�洢
typedef struct StringNode {
	char ch; //ÿ������1���ַ�
	struct StringNode* next;
}StringNode,*String;
//ÿ���������ַ�
typedef struct StringNode2 {
	char ch[4]; //ÿ�������ĸ��ַ�
	struct StringNode2* next;
}StringNode2,*String2;

//���Ӵ�����Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
bool SubString(SString& Sub, SString S, int pos, int len)
{
	//�Ӵ���ΧԽ��
	if (pos + len - 1 > S.length) return false;
	for (int i = pos; i < pos + len; i++)
		Sub.ch[i - pos + 1] = S.ch[i];
	Sub.length = len;
	return true;
}

//�Ƚϲ���
int StrCompare(SString S, SString T)
{
	for (int i = 1; i <= S.length && i <= T.length; i++)
	{
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	//ɨ����������ַ�����ͬ���򳤶ȳ��Ĵ�����
	return S.length - T.length;
}


int main()
{
	HString S;
	S.ch = (char*)malloc(MAXLEN * sizeof(char));
	S.length = 0;
	return 0;
}
 