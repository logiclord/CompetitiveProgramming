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


int dist[1001];

int main()
{

	int mini[1001];
	int n,m,t;
	int cases = 1;
	scanf("%d",&t);
	while(t--)
	{
		//bool inQueue[1001];

		int graph[101][101];
		scanf("%d",&n);
		string tmp, tmp2;
		map<string,int> mapping;

		for(int i=0; i<=n; i++)
		{
			dist[i] = 10000000;
			mini[i] = 10000000;
			for(int j=0; j<=n; j++)
			{
				graph[i][j] = 10000000;
			}
		}

		for(int i=1;i<=n;i++)
		{
			cin>>tmp;
			mapping[tmp] = i;
		}

		scanf("%d",&m);
		int d;

		for(int i=1; i<=m ;i++)
		{
			cin>>tmp>>tmp2;
			scanf("%d",&d);
			int x = mapping[tmp], y = mapping[tmp2];
			graph[x][y] = min(graph[x][y], d);
		}

		dist[1] = 0;
		mini[0] = graph[1][n]; 
		for(int i=1; i<=n; i++)
		{
			// Trick is to relax by endpoint of edges (highest -> lowest)
			for(int j=n; j>=1; j--)
			{
				for(int k=1; k<=n; k++)
				{
					dist[j] = min(dist[j], dist[k] + graph[k][j]);
				}
			}
			if(i!=1)
				mini[i-1] = min(mini[i-2], dist[n]);
		}


		if(cases!=1)
			printf("\n");

		printf("Scenario #%d\n",cases);

		int Q;
		cin>>Q;
		while(Q--)
		{
			int q;
			scanf("%d",&q);
			q = max(q,0);
			q = min(q,n-1);
			if(mini[q]<10000000)
			{
				printf("Total cost of flight(s) is $%d\n",mini[q]);
			}
			else
			{
				printf("No satisfactory flights\n");
			}
		}

		cases++;
	}
	return 0;
}