#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Edge
{
	int wt,v1,v2;
	bool operator <(const Edge &e) const 
	{
		return wt < e.wt;
	}
};

int parent[101];

void initializeSet(int n)
{
	for(int i=0; i<=n; i++)
	{
		parent[i] = i;
	}
}

int findSet(int x)
{
	return ((parent[x]==x) ? x : (parent[x]=findSet(parent[x])));
}

bool isSameSet(int x, int y)
{
	return findSet(x) == findSet(y);
}

void unionSet(int x, int y)
{
	if(!isSameSet(x,y))
	{
		parent[findSet(x)] = findSet(y);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		initializeSet(n);
		vector<Edge> edgeList(m);
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d", &edgeList[i].v1, &edgeList[i].v2, &edgeList[i].wt);
		}

		sort(edgeList.begin(), edgeList.end());
		int sum = 0, secondSum = 9999999, sumTemp = 0;
		vector<int> selectedEdge;
		int covered = 0;
		// Kruskal MST
		for(vector<Edge>::iterator it = edgeList.begin(); it!=edgeList.end() && covered<n; it++)
		{
			if(!isSameSet(it->v1, it->v2))
			{ 
				covered++;
				sum += it->wt;
				unionSet(it->v1, it->v2);
				selectedEdge.push_back(it-edgeList.begin());
			}
		}

		for(vector<int>::iterator ik = selectedEdge.begin(); ik!=selectedEdge.end(); ik++)
		{
			sumTemp = 0;
			initializeSet(n);
			covered = 0;
			// Trying to build next MST by removing 1 edge at a time.
			// Some Pruning tricks
			for(vector<Edge>::iterator it = edgeList.begin(); it!=edgeList.end() && covered<n && sumTemp<secondSum; it++)
			{
				if(it-edgeList.begin()!=*ik && !isSameSet(it->v1, it->v2))
				{ 
					covered++;
					sumTemp += it->wt;
					unionSet(it->v1, it->v2);
				}
			}
			if(covered+1==n)
				secondSum = min(secondSum, sumTemp);
		}

		printf("%d %d\n",sum, secondSum);
	}
	return 0;
}