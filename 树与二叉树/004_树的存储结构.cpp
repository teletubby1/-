#include<iostream>

using namespace std;

//������˫�ױ�ʾ����˳��洢����
#define MAX_TREE_SIZE 100

typedef struct {
    int data; //����Ԫ��
    int parent;//˫��λ����
}PTNode;
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];//˫�ױ�ʾ
    int n;//�����
}PTree;

//���������ӱ�ʾ����˳��+��ʽ�洢��
struct CTNode {
    int child;//���ӽڵ��������е�λ��
    struct CTNode* next;//��һ������
};
typedef struct {
    int data; //����Ԫ�أ�����Ԫ�����Ͳ���
    struct CTNode* firstChild;//��һ������
}CTBox;
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];//˫�ױ�ʾ
    int n, r;//������͸���λ��
}CTree;

//�����������ֵܱ�ʾ������ʽ�洢��
typedef struct CSNode {
    int data; //�������������Ͳ���
    struct CSNode* firstChild, * nextsibiling;//��һ�����Ӻ����ֵ�ָ��
}CSNode, * CSTree;

int main()
{
	return 0;
}