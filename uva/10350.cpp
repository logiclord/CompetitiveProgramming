#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;


#define INF 999999999


int dp(map<pair<int,int>, int> &dist, map<pair<int,int>, vector< pair<int, pair<int,int> > > > &graph, int i, int j, int n, int m)
{
	if(i == 0 && j > 0 && j<=m)
		return 0;
	else if(dist.find(make_pair(i,j)) != dist.end())
		return dist[make_pair(i,j)];
	else
	{
		int answer = INF;
		pair<int,int> p = make_pair(i,j);
		for(vector< pair<int, pair<int,int> > >::iterator it = graph[p].begin(); it!=graph[p].end(); it++)
		{
			answer = min(answer, it->first + dp(dist, graph, it->second.first, it->second.second , n, m));
		}
		dist[p] = answer;
		return answer;
	}
}

int main()
{
	char data[100];
	int n, m;
	while (scanf("%s%d%d", data, &n, &m)!=EOF)
	{
		int wt;
		map<pair<int,int>, vector< pair<int, pair<int,int> > > >graph;
		map<pair<int,int>, int> dist;
		for(int i=0; i<n-1; i++)
		{
			for(int j=1; j<=m; j++)
			{
				for(int k=1; k<=m; k++)
				{
					scanf("%d", &wt);
					graph[make_pair(i+1, k)].push_back(make_pair(wt, make_pair(i, j)));
				}
			}
		}
		int answer = INF;

		for(int i=1; i<=m; i++)
		{
			answer = min(answer, dp(dist, graph, n-1, i, n, m));
		}


		printf("%s\n%d\n",data, (n-1)*2 + answer);
	}	
	return 0;
}