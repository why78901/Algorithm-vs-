#include "AStar.h"



AStar::AStar()
{
}


AStar::~AStar()
{
}

//计算start到end的最短距离,其中graph[i][j]为i-j之间的距离,p[i]为第i个城市的坐标和名称
void AStar::AStarSearch(const vector<vector<float> >& graph, int start, int end, const vector<CPoint>& p)
{
	int N = (int)graph.size();
	int* type = new int[N];		//0:新点, 1:边点, 2:内点(openlist和closelist)
	float* f = new float[N];	//经过f[i]的start到end的估计值
	float* g = new float[N];	//从start到g[i]的精确值
	float* h = new float[N];	//从h[i]到end的估计值
	int* pre = new int[N];		//pre[i]:i的前驱
	
	//初始化
	int k;
	for (k = 0; k < N; k++)
	{
		g[k] = graph[start][k];					//到点距离
		h[k] = CPoint::Distance(p[k], p[end]);	//离点距离
		f[k] = g[k] + h[k];						//总距离
		pre[k] = -1;
		type[k] = 0;
	}

	//start加入边点集合
	type[start] = 1;
	g[start] = 0;
	f[start] = h[start];

	float d;
	int j = start;
	while (j != end)
	{
		//选择边点集合中f[i]最小的
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
		type[j] = 2; //边点变成内点
	}

	//恢复路径
	vector<int> path;
	path.push_back(end);
	while (pre[end] != -1)
	{
		end = pre[end];
		path.push_back(end);
	}
	reverse(path.begin(), path.end());

	//输出路径点
	float m = 0;
	for (k = 0; k < path.size(); k++)
	{
		cout <<  p[path[k]].cityName << '\n';
		if (k != 0)
			m += graph[path[k - 1]][path[k]];

	}
	cout << m << '\n';
}
