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
using namespace std;

int bfsMaxFlow(int s,int t,vector<vector<int> > &graph,int Cap[101][101],int Flow[101][101], int parent[101], int size)
{
	int minInPath[101] ;

	for(int i=1; i<=size; i++)
		parent[i] = -1;

	minInPath[s] = INF;
	parent[s] = -2;
	queue<int> qu;
	qu.push(s);
	while(!qu.empty())
	{
		int cur = qu.front();
		qu.pop();
		for(vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
		{
			if(parent[*it]==-1 && Cap[cur][*it] - Flow[cur][*it] > 0)
			{
				minInPath[*it] = min(minInPath[cur], Cap[cur][*it] - Flow[cur][*it]);
				parent[*it] = cur;
				qu.push(*it);
				if(*it == t)
					return minInPath[t];
			}
		}
	}
	return 0;
}

int edmondKarpMaxFlow(int s,int t,vector<vector<int> > &graph,int Cap[101][101],int Flow[101][101])
{
	int maxflow = 0;
	int size = graph.size()-1;
	int currentflow = 0;
	do
	{
		int parent[101];
		currentflow = bfsMaxFlow(s, t, graph, Cap, Flow, parent, size);
		int u=t,v;
		if(currentflow != 0)
		{
			maxflow += currentflow;
			while(u!=s)
			{
				v = parent[u];
				Flow[u][v] -= currentflow;
				Flow[v][u] += currentflow;
				u = v;
			}
		}
	}while(currentflow > 0);
	return maxflow;
}

int main()
{
	int n, tcase = 1;
	while(scanf("%d",&n)!=EOF && n)
	{
		int Cap[101][101] = {0};
		int Flow[101][101] = {0};
		vector<vector<int> > graph(n+1);
		int s,t,e, u,v, w;
		scanf("%d%d%d",&s, &t, &e);
		for(int i=0; i<e; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			graph[u].push_back(v);
			graph[v].push_back(u);
			Cap[u][v] += w;
			Cap[v][u] += w;
		}
		int maxFlow = edmondKarpMaxFlow(s,t, graph, Cap, Flow);
		printf("Network %d\n", tcase++);
		printf("The bandwidth is %d.\n\n", maxFlow);
	}
	return 0;
}