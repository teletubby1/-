#include<iostream>

using namespace std;

#define MAX_VERTEX_NUM 100//������Ŀ�����ֵ

bool visited[MAX_VERTEX_NUM];//���ʱ������

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
}

int main()
{
	return 0;
}