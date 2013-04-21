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

int t = 1,n,m;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int isValid = true;
        map<int, int> bfs;
        queue<int> q;

        int x,y;
        int adj[201][201] = {0};

        scanf("%d%d",&n,&m);
        for(int j=0; j<m; j++)
        {
            scanf("%d%d",&x,&y);
            adj[x][y] = 1;
            adj[y][x] = 1;
        }

        int ans = 0;
        for(int i=0; isValid && i<n; i++)
        {
            if(bfs.find(i)==bfs.end())
            {
                q.push(i);
                bfs[i] = 1;
                int curz = 0, curo = 1;
                while(isValid && !q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    for(int k=0; k<n; k++)
                    {
                        if(adj[cur][k]==1)
                        {
                            if( bfs.find(k)==bfs.end())
                            {
                                q.push(k);
                                bfs[k] = 1 - bfs[cur];
                                if(bfs[k] == 1)
                                {
                                    curo++;
                                }
                                else
                                {
                                    curz++;
                                }
                            }
                            else if(bfs[k] == bfs[cur])
                            {
                                isValid = false;
                                break;
                            }
                        }
                    }
                }
                if(curz+curo > 1)
                    ans += min(curz, curo);
                else
                    ans++;
            }
        }
        if(isValid)
        {
            printf("%d\n",ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
