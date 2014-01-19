#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<set>
#include<functional>
#include<ctime>
#include<string>
#include<climits>
#include<cmath>
#include<stack>
#include<vector>
#include<cassert>
#include<map>

#define EPS 0.001
using namespace std;


int main()
{
	int numNodes;
	while(scanf("%d", &numNodes)!=EOF && numNodes > 0)
	{
		int numEdges, source, destination;
		scanf("%d", &numEdges);
		vector<vector<int> > graph(numNodes);
		for(int index=0; index<numEdges; index++)
		{
			scanf("%d%d", &source, &destination);
			graph[source].push_back(destination);
			graph[destination].push_back(source);
		}


		queue<int> pendingQueue;
		map<int, int> visited;
		pendingQueue.push(0);
		visited[0] = 1;
		bool isBipartite = true;
		while(!pendingQueue.empty() && isBipartite)
		{
			int currentVertex = pendingQueue.front();
			pendingQueue.pop();
			for(vector<int>::iterator it = graph[currentVertex].begin(); isBipartite && it!=graph[currentVertex].end(); it++)
			{
				if(visited.find(*it) == visited.end())
				{
					visited[*it] = !visited[currentVertex];
					pendingQueue.push(*it);
				}
				else if(visited[*it] == visited[currentVertex])
				{
					isBipartite = false;
				}
			}
		}

		if(isBipartite)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}
	return 0;
}
