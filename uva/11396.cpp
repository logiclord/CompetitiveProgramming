#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>

using namespace std;

int n;

int main()
{
    while(scanf("%d",&n) && n)
    {
        int isValid = true;
        map<int, int> bfs;
        queue<int> q;

        int x,y;
        int adj[301][301] = {0};

        while(scanf("%d%d",&x,&y) && (x|y))
        {
            adj[x][y] = 1;
            adj[y][x] = 1;
        }

        for(int i=1; isValid && i<=n; i++)
        {
            if(bfs.find(i)==bfs.end())
            {
                q.push(i);
                bfs[i] = 1;
                while(isValid && !q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    for(int k=1; k<=n; k++)
                    {
                        if(adj[cur][k]==1)
                        {
                            if( bfs.find(k)==bfs.end())
                            {
                                q.push(k);
                                bfs[k] = 1 - bfs[cur];
                            }
                            else if(bfs[k] == bfs[cur])
                            {
                                isValid = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(isValid)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
