#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>


using namespace std;

int n,m;
map<string, int> data;
vector<string> names;
vector<vector<int> > graph;


int dfs_low[30];
int dfs_num[30];
int visited[30];
int num = 0;

void scc(int cur, vector<int>& trav)
{
	dfs_low[cur] = dfs_num[cur] = num++;
	visited[cur] = 1;
	trav.push_back(cur);

	for(vector<int>::iterator it = graph[cur].begin(); it!=graph[cur].end(); it++)
	{
		if(dfs_low[*it]==-1)
		{
			scc(*it, trav);
			if(visited[*it])
				dfs_low[cur] = min(dfs_low[cur], dfs_low[*it]);
		}
		else
		{
			dfs_low[cur] = min(dfs_low[cur], dfs_num[*it]);
		}
	}

	if(dfs_low[cur] == dfs_num[cur])
	{
		int tmp = trav.back();
		cout<<endl<<names[tmp];
		trav.pop_back();
		visited[tmp] = 0;
		while(tmp!=cur)
		{
			tmp = trav.back();
			cout<<", "<<names[tmp];
			trav.pop_back();
			visited[tmp] = 0;
		}
	}
}

int main()
{
	int cases = 1;
	while(scanf("%d%d",&n,&m)!=EOF && (n|m))
	{
		data.clear();
		names.clear();
		graph.clear();
		num = 0;
		memset(dfs_low, -1, sizeof(dfs_low));
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(visited, 0, sizeof(dfs_num));


		for(int i=0; i<n;i++)
		{
			vector<int> v;
			graph.push_back(v);
		}

		string str1, str2;
		int count = 0;
		for(int i=0; i<m; i++)
		{
			cin>>str1>>str2;
			if(data.find(str1) == data.end())
			{
				data[str1] = count++;
				names.push_back(str1);
			}
			if(data.find(str2) == data.end())
			{
				data[str2] = count++;
				names.push_back(str2);
			}
			graph[data[str1]].push_back(data[str2]);
		}

		if(cases!=1)
			printf("\n");

		printf("Calling circles for data set %d:",cases);
		for(int i=0; i<n; i++)
		{
			//cout<<"\ncalling"<<names[i]<<endl;
			if(dfs_num[i]==-1)
			{
				vector<int> v;
				scc(i, v);
			}
		}
		printf("\n");
		cases++;

	}
	return 0;
}