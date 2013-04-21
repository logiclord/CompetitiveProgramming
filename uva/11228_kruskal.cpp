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
using namespace std;



int roundOff(double d)
{
    return (d+0.5);
}
// Disjoint DS

int p[1001];
int rank[1001];
void preSet(int n)
{
    for(int i=0; i<n; i++)
    {
        p[i] = i;
        rank[i] = 1;
    }
}

int findSet(int x)
{
    return ((p[x]==x)? x:(p[x] = findSet(p[x])));
}

int isSameSet(int x, int y)
{
    return (findSet(x) == findSet(y)) ;
}

void unionSet(int x, int y)
{
    if(!isSameSet(x,y))
    {
        int l = findSet(x), m = findSet(y);
        if(rank[m] >= rank[l])
        {
            p[l] = m;
            rank[m] += rank[l];
        }
        else
        {
            p[m] = l;
            rank[l] += m;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        int n,r, x,y ;
        vector<pair<double, pair<int,int> > > edgelist;
        vector<pair<int,int> > v;
        scanf("%d%d",&n,&r);

        preSet(n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            v.push_back(make_pair(x,y));
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double dist = sqrt((v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second-v[j].second)*(v[i].second-v[j].second));
                edgelist.push_back(make_pair(dist , make_pair(i,j)));
            }
        }

        sort(edgelist.begin(), edgelist.end());

        // Using Kruskal MST
        int city = 1;
        double road = 0.0, rail = 0.0;
        for(vector<pair<double, pair<int,int> > >::iterator it=edgelist.begin(); it!= edgelist.end(); it++)
        {
            // cout<<it->first<<endl;
            if(!isSameSet(it->second.first, it->second.second))
            {
                unionSet(it->second.first, it->second.second);
                if(it->first > r)
                {
                    rail += it->first;
                    city++;
                }
                else
                {
                    road += it->first;
                }
            }

        }

        printf("Case #%d: %d %d %d\n",cas,city,roundOff(road),roundOff(rail));
    }
    return 0;
}


