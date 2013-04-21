#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include<map>
#include<cstdio>
#include<stack>
#include<cstring>
#include<climits>
#include<cmath>
#include<queue>

using namespace std;

int parent[1001];

void preSet(int x)
{
	for(int i=0;i<=x;i++)
	{
		parent[i] = i;
	}
}

int findSet(int x)
{
	return (parent[x]==x ? x : (parent[x]=findSet(parent[x])));
}

bool isSameSet(int x, int y)
{
	return findSet(x) == findSet(y);
}

void unionSet(int x, int y)
{
	parent[findSet(x)] = findSet(y);
}


int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF && (n|m))
	{
		vector<int> ans;
		vector<pair<int, pair<int,int> > > graph;
		preSet(n);

		int p,q,w;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &w);
			graph.push_back(make_pair(w, make_pair(p,q)));
		}

		sort(graph.begin(), graph.end());

		int nofound = true;
		for(vector<pair<int, pair<int,int> > >::iterator it =  graph.begin(); it!= graph.end(); it++)
		{
			if(!isSameSet(it->second.first, it->second.second))
			{
				unionSet(it->second.first, it->second.second);
			}
			else
			{
				if(nofound)
				{
					nofound = false;
					printf("%d", it->first);
				}
				else
				{
					printf(" %d", it->first);
				}
			}
		}
		if(nofound)
		{
			printf("forest");
		}
		printf("\n");
	}

	//system("pause");
	return 0;
}


