#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<map>
#include<queue>
using namespace std;
#define NN 100
#define INF 99999999999

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
		maxFlow += currentflow;
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

int processInput(char input[], vector<vector<int> > &graph, int Cap[NN][NN], int flow[NN][NN])
{
	int app = input[0]-'A'+ 1;
	int num = input[1] - '0';

	Cap[0][app] += num;
	Cap[app][0] += num;
	graph[0].push_back(app);

	for(int i=3; input[i]!=';'; i++)
	{
		int comp = input[i] - '0' + 27;
		graph[app].push_back(comp);
		graph[comp].push_back(app);
		Cap[app][comp] = 1;
		// Cap[comp][app] <> 1 (only one directional flow allowed)
	}
	return num;
}

int main()
{

	char line[100];
	while(gets(line)!=NULL && line[0]!='\0')
	{
		int Cap[NN][NN] = {0}, flow[NN][NN] = {0};
		vector<vector<int> > graph(38);

		//Adding Constraint
		for(int i=27; i<=36; i++)
		{
			graph[37].push_back(i);
			graph[i].push_back(37);
			Cap[i][37] = Cap[37][i] = 1;
		}

		int val = processInput(line, graph, Cap, flow);
		while(gets(line)!=NULL && line[0]!='\0')
		{
			val += processInput(line, graph, Cap, flow);
		}
		int mf = edmondKarp(0, 37, Cap, flow, graph);
		if(mf != val)
		{
			printf("!\n");
		}
		else
		{
			int temp;
			for(int i=27; i<37; i++)
			{
				temp = -1;
				for(int j=1; j<=26; j++)
				{
					if(Cap[i][j] - flow[i][j] == 2)
					{
						temp = j;
						break;
					}
				}
				if(temp==-1)
					printf("_");
				else
					printf("%c",temp + 'A' -1);
			}
			printf("\n");
		}
	}
	return 0;
}