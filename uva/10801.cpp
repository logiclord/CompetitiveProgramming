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
#include<sstream>

using namespace std;


int data[101][101];

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int dist[101];
		for(int i=0; i<101; i++)
		{
			for(int j=0; j<101; j++)
			{
				data[i][j] = 1000000;
			}
		}

		int maxf = 0 ;
		int cost[5];
		for(int i=0; i<n; i++)
		{
			scanf("%d",&cost[i]);
		}

		int current[101];
		string cur;
		getchar();
		for(int i=0; i<n; i++)
		{
			getline(cin, cur, '\n');
			stringstream sst(cur);
			int tmp;
			int p = 0;
			while(sst>>current[p])
			{
				maxf = max(maxf,current[p]);
				p++;
			}
			for(int j=0; j<p; j++)
			{
				int tmp1 = current[j];
				for(int l=j+1; l<p; l++)
				{
					int tmp2 = current[l];
					int val = min(data[tmp1][tmp2], cost[i]*(tmp2 - tmp1));
					data[tmp1][tmp2] = data[tmp2][tmp1] = val;
				}
			}
		}
	
		for(int i=0; i<=maxf; i++)
		{
			dist[i] = 1000000;
		}

		priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
		dist[0] = 0;
		pq.push(make_pair(0,0));
		while(!pq.empty())
		{
			pair<int,int> cur = pq.top();
			int curdist = cur.first;
			int curnode = cur.second;
			pq.pop();
			if(dist[curnode] == curdist)
			{
				for(int i=1; i<=maxf; i++)
				{
					if((curdist + data[curnode][i] + 60*(curnode!=0) )< dist[i])
					{
						dist[i] = curdist + data[curnode][i] +   60*(curnode!=0);
						pq.push(make_pair(dist[i], i));
					}
				}
			}
		}

		if(dist[k]!=1000000)
		{
			printf("%d\n",dist[k]);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}