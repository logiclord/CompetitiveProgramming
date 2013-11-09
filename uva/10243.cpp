#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;
#define INF 99999999

int data[1001][2];

int fill(vector<vector<int> > &graph, int v, int s, int parent)
{
	int answer = s;
	if(data[v][s] != INF)
		return data[v][s];
	else if(s == 0)
	{
		answer = 0;
		for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++)
		{
			if(*it == parent)
				continue;
			answer += fill(graph, *it, 1, v);
		}
	}
	else
	{
		answer = 1;
		for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++)
		{
			if(*it == parent)
				continue;
			answer += min(fill(graph, *it, 1, v), fill(graph, *it, 0, v));
		}
	}
	return data[v][s] = answer;
}

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF && n)
	{
		int cur;
		vector<vector<int> > graph(n+1);
		for(int i=1; i<=n ; i++)
		{
			data[i][0] = data[i][1] = INF;
			scanf("%d", &cur);
			int tmp;
			for(int j=0;j<cur;j++)
			{
				scanf("%d", &tmp);
				graph[i].push_back(tmp);
			}
		}

		int answer = min(fill(graph, 1,0, -1), fill(graph, 1,1, -1));

		/*
		// Not needed as we have a connected graph
		for(int i=1; i<=n; i++)
		{
			if(data[i][0] == INF && data[i][1]==INF)
			{
				answer += min(fill(graph, i,0, -1), fill(graph, i,1, -1));
			}
		}*/

		if(n == 1)
			answer = 1;
		printf("%d\n", answer);
	}
	return 0;
}


