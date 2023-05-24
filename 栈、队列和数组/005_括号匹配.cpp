//ջ��Ӧ�á�������ƥ������
#include<iostream>

using namespace std;

//����˳��ջ
# define  MaxSize 10
typedef struct {
    char data[MaxSize];
    int top;
} SqStack;

//��ʼ��
void InitStack(SqStack& S) {
    S.top = -1;//ջ��ָ��ʼ��ָ��ջ��Ԫ��
}

//��ջ
bool Push(SqStack& S, char t) {
    if (S.top == MaxSize - 1)return false;//ջ��
    S.data[++S.top] = t;
    return true;
}

//��ջ
bool Pop(SqStack& S, char& x) {
    if (S.top == -1)return false;//ջ�ձ���
    x = S.data[S.top--];
    return true;
}

//�п�
bool StackEmpty(SqStack S) {
    return S.top == -1;
}

//����ƥ��
bool bracketCheck(char* str, int length) {
    SqStack S;
    InitStack(S);//��ʼ��һ��ջ
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);//ɨ�赽�����ţ���ջ
        }
        else {
            if (StackEmpty(S))return false;//ɨ�赽�������ҵ�ǰջ�գ�ƥ��ʧ��
            char topElem;
            Pop(S, topElem);//ջ��Ԫ�س�ջ����ƥ��
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S);//�����ջ������ƥ��ɹ����ǿ�ƥ��ʧ��
}

int main() {
    return 0;
}