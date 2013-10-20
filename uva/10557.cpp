#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>

#define INF 999999999

using namespace std;


bool isReachable(vector<vector<int> > &graph, int s, int d)
{
	vector<int> visited(graph.size(), 0);
	queue<int> qu;

	qu.push(s);
	visited[s] = 1;

	while(!qu.empty())
	{
		int cur = qu.front();
		qu.pop();

		for(vector<int>::iterator it= graph[cur].begin(); it!=graph[cur].end(); it++)
		{
			if(*it==d)
				return true;
			if(!visited[*it])
			{
				visited[*it] = 1;
				qu.push(*it);
			}
		}
	}
	return false;
}

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF && n>=0)
	{
		vector<vector<int> > graph(n);
		vector<int> cost(n);
		vector<int> dist(n, -INF);

		int tmp, tmp2, s=-1, d=-1;

		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &cost[i], &tmp);
			if(cost[i] == 0)
			{
				if(s==-1)
					s = i;
				else
					d = i;
			}
			for(int j=0; j<tmp; j++)
			{
				scanf("%d", &tmp2);
				graph[i].push_back(tmp2-1);
			}
		}

		bool answer = false;

		dist[s] = 100;

		bool hasChanged = true;
		// Bellman-Ford
		for(int i=0;hasChanged && i<n; i++)
		{
			hasChanged = false;
			for(int j=0; j<n; j++)
			{
				for(vector<int>::iterator it= graph[j].begin(); it!=graph[j].end(); it++)
				{
					if(dist[*it] < dist[j] + cost[*it] && dist[j] + cost[*it] > 0)
					{
						hasChanged = true;
						dist[*it] = dist[j] + cost[*it];
					}
				}
			}
		}

		answer = dist[d] > 0;

		for(int i=0; i<n && !answer; i++)
		{
			for(vector<int>::iterator it = graph[i].begin(); it!=graph[i].end() && !answer; it++)
			{
				if(dist[*it] < dist[i] + cost[*it] && dist[i] + cost[*it] > 0 && isReachable(graph, i, d))
				{
					answer = true;
				}
			}
		}

		if(answer)
		{
			// reachable if there it is connected and if
			// 1 We have good enough path
			// 2 We have a positive cycle
			printf("winnable\n");
		}
		else
		{
			printf("hopeless\n");
		}
	}
	return 0;
}