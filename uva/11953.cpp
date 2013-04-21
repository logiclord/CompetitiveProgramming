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

int n;
int county = 0;
char data[101][101];
int dfs_state[101][101];

int dfs(int l, int h)
{
    int ret = 0;
    if(l>=0 && l<n && h>=0 && h<n && data[l][h] != '.' && dfs_state[l][h] == -1)
    {
        if(data[l][h] == 'x')
            ret = 1;
        dfs_state[l][h] = 1;
        ret += dfs(l+1,h);
        ret += dfs(l, h+1);
        ret += dfs(l-1,h);
        ret += dfs(l, h-1);
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        scanf("%d",&n);
        int x,y;
        county = 0;
        for(int i=0; i<n; i++)
        {
            getchar();
            for(int j=0; j<n; j++)
            {
                scanf("%c",&data[i][j]);
                dfs_state[i][j] = -1;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dfs_state[i][j] == -1 && data[i][j]!='.' && dfs(i,j) > 0)
                {
                    county++;
                    //cout<<" --- "<<i<<" "<<j<<" "<<county<<endl;
                }
            }
        }

        printf("Case %d: %d\n",cas,county);
    }
}
