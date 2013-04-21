#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include <functional>
#include<cmath>

using namespace std;


int main()
{
	int n,m,t;
	scanf("%d",&t);
	while(t--)
	{
		int dist[1001];
		vector<vector<pair<int,int> > > graph;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			vector<pair<int,int> > v;
			graph.push_back(v);
			dist[i] = 1000000;
		}

		int x,y,d;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d",&x,&y,&d);
			graph[x].push_back(make_pair(y,d));
		}

		int isPossible = true;

		for(int i=0; i<n-1; i++)
		{
			for(int j=0; j<n; j++)
			{
				for(vector<pair<int,int> >::iterator it = graph[j].begin(); it!=graph[j].end(); it++)
				{
					dist[it->first] = min(dist[it->first], dist[j] + it->second);
				}
			}
		}

		for(int j=0; j<n && isPossible; j++)
		{
			for(vector<pair<int,int> >::iterator it = graph[j].begin(); it!=graph[j].end(); it++)
			{
				if(dist[it->first] >dist[j] + it->second)
				{
					isPossible = false;
					break;
				}
			}
		}

		if(!isPossible)
			printf("possible\n");
		else
			printf("not possible\n");

	}
	return 0;
}