#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<sstream>
using namespace std;

void findCriticalVertices(vector<vector<int> > &graph,int *dfs_low,int * dfs_num,int current,int &rootChilds, int &root,int & visitingNumber,int * isCritialVertex)
{
	dfs_low[current] = dfs_num[current] = visitingNumber++;
	for(vector<int>::iterator it = graph[current].begin(); it != graph[current].end(); it++)
	{
		if(dfs_num[*it] == 0)
		{
			if(current == root)
				rootChilds++;

			findCriticalVertices(graph, dfs_low, dfs_num, *it, rootChilds, root, visitingNumber, isCritialVertex);

			if(dfs_low[*it] >= dfs_num[current])
			{
				isCritialVertex[current]  = 1;
			}

			dfs_low[current] = min(dfs_low[current], dfs_low[*it]);
		}
		else
		{
			dfs_low[current] = min(dfs_low[current], dfs_num[*it]);
		}
	}
}

int main()
{
	int n;
	while(scanf("%d", &n)!=EOF && n)
	{
		vector<vector<int> > graph(n);
		int current, edge;
		while(scanf("%d", &current)!=EOF && current)
		{
			string str;
			getline(cin, str);
			istringstream ist(str);
			while(ist>>edge)
			{
				graph[current-1].push_back(edge-1);
				graph[edge-1].push_back(current-1);
			}
		}

		int dfs_low[100] = {0};
		int dfs_num[100] = {0};
		int rootChilds = 0;
		int visitingNumber = 1;
		int answer = 0;

		for(int i=0; i<n; i++)
		{
			if(dfs_num[i] == 0)
			{
				int isCritialVertex[100] = {0};
				rootChilds = 0;
				findCriticalVertices(graph, dfs_low, dfs_num, i, rootChilds, i, visitingNumber, isCritialVertex);
				isCritialVertex[i] = rootChilds > 1;
				for(int j=0; j<n; j++)
				{
					answer += isCritialVertex[j];
				}
			}
		}
		cout<<answer<<endl;
	}

	return 0;
}