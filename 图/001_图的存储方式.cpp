#include<iostream>

using namespace std;

//�ڽӾ���
#define MaxVertexNum 100//������Ŀ�����ֵ
typedef struct
{
	char Vex[MaxVertexNum];//����� ���ɴ�����ӵ���Ϣ��
	int Edge[MaxVertexNum][MaxVertexNum];//�ڽӾ��󣬱߱�������bool�ͻ�ö���ͱ�����ʾ�ߣ�
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱ���/����
}MGraph;

//�ڽӱ�
typedef char VertexType;//�������������
//����/����
typedef struct ArcNode
{
	int adjvex;//��/��ָ���ĸ��ڵ�
	struct ArcNode* next;//ָ����һ������ָ��
	//InfoType info;//Ȩֵ
}ArcNode;
//�����㡱
typedef struct VNode
{
	VertexType data;//������Ϣ
	ArcNode* first;//��һ����/��
}VNode,AdjList[MaxVertexNum];
//���ڽӱ�洢��ͼ
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

int main()
{
	return 0;
}