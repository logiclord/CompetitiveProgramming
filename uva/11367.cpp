#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<map>

#define INF 99999999

using namespace std;

struct state
{
	int city;
	int fuel;
	int cost;
	bool operator<(const state &s) const
	{
		if(cost > s.cost) return true;
		if(cost == s.cost && fuel < s.fuel) return true;
		if(cost == s.cost && fuel == s.fuel && city < s.city) return true;
		return false;
	}
};



state createState(int city, int fuel, int cost)
{
	state current;
	current.city = city;
	current.fuel = fuel;
	current.cost = cost;
	return current;
}

void MiniFuel(vector<vector<pair<int,int> > > &graph, 	vector<int> &cost, int cap, int s, int d)
{
	priority_queue<state> qu;
	int dist[1001][100];

	for(int i=0; i<=graph.size(); i++)
	{
		for(int j=0; j<= cap; j++)
			dist[i][j] = INF;
	}

	dist[s][0] = 0;
	qu.push(createState(s,0,0));

	while(!qu.empty())
	{
		state current = qu.top();
		qu.pop();
		if(current.cost == dist[current.city][current.fuel])
		{
			if(current.fuel<cap && dist[current.city][current.fuel+1] > current.cost + cost[current.city])
			{
				dist[current.city][current.fuel+1] = current.cost + cost[current.city];
				qu.push(createState(current.city, current.fuel+1, current.cost + cost[current.city]));
			}
			for(vector<pair<int,int> >::iterator it = graph[current.city].begin(); it != graph[current.city].end(); it++)
			{
				if(it->second <= current.fuel && dist[it->first][current.fuel - it->second] > current.cost)
				{
					dist[it->first][current.fuel - it->second] = current.cost;
					qu.push(createState(it->first,current.fuel - it->second,current.cost));
				}
			}
		}
	}

	int answer = INF;
	for(int i=0; i<=cap; i++)
	{
		answer = min(answer, dist[d][i]);
	}
	if(answer == INF)
	{
		printf("impossible\n");
	}
	else
	{
		printf("%d\n", answer);
	}
}

int main()
{
	int n,m, x, y, wt;
	scanf("%d%d",&n,&m);
	vector<vector<pair<int,int> > > graph(n);
	vector<int> cost(n);

	for(int i=0; i<n; i++)
	{
		scanf("%d", &cost[i]);
	}

	for(int i=0; i<m; i++)
	{
		scanf("%d%d%d", &x, &y, &wt);
		graph[x].push_back(make_pair(y, wt));
		graph[y].push_back(make_pair(x, wt));
	}

	int q;
	scanf("%d", &q);

	for(int i=0; i<q; i++)
	{
		scanf("%d%d%d", &wt, &x, &y);
		MiniFuel(graph, cost,wt, x, y);
	}

	return 0;
}


