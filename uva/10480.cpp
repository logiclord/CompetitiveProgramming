#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<functional>
#include<ctime>
#include<string>
#include<climits>
#include<cmath>
#include<stack>
#include<vector>
#include<cassert>
#define EPS 1e-9
#define INF 2000000000;
#define NN 51
using namespace std;

int bpsMaxFlow(int s, int t, int Cap[NN][NN], int flow[NN][NN], vector<vector<int> >&graph, int parent[NN], int n)
{
	int minMaxFlow[NN];
	for(int i=0; i<=n; i++)
		parent[i] = -1;

	queue<int> qu;
	qu.push(s);
	parent[s] = -2;
	minMaxFlow[s] = INF;

	while(!qu.empty())
	{
		int cur = qu.front();
		qu.pop();
		for(vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
		{
			if(parent[*it] == -1 && Cap[cur][*it] - flow[cur][*it] > 0)
			{
				parent[*it] = cur;
				qu.push(*it);
				minMaxFlow[*it] = min(minMaxFlow[cur], Cap[cur][*it] - flow[cur][*it]);
				if(*it == t)
					return minMaxFlow[t];
			}
		}
	}
	return 0;
}

int edmondKarp(int s, int t, int Cap[NN][NN], int flow[NN][NN], vector<vector<int> >&graph)
{
	int maxFlow = 0;
	int currentflow = 0;
	int parent[NN];
	int n= graph.size()-1;
	do
	{
		currentflow = bpsMaxFlow(s, t, Cap, flow, graph, parent, n);
		if(currentflow > 0)
		{
			int u = t;
			while(u!=s)
			{
				flow[u][parent[u]] -= currentflow;
				flow[parent[u]][u] += currentflow;
				u = parent[u];
			}
		}
	}while(currentflow>0);
	return maxFlow;
}

int main()
{
	int n, m, tcase = 1;
	while(scanf("%d%d",&n, &m)!=EOF && (n|m))
	{
		int s, t, w;
		vector<vector<int> >graph(n+1);
		int flow[NN][NN] = {0};
		int Cap[NN][NN] = {0};

		for(int i=0; i<m ; i++)
		{
			scanf("%d%d%d", &s, &t, &w);
			graph[s].push_back(t);
			graph[t].push_back(s);
			Cap[s][t] += w;
			Cap[t][s] += w;
		}

		s = 1;
		t = 2;

		int parent[NN];
		edmondKarp(s, t, Cap, flow, graph);
		bpsMaxFlow(s, t, Cap, flow, graph, parent, graph.size()-1);
		parent[s] = 0;

		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(Cap[i][j] > 0 && Cap[i][j] <= flow[i][j] && (parent[i] * parent[j])< 0)
				{
					printf("%d %d\n", i, j);
				}
			}
		}
		printf("\n");
	}
	return 0;
}