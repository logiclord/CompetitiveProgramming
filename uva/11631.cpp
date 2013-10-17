#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Edge
{
	public:
	int wt;
	int v1,v2;
	bool operator <(const Edge &e) const
	{
		return wt < e.wt;
	}
};


int parent[200001];

void initialize(int n)
{
	for(int i=0;i<=n;i++)
	{
		parent[i] = i;
	}
}

int find(int n)
{
	return (parent[n] == n ? n : (parent[n]=find(parent[n])));
}

int isSame(int x,int y)
{
	return find(x) == find(y);
}

void takeUnion(int x, int y)
{
	parent[find(x)] = find(y);
}


int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF && m>0 && n>0)
	{
		vector<Edge> edgeList(n);
		initialize(m);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d", &edgeList[i].v1, &edgeList[i].v2, &edgeList[i].wt);
		}
		sort(edgeList.begin(), edgeList.end());
		long long answer = 0;
		for(vector<Edge>::iterator it = edgeList.begin(); it!=edgeList.end(); it++)
		{
			if(isSame(it->v1,it->v2)==false)
			{
				takeUnion(it->v1, it->v2);
			}
			else
			{
				answer += it->wt;
			}
		}

		printf("%lld\n", answer);
	}
	return 0;
}