#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

int dppp(vector<int> &paths, vector<vector<int> > &graph, int cur )
{
	if(paths[cur] != -1)
		return paths[cur];

	int ans = 0;
	for(vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
	{
		ans += dppp(paths, graph, *it);
	}

	return paths[cur] = ans;
}

int main()
{
	int n;
	bool blank = false;
	while(scanf("%d", &n)!=EOF)
	{
		if(blank)
			printf("\n");
		blank = true;
		int tmp, tmp2;
		vector<int> deadv;
		vector<vector<int> > graph(n);
		vector<int> paths(n);
		for(int i=0; i<n; i++)
		{
			paths[i] = -1;
			scanf("%d", &tmp);
			if(tmp == 0)
				deadv.push_back(i);
			for(int j=0; j<tmp; j++)
			{
				scanf("%d", &tmp2);
				graph[tmp2].push_back(i);
			}
		}

		int answer = 0;
		paths[0] = 1;
		for(vector<int>::iterator it = deadv.begin(); it != deadv.end(); it++)
		{
			answer = answer + dppp(paths, graph, *it);
		}
		printf("%d\n", answer);
	}

	return 0;
}