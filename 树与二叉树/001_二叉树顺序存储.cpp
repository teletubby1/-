#include <iostream>

using namespace std;

#define MaxSize 100

struct TreeNode {
    int value;//����е�����Ԫ��
    bool isEmpty;//�жϽ���Ƿ�Ϊ��
};

int main()
{
    TreeNode t[MaxSize];//����һ������ΪMaxSize������t�����մ������£��������ҵ�˳�����δ洢�������еĸ������

    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;//��ʼ��ʱ���н����Ϊ��
    }
}