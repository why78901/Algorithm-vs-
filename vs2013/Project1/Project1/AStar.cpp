#include "AStar.h"



AStar::AStar()
{
}


AStar::~AStar()
{
}

//����start��end����̾���,����graph[i][j]Ϊi-j֮��ľ���,p[i]Ϊ��i�����е����������
void AStar::AStarSearch(const vector<vector<float> >& graph, int start, int end, const vector<CPoint>& p)
{
	int N = (int)graph.size();
	int* type = new int[N];		//0:�µ�, 1:�ߵ�, 2:�ڵ�(openlist��closelist)
	float* f = new float[N];	//����f[i]��start��end�Ĺ���ֵ
	float* g = new float[N];	//��start��g[i]�ľ�ȷֵ
	float* h = new float[N];	//��h[i]��end�Ĺ���ֵ
	int* pre = new int[N];		//pre[i]:i��ǰ��
	
	//��ʼ��
	int k;
	for (k = 0; k < N; k++)
	{
		g[k] = graph[start][k];					//�������
		h[k] = CPoint::Distance(p[k], p[end]);	//������
		f[k] = g[k] + h[k];						//�ܾ���
		pre[k] = -1;
		type[k] = 0;
	}

	//start����ߵ㼯��
	type[start] = 1;
	g[start] = 0;
	f[start] = h[start];

	float d;
	int j = start;
	while (j != end)
	{
		//ѡ��ߵ㼯����f[i]��С��
		j = -1;
		for (k = 0; k < N; k++)
		{
			if (type[k] != 1)
				continue;
			if ((j == -1) || (d > f[k]))
			{
				d = f[k];
				j = k;
			}
		}

		for (k = 0; k < N; k++)
		{
			if (graph[j][k] >= INFINITY)
				continue;
			if (type[k] == 0)
			{
				if (g[k] > g[j] + graph[j][k])
				{
					g[k] = g[j] + graph[j][k];
					f[k] = g[k] + h[k];
				}
				type[k] = 1;
				pre[k] = j;
			}
			else if(type[k] == 2)
			{
				if (g[k] > g[j] + graph[j][k])
				{
					g[k] = g[j] + graph[j][k];
					f[k] = g[k] + h[k];
					type[k] = 1;
					pre[k] = j;
				}
			}
			else if(type[k] == 1)
			{
				if (g[k] > g[j] + graph[j][k])
				{
					g[k] = g[j] + graph[j][k];
					f[k] = g[k] + h[k];
					pre[k] = j;
				}
			}
		}
		type[j] = 2; //�ߵ����ڵ�
	}

	//�ָ�·��
	vector<int> path;
	path.push_back(end);
	while (pre[end] != -1)
	{
		end = pre[end];
		path.push_back(end);
	}
	reverse(path.begin(), path.end());

	//���·����
	float m = 0;
	for (k = 0; k < path.size(); k++)
	{
		cout <<  p[path[k]].cityName << '\n';
		if (k != 0)
			m += graph[path[k - 1]][path[k]];

	}
	cout << m << '\n';
}
