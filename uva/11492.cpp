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
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		string source, destination;
		string sl,dl, word;
		map<string, vector<pair<string,string> > >  graph;
		map<string, map<char,int> >  dist;

		cin>>source>>destination;
		for(int i=0; i<n; i++)
		{
			cin>>sl>>dl>>word;
			if(graph.find(sl) == graph.end())
			{
				vector<pair<string, string> > v;
				map<char , int> t;
				dist[sl] = t;
				for(char cur = 'a'; cur<='z'; cur++)
				{
					dist[sl] [cur]= 1000000;
				}
				graph.insert(make_pair(sl,v));
			}
			if(graph.find(dl) == graph.end())
			{
				vector<pair<string, string> > v;
				map<char , int> t;
				dist[dl] = t;
				for(char cur = 'a'; cur<='z'; cur++)
				{
					dist[dl] [cur] = 1000000;
				}
				graph.insert(make_pair(dl,v));
			}
			graph[sl].push_back(make_pair(word,dl));
			graph[dl].push_back(make_pair(word,sl));
		}

		//  Dikshtra
		priority_queue<pair<int,pair<char,string> > , vector<pair<int,pair<char,string> > >, greater<pair<int,pair<char,string> > > > pq;
		dist[source]['_'] = 0;
		pq.push(make_pair(0,make_pair('_',source)));

		while(!pq.empty())
		{
			pair<int,pair<char,string> >  cur = pq.top();
			int curdist = cur.first;
			char lc = cur.second.first;
			string curnode = cur.second.second;
			pq.pop();
			if(dist[curnode][lc] == curdist)
			{
				for(int i=0; i < graph[curnode].size(); i++)
				{
					string word = graph[curnode][i].first;
					string endpoint = graph[curnode][i].second;
					if(word[0]!=lc && dist[curnode][lc] + word.size() < dist[endpoint][word[0]])
					{
						dist[endpoint][word[0]] =  dist[curnode][lc] + word.size();
						pq.push(make_pair(dist[endpoint][word[0]],make_pair(word[0], endpoint)));
					}
				}
			}
		}

		if(source!=destination && dist.find(destination)!=dist.end())
		{
			int mini = 1000000;
			// Try to find shortest from any last character
			for(char cur = 'a'; cur<='z'; cur++)
			{
				mini = min(mini, dist[destination][cur]);
			}
			if(mini!=1000000)
				printf("%d\n",mini);
			else
				printf("impossivel\n");
		}
		else
		{
			printf("impossivel\n");
		}
	}
	return 0;
}