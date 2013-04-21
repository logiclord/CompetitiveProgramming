#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<cstdlib>
#include<set>

using namespace std;

int adj[100][100];
int data[12][10000];

int n,m,p;

int tsp(int index, int mask)
{
    if(data[index][mask] != -1)
        return data[index][mask];
    if(mask == ((1<<p) - 1))
    {
        data[index][mask] = adj[index][0];
    }
    else
    {
        int total = INT_MAX;
        for(int k=0; k<p; k++)
        {
            if((mask & (1<<k))==0 && k!=index)
            {
                total = min(total,adj[index][k] + tsp(k, mask | 1<<k));
            }
        }
        data[index][mask]  = total;
    }
    return  data[index][mask];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        vector<pair<int,int> > v;
        scanf("%d%d",&n,&m);
        scanf("%d%d",&x,&y);
        v.push_back(make_pair(x,y));
        scanf("%d",&p);
        for(int i=0; i<p; i++)
        {
            scanf("%d%d",&x,&y);
            v.push_back(make_pair(x,y));
        }
        p++;
        for(int i=0; i<p; i++)
        {
            pair<int,int> ini = v[i];
            for(int j=0; j<p; j++)
            {
                pair<int,int> p2 = v[j];
                if(i==j)
                {
                    adj[i][j] = -1;
                }
                else
                {
                    adj[i][j] = abs(ini.first - p2.first) + abs(ini.second - p2.second);
                }
            }
        }
        memset(data, -1, sizeof(data));
        printf("The shortest path has length %d\n",tsp(0,1));
    }
}
