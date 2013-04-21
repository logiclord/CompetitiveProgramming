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
using namespace std;

int main()
{
    int t = 1;
    cin>>t;
    for(int currentCase = 1; currentCase <= t; currentCase++)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        int graph[101][101];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j <n; j++)
            {
                graph[i][j] = 10000000;
            }
            graph[i][i] = 0;
        }

        int u,v;
        for(int i=0; i<r; i++)
        {
            scanf("%d%d",&u,&v);
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j <n; j++)
                {
                    if(graph[i][j] > graph[i][k] + graph[k][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        int s,d;
        scanf("%d%d",&s,&d);
        int cost = 0;
/*
        for(int i=0; i<n; i++)
        {
            for(int j=0; j <n; j++)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
*/
        // search for the bottelneck as others can be accomodated in this timeframe due to infinite commandos
        // can be solved by 2 bfs starting from s and d
        for(int i=0; i<n; i++)
        {
            cost = max(cost, graph[s][i] + graph[i][d]);

        }
        printf("Case %d: %d\n",currentCase, cost);


    }
    return 0;
}


