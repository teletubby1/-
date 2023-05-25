#include<iostream>

using namespace std;

#define MaxVertexNum 100//ͼ�ж�����Ŀ�����ֵ

//�����ڽӱ�
typedef char VertexType;//�������������
//����/����
typedef struct ArcNode
{
	int adjvex;//��/��ָ���ĸ��ڵ�
	struct ArcNode* nextarc;//ָ����һ������ָ��
	//InfoType info;//Ȩֵ
}ArcNode;
//�����㡱
typedef struct VNode
{
	VertexType data;//������Ϣ
	ArcNode* firstarc;//��һ����/��
}VNode, AdjList[MaxVertexNum];
//���ڽӱ�洢��ͼ
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;


//��������
bool TopologicalSort(Graph G)
{
	InitStack(S);//��ʼ��ջ���洢���Ϊ0�Ľ��
	for (int i = 0; i < G.vexnum; i++)
	{
		if (indegree[i] == 0)
		{
			Push(S, i);//���������Ϊ0�Ķ����ջ
		}
	}
	int count = 0;//��������¼��ǰ�Ѿ�����Ķ�����
	while (!IsEmpty(S))//ջ���գ���������Ϊ0�Ķ���
	{
		Pop(S, i);//ջ��Ԫ�س�ջ
		print(count++) = i;//�������i
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			//������iָ��Ķ������ȼ�1�����ҽ����Ϊ0�Ķ���ѹ��ջS
			v = p->adjvex;
			if (!(--indegree[v]))//��Ϊ0
			{
				Push(S, v);//��ջ
			}
		}
	}
	if (count < G.vexnum)
	{
		return false;//����ʧ�ܣ�����ͼ���л�·
	}
	else
		return true;//��������ɹ�
}

//����������
void DFSTraverse(Graph G)//������ȱ���ͼG
{
	for (v = 0; v < G.vexnum; ++v)
		visited[v] = false;//��ʼ���ѷ��ʱ������
	for (v = 0; v < G.vexnum; ++v)//��v=0��ʼ����
		if (!visited[v])
			DFS(G, v);
}

void DFS(Graph G, int v)//�Ӷ���v������������ȱ���ͼG
{
	visit(v);//���ʶ���v
	visited[v] = true;//���ѷ��ʱ��
	for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
	{
		if (!visited[w])
		{
			DFS(G, w); // wΪv����δ���ʵ��ڽӶ���
		}
	}
	print(v);//�������
}

int main()
{
	return 0;
}