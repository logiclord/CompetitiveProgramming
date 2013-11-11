#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
#include<list>
#include<stack>

using namespace std;
#define INF 99999999

// Its a tree so we will have exactly one path between any 2 nodes
void dfs(vector<vector<int> > &graph, int s, int parent[])
{
	int visited[5002] = {0};
	stack<int> nodes;
	nodes.push(s);
	visited[s] = 1;

	while(!nodes.empty())
	{
		int cur = nodes.top();
		nodes.pop();
		visited[cur] = 2; //BLACK
		for(vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
		{
			if(visited[*it] == 0)
			{
				parent[*it] = cur;
				visited[*it] = 1; //GRAY
				nodes.push(*it);
			}
		}
	}
}

void fillPath(pair<int,int>& answer, int s, int d, int parent[])
{
	vector<int> paths, pathd;
	int cur = s;
	while(cur != 0)
	{
		paths.push_back(cur);
		cur = parent[cur];
	}

	cur = d;
	while(cur != 0)
	{
		pathd.push_back(cur);
		cur = parent[cur];
	}

	int n = paths.size()-1, m= pathd.size()-1;
	for(; m>0 && n>0; n--,m--)
	{
		if(paths[n-1] != pathd[m-1])
			break;
	}
	vector<int> path;

	for(int i=0; i<=n; i++)
	{
		path.push_back(paths[i]);
	}
	m--;
	while(m>=0)
	{
		path.push_back(pathd[m--]);
	}
	if(path.size()%2 == 0)
	{
		answer.first = path[path.size()/2];
		answer.second = path[path.size()/2-1];
	}
	else
	{
		answer.first = path[path.size()/2];
		answer.second = -1;
	}
}

int main()
{
	int n;
	// Generic LCA
	while(scanf("%d",&n)!=EOF && n)
	{
		vector<vector<int> > graph(n+1);
		int s, d, k, root = 1, maxi = 0;
		int parent[5002] = {0};
		for(int i = 0; i<n-1 ; i++)
		{
			scanf("%d%d", &s, &d);
			graph[s].push_back(d);
			graph[d].push_back(s);
			maxi = max(maxi, (int)max(graph[s].size(), graph[d].size()));
			if(maxi == graph[s].size())
				root = s;
			else if(maxi == graph[d].size())
				root = d;
		}
		dfs(graph, root, parent);

		scanf("%d", &k);
		for(int i=0; i<k; i++)
		{
			scanf("%d%d", &s, &d);
			pair<int,int> path;
			fillPath(path, s, d, parent);
			if(path.second != -1)
			{
				printf("The fleas jump forever between %d and %d.\n", min(path.first, path.second), max(path.first,path.second));
			}
			else
			{
				printf("The fleas meet at %d.\n", path.first);
			}
		}
	}
	return 0;
}






