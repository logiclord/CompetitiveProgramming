#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
#include<list>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
#define INF 99999999

list<int> cyc;

bool EulerTour(list<int>::iterator itc, vector<vector<pair<int, bool> > > &graph, int s)
{
	bool possible = (graph[s].size()%2 == 0);
	for(vector<pair<int, bool> >::iterator it = graph[s].begin(); possible && it != graph[s].end(); it++)
	{
		if(it->second)
		{
			it->second = false;
			// Removing bidirectional edge
			for(vector<pair<int, bool> >::iterator ij = graph[it->first].begin(); ij != graph[it->first].end(); ij++)
			{
				if(ij->first == s && ij->second)
				{
					ij->second = false;
					break;
				}
			}
			possible = possible && EulerTour(cyc.insert(itc, s), graph, it->first);
		}
	}
	return possible;
}

int main()
{
	int t;
	cin>>t;
	for(int tcase=1; tcase<=t; tcase++)
	{
		if(tcase>1)
			printf("\n");
		cyc.clear();
		int n,x,y;
		cin>>n;
		vector<vector<pair<int, bool> > > graph(1001);
		for(int i=0; i<n; i++)
		{
			cin>>x>>y;
			graph[x].push_back(make_pair(y, true));
			graph[y].push_back(make_pair(x, true));
		}
		printf("Case #%d\n", tcase);
		if(EulerTour(cyc.begin(), graph, x))
		{
			list<int>::iterator it = cyc.begin();
			int prev = *it;
			it++;
			while(it!=cyc.end())
			{
				printf("%d %d\n", prev, *it);
				prev = *it;
				it++;
			}
			printf("%d %d\n", prev, *cyc.begin());
		}
		else
		{
			printf("some beads may be lost\n");
		}
	}
	return 0;
}


