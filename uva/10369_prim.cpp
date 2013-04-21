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
#include<cstdlib>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,n;
		scanf("%d%d",&s,&n);
		int x[501], y[501];
		int data[501][501];
		vector<int> selectedEdges;
		int dist[501];

		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}

		for(int i=0; i<n; i++)
		{
		    dist[i] = 10000000.0;
			for(int j=i+1; j<n; j++)
			{
				int d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
				data[i][j] = d;
				data[j][i] = d;
			}
		}


        // optimized prim
		priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
		pq.push(make_pair(0,0));
        dist[0] = 0;
		while(!pq.empty())
		{
			pair<int,int> cur = pq.top();
			pq.pop();
			if(dist[cur.second] == cur.first)
			{
				selectedEdges.push_back(cur.first);
				for(int i=0; i<n; i++)
				{
					if(dist[i]>data[cur.second][i])
					{
						 dist[i] = data[cur.second][i];
						 pq.push(make_pair(data[cur.second][i], i));
					}
				}
			}
		}

		sort(selectedEdges.begin(), selectedEdges.end(), greater<int>());
		printf("%.2lf\n", sqrt((double)selectedEdges[s-1]));
	}
	return 0;
}
