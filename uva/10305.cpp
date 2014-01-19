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


void topologicalSort(vector<vector<int> > &graph, int source, map<int,int>& visited, vector<int>& possibleOrder)
{
	visited[source] = 1;
	for(vector<int>::iterator it = graph[source].begin(); it!=graph[source].end(); it++)
	{
		if(visited.find(*it) == visited.end())
		{
			topologicalSort(graph, *it, visited, possibleOrder);	
		}	
	}
	possibleOrder.push_back(source);
}

int main()
{
	int numVertices, numEdges;
	while(scanf("%d%d", &numVertices, &numEdges)!=EOF && (numVertices || numEdges))
	{
		int source, destination;
		vector< vector<int> > graph(numVertices);
		for(int index= 0; index< numEdges; index++)
		{
			scanf("%d%d", &source, &destination);
			graph[source-1].push_back(destination-1);	
		}

		vector<int> possibleOrder;
		map<int, int> visited;
		for(int index= 0; index< numVertices; index++)
		{
			if(visited.find(index) == visited.end())
			{
				topologicalSort(graph, index, visited, possibleOrder);
			}
		}

		bool firstTime = true;
		for(vector<int>::reverse_iterator it = possibleOrder.rbegin(); it!= possibleOrder.rend(); it++)
		{	
			if(firstTime)
				printf(" ");
			printf("%d", *it + 1);
			firstTime = true;
		}		
		printf("\n");
	}
	
	return 0;
}
