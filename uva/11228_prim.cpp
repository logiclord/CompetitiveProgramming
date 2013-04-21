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

int roundOff(double d)
{
    return (d+0.5);
}

struct Comparator
{
  bool operator()(const pair<double,int>& lhs, const pair<double,int>& rhs)
  {
      return lhs.first > rhs.first;
  }
};

double graph[1000][1000];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        int n,r, x,y ;
        double dist[1000];
        vector<pair<int,int> > v;
        scanf("%d%d",&n,&r);

        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            v.push_back(make_pair(x,y));
        }

        for(int i=0; i<n; i++)
        {
            dist[i] = INT_MAX;
            for(int j=0; j<n; j++)
            {
                graph[i][j] = sqrt((v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second-v[j].second)*(v[i].second-v[j].second));
            }
        }

        int city = 1;
        double rail = 0.0, road = 0.0;

        priority_queue<pair<double,int>, vector<pair<double,int> >, Comparator >qu;
        qu.push(make_pair(0,0));
        int visited[1000] = {0};
        dist[0] = 0.0;

        while(!qu.empty())
        {
            pair<double, int> cur = qu.top();
            //cout<<cur.first<<" "<<cur.second<<endl;

            qu.pop();
            if(visited[cur.second] == 0)
            {
                dist[cur.second] = cur.first;
                if(cur.first > r)
                {
                    city++;
                    rail = rail + cur.first;
                }
                else
                {
                    road += cur.first;
                }
                visited[cur.second] = 1;
                for(int i=0; i<n; i++)
                {
                    if(i!=cur.second && visited[i]==0 && dist[i]>graph[cur.second][i])
                    {
                        dist[i] = graph[cur.second][i];
                        qu.push(make_pair(dist[i], i));
                    }
                }
            }
        }

        printf("Case #%d: %d %d %d\n",cas,city,roundOff(road),roundOff(rail));
    }
    return 0;
}


