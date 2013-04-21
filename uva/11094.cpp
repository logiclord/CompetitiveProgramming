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

int n,m;
int county = 0;
char land;
char data[101][101];
int dfs_state[101][101];

int dfs(int l, int h)
{
    int ret = 0;
    if(data[l][h] == land && dfs_state[l][h] == -1 && l>=0 && l<n)
    {
        ret = 1;
        dfs_state[l][h] = 1;
        ret += dfs(l+1,h);
        //ret += dfs((l+1)%n, h);
        ret += dfs(l, (h+1)%m);
        ret += dfs(l-1,h);
        // ret += dfs((l-1+n)%n, h);
        ret += dfs(l, (h-1+m)%m);
    }
    return ret;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int x,y;
        county = 0;
        for(int i=0; i<n; i++)
        {
            getchar();
            for(int j=0; j<m; j++)
            {
                scanf("%c",&data[i][j]);
                dfs_state[i][j] = -1;
            }
        }
        scanf("%d%d",&x,&y);
                land = data[x][y];
        dfs(x,y);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(dfs_state[i][j] == -1 && data[i][j]==land)
                {
                    county = max(county, dfs(i,j));
                    //cout<<" --- "<<i<<" "<<j<<" "<<county<<endl;
                }
            }
        }

        printf("%d\n",county);
    }
}
