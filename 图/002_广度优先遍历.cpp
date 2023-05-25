#include<iostream>

using namespace std;

#define MAX_VERTEX_NUM 100//������Ŀ�����ֵ

bool visited[MAX_VERTEX_NUM];//���ʱ������
void BFSTraverse(Graph G) //��ͼG���й�����ȱ���
{
	for (int i = 0; i < G.vexnum; ++i)
		visited[i] = false;//���ʱ�������ʼ��
	InitQueue(Q);//��ʼ����������Q
	for (int i = 0; i < G.vexnum; ++i)//��0�Ŷ��㿪ʼ����
	{
		if (!visited[i])//��ÿ����ͨ��������һ��BFS
			BFS(G, i);//viδ���ʹ�����vi��ʼBFS
	}
}

//������ȱ���
void BFS(Graph G, int v) //�Ӷ���v������������ȱ���ͼG
{
	visit(v);//���ʳ�ʼ����v
	visited[v] = true;//��v���ѷ��ʱ��
	Enqueue(Q, v);//����v�����Q
	while (!isEmpty(Q))
	{
		DeQueue(Q, v);//����v������
		for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
		{
			//���v�����ڽӵ�
			if (!visited[w])//wΪv����δ���ʵ��ڽӶ���
			{
				visit(w);//���ʶ���w
				visited[w] = true;//��w���ѷ��ʱ��
				EnQueue(Q, w);//����w�����
			}
		}
	}
}

//����Ǵ�Ȩͼ�ĵ�Դ���·������
void BFS_MIN_Distance(Graph G, int u)
{
	//d[i]��ʾ��u��i�������·��
	for (int i = 0; i < G.vexnum; ++i)
	{
		d[i] = 0x3f3f3f3f;//����󣬳�ʼ��·������
	}
	visited[u] = true;
	d[u] = 0;
	EnQueue(Q, u);
	while (!isEmpty(Q))//BFS�㷨������
	{
		DeQueue(Q, u);//��ͷԪ��u����
		for (w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
		{
			if (!visited[w])//wΪu����δ���ʵ��ڽӶ���
			{
				visited[w] = true;//���ѷ��ʱ��
				d[w] = d[u] + 1;//·�����ȼ�1
				EnQueue(Q, w);//����w���
			}
		}
	}
}


int main()
{
	return 0;
}